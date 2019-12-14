//
// Created by gerko on 14.12.2019.
//

#include "Clasterisation.h"

Clasterisation::Claster::Claster()
{
    points = std::set<Point2D>();
}



void Clasterisation::Claster::add(Point2D point)
{
    points.insert(point);
}



decltype(Clasterisation::Claster::points.begin()) Clasterisation::Claster::begin()
{
    return points.begin();
}



const decltype(Clasterisation::Claster::points.cbegin()) Clasterisation::Claster::cbegin() const
{
    return points.cbegin();
}



decltype(Clasterisation::Claster::points.end()) Clasterisation::Claster::end()
{
    return points.end();
}



const decltype(Clasterisation::Claster::points.end()) Clasterisation::Claster::cend() const
{
    return points.cend();
}



void Clasterisation::Claster::update(const std::set<Point2D>& pointSet)
{
    for (auto point : pointSet)
    {
        if (this->points.find(point) == this->points.end())
            add(point);
    }
}



bool Clasterisation::Claster::done()
{
    for (auto point : points)
    {
        if (!point.isMarked())
            return false;
    }
    return true;
}



Clasterisation::Clasterisation(std::set<Point2D> points, std::map<Point2D, Neighbours> neighboursMap)
{
    clasters = std::vector<Claster>();
    while (!points.empty())
    {
        auto x = *(points.begin());
        Claster claster = Claster();
        claster.add(x);
        while (!claster.done())
        {
            for (auto point : claster)
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
        clasters.push_back(claster);
    }

}
