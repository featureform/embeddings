# Getting Started

- In this article, we’ll show you how to get Embedding Store up and running in minutes. Embedding Store is open-source and can be accessed [here](https://github.com/featureform/embeddings).
- By the end of this tutorial, you will have:
    - Your Embedding Store client up and running
    - The ability to create and retrieve new vector embeddings

**Installing Embedding Store**

-The easiest way to install the Python SDK for Python is to use pip.
<br />
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`pip install embedding_store`

**Initializing the Client**
    <br />
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`client = new featureform.embedding.EmbeddingStoreClient()`

**Creating your first embedding**

In this example, we'll upload a vector embedding to the server.

    import embeddingstore

    client.set(key, value)

    client.get(key, value)

