#pragma once

#include <algorithm>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace leetcode::containers
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
	
    /* 380. Insert Delete GetRandom O(1).

    Design a data structure that supports all following operations in average O(1) time.

    insert(val): Inserts an item val to the set if not already present.
    remove(val): Removes an item val from the set if present.
    getRandom: Returns a random element from current set of elements (it's guaranteed that at least one
    element exists when this method is called). Each element must have the same probability of being returned.

    Example:

    // Init an empty set.
    RandomizedSet randomSet = new RandomizedSet();

    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomSet.insert(1);

    // Returns false as 2 does not exist in the set.
    randomSet.remove(2);

    // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomSet.insert(2);

    // getRandom should return either 1 or 2 randomly.
    randomSet.getRandom();

    // Removes 1 from the set, returns true. Set now contains [2].
    randomSet.remove(1);

    // 2 was already in the set, so return false.
    randomSet.insert(2);

    // Since 2 is the only number in the set, getRandom always return 2.
    randomSet.getRandom();
    */

    class randomized_set
    {
        class randomizer
        {
            // random seed by default
            std::mt19937 gen_;
            std::uniform_int_distribution<size_t> dist_;

        public:

            randomizer( const std::size_t min, const std::size_t max,
                       const unsigned int seed = std::random_device{}( ) )
                : gen_{ seed }, dist_{ min, max } {
            }

            void set_seed( const unsigned int seed ) {
                gen_.seed( seed );
            }

            size_t operator()()
            {
                return dist_( gen_ );
            }
        };

        std::unordered_set<int> values_;
        randomizer rand_;

    public:

        randomized_set( const int seed = 0 )
            : rand_{ randomizer( 0, INT32_MAX, seed ) }
        { }
    	
        /// <summary>
        /// Inserts a value to the set.
        /// </summary>
        /// <param name="val">value to insert</param>
        /// <returns>returns true if the set did not already contain the specified element.</returns>
        bool insert( const int val )
        {
            if( values_.find( val ) == values_.end() )
            {
                values_.insert( val );

                return true;
            }

            return false;
        }

        /// <summary>
        /// Removes a value from the set.
        /// </summary>
        /// <param name="val">the value to remove.</param>
        /// <returns>returns true if the set contained the specified element.</returns>
        bool remove( const int val )
        {
            if( values_.find( val ) != values_.end() )
            {
                values_.erase( val );

                return true;
            }

            return false;
        }

        /// <summary>
        /// Get a random element from the set.
        /// </summary>
        /// <returns>random element</returns>
        int get_random()
        {
            const auto offset = rand_() % values_.size();

            auto it = values_.begin();
            std::advance( it, offset );

            return *it;
        }
    };
}