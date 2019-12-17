//
// Created by gerko on 14.12.2019.
//



#ifndef CLASTERISATION_THREADPOOL_H
#define CLASTERISATION_THREADPOOL_H

#include "Point2D.h"


class ThreadPool
{
public:

    ThreadPool (int threads) ;

    ~ThreadPool ();

    void doJob (std::function <void (void)> func);

protected:

    void threadEntry (int i);

    std::mutex lock_;
    std::condition_variable condVar_;
    bool shutdown_;
    std::queue <std::function <void (void)>> jobs_;
    std::vector <std::thread> threads_;
};

#endif //CLASTERISATION_THREADPOOL_H
