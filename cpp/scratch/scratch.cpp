#include <bits/stdc++.h>

/*705. Design HashMap.

Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);
hashMap.put(2, 2);
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found)

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.

*/

class my_hash_map
{
	template<typename U, typename V>
	struct pair
	{
        U first;
        V second;

		pair( U first, V second ) :
			first{ first }, second{ second }
		{}
	};

	class bucket
	{
        std::list<pair<int, int>> container_;

		auto find_key( const int key )
		{
			return std::find_if( container_.begin(), container_.end(),
				[key]( const pair<int, int>& current )
				{
					return key == current.first;
				} );
		}
		
	public:

		int get( const int key )
		{
			const auto iter = find_key( key );
			
            if( iter == container_.end() ) return -1;

            return iter->second;
		}

		void update( const int key, const int value )
		{
			const auto iter = find_key( key );
			
			if( iter == container_.end() )
			{
				container_.emplace_back( key, value );
			}
			else
			{
				iter->second = value;
			}
		}
		
		void remove( const int key )
		{
			const auto iter = find_key( key );

			if( iter != container_.end() )
			{
				container_.erase( iter );
			}
		}
	};
	
    std::vector<bucket> buckets_;
    const int num_buckets_ = 2069;

protected:

    [[nodiscard]] int hash( const int key ) const
	{
        return key % num_buckets_;
	}
	
public:
	
    my_hash_map()
    {
        buckets_ = std::vector<bucket>( num_buckets_, bucket() );
    }

    void put( const int key, const int value )
	{
		buckets_[ hash( key ) ].update( key, value );
    }

    void remove( const int key )
	{
		buckets_[ hash( key ) ].remove( key );
    }

    int get( const int key )
    {
		return buckets_[ hash( key ) ].get( key );
    }
};

auto main() -> int
{
    auto hash_map = my_hash_map();

    hash_map.put( 1, 1 );
    hash_map.put( 2, 2 );
    hash_map.get( 1 );            // returns 1
    hash_map.get( 3 );            // returns -1 (not found)
    hash_map.put( 2, 1 );          // update the existing value
    hash_map.get( 2 );            // returns 1 
    hash_map.remove( 2 );          // remove the mapping for 2
    hash_map.get( 2 );            // returns -1 (not found)
	
	return 0;
}