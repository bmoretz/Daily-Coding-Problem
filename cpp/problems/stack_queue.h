#pragma once

#include <memory>
#include <vector>
#include <list>
#include <set>

namespace stack_queue_problems
{
    /* Min Stack.
     *
     * Design a stack which, in addition to push and pop, has a
     * min function which returns the minimum element?
     *
     * Push, pop and min should all operate in N(1) time.
     */

    template<typename Ty>
    class min_stack
    {
        std::vector<Ty> data_, min_;

    public:

        /// <summary>
		/// min_stack
		///
		/// This approach to the min stack problem simply keeps a duplicate
		/// vector of n items, each which correspond to the minimum value in
		/// the stack when it has i items.
		/// <complexity>
		///		<run-time>O(1) for all operations</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>
        explicit min_stack()
            : data_{ }, min_{ }
        { }

		min_stack( const std::initializer_list<Ty>& init_list )
        {
			for( auto item : init_list )
			{
                push_back( item );
			}
        }

        [[nodiscard]] std::size_t size() const { return data_.size(); }

        [[nodiscard]] bool empty() const { return data_.empty(); }
    	
        void push_back( Ty item )
        {
            data_.push_back( item );

            min_.push_back( min_.empty() || item < min_.back() ? item : min_.back() );
        }

        [[nodiscard]] Ty pop()
        {
            Ty item = Ty();
        	
            if( !data_.empty() )
            {
                item = data_.back();

                data_.pop_back();
                min_.erase( min_.begin() );
            }

            return item;
        }

        [[nodiscard]] Ty min() const { return min_.front(); }
    };

    /* Stack of Plates.
     *
     *Imagine a (literal) stack of plates. If the stack gets too high, it might
     *topple. Therefore, in real life, we would likely start a new stack when the previous
     *stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
     *
     *Set of stacks should be composed of several stacks and should create a new stack once the
     *previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave
     *identically to a single stack (that is, pop() should  return the same values as it would
     *if there were just a single stack()).
     *
     *FOLLOW UP
     *
     *Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
     */

    template<typename Ty>
    class stack_of_stacks1
    {
        std::vector<std::list<Ty>> stacks_;
        std::size_t threshold_{}, elements_{ };

    public:
			
		/// <summary>
		/// stack of stacks, 1
		///
		/// This approach uses an internal vector of stacks each with size T,
		/// where T is the stack size threshold. The push/pop operations act
		/// as if the stacks get consolidated to the minimum size (of stacks)
		/// required to hold the N total elements.
		/// <complexity>
		///		<run-time>O(1) push, O(N) pop</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>	
        explicit stack_of_stacks1( const std::size_t max_size )
            : threshold_{ max_size }
        { }

        stack_of_stacks1( const std::initializer_list<Ty>& init_list, std::size_t max_size )
            : stack_of_stacks1( max_size )
        {
            for( const auto& item : init_list )
            {
                push_back( item );
            }
        }

        void push_back( const Ty& item )
        {
            const auto stack = elements_ / threshold_;

            if( stacks_.size() <= stack )
                stacks_.resize( stack + 1 );

            stacks_[ stack ].push_back( std::move( item ) );

            elements_++;
        }

        [[nodiscard]] std::size_t size() const
        {
            return stacks_.size();
        }

        [[nodiscard]] bool empty() const { return elements_ == 0; }

        Ty pop() { return pop_at( 0 ); }

        Ty pop_at( const std::size_t index )
        {
            const auto value = stacks_[ index ].back();

            stacks_[ index ].pop_back();

            for( auto current = index; current < size() - 1; current++ )
            {
                stacks_[ current ].push_back( stacks_[ current + 1 ].front() );
                stacks_[ current + 1 ].pop_front();
            }

            if( stacks_.back().empty() )
                stacks_.pop_back();
        	
            elements_--;

            return value;
        }
    };

    /* Queue via Stacks.
     *
     * Implement a MyQueue class which implements a queue using two stacks.
     */

    template<typename Ty>
    class my_queue
    {
        class stack
        {
            std::vector<Ty> data_;

        public:
            explicit stack()
                : data_{ }
            { }

            void push( const Ty& value )
            {
                data_.push_back( value );
            }

            [[nodiscard]] bool empty() const { return data_.empty(); }

            Ty pop()
            {
                const auto value = data_.back();

                data_.pop_back();

                return value;
            }
        };

        stack data_{};

    public:

        /// <summary>
		/// my_queue
		///
		/// This approach uses a stack as the internal storage structure
		/// and then places the internal stack into a new temp stack on a
		/// dequeue operation, returning the top of the internal stack (first
		/// in), then rebalances the internal stack with the remaining n-1
		/// elements.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
        my_queue() = default;

        my_queue( const std::initializer_list<Ty>& init_list )
        {
            for( const auto& value : init_list )
            {
                data_.push( value );
            }
        }

        [[nodiscard]] bool empty() const { return data_.empty(); }
    	
        void enqueue( Ty item )
        {
            data_.push( item );
        }

        Ty dequeue()
        {
            stack tmp;

            while( !data_.empty() )
                tmp.push( data_.pop() );

            const auto value = tmp.pop();

            data_ = stack();

            while( !tmp.empty() )
                data_.push( tmp.pop() );

            return value;
        }
    };

    /* Sort Stack.
     *
     * Write a program to sort a stack such that the smallest items are on the top. You
     * can use an additional temporary stack, but you may not copy the elements into any
     * other data structure (such as an array). The stack supports the following operations:
     *
     * push, pop, peek, and isEmpty
     */

    template<typename Ty>
    class sort_stack
    {
        class stack
        {
            std::vector<Ty> data_;

        public:

            explicit stack()
                : data_{ }
            {}

            void push( const Ty& item )
            {
                data_.push_back( item );
            }

            Ty pop()
            {
                const auto value = data_.back();

                data_.pop_back();

                return value;
            }

            [[nodicard]] Ty peek() const { return data_.back(); }
            [[nodiscard]] bool empty() const { return data_.empty(); }
        };

        stack data_;

        /// <summary>
        /// pop_min
        ///
        /// This is the worker method for the sorting routing. Here we keep
        /// a running tally of the minimum element as we iterate over the
        /// internal stack, holding it out of the passed in stack each iteration,
        /// then we return the minimum element and the passed in stack now has
        /// n-1 elements.
        /// <complexity>
        ///		<run-time>O(N)</run-time>
        ///		<space>O(N)</space>
        /// </complexity>
        /// </summary>    	
        static Ty pop_min( stack& s )
        {
            Ty min = s.pop();

            stack tmp;

            while( !s.empty() )
            {
                auto cur = s.pop();

                if( cur < min )
                {
                    tmp.push( min );
                    min = cur;
                }
                else
                {
                    tmp.push( cur );
                }
            }

            s = tmp;

            return min;
        }

    public:

        sort_stack()
            : data_{ }
        {  }

        sort_stack( const std::initializer_list<Ty> init_values )
        {
            for( const auto& val : init_values )
            {
                push( val );
            }
        }

        void push( const Ty& item ) { data_.push( item ); }
        Ty pop() { return data_.pop(); }
        [[nodiscard]] Ty empty() { return data_.empty(); }

        void sort1()
        {
            stack tmp{};

            while( !data_.empty() )
            {
                auto min = pop_min( data_ );
                tmp.push( min );
            }

            data_ = tmp;
        }
    };
}