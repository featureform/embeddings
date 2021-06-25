# Recommender System

In this example, we’ll build a movie recommender system that’s based on ratings. We’ll manage a collection of users, movies, and ratings that range from 1 to 5. Our final product will take accept a user id and return a list of movies for that user.

**Tutorial structure**

- This example will consist of the following parts:
    - 1) A dataset of movies
    - 2) Models for embedding users and movies
    - 3) An Embedding Store generated index to perform semantic search on those embeddings

**Model and Data preparation**

- Installing python dependencies
    - `!pip install -qU scikit-learn pandas matplotlib tensorflow tfds-nightly`

    ```
    import numpy as np
    import pandas as pd
    import tensorflow as tf
    import tensorflow_datasets as tfds
    ```

**Downloading the data set**

We’ll be using the [Movielens data set](https://grouplens.org/datasets/movielens/), which contains 100,000 ratings (1-5) from 943 users on 1,682 movies.

**Load pre-made Embeddings:**
<br/>
We’ll use TensorFlow recommender library to generate pre-trained movie and user embedding models. We’ll feed the model a user id or a movie title and return a corresponding vector representation.

- Snippet

**Load Ranking Model**
<br/>

For our ranking score, we use this [TensorFlow recommender library tutorial](https://www.tensorflow.org/recommenders/examples/basic_retrieval) to generate a pairwaise scoring model. The model receives a pair of user-movie embeddings and returns a score indicating it's relevance to the user.

- Snippet

## Building the Movie Recommendation Engine 

Now that we have our models ready to go, we can:
-Deploy a recommender system that transforms our data into embeddings, 
-Generate real-time indices for our embeddings
-Return relevant search results for any movie/user

First, we'll need upload our embedding models into Embedding Store and create an index for each. 

**Creating the index**
- snippet

**Uploading Embeddings**

Our recomendation engine will use the movie models to generate embeddings. We'll transform the raw data into embeddings and prepare our items for indexing.

 -snippet

 **Indexing Items**

 -snippet

 ## Testing our Movie Search

 Now that we've created our indexing service and generated our movie embeddings, lets test out our engine!

 **Search for Movie Recommendations**

 In this section, we'll hard code a user (ex. user 8) and retrieve the top 100 movies for them. We'll only display the top ten recommendations, but will use the remaining results for our ranking model.

 -snippet

 ## Deleting the engine

 This optional section will show you how to delete your engine. 

 -snippet

 ## Summary

 To recap, we:
 -Uploaded a premade models
 -Generated user-movie embeddings with indexing
 -Queried our embeddings and returned the most relevant ranking for a given user
 
 Thanks for building a movie recommender with us! 