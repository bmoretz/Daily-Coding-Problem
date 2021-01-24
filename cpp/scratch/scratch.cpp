#include <bits/stdc++.h>

/*705. Design HashSet.

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();

hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.

*/

class my_hash_set
{
    class bucket
    {
        std::list<int> container_;
    	
    public:

    	void insert( const int key )
    	{
            if( std::find( container_.begin(), container_.end(), key ) != container_.end() )
                return;
    		
			container_.insert( container_.begin(), key );
    	}

    	void remove( const int key )
    	{
            const auto position = 
                std::find( container_.begin(), container_.end(), key );

            if( position == container_.end() )
                return;

            container_.erase( position );
    	}

    	bool exists( const int key )
    	{
            return std::find( container_.begin(), container_.end(), key ) != container_.end();
    	}
    };

    std::vector<bucket> buckets_;
    const int num_buckets = 11;

protected:

    [[nodiscard]] int hash( const int key ) const
	{
        return key % num_buckets;
	}
	
public:
	
    my_hash_set()
    {
        buckets_ = std::vector<bucket>( num_buckets, bucket() );
    }

    void add( const int key )
	{
        buckets_[ hash( key ) ].insert( key );
    }

    void remove( int key )
	{
        buckets_[ hash( key ) ].remove( key );
    }

    bool contains( int key )
    {
        return buckets_[ hash( key ) ].exists( key );
    }
};

auto main() -> int
{
    auto hash_set = my_hash_set();
	
    hash_set.add( 1 );
    hash_set.add( 2 );
    hash_set.contains( 1 );    // returns true
    hash_set.contains( 3 );    // returns false (not found)
    hash_set.add( 2 );
    hash_set.contains( 2 );    // returns true
    hash_set.remove( 2 );
    hash_set.contains( 2 );    // returns false (already removed)
	
	return 0;
}