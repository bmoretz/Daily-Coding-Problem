#include <bits/stdc++.h>

/* 754. Reach a Number.

You are standing at position 0 on an infinite number line. There is a goal at position target.

On each move, you can either go left or right. During the n-th move (starting from 1), you take n steps.

Return the minimum number of steps required to reach the destination.

Example 1:
Input: target = 3
Output: 2
Explanation:
On the first move we step from 0 to 1.
On the second step we step from 1 to 3.
Example 2:
Input: target = 2
Output: 3
Explanation:
On the first move we step from 0 to 1.
On the second move we step  from 1 to -1.
On the third move we step from -1 to 2.
Note:
target will be a non-zero integer in the range [-10^9, 10^9].
*/

#include <mutex>
#include <condition_variable>

class bounded_blocking_queue
{
    std::mutex queue_mutex_;
    std::condition_variable queue_changed_;
    std::queue<int> queue_;
    std::size_t capacity_;

public:

	explicit bounded_blocking_queue( const int capacity )
	{
        capacity_ = capacity;
    }

    void enqueue( const int element )
	{
		// add to the front of the queue
        {
            std::unique_lock<std::mutex> lock( queue_mutex_ );

        	// grab the lock with queue size < capacity
            queue_changed_.wait( lock, [this] { return queue_.size() < capacity_; } );

            queue_.push( element );
        }

        // Avoid waiters waking up and immediately blocking by unlocking
		// before notifying
        queue_changed_.notify_one();
    }

    int dequeue()
	{
        // remove from the front of the queue

        int ret;
		
        {
            std::unique_lock<std::mutex> lock( queue_mutex_ );

            queue_changed_.wait( lock, [this] { return queue_.size() > 0; } );

            ret = queue_.front();
            queue_.pop();
        }

        queue_changed_.notify_one();

        return ret;
    }

    int size()
	{
        std::unique_lock<std::mutex> lock( queue_mutex_ );

        return queue_.size();
    }
};

auto main() -> int
{
    auto queue = bounded_blocking_queue( 2 );   // initialize the queue with capacity = 2.

    queue.enqueue( 1 );   // The producer thread enqueues 1 to the queue.
    queue.dequeue();    // The consumer thread calls dequeue and returns 1 from the queue.
    queue.dequeue();    // Since the queue is empty, the consumer thread is blocked.
    queue.enqueue( 0 );   // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
    queue.enqueue( 2 );   // The producer thread enqueues 2 to the queue.
    queue.enqueue( 3 );   // The producer thread enqueues 3 to the queue.
    queue.enqueue( 4 );   // The producer thread is blocked because the queue's capacity (2) is reached.
    queue.dequeue();    // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
    queue.size();       // 2 elements remaining in the queue. size() is always called at the end of each test case.
	
    return 0;
}