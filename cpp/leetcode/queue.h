#pragma once

#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

namespace leetcode::queue
{
    /* 1429. First Unique Number.

    You have a queue of integers, you need to retrieve the first unique integer in the queue.

    Implement the FirstUnique class:

    FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
    int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
    void add(int value) insert value to the queue.

    Example 1:

    Input:
    ["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
    [[[2,3,5]],[],[5],[],[2],[],[3],[]]
    Output:
    [null,2,null,2,null,3,null,-1]
    Explanation:
    FirstUnique firstUnique = new FirstUnique([2,3,5]);
    firstUnique.showFirstUnique(); // return 2
    firstUnique.add(5);            // the queue is now [2,3,5,5]
    firstUnique.showFirstUnique(); // return 2
    firstUnique.add(2);            // the queue is now [2,3,5,5,2]
    firstUnique.showFirstUnique(); // return 3
    firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
    firstUnique.showFirstUnique(); // return -1
    Example 2:

    Input:
    ["FirstUnique","showFirstUnique","add","add","add","add","add","showFirstUnique"]
    [[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
    Output:
    [null,-1,null,null,null,null,null,17]
    Explanation:
    FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
    firstUnique.showFirstUnique(); // return -1
    firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
    firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
    firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
    firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
    firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
    firstUnique.showFirstUnique(); // return 17
    Example 3:

    Input:
    ["FirstUnique","showFirstUnique","add","showFirstUnique"]
    [[[809]],[],[809],[]]
    Output:
    [null,809,null,-1]
    Explanation:
    FirstUnique firstUnique = new FirstUnique([809]);
    firstUnique.showFirstUnique(); // return 809
    firstUnique.add(809);          // the queue is now [809,809]
    firstUnique.showFirstUnique(); // return -1


    Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^8
    1 <= value <= 10^8
    At most 50000 calls will be made to showFirstUnique and add.
    */

    class first_unique
    {
        std::unordered_map<int, int> seen_;
        std::queue<int> values_;

        void insert_value( const int value )
        {
            seen_[ value ]++;
            values_.push( value );
        }

    public:

        explicit first_unique( const std::vector<int>& numbers )
        {
            for( auto num : numbers )
            {
                insert_value( num );
            }
        }

        int show_first_unique()
        {
            while( !values_.empty() && seen_[ values_.front() ] > 1 )
                values_.pop();

            return values_.empty() ? -1 : values_.front();
        }

        void add( const int value )
        {
            insert_value( value );
        }
    };

    /*346. Moving Average from Data Stream.

    Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

    Example:

    MovingAverage m = new MovingAverage(3);
    m.next(1) = 1
    m.next(10) = (1 + 10) / 2
    m.next(3) = (1 + 10 + 3) / 3
    m.next(5) = (10 + 3 + 5) / 3
    */

    class moving_average_stream
    {

        std::deque<int> data_;
        int capacity_;
        double size_;

    public:

        explicit moving_average_stream( const int size )
            : capacity_{ size }, size_{}
        { }

        double next( const int val )
        {
            if( size_ == capacity_ )
            {
                data_.pop_back();
                size_--;
            }

            data_.push_front( val );
            ++size_;

            auto sum = 0.0;

            for( auto index = 0;
                index < capacity_ && index < data_.size();
                ++index )
            {
                sum += data_[ index ];
            }

            return sum / size_;
        }
    };
}
