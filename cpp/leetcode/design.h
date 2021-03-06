#pragma once

#include <algorithm>
#include <list>
#include <queue>
#include <vector>

namespace leetcode::design
{
    /* 348. Design Tic-Tac-Toe.

    Design a Tic-tac-toe game that is played between two players on a n x n grid.

    You may assume the following rules:

    A move is guaranteed to be valid and is placed on an empty block.
    Once a winning condition is reached, no more moves is allowed.
    A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
    Example:
    Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

    TicTacToe toe = new TicTacToe(3);

    toe.move(0, 0, 1); -> Returns 0 (no one wins)
    |X| | |
    | | | |    // Player 1 makes a move at (0, 0).
    | | | |

    toe.move(0, 2, 2); -> Returns 0 (no one wins)
    |X| |O|
    | | | |    // Player 2 makes a move at (0, 2).
    | | | |

    toe.move(2, 2, 1); -> Returns 0 (no one wins)
    |X| |O|
    | | | |    // Player 1 makes a move at (2, 2).
    | | |X|

    toe.move(1, 1, 2); -> Returns 0 (no one wins)
    |X| |O|
    | |O| |    // Player 2 makes a move at (1, 1).
    | | |X|

    toe.move(2, 0, 1); -> Returns 0 (no one wins)
    |X| |O|
    | |O| |    // Player 1 makes a move at (2, 0).
    |X| |X|

    toe.move(1, 0, 2); -> Returns 0 (no one wins)
    |X| |O|
    |O|O| |    // Player 2 makes a move at (1, 0).
    |X| |X|

    toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
    |X| |O|
    |O|O| |    // Player 1 makes a move at (2, 1).
    |X|X|X|

    Follow up:
    Could you do better than O(n2) per move() operation?
    */

    class tic_tac_toe
    {
        std::vector<int> rows_, columns_;
        int target_, diagonal_, antidiagonal_;

    public:

        explicit tic_tac_toe( const int n )
            : diagonal_{}, antidiagonal_{}
        {
            target_ = n;
            rows_.resize( n );
            columns_.resize( n );
        }

        int move( const int row, const int col, const int player )
        {
            auto result = 0;
            const auto increment = player == 1 ? 1 : -1;

            columns_[ col ] += increment;
            rows_[ row ] += increment;

            diagonal_ += row == col ? increment : 0;
            antidiagonal_ += row == target_ - 1 - col ? increment : 0;

            if( abs( rows_[ row ] ) == target_ || abs( columns_[ col ] ) == target_ ||
                abs( diagonal_ ) == target_ || abs( antidiagonal_ ) == target_ )
            {
                result = player == 1 ? 1 : 2;
            }

            return result;
        }
    };

    /*251. Flatten 2D Vector.

    Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

    Example:

    Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

    iterator.next(); // return 1
    iterator.next(); // return 2
    iterator.next(); // return 3
    iterator.hasNext(); // return true
    iterator.hasNext(); // return true
    iterator.next(); // return 4
    iterator.hasNext(); // return false


    Notes:

    Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
    You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.

    Follow up:

    As an added challenge, try to code it using only iterators in C++ or iterators in Java.
    */

    class vector_iterator
    {
        const std::vector<std::vector<int>>& vectors_;
        std::size_t row_ = 0, col_ = 0;

    public:

        explicit vector_iterator( const std::vector<std::vector<int>>& v )
            : vectors_( v )
        {}

        int next()
        {
            while( row_ < vectors_.size() &&
                col_ == vectors_[ row_ ].size() )
            {
                ++row_;
                col_ = 0;
            }

            const auto value = vectors_[ row_ ][ col_ ];
            ++col_;

            return value;
        }

        [[nodiscard]] bool has_next() const
        {
            if( row_ >= vectors_.size() ) return false;
            if( col_ < vectors_[ row_ ].size() ) return true;

            auto next = row_ + 1;

            while( next < vectors_.size() )
            {
                if( !vectors_[ next ].empty() )
                    return true;

                ++next;
            }

            return false;
        }
    };

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
        const int num_buckets_ = 11;

    protected:

        [[nodiscard]] int hash( const int key ) const
        {
            return key % num_buckets_;
        }

    public:

        my_hash_set()
        {
            buckets_ = std::vector<bucket>( num_buckets_, bucket() );
        }

        void add( const int key )
        {
            buckets_[ hash( key ) ].insert( key );
        }

        void remove( const int key )
        {
            buckets_[ hash( key ) ].remove( key );
        }

        bool contains( const int key )
        {
            return buckets_[ hash( key ) ].exists( key );
        }
    };

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
}
