#include <ctime>
#include <iostream>
#include <vector>

#include "csv.h"
#include "point.h"

#ifdef WINDOWS
#include <direct.h>
#define getCurrentDir _getcwd
#else
#include <unistd.h>
#define getCurrentDir getcwd
#endif

std::string pwd()
{
    char buff[FILENAME_MAX]; // create string buffer to hold path
    getCurrentDir(buff, FILENAME_MAX);
    std::string workingDir(buff);
    return workingDir;
}

const std::string CSV_INPUT_FILE = pwd() + "/resources/input.csv";
const std::string CSV_OUTPUT_FILE = pwd() + "/resources/output.csv";
const int COMPUTE_REITERATIONS = 1000;
const int K_CLUSTERS = 5;

/**
 * kmeans
 *   Finds t_k clusters of points in a dataset such that
 *   the total variance within each cluster is minimized.
 *
 *   kmeans partitions feature space into t_k subsets to
 *   minimize the "within-cluster sum-of-square deviations"
 *   (WCSS), which is the sum of square Euclidean distances
 *   between each data point and the centroid.
 *
 * @param tptr_points ("tptr" reads this pointer)
 *   2D Points, i.e., x and y in a Cartesian coordinate system:
 *   | x | y |
 *
 * @param t_reiterations ("t" reads this)
 *   number of iterations over which to refine k-means clusters
 *
 * @param t_k ("t" reads this)
 *   number of clusters
 *
 * @retval
 *   returns points allocated to their closest centroid
 *   , i.e., clusters about computed centroids:
 *   | x | y | centroid |
 *
 */
std::vector<Point>* kmeans(
    std::vector<Point>* tptr_points, int t_reiterations, int t_k)
{
    int clusterId = 0;                   // cluster label/id
    std::vector<float> sumY;             // sum of x values per cluster
    std::vector<float> sumX;             // sum of x values per cluster
    std::vector<Point> centroids;        // cluster centroids
    std::vector<int> numClusterPoints;   // number of points per cluster
    int numPoints = tptr_points->size(); // total number of points

    /* initialise random centroids */
    srand(time(0));
    for (int i = 0; i < t_k; ++i) {
        centroids.push_back(tptr_points->at(rand() % numPoints));
    }

    /* for t_reiterations ... */
    for (int i = 0; i < t_reiterations; ++i) {
        clusterId = 0;

        /* assign each data point to the closest centroid */
        for (auto& centroid : centroids) {
            for (auto& point : *tptr_points) {
                if (centroid.distance(point) < point.minDist) {
                    point.minDist = centroid.distance(point);
                    point.cluster = clusterId;
                }
            }
            clusterId++;
        }

        /* per update:
         * re-initialize enumeration containers */
        for (int j = 0; j < t_k; ++j) {
            numClusterPoints.push_back(0);
            sumX.push_back(0.0);
            sumY.push_back(0.0);
        }

        /* enumerate number of points in each cluster:
         * for determining the new centroid locations */
        for (auto& point : *tptr_points) {
            numClusterPoints[point.cluster] += 1;
            sumX[point.cluster] += point.x;
            sumY[point.cluster] += point.y;
            point.minDist = __DBL_MAX__; // reset distance
        }

        clusterId = 0;

        /* compute new centroid for each cluster */
        for (auto& centroid : centroids) {
            centroid.x = sumX[clusterId] / numClusterPoints[clusterId];
            centroid.y = sumY[clusterId] / numClusterPoints[clusterId];
            clusterId++;
        }
    }
    return tptr_points;
}

int main()
{
    std::vector<Point> points;
    std::vector<Point>* ptr_points = nullptr;

    /* get points from csv file */
    points = readcsv(CSV_INPUT_FILE);

    /* evaluate kmeans clusters */
    ptr_points = kmeans(&points, COMPUTE_REITERATIONS, K_CLUSTERS);

    /* write points with assigned clusters */
    write(ptr_points, CSV_OUTPUT_FILE);
}
