#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <list>

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
    std::size_t threshold_{}, elements_ { };

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

    [[nodiscard]] bool empty() const { return elements_ > 0; }

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

        elements_--;

        return value;
    }
};

auto main() -> int
{
    auto stack = stack_of_stacks1<int>{ { 5, 8, 9, 12, 15, 18, 20, 22, 23 }, 3 };

    auto val = stack.pop_at( 1 );
	
}