#ifndef POINT2D_H
#define POINT2D_H

#include "point.h"

class Point2d : public Point {

public:
    Point2d(float t_x, float t_y)
        : Point(t_x, t_y)
    {
    }

    float distance(Point* t_point) override
    {
        return (t_point->m_x - m_x) * (t_point->m_x - m_x)
            + (t_point->m_y - m_y) * (t_point->m_y - m_y);
    }
};
#endif /* POINT2D_H */
