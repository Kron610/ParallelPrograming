//
// Created by gerko on 27.11.2019.
//

#ifndef CLASTERISATION_NEIGHBOURS_H
#define CLASTERISATION_NEIGHBOURS_H

#include "Point2D.h"
#include "SafePtr.h"

class Neighbours
{
public:
    std::set<Point2D> neighours[Point2D::quadrantsCount];

    Neighbours();

    const std::set<Point2D>& operator[](size_t index) const;

    std::set<Point2D>& operator[](size_t index);

};

void getNeighbours(const std::set<Point2D>& points,Point2D point, Neighbours& neighbours, const double R);


#endif //CLASTERISATION_NEIGHBOURS_H
