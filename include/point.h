#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>

class Point {
public:
    float m_x;
    float m_y;
    float m_z;
    int m_cluster;
    float m_minDist;

    friend std::ostream& operator<<(std::ostream& t_out, const Point& t_point);

    virtual float distance(Point* tptr_point) = 0;

protected:
    Point()
        : m_x(0.0)
        , m_y(0.0)
        , m_z(0.0)
        , m_cluster(-1)
        , m_minDist(__DBL_MAX__)
    {
    }

    Point(float t_x, float t_y)
        : m_x(t_x)
        , m_y(t_y)
        , m_cluster(-1)
        , m_minDist(__DBL_MAX__)
    {
        m_z = 0;
    }

    Point(float t_x, float t_y, float t_z)
        : m_x(t_x)
        , m_y(t_y)
        , m_z(t_z)
        , m_cluster(-1)
        , m_minDist(__DBL_MAX__)
    {
    }
};

std::ostream& operator<<(std::ostream& t_out, const Point& t_point)
{
    t_out << t_point.m_x << " " << t_point.m_y << " " << t_point.m_z;
    return t_out;
}

#endif /* POINT_H */

/**
 * virtual functions
 * see:
 * https://www.geeksforgeeks.org/virtual-function-cpp/
 * date: 2020-12-10 17:11
 */

/**
 * polymorphism
 * see:
 * https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor
 * see:
 * https://www.ibm.com/support/knowledgecenter/SSLTBW_2.2.0/com.ibm.zos.v2r2.cbclx01/cplr388.htm
 * date: 2020-12-10 17:34
 */
