/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "embedding_store.h"

#include <glog/logging.h>

#include <cstdlib>
#include <iostream>
#include <memory>

#include "rocksdb/db.h"

using ::featureform::embedding::proto::Neighbor;

namespace featureform {

namespace embedding {

std::unique_ptr<EmbeddingStore> EmbeddingStore::load_or_create(std::string path,
                                                               std::string name,
                                                               int dims) {
  auto storage = EmbeddingStorage::load_or_create(path, dims);
  return std::unique_ptr<EmbeddingStore>(
      new EmbeddingStore(std::move(storage), name, dims));
}

std::unique_ptr<EmbeddingStore> EmbeddingStore::load_or_create_with_index(
    std::string path, std::string name, int dims) {
  auto storage = EmbeddingStorage::load_or_create(path, dims);
  auto store = std::unique_ptr<EmbeddingStore>(
      new EmbeddingStore(std::move(storage), name, dims));
  store->get_or_create_index();
  return store;
}

EmbeddingStore::EmbeddingStore(std::unique_ptr<EmbeddingStorage> storage,
                               std::string name, int dims)
    : storage_(std::move(storage)), name_(name), dims_(dims), idx_(nullptr) {}

void EmbeddingStore::close() {
  DLOG(INFO) << "store: " << name_ << " storage closing...";
  storage_->close();
  storage_.reset();
  DLOG(INFO) << "store: " << name_ << " storage closed";
  if (idx_ != nullptr) {
    DLOG(INFO) << "store: " << name_ << " closing index...";
    idx_.reset();
    DLOG(INFO) << "store: " << name_ << " index closed";
  }
}

void EmbeddingStore::erase() {
  storage_->erase();
  storage_.reset();
  if (idx_ != nullptr) {
    idx_->erase();
    idx_.reset();
  }
}

void EmbeddingStore::set(std::string key, std::vector<float> val) {
  if (idx_ != nullptr) {
    idx_->set(key, val);
  }
  storage_->set(key, val);
}

const std::vector<float> EmbeddingStore::get(const std::string& key) const {
  return storage_->get(key);
}

// Create hnsw index for the class instance
std::shared_ptr<const ANNIndex> EmbeddingStore::get_or_create_index() {
  if (idx_ != nullptr) {
    return idx_;
  }
  idx_ = std::make_shared<ANNIndex>(dims_);
  auto data = storage_->get_all();
  for (const std::pair<std::string, std::vector<float>> row : data) {
    auto key = row.first;
    auto val = row.second;
    idx_->set(key, val);
  }
  return idx_;
}

std::shared_ptr<const ANNIndex> EmbeddingStore::get_index() const {
  return idx_;
}

std::vector<Neighbor> EmbeddingStore::get_neighbors(const std::string& key,
                                                    size_t num) const {
  auto embedding = get(key);
  return idx_->get_neighbors(embedding, num, key);
}

}  // namespace embedding
}  // namespace featureform
