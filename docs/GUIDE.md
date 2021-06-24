# Guide

## Upload and Retrieve Embeddings

- Setting and Retrieving embeddings
    - First, we'll need to upload an embedding vector to the server.
        <br/>
        ```
            client.set(key, value)
            client.get(key, value

    - Now that we've stored an embedding, let's retrieve it.
        <br/>
        ```
        client.get(key)

- Multiset
    - Adding vectors one-at-a-time can be time consuming. Let's use multiSet to upload multiple embeddings at once.
        <br/>
        ```
        client.multiset(dictionary)

- Multiget
    - Using the same logic above, let's retrieve multiple embeddings at once.
        <br/>
        ```
        client.multiget(keys)

## Run Operations
- Spaces
    - Embedding store Spaces act as tables for your embeddings for any given number of dimensions. They can be immutable and accommodate different versions of embeddings. To create a new space, enter a `space_name` and the `number of dimensions` you'd like to accommodate.
    - `code snippet`

- Averaging
    - Embedding store averaging method lets you sum your embeddings and generates a 1D representation. In this example, we'll create some word embeddings and use averaging to generate an embedding for a full sentence.
    - `code snippet`

- Nearest Neighbor
    - Embedding store ANN offers a great way to retrieve embeddings that are similar to a given embedding. Use ANN to build a recommender system or similarity search. Our ANN method takes in the `space` we'd like to retrieve from, the embedding index, also known as the `key` we'd like to retrieve, and the `number` of nearest neighbors.
    - `code snippet`