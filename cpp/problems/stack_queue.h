#pragma once

#include <memory>
#include <vector>
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

        bool empty() const { return data_.empty(); }
    	
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
	
}