## k-means
k-means concept from scratch (under 10 minutes): a standard CMake project demonstrating a naive k-means implementation

---

k-means undoubtedly has varying levels of complexity, depending on approach and application. However, the core concept boils down to 5 easy to grasp fundamental step which can be put together in under 10 minutes (more or less) in CPP.

###### usage:

CMake the project and run the target executable without any args.

main.cpp reads in kemeans.csv |x|y| and outputs output.csv |x|y|label|

graph.py reads and plots both kmeans.csv and output.csv with discernable color markers

## Gist:

##### step 1: select number of clusters
##### step 2: assign random initial centroids
##### step 3: form clusters (i.e., assign each point to its nearest centroid)
##### step 4: compute new cluster centroids
##### step 5: reform clusters (i.e, re-assign each point to its nearest centroid)
