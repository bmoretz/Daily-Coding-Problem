#pragma once

#include <algorithm>
#include <random>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <stack>

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
        ///
        /// tri based approach.
        /// </summary>
        /// <param name="products">list of products to search</param>
        /// <param name="search_word">search word</param>
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

    /* 1188. Design Bounded Blocking Queue.

		Implement a thread safe bounded blocking queue that has the following methods:

		BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
		void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling thread is blocked until the queue is no longer full.
		int dequeue() Returns the element at the rear of the queue and removes it. If the queue is empty, the calling thread is blocked until the queue is no longer empty.
		int size() Returns the number of elements currently in the queue.
		Your implementation will be tested using multiple threads at the same time. Each thread will either be a producer thread that only makes calls to the enqueue method or a consumer thread that only makes calls to the dequeue method. The size method will be called after every test case.

		Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.

		Example 1:

		Input:
		1
		1
		["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
		[[2],[1],[],[],[0],[2],[3],[4],[]]

		Output:
		[1,0,2,2]

		Explanation:
		Number of producer threads = 1
		Number of consumer threads = 1

		BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // initialize the queue with capacity = 2.

		queue.enqueue(1);   // The producer thread enqueues 1 to the queue.
		queue.dequeue();    // The consumer thread calls dequeue and returns 1 from the queue.
		queue.dequeue();    // Since the queue is empty, the consumer thread is blocked.
		queue.enqueue(0);   // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
		queue.enqueue(2);   // The producer thread enqueues 2 to the queue.
		queue.enqueue(3);   // The producer thread enqueues 3 to the queue.
		queue.enqueue(4);   // The producer thread is blocked because the queue's capacity (2) is reached.
		queue.dequeue();    // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
		queue.size();       // 2 elements remaining in the queue. size() is always called at the end of each test case.
		 

		Example 2:

		Input:
		3
		4
		["BoundedBlockingQueue","enqueue","enqueue","enqueue","dequeue","dequeue","dequeue","enqueue"]
		[[3],[1],[0],[2],[],[],[],[3]]

		Output:
		[1,0,2,1]

		Explanation:
		Number of producer threads = 3
		Number of consumer threads = 4

		BoundedBlockingQueue queue = new BoundedBlockingQueue(3);   // initialize the queue with capacity = 3.

		queue.enqueue(1);   // Producer thread P1 enqueues 1 to the queue.
		queue.enqueue(0);   // Producer thread P2 enqueues 0 to the queue.
		queue.enqueue(2);   // Producer thread P3 enqueues 2 to the queue.
		queue.dequeue();    // Consumer thread C1 calls dequeue.
		queue.dequeue();    // Consumer thread C2 calls dequeue.
		queue.dequeue();    // Consumer thread C3 calls dequeue.
		queue.enqueue(3);   // One of the producer threads enqueues 3 to the queue.
		queue.size();       // 1 element remaining in the queue.

		Since the number of threads for producer/consumer is greater than 1, we do not know how the threads will be scheduled in the operating system, even though the input seems to imply the ordering. Therefore, any of the output [1,0,2] or [1,2,0] or [0,1,2] or [0,2,1] or [2,0,1] or [2,1,0] will be accepted.
    */

    class bounded_blocking_queue
    {
        std::mutex queue_mutex_;
        std::condition_variable queue_changed_;
        std::queue<int> queue_;
        std::size_t capacity_;

    public:

        explicit bounded_blocking_queue( const int capacity )
        {
            capacity_ = capacity;
        }

        void enqueue( const int element )
        {
            // add to the front of the queue
            {
                std::unique_lock<std::mutex> lock( queue_mutex_ );

                // grab the lock with queue size < capacity
                queue_changed_.wait( lock, [this] { return queue_.size() < capacity_; } );

                queue_.push( element );
            }

            // Avoid waiters waking up and immediately blocking by unlocking
            // before notifying
            queue_changed_.notify_one();
        }

        int dequeue()
        {
            // remove from the front of the queue

            int ret;

            {
                std::unique_lock<std::mutex> lock( queue_mutex_ );

                queue_changed_.wait( lock, [this] { return queue_.size() > 0; } );

                ret = queue_.front();
                queue_.pop();
            }

            queue_changed_.notify_one();

            return ret;
        }

        int size()
        {
            std::unique_lock<std::mutex> lock( queue_mutex_ );

            return queue_.size();
        }
    };

    /* 895. Maximum Frequency Stack.

    Implement FreqStack, a class which simulates the operation of a stack-like data structure.

    FreqStack has two functions:

    push(int x), which pushes an integer x onto the stack.
    pop(), which removes and returns the most frequent element in the stack.
    If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

    Example 1:

    Input:
    ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
    [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
    Output: [null,null,null,null,null,null,null,5,7,5,4]
    Explanation:
    After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

    pop() -> returns 5, as 5 is the most frequent.
    The stack becomes [5,7,5,7,4].

    pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
    The stack becomes [5,7,5,4].

    pop() -> returns 5.
    The stack becomes [5,7,4].

    pop() -> returns 4.
    The stack becomes [5,7].

    Note:

    Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
    It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
    The total number of FreqStack.push calls will not exceed 10000 in a single test case.
    The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
    The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.

    */

    class frequency_stack
    {
        std::unordered_map<int, std::stack<int>> group_;
        std::unordered_map<int, int> freq_;
        int max_freq_;

    public:

        frequency_stack()
            : max_freq_{ 0 }
        { }

        void push( const int value )
        {
            freq_[ value ]++;
            group_[ freq_[ value ] ].push( value );
            max_freq_ = std::max( max_freq_, freq_[ value ] );
        }

        int pop()
        {
            const auto val = group_[ max_freq_ ].top();

            group_[ max_freq_ ].pop();
            freq_[ val ]--;

            if( group_[ max_freq_ ].empty() )
                --max_freq_;

            return val;
        }
    };
}
