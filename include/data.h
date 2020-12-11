#ifndef DATA_H
#define DATA_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "point.h"
#include "point2d.h"

class Data {
private:
public:
    /* data points to be parsed, created and collected */
    std::vector<Point*> m_points;

    Data(const std::string& t_file)
    {
        /* type definitions for the data */
        float x = 0;
        float y = 0;

        /* type definitions for parsing csv file */
        std::ifstream data(t_file);
        std::string line;

        /* get each line in csv */
        while (std::getline(data, line)) {
            std::stringstream ss(line);
            std::string cell;
            std::vector<std::string> row;

            /* parse each line into vector of strings delimited
             * by [,] */
            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }
            /* create data points */
            x = (float)std::stof(row[0]);
            y = (float)std::stof(row[1]);
            Point* ptr_point = new Point2d(x, y);
            m_points.push_back(ptr_point);
        }
    }

    void write(const std::vector<Point*>& t_points, const std::string& t_file)
    {
        std::ofstream filestream;
        filestream.open(t_file);
        filestream << "x,y,label" << std::endl;

        for (const auto* ptr_point : t_points) {
            filestream << ptr_point->m_x << "," << ptr_point->m_y << ","
                       << ptr_point->m_cluster << std::endl;
        }
        filestream.close();
    }
};
#endif /* Data_H */

/**
 * returning pointers from functions
 * see:
 * https://www.reddit.com/r/cs50/comments/6cfz48/returning_a_pointer_address_from_a_function_not/
 * date: 2020-12-10 19:01
 */

/**
 * caveat:
 *   when creating new data and data pointer within a loop,
 *   take care not to reference the same address repeatedly.
 * date: 2020-12-10 19:01
 */
