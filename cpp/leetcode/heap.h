#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <vector>

namespace leetcode::heap
{
	/* 1005. Maximize Sum Of Array After K Negations.

	Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we
	repeat this process K times in total.  (We may choose the same index i multiple times.)

	Return the largest possible sum of the array after modifying it in this way.

	Example 1:
	Input: A = [4,2,3], K = 1
	Output: 5
	Explanation: Choose indices (1,) and A becomes [4,-2,3].

	Example 2:
	Input: A = [3,-1,0,2], K = 3
	Output: 6
	Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].

	Example 3:
	Input: A = [2,-3,-1,5,-4], K = 2
	Output: 13
	Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].


	Note:

	1 <= A.length <= 10000
	1 <= K <= 10000
	-100 <= A[i] <= 100
	*/

	struct k_negations
	{
		/// <summary>
		/// max sum after k negations
		///
		/// the strategy here is to us a heap to take the k minimum elements one by one,
		/// push the negated version back into the array using heap push, then take the next
		/// until we have negated k values.
		/// </summary>
		/// <param name="arr">array of values</param>
		/// <param name="k">number of negations allowed</param>
		/// <returns>max sum</returns>
		static int largest_sum_after_k_negations( std::vector<int>& arr, int k )
		{
			if( arr.empty() ) return 0;
			if( k == 0 ) return std::accumulate( arr.begin(), arr.end(), 0 );

			std::make_heap( arr.begin(), arr.end(), std::greater<>() );

			while( k > 0 )
			{
				const auto min_value = arr.front();

				std::pop_heap( arr.begin(), arr.end(), std::greater<>() );
				arr.pop_back();

				arr.push_back( -min_value );
				std::push_heap( arr.begin(), arr.end(), std::greater<>() );

				--k;
			}

			return std::accumulate( arr.begin(), arr.end(), 0 );
		}
	};

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

	/// <summary>
	/// median finder
	///
	/// this approach uses two heaps, 1 min & 1 max, to keep the elements partitioned
	/// into two sets, 1 lower than the median and 1 greater than or equal to the median. If
	/// we have a total number of elements that is even, then the median is the simple avg
	/// of the lower and upper top elements. If it's even, then the median is just the top
	/// of the upper heap.
	///
	/// run-time complexity = O(log n)
	/// </summary>
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

	/* 253. Meeting Rooms II.

	Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
	(si < ei), find the minimum number of conference rooms required.

	Example 1:

	Input: [[0, 30],[5, 10],[15, 20]]
	Output: 2

	Example 2:

	Input: [[7,10],[2,4]]
	Output: 1
	NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
	*/

	class meeting_rooms_ii
	{

	public:
		
		/// <summary>
		/// meeting scheduler
		///
		/// uses a priority queue (heap) to book the meetings by first occurring time. 
		/// </summary>
		/// <param name="intervals"></param>
		/// <returns></returns>
		static int schedule( const std::vector<std::vector<int>>& intervals )
		{
			auto meeting_comparer = []( std::vector<int> left, std::vector<int> right )
			{
				return left.front() > right.front();
			};
			
			std::priority_queue<
				std::vector<int>,
				std::vector<std::vector<int>>, decltype( meeting_comparer )> meetings{ meeting_comparer };

			for( const auto& interval : intervals )
			{
				meetings.push( interval );
			}

			std::vector<std::vector<int>> rooms;

			while( !meetings.empty() )
			{
				auto meeting = meetings.top();

				for( auto index = 0ULL; index < rooms.size() + 1; ++index )
				{
					if( rooms.size() <= index )
						rooms.emplace_back();
					
					const auto free_at = rooms[ index ].empty() ? 0 : rooms[ index ].back();
					const auto meeting_start = meeting.at( 0 );

					if( free_at == 0 || free_at <= meeting_start )
					{
						// book it
						const auto meeting_end = meeting.at( 1 );
						rooms[ index ].push_back( meeting_end );
						break;
					}
				}

				meetings.pop();
			}

			return rooms.size();
		}
	};
}