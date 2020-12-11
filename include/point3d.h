#ifndef POINT3D_H
#define POINT3D_H

#include "point.h"

class Point3d : public Point {

public:
    Point3d(float t_x, float t_y, float t_z)
        : Point(t_x, t_y, t_z)
    {
    }

    float distance(Point t_point) const
    {
        return (t_point.m_x - m_x) * (t_point.m_x - m_x)
            + (t_point.m_y - m_y) * (t_point.m_y - m_y)
            + (t_point.m_z - m_z) * (t_point.m_y - m_z);
    }
};
#endif /* POINT3D_H */
