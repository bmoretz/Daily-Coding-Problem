#include <bits/stdc++.h>

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

auto main() -> int
{
    const auto input = std::vector<int>{ 4, 5, 6, 7, 0, 1, 2 };

    auto ma = moving_average_stream( 3 );

    const auto expected = std::vector<int>{ 4, 4.5, 33, 3 };
	
	for( auto num : input )
	{
        ma.next( num );
	}
	
    const auto actual = moving_average_stream::next( );
    const auto expected = 4;
	
	return 0;
}