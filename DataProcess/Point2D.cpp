//
// Created by gerko on 05.11.2019.
//
#include <cmath>
#include "Point2D.h"

Point2D::Point2D()
{
    x_ = 0;
    y_ = 0;
}


Point2D::Point2D(double x, double y):
x_(x), y_(y), marked_(false)
{}


double Point2D::x() const
{
    return x_;
}



double Point2D::y() const
{
    return y_;
}



double Point2D::r() const
{
    return sqrt(x_ * x_ + y_ * y_);
}



bool Point2D::isMarked() const
{
    return marked_;
}



void Point2D::mark() const
{
    marked_ = true;
}



void Point2D::unmark() const
{
    marked_ = false;
}



double Point2D::theta() const
{
    return atan2(y_, x_);
}



double Point2D::angleTo(const Point2D &that) const
{
    double dx = that.x_ - this->x_;
    double dy = that.y_ - this->y_;
    return atan2(dy, dx);
}



int Point2D::ccw(const Point2D &a, const Point2D &b, const Point2D &c)
{
    double area2 = (b.x_ - a.x_) * (c.y_ - a.y_) - (b.y_ - a.y_) * (c.x_ - a.x_);
    if (area2 < 0) return -1;
    else if (area2 > 0) return +1;
    else return 0;
}



double Point2D::area2(const Point2D &a, const Point2D &b, const Point2D &c)
{
    return (b.x_ - a.x_) * (c.y_ - a.y_) - (b.y_ - a.y_) * (c.x_ - a.x_);
}



double Point2D::distanceTo(const Point2D &that) const
{
    double dx = this->x_ - that.x_;
    double dy = this->y_ - that.y_;
    return sqrt(dx * dx + dy * dy);
}



double Point2D::distanceSquaredTo(const Point2D &that) const
{
    double dx = this->x_ - that.x_;
    double dy = this->y_ - that.y_;
    return dx * dx + dy * dy;
}



size_t Point2D::quadrantTo(const Point2D &that) const
{
    if (this->x_ > that.x_)
    {
        if (this->y_ > that.y_)
            return 0;
        else
            return 3;
    }
    else
    {
        if (this->y_ > that.y_)
            return 1;
        else
            return 2;
    }
}



bool Point2D::operator<(const Point2D &that) const
{
    if (this->y_ < that.y_) return true;
    if (this->y_ > that.y_) return false;
    if (this->x_ < that.x_) return true;
    return false;
}



bool Point2D::operator>(const Point2D &that) const
{
    if (this->y_ < that.y_) return false;
    if (this->y_ > that.y_) return true;
    if (this->x_ > that.x_) return true;
    return false;
}



bool Point2D::operator==(const Point2D &that) const
{
    if (this->y_ == that.y_ && this->x_ == that.x_) return true;
    return false;
}



bool Point2D::operator!=(const Point2D &that) const
{
    return !(*this == that);
}



bool Point2D::operator<=(const Point2D &that) const
{
    return !(*this > that);
}



bool Point2D::operator>=(const Point2D &that) const
{
    return !(*this < that);
}



std::string Point2D::toString() const
{
    return "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
}



void Point2D::draw() const
{

}



void Point2D::drawTo(Point2D that) const
{

}



size_t std::hash<Point2D>::operator()(const Point2D &point) const
{
    size_t h1 = std::hash<double>()(point.x());
    size_t h2 = std::hash<double>()(point.y());
    return h1 ^ ( h2 << 1 );
}



bool std::equal_to<Point2D>::operator()(const Point2D& lhs, const Point2D rhs) const
{
    return lhs == rhs;
}
