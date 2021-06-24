# Introduction

Featureform’s Embedding Store is an open-source embedding management system. Embedding Store powers machine learning development by:
- Storing embeddings durably and with high availability
- Supporting approximate nearest neighbor operations
- Building a workflow around your embeddings
- Providing local caching and offline storage for training


## How it works:

- The general workflow for getting Embedding Store up and running is :
    1) Connect your data sources or upload data directly to Embedding Store.
    2) Set embedding vectors (individually or multi-set) on the server.
    3) Serve embeddings in production or use them as inputs to other models.
- At any point, you can also:
    - Update existing embeddings
    - Rollback versioning and manage provisioning

## Why use Embedding Store?

- Guarantee persistence and availability of your embeddings
    - Generating embeddings can be time-consuming and tedious. Embedding Store allows you to store your embeddings and easily retrieve them, without the hassle and repetitive work.
- Share and re-use your embeddings across your organization
    - Embedding Store allows embedding engineering advancements made by one team to be shared by others. By treating embeddings as building blocks for your models, teams can share and re-use embeddings to increase model performance across the organization.
- Manage your embeddings with built-in versioning and access control
    - Embedding management is essential for an efficient Machine Learning development process. With Embedding Store, anyone can use a specific version of an embedding without breaking the embedding registry.
