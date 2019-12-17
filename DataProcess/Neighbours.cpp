//
// Created by gerko on 14.12.2019.
//

#include "Neighbours.h"



Neighbours::Neighbours()
{
for (auto item : neighours)
    item = std::set<Point2D>();
}



const std::set<Point2D>& Neighbours::operator[](size_t index) const
{
    return neighours[index];
}



std::set<Point2D>& Neighbours::operator[](size_t index)
{
    return neighours[index];
}




void getNeighbours(const std::set<Point2D>& points, Point2D point, Neighbours& neighbours, const double R)
{
    for (const Point2D& point2 : points)
    {
        if (point2 == point)
            continue;
        auto& points_set = neighbours[point.quadrantTo(point2)];
        if (point.distanceTo(point2) < R)
        {
            if (points_set.empty())
                points_set.insert(point2);
            else
            {
                if (points_set.begin()->distanceTo(point) < point2.distanceTo(point))
                    continue;
                else if (points_set.begin()->distanceTo(point) == point2.distanceTo(point))
                    points_set.insert(point2);
                else
                {
                    points_set.clear();
                    points_set.insert(point2);
                }
            }
        }
    }
}