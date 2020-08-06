#include <bits/stdc++.h>

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
class LRUCache
{
	const std::size_t capacity_;
	std::unordered_map<TKey, TValue> values_;
	std::list<TKey> keys_;
	
public:

	explicit LRUCache( const std::size_t capacity )
		: capacity_{ capacity }
	{ }

	void put( const TKey key, const TValue value )
	{
		if( values_.find( key ) != values_.end() )
		{
			keys_.remove( key );
			keys_.push_front( key );
		}
		else
		{
			if( keys_.size() >= capacity_ )
			{
				values_.erase( keys_.back() );
				keys_.remove( keys_.back() );
			}
			
			values_.insert( std::make_pair( key, value ) );
			keys_.push_front( key );
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

auto main() -> int
{
	auto cache = LRUCache<int, int>( 2 ); // capacity 

	cache.put( 1, 1 );
	cache.put( 2, 2 );
	std::cout << cache.get( 1 ) << std::endl;     // returns 1
	cache.put( 3, 3 );						 // evicts key 2
	std::cout << cache.get( 2 ) << std::endl;;    // returns -1 (not found)
	cache.put( 4, 4 );						 // evicts key 1
	std::cout << cache.get( 1 ) << std::endl;;     // returns -1 (not found)
	std::cout << cache.get( 3 ) << std::endl;;     // returns 3
	std::cout << cache.get( 4 ) << std::endl;;     // returns 4
	
	return 0;
}