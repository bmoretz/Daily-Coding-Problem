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

        my_queue() {  }

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
}