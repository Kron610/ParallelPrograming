//
// Created by gerko on 27.11.2019.
//

#ifndef CLASTERISATION_CLASTERISATION_H
#define CLASTERISATION_CLASTERISATION_H

#include "Neighbours.h"




class Clasterisation
{
public:
    class Claster
    {
        std::unordered_set<Point2D> points;

    public:
        Claster();

        decltype(points)::iterator begin();
        decltype(points)::const_iterator cbegin() const;

        decltype(points)::iterator end();
        decltype(points)::const_iterator cend() const;
        void add(Point2D&);
        bool done() const;
    };


    Clasterisation(std::set<Point2D>& points, std::map<Point2D, Neighbours>& neighboursMap);

    std::vector<Claster>& getClasters();

    size_t getNumberOfClaster() const;

private:
    size_t numberOfClaster;
    std::vector<Claster> clasters;
};



#endif //CLASTERISATION_CLASTERISATION_H
