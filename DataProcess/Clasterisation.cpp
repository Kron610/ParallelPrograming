//
// Created by gerko on 14.12.2019.
//

#include "Clasterisation.h"

Clasterisation::Claster::Claster()
{
    points = std::unordered_set<Point2D>();
}



void Clasterisation::Claster::add(Point2D& point)
{
    points.insert(point);
}



decltype(Clasterisation::Claster::points)::iterator Clasterisation::Claster::begin()
{
    return points.begin();
}



decltype(Clasterisation::Claster::points)::const_iterator Clasterisation::Claster::cbegin() const
{
    return points.cbegin();
}



decltype(Clasterisation::Claster::points)::iterator Clasterisation::Claster::end()
{
    return points.end();
}



decltype(Clasterisation::Claster::points)::const_iterator Clasterisation::Claster::cend() const
{
    return points.cend();
}



bool Clasterisation::Claster::done() const
{
    for (auto point : points)
    {
        if (!point.isMarked())
            return false;
    }
    return true;
}



Clasterisation::Clasterisation(std::set<Point2D>& points, std::map<Point2D, Neighbours>& neighboursMap)
{
    numberOfClaster = 0;
    clasters = std::vector<Claster>();
    while (!points.empty())
    {
        auto x = *(points.begin());
        Claster claster = Claster();
        claster.add(x);
        while (!claster.done())
        {
            for (auto& point : claster)
            {
                if (!point.isMarked())
                {
                    for (size_t i = 0; i < Point2D::quadrantsCount; i++)
                    {
                        for (auto item : neighboursMap[point][i])
                        {
                            claster.add(item);
                        }
                    }
                }
                point.mark();
            }
        }
        for (auto point : claster)
        {
            points.erase(point);
        }
        numberOfClaster++;
        clasters.push_back(claster);
    }
}



std::vector<Clasterisation::Claster>& Clasterisation::getClasters()
{
    return Clasterisation::clasters;
}



size_t Clasterisation::getNumberOfClaster() const
{
    return numberOfClaster;
}