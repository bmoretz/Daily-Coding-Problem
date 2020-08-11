#include <bits/stdc++.h>
#include <random>

/* 295. Find Median from Data Stream.

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/

class median_finder_stream
{
	std::priority_queue<int, std::vector<int>, std::less<>> lower_;
	std::priority_queue<int, std::vector<int>, std::greater<>> upper_;

public:
	
	void add_number( const int number )
	{
		upper_.push( number );

		if( lower_.empty() || upper_.size() - lower_.size() > 1 )
		{
			const auto next = upper_.top();
			upper_.pop();
			lower_.push( next );
		}
		else if( !( lower_.empty() || upper_.empty() ) && lower_.top() > upper_.top() )
		{
			const auto l = lower_.top(), u = upper_.top();
			lower_.pop(); upper_.pop();

			lower_.push( u );
			upper_.push( l );
		}
	}

	double find_median()
	{
		if( upper_.empty() ) return 0;

		const auto num_elements = lower_.size() + upper_.size();

		if( num_elements % 2 == 0 )
		{
			return ( lower_.top() + upper_.top() ) / 2.0f;
		}

		return upper_.top();
	}
};

auto main() -> int
{
	auto mf = median_finder_stream{ };

	mf.add_number( 5 );
	std::cout << mf.find_median() << std::endl;
	
	mf.add_number( 3 );
	std::cout << mf.find_median() << std::endl;

	mf.add_number( 2 );
	std::cout << mf.find_median() << std::endl;

	mf.add_number( 8 );
	std::cout << mf.find_median() << std::endl;

	mf.add_number( 10 );
	std::cout << mf.find_median() << std::endl;

	mf.add_number( 1 );
	std::cout << mf.find_median() << std::endl;
	
    return 0;
}