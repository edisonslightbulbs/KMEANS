#include <ctime>
#include <iostream>
#include <vector>

#include "data.h"
#include "point.h"

#ifdef WINDOWS
#include <direct.h>
#define getCurrentDir _getcwd
#else
#include <unistd.h>
#define getCurrentDir getcwd
#endif

/**
 * kmeans
 *   Finds clusters between points in a dataset such that the to-
 *   tal variance within each cluster is minimized.
 *
 *   kmeans partitions feature space into t_k subsets to minimize
 *   the "within-cluster sum-of-square deviations" (WCSS), which
 *   is the sum of square Euclidean distances between each data
 *   point and the centroid.
 *
 * @param t_points
 *   Points parsed from an external file
 *
 * @param t_reiterations
 *   number of update iterations for computing k-means clusters
 *
 * @param t_k
 *   number of clusters
 *
 * @retval
 *   returns points allocated with their closest centroid */
std::vector<Point*> kmeans(
    const std::vector<Point*>& t_points, int t_reiterations, int t_k)
{
    int clusterId = 0;
    std::vector<float> sumY;
    std::vector<float> sumX;
    std::vector<Point*> centroids;
    int numPoints = t_points.size();
    std::vector<int> numClusterPoints;

    /* initialise random centroids */
    srand(time(0));
    for (int i = 0; i < t_k; ++i) {
        centroids.push_back(t_points.at(rand() % numPoints));
    }
    /* for t_reiterations ... */
    for (int i = 0; i < t_reiterations; ++i) {

        /* ... assign each point to centroid closest to it &
         * label each point with the ID of the closest centroid
         */
        clusterId = 0;
        for (auto* ptr_centroid : centroids) {
            for (auto* ptr_point : t_points) {
                if (ptr_centroid->distance(ptr_point) < ptr_point->m_minDist) {
                    ptr_point->m_minDist = ptr_centroid->distance(ptr_point);
                    ptr_point->m_cluster = clusterId;
                }
            }
            clusterId++;
        }
        /* ... initialize enumeration containers */
        for (int j = 0; j < t_k; ++j) {
            numClusterPoints.push_back(0);
            sumX.push_back(0.0);
            sumY.push_back(0.0);
        }
        /* ... enumerate points in each cluster */
        for (auto* ptr_point : t_points) {
            numClusterPoints[ptr_point->m_cluster] += 1;
            sumX[ptr_point->m_cluster] += ptr_point->m_x;
            sumY[ptr_point->m_cluster] += ptr_point->m_y;
            ptr_point->m_minDist = __DBL_MAX__; // re-initialize
        }
        /* ... compute new centroid for each cluster */
        clusterId = 0;
        for (auto* ptr_centroid : centroids) {
            ptr_centroid->m_x = sumX[clusterId] / numClusterPoints[clusterId];
            ptr_centroid->m_y = sumY[clusterId] / numClusterPoints[clusterId];
            clusterId++;
        }
    }
    return t_points;
}

std::string pwd()
{
    char buff[FILENAME_MAX];
    getCurrentDir(buff, FILENAME_MAX);
    std::string workingDir(buff);
    return workingDir;
}

int main()
{
    const int K_CLUSTERS = 3;
    const int COMPUTE_REITERATIONS = 1000;
    const std::string CSV_INPUT_FILE = pwd() + "/resources/input.csv";
    const std::string CSV_OUTPUT_FILE = pwd() + "/resources/output.csv";

    /* parse csv file */
    Data data(CSV_INPUT_FILE);

    /* evaluate kmeans clusters */
    std::vector<Point*> points;
    points = kmeans(data.m_points, COMPUTE_REITERATIONS, K_CLUSTERS);

    /* write points with assigned clusters */
    data.write(points, CSV_OUTPUT_FILE);
}
