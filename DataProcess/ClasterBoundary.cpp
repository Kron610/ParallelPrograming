//
// Created by gerko on 16.12.2019.
//

#include "ClasterBoundary.h"


Boundary::Boundary()
{
    points = std::set<Point2D>();
}



void Boundary::add(Point2D& point)
{
    points.insert(point);
}



decltype(Boundary::points)::iterator Boundary::begin()
{
    return points.begin();
}



decltype(Boundary::points)::const_iterator Boundary::cbegin() const
{
    return points.cbegin();
}



decltype(Boundary::points)::iterator Boundary::end()
{
    return points.end();
}



decltype(Boundary::points)::const_iterator Boundary::cend() const
{
    return points.cend();
}



bool Boundary::done() const
{
    for (auto point : points)
    {
        if (!point.isMarked())
            return false;
    }
    return true;
}



unsigned long long int Boundary::size() const
{
    return points.size();
}




void getClasterBoundary(Clasterisation::Claster& claster, std::map<Point2D, Neighbours>& neighboursMap, std::vector<Boundary>& boundaries_vector)
{
    std::set<Point2D> points_set;
    for (auto& point : claster)
    {
        for (size_t i = 0; i < Point2D::quadrantsCount; i++)
        {
            if ((neighboursMap[point][i]).empty())
            {
                point.unmark();
                points_set.insert(point);
                break;
            }
        }
    }
    while (!points_set.empty())
    {
        auto x = *(points_set.begin());
        Boundary boundary;
        boundary.add(x);
        while (!boundary.done())
        {
            for (auto &point : boundary)
            {
                if (!point.isMarked())
                {
                    for (size_t i = 0; i < Point2D::quadrantsCount; i++)
                    {
                        for (auto item : neighboursMap[point][i])
                        {
                            if (points_set.find(item) != points_set.end())
                                boundary.add(item);
                        }
                    }
                }
                point.mark();
            }
        }
        for (auto point : boundary)
        {
            points_set.erase(point);
        }
        boundaries_vector.push_back(boundary);
    }
}