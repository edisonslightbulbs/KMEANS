#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

struct Point {
    //     Point(Point* pPoint);
    //
    //     float x;
    //     float y;
    //     float z;
    //
    //     Point()
    //     {
    //         x = 0.0;
    //         y = 0.0;
    //         z = 0.0;
    //     }
    //
    //     Point(const float& x, const float& y, const float& z)
    //         : x(x)
    //         , y(y)
    //         , z(z)
    //     {
    //     }
    //
    //     Point(const Point& point)
    //     {
    //         x = point.x;
    //         y = point.y;
    //         z = point.z;
    //     }
    //
    //     Point& operator=(const Point& point)
    //     {
    //         x = point.x;
    //         y = point.y;
    //         z = point.z;
    //         return *this;
    //     }
    //
    //     friend std::ostream& operator<<(std::ostream& out, const Point&
    //     point);
    float x, y;
    int cluster;
    float minDist;

    Point()
        : x(0.0)
        , y(0.0)
        , cluster(-1)
        , minDist(__DBL_MAX__)
    {
    }
    Point(float x, float y)
        : x(x)
        , y(y)
        , cluster(-1)
        , minDist(__DBL_MAX__)
    {
    }

    /**
     * Computes the (square) euclidean distance between this point and another
     */
    float distance(Point p) const
    {
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
    }
};

// std::ostream& operator<<(std::ostream& out, const Point& point)
// {
//     out << point.x << " " << point.y << " " << point.z;
//     return out;
// }

#endif /* POINT_H */
