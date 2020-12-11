k-means concept from scratch (under 10 minutes): a standard CMake project
demonstrating a naive k-means implementation

***

k-means undoubtedly has varying levels of complexity, depending on approach and
application. However, the core concept boils down to 5 easy to grasp fundamental
step which can be put together in under ~10 minutes in CPP.

## Usage:

CMake the project (thats pretty much it!).

The target and helper scripts are auto-run post the cmake build process.

The helper script `graph.py` graphs data before and after clustering

before clustering |  after clustering
:-------------------------:|:-------------------------:
![](https://raw.githubusercontent.com/edisonslightbulbs/kmeans-cpp/main/resources/before.png)  |  ![](https://raw.githubusercontent.com/edisonslightbulbs/kmeans-cpp/main/resources/after.png)

## Gist:

##### step 1: select number of clusters

##### step 2: assign random initial centroids

##### step 3: form clusters (i.e., assign each point to its nearest centroid)

##### step 4: compute new cluster centroids

##### step 5: reform clusters (i.e, re-assign each point to its nearest centroid)
