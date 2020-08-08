#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::hashtable
{
	/* 146. LRU Cache.

	Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

	The cache is initialized with a positive capacity.

	Follow up:
	Could you do both operations in O(1) time complexity?

	Example:

	LRUCache cache = new LRUCache( 2 ); // capacity

	cache.put( 1, 1 );
	cache.put( 2, 2 );
	cache.get( 1 );       // returns 1
	cache.put( 3, 3 );    // evicts key 2
	cache.get( 2 );       // returns -1 (not found)
	cache.put( 4, 4 );    // evicts key 1
	cache.get( 1 );       // returns -1 (not found)
	cache.get( 3 );       // returns 3
	cache.get( 4 );       // returns 4
	*/

	template<typename TKey, typename TValue>
	class lru_cache
	{
		const std::size_t capacity_;
		std::unordered_map<TKey, TValue> values_;
		std::list<TKey> keys_;

	public:

		explicit lru_cache( const std::size_t capacity )
			: capacity_{ capacity }
		{ }

		void put( const TKey key, const TValue value )
		{
			if( values_.find( key ) != values_.end() )
			{
				// move the key to the front of the list.
				keys_.remove( key );
				keys_.push_front( key );

				// ensure value is updated
				values_[ key ] = value;
			}
			else
			{
				// if we're at capacity, remove the
				// lru item (back of dll)
				if( keys_.size() >= capacity_ )
				{
					values_.erase( keys_.back() );
					keys_.remove( keys_.back() );
				}

				keys_.push_front( key );
				
				values_[ key ] = value;
			}
		}

		TValue get( const TKey key )
		{
			if( values_.find( key ) != values_.end() )
			{
				auto result = values_.at( key );

				keys_.remove( key );
				keys_.push_front( key );

				return result;
			}

			return -1;
		}
	};

	/* 1287. Element Appearing More Than 25% In Sorted Array.

	Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

	Return that integer.

	Example 1:

	Input: arr = [1,2,2,6,6,6,6,7,10]
	Output: 6

	Constraints:

	1 <= arr.length <= 10^4
	0 <= arr[i] <= 10^5
	*/

	struct element_with_most_appearances
	{
		static int find_special_integer( const std::vector<int>& arr )
		{
			std::unordered_map<int, int> counts;
			auto max_freq = -1;

			for( auto cur : arr )
			{
				counts[ cur ]++;

				if( max_freq == -1 || counts[ cur ] > counts[ max_freq ] )
				{
					max_freq = cur;
				}
			}

			return max_freq;
		}
	};
}