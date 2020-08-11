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

    /* 1268. Search Suggestions System.

    Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product
    names from products after each character of searchWord is typed. Suggested products should have common prefix with the
    searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

    Return list of lists of the suggested products after each character of searchWord is typed.

    Example 1:

    Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
    Output: [
        ["mobile","moneypot","monitor"],
        ["mobile","moneypot","monitor"],
        ["mouse","mousepad"],
        ["mouse","mousepad"],
        ["mouse","mousepad"]
    ]

    Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
    After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
    After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
    Example 2:

    Input: products = ["havana"], searchWord = "havana"
    Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
    Example 3:

    Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
    Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
    Example 4:

    Input: products = ["havana"], searchWord = "tatiana"
    Output: [[],[],[],[],[],[],[]]

    Constraints:

    1 <= products.length <= 1000
    There are no repeated elements in products.
    1 <= sum( products[i].length ) <= 2 * 10^4
    All characters of products[i] are lower-case English letters.
    1 <= searchWord.length <= 1000
    All characters of searchWord are lower-case English letters.
    */

    class search_recommendation_system
    {
        class search_tri
        {
            struct tree_node;

            std::unique_ptr<tree_node> root_;

            struct tree_node
            {
                char data;
                std::map<char, std::unique_ptr<tree_node>> children;

                explicit tree_node( const char value )
                    : data{ value }
                { }

                bool has_character( const char chr )
                {
                    return children.find( chr ) != children.end();
                }

                tree_node* insert_child( const char chr )
                {
                    if( children.find( chr ) == children.end() )
                    {
                        children[ chr ] = std::make_unique<tree_node>( chr );
                    }

                    return children[ chr ].get();
                }

                tree_node* get_children( const char chr )
                {
                    return children[ chr ].get();
                }
            };

        public:

            search_tri()
            {
                root_ = std::make_unique<tree_node>( '\0' );
            }

            void insert_word( const std::string& word ) const
            {
                auto level = root_.get();

                for( const auto chr : word )
                {
                    level = level->insert_child( chr );
                }

                level->data = '*';
            }

            static void search( const std::string& res, std::vector<std::string>& item,
                const std::string& prefix, tree_node* node,
                const std::size_t max_result_size = 3 )
            {
                if( item.size() == max_result_size ) return;
                if( !node ) return;

                if( node->data == '*' )
                    item.push_back( prefix + res );

                for( auto iter = node->children.begin();
                    iter != node->children.end(); ++iter )
                {
                    search( res + iter->first, item, prefix, node->children[ iter->first ].get() );
                }
            }

            [[nodiscard]] std::vector<std::vector<std::string>> get_results( const std::string& term,
                                                                             const int max_results = 3 ) const
            {
                auto results = std::vector<std::vector<std::string>>( term.size() );
                auto result_index = std::size_t();

                auto node = root_.get();
                auto prev = true;
                std::string prefix;

                for( auto chr : term )
                {
                    if( node->has_character( chr ) && prev )
                    {
                        prefix += chr;
                        node = node->children[ chr ].get();
                        std::vector<std::string> items;
                        search( "", items, prefix, node );
                        results[ result_index++ ] = items;
                    }
                    else
                    {
                        prev = false;
                        ++result_index;
                    }
                }

                return results;
            }
        };

        search_tri searcher_;

    public:

        /// <summary>
        /// suggest products
        /// </summary>
        /// <param name="products"></param>
        /// <param name="search_word"></param>
        /// <returns></returns>
        [[nodiscard]] std::vector<std::vector<std::string>> suggest_products( const std::vector<std::string>& products,
                                                                              const std::string& search_word ) const
        {
            for( auto& word : products )
            {
                searcher_.insert_word( word );
            }

            return searcher_.get_results( search_word, 3 );
        }
    };
}