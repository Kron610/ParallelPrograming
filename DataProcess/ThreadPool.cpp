//
// Created by gerko on 14.12.2019.
//

#include "ThreadPool.h"
ThreadPool::ThreadPool (int threads) : shutdown_ (false)
{
// Create the specified number of threads
    threads_.reserve (threads);
    for (int i = 0; i < threads; ++i)
        threads_.emplace_back (std::bind (&ThreadPool::threadEntry, this, i));
}



ThreadPool::~ThreadPool ()
{
    {
// Unblock any threads and tell them to stop
        std::unique_lock<std::mutex> l(lock_);

        shutdown_ = true;
        condVar_.notify_all();
    }
    // Wait for all threads to stop
    for (auto& thread : threads_)
        thread.join();
}



void ThreadPool::doJob (std::function <void (void)> func)
{
// Place a job on the queu and unblock a thread
std::unique_lock <std::mutex> l (lock_);

jobs_.emplace (std::move (func));
condVar_.notify_one();
}



void ThreadPool::threadEntry (int i)
{
    std::function <void (void)> job;

    while (true)
    {
        {
            std::unique_lock <std::mutex> l (lock_);

            while (! shutdown_ && jobs_.empty())
                condVar_.wait (l);

            if (jobs_.empty ())
            {
// No jobs to do and we are shutting down
                return;
            }

            job = std::move (jobs_.front ());
            jobs_.pop();
        }

// Do the job without holding any locks
        job ();
    }

}