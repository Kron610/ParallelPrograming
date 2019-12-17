//
// Created by gerko on 05.11.2019.
//

#ifndef CLASTERISATION_POINT2D_H
#define CLASTERISATION_POINT2D_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <chrono>
#include <memory>



class Point2D {


private:


    double x_;    // x coordinate
    double y_;    // y coordinate
    mutable bool marked_;
/**
 * Initializes a new point (x, y).
 * @param x the x-coordinate
 * @param y the y-coordinate
 */
public:
    static constexpr size_t quadrantsCount = 4;

    Point2D();

    Point2D(double x, double y);

/**
 * Returns the x-coordinate.
 * @return the x-coordinate
 */
    double x() const ;

/**
 * Returns the y-coordinate.
 * @return the y-coordinate
 */
    double y() const;

/**
 * Returns the polar radius of this point.
 * @return the polar radius of this point in polar coordiantes: sqrt(x*x + y*y)
 */
    double r() const;

    bool isMarked() const;

    void mark() const ;

    void unmark() const;
/**
 * Returns the angle of this point in polar coordinates.
 * @return the angle (in radians) of this point in polar coordiantes (between –&pi; and &pi;)
 */
    double theta() const;

/**
 * Returns the angle between this point and that point.
 * @return the angle in radians (between –&pi; and &pi;) between this point and that point (0 if equal)
 */
    double angleTo(const Point2D &that) const;

/**
 * Returns true if a→b→c is a counterclockwise turn.
 * @param a first point
 * @param b second point
 * @param c third point
 * @return { -1, 0, +1 } if a→b→c is a { clockwise, collinear; counterclocwise } turn.
 */
    static int ccw(const Point2D &a, const Point2D &b, const Point2D &c);

/**
 * Returns twice the signed area of the triangle a-b-c.
 * @param a first point
 * @param b second point
 * @param c third point
 * @return twice the signed area of the triangle a-b-c
 */
    static double area2(const Point2D &a, const Point2D &b, const Point2D &c);

/**
 * Returns the Euclidean distance between this point and that point.
 * @param that the other point
 * @return the Euclidean distance between this point and that point
 */
    double distanceTo(const Point2D &that) const;

/**
 * Returns the square of the Euclidean distance between this point and that point.
 * @param that the other point
 * @return the square of the Euclidean distance between this point and that point
 */
    double distanceSquaredTo(const Point2D &that) const;



    size_t quadrantTo(const Point2D& that) const;
/**
 * Compares two points by y-coordinate, breaking ties by x-coordinate.
 * Formally, the invoking point (x0, y0) is less than the argument point (x1, y1)
 * if and only if either {@code y0 < y1} or if {@code y0 == y1} and {@code x0 < x1}.
 *
 * @param  that the other point
 * @return the value {@code 0} if this string is equal to the argument
 *         string (precisely when {@code equals()} returns {@code true});
 *         a negative integer if this point is less than the argument
 *         point; and a positive integer if this point is greater than the
 *         argument point
 */

    bool operator<(const Point2D &that) const;

    bool operator>(const Point2D &that) const;

    bool operator==(const Point2D &that) const;

    bool operator!=(const Point2D &that) const;

    bool operator<=(const Point2D &that) const;

    bool operator>=(const Point2D &that) const;

    std::string toString() const;

/**
 * Plot this point using standard draw.
 */
    void draw() const;

/**
 * Plot a line from this point to that point using standard draw.
 * @param that the other point
 */
    void drawTo(Point2D that) const;

};

namespace std {
    template<>
    class hash<Point2D> {
    public:
        size_t operator()(const Point2D &point) const;
    };



    template<>
    class equal_to<Point2D>
    {
    public:
        bool operator()(const Point2D& lhs, const Point2D rhs) const;
    };
}
#endif //CLASTERISATION_POINT2D_H
