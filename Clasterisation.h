//
// Created by gerko on 27.11.2019.
//

#ifndef CLASTERISATION_CLASTERISATION_H
#define CLASTERISATION_CLASTERISATION_H

#include "Neighbours.h"




class Clasterisation
{
private:
    class Claster
    {
        std::set<Point2D> points;

    public:
        Claster();

        decltype(points.begin()) begin();
        const decltype(points.begin()) cbegin() const;

        decltype(points.end()) end();
        const decltype(points.end()) cend() const;
        void add(Point2D);
        void update(const std::set<Point2D>& pointSet);
        bool done();
    };
    std::vector<Claster> clasters;


public:
    Clasterisation(std::set<Point2D> points, std::map<Point2D, Neighbours> neighboursMap);
};



#endif //CLASTERISATION_CLASTERISATION_H
