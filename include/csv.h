#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "point.h"

std::vector<Point> readcsv(const std::string& t_file)
{
    std::ifstream data(t_file);
    std::string line;
    std::vector<Point> points;
    float x = 0, y = 0;

    while (std::getline(data, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> pointString;

        while (std::getline(lineStream, cell, ',')) {
            pointString.push_back(cell);
        }

        x = (float)std::stof(pointString[0]);
        y = (float)std::stof(pointString[1]);
        Point point(x, y);
        points.push_back(point);
    }
    return points;
}

void write(const std::vector<Point>* points, const std::string& t_file)
{
    std::ofstream myfile;
    myfile.open(t_file);
    myfile << "x,y,label" << std::endl;
    for (const auto& point : *points) {
        myfile << point.x << "," << point.y << "," << point.cluster << std::endl;
    }
    myfile.close();
}

#endif /* CSVREADER_H */
