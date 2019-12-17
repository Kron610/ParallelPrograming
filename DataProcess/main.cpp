
#include "ThreadPool.h"
#include "ClasterBoundary.h"
#include <iostream>
#include <fstream>

int main()
{
    size_t n = 0;
    const double R = 2;
    const size_t threadCount = 3;
    std::vector<Point2D> points;
    std::set<Point2D> points_set;
    std::vector<Neighbours> neighbours_vector;
    std::ifstream in("../points.txt");
    while(!in.eof())
    {
        n++;
        double x, y;
        in >> x >> y;
        Point2D point (x, y);
        points.push_back(point);
        points_set.insert(point);
        neighbours_vector.emplace_back(Neighbours());
    }
    in.close();
    std::map<Point2D, Neighbours> map;

    for (size_t i = 0; i < n; i++)
    {
        getNeighbours(points_set, points[i], neighbours_vector[i], R);
    }

    for (size_t i = 0; i < n; i++)
    {
        map[points[i]] = neighbours_vector[i];
    }

    Clasterisation clasterisation(points_set, map);
    size_t i = 0;
    std::ofstream outCount("../Data/count.txt");
    outCount << clasterisation.getNumberOfClaster();
    outCount.close();
    for (auto& claster : clasterisation.getClasters())
    {
        std::ofstream outClaster("../Data/claster_" + std::to_string(i) + ".txt");
        for (auto& point : claster)
        {
            double x = point.x();
            double y = point.y();
            outClaster << x << " ";
            outClaster << y << "\t";
        }
        outClaster.close();
        std::ofstream out("../Data/clasterBoundaries_" + std::to_string(i) + ".txt");
        std::vector<Boundary> boundaries;
        getClasterBoundary(claster, map, boundaries);
        out << boundaries.size() << "\n";
        for (auto& item : boundaries)
        {
            out << item.size() << " ";
            for (auto& point : item)
            {
                double x = point.x();
                double y = point.y();
                out << x << " ";
                out << y << " ";
            }
            out.write("\n", 1);
        }
        std::cout<< "done";
        i++;
        out.close();
    }
    std:: cout<< "done";

    return 0;
}