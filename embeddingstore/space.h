/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <memory>
#include <optional>
#include <unordered_map>

#include "index.h"
#include "storage.h"

namespace featureform {

namespace embedding {

class Space {
 public:
  static std::shared_ptr<Space> load_or_create(std::string path,
                                               std::string name, int dims);
  void set(std::string key, std::vector<float> value);
  std::string name() const;
  int dims() const;
  std::vector<float> get(const std::string& key) const;
  std::shared_ptr<const ANNIndex> create_ann_index();
  std::shared_ptr<const ANNIndex> get_ann_index() const;

 private:
  Space(std::shared_ptr<EmbeddingStorage> storage, std::string name, int dims);
  std::shared_ptr<EmbeddingStorage> storage_;
  std::string name_;
  int dims_;
  std::shared_ptr<ANNIndex> idx_;
};
}  // namespace embedding
}  // namespace featureform
