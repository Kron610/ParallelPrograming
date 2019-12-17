//
// Created by gerko on 16.12.2019.
//

#ifndef CLASTERISATION_CLASTERBOUNDARY_H

#define CLASTERISATION_CLASTERBOUNDARY_H

#include "Clasterisation.h"

class Boundary
{
private:
    std::set<Point2D> points;

public:
    Boundary();
    decltype(points)::iterator begin();
    decltype(points)::const_iterator cbegin() const;

    decltype(points)::iterator end();
    decltype(points)::const_iterator cend() const;
    void add(Point2D&);
    bool done() const;
    unsigned  long long int size() const;
};

void getClasterBoundary(Clasterisation::Claster& claster, std::map<Point2D, Neighbours>& neighboursMap, std::vector<Boundary>& boundaries_vector);

#endif //CLASTERISATION_CLASTERBOUNDARY_H
