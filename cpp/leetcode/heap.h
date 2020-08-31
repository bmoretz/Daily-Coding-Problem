﻿#pragma once

#include <algorithm>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
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

	/*1167. Minimum Cost to Connect Sticks.

	You have some sticks with positive integer lengths.

	You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

	Return the minimum cost of connecting all the given sticks into one stick in this way.

	Example 1:

	Input: sticks = [2,4,3]
	Output: 14

	Example 2:

	Input: sticks = [1,8,3,5]
	Output: 30

	Constraints:

	1 <= sticks.length <= 10^4
	1 <= sticks[i] <= 10^4
	*/

	class connect_sticks
	{
	public:

		/// <summary>
		/// connect sticks
		///
		/// uses a min heap to take the shortest two sticks to make a new stick,
		/// and each time a new stick is created we accumulate the result variable
		/// with the new stick length, and then push the new stick onto the pile. We
		/// quit accumulating the stick lengths once we have a single stick in the pile.
		/// </summary>
		/// <param name="sticks">stick lengths</param>
		/// <returns>minimum sum of their cumulative lengths.</returns>
		static int connect( const std::vector<int>& sticks )
		{
			auto heap = std::vector<int>( sticks );
			auto result = 0;

			std::make_heap( heap.begin(), heap.end(), std::greater<>{} );

			while( heap.size() > 1 )
			{
				std::pop_heap( heap.begin(), heap.end(), std::greater<>{} );
				const auto s1 = heap.back();
				heap.pop_back();

				std::pop_heap( heap.begin(), heap.end(), std::greater<>{} );
				const auto s2 = heap.back();
				heap.pop_back();

				const auto new_stick = s1 + s2;
				result += new_stick;

				heap.push_back( new_stick );
			}

			return result;
		}
	};

	/*692. Top K Frequent Words.

	Given a non-empty list of words, return the k most frequent elements.

	Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

	Example 1:

	Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
	Output: ["i", "love"]

	Explanation: "i" and "love" are the two most frequent words.
		Note that "i" comes before "love" due to a lower alphabetical order.
	Example 2:

	Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
	Output: ["the", "is", "sunny", "day"]
	Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
		with the number of occurrence being 4, 3, 2 and 1 respectively.
	Note:

	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.

	Input words contain only lowercase letters.
	Follow up:
	Try to solve it in O(n log k) time and O(n) extra space.

	*/

	class top_k_frequent
	{
		static std::unordered_map<std::string, int> to_frequency_map( const std::vector<std::string>& words )
		{
			std::unordered_map<std::string, int> frequency;

			for( const auto& word : words )
			{
				frequency[ word ]++;
			}

			return frequency;
		}

		static auto to_priority_queue( const std::unordered_map<std::string, int>& freq )
		{
			auto compare = []( const std::pair<std::size_t, std::string>& left, const std::pair<std::size_t, std::string>& right )
			{
				if( left.first < right.first ) return true;
				if( left.first == right.first && left.second > right.second ) return true;

				return false;
			};

			std::priority_queue<std::pair<int, std::string>,
				std::vector<std::pair<int, std::string>>,
				decltype( compare )> queue( compare );

			for( auto& [k, v] : freq )
			{
				queue.push( std::make_pair( v, k ) );
			}

			return queue;
		}

	public:

		/// <summary>
		/// top k frequent words
		///
		/// the approach here is to create a freq counter in a map (str->int), then insert the key/value pairs from the freq table
		/// into a heap with a custom comparer (first priority is the freq, then break freq ties with the lexicographical ordering of
		/// the keys).
		/// </summary>
		/// <param name="words">list of words</param>
		/// <param name="k">top k to return</param>
		/// <returns>top k most frequent</returns>
		static std::vector<std::string> top_k( const std::vector<std::string>& words,
			const std::size_t k )
		{
			if( words.size() < k ) return words;

			const auto freq = to_frequency_map( words );
			auto queue = to_priority_queue( freq );

			auto result = std::vector<std::string>();

			for( auto index = 0; index < k; ++index )
			{
				result.push_back( queue.top().second );
				queue.pop();
			}

			return result;
		}
	};

}