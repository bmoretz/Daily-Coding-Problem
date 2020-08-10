#include <bits/stdc++.h>
#include <random>

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
        
        randomizer( std::size_t min, const std::size_t max, 
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

    std::set<int> values_;
    randomizer rand_{ 0, INT32_MAX };
	
public:

	randomized_set( const int seed = 0 )
    {
        rand_ = randomizer( 0, INT32_MAX, seed );
    }
	
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
    int getRandom()
	{
        const auto offset = rand_() % values_.size();

        auto it = values_.begin();
        std::advance( it, offset );
    	
        return *it;
    }
};

auto main() -> int
{
    auto rnd = randomized_set();
	
    rnd.insert( 1 );
    rnd.insert( 2 );
    rnd.insert( 1 );
	
    std::cout << rnd.getRandom() << std::endl;
	
    return 0;
}