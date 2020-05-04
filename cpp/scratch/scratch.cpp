#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <list>

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
            : data_ { }
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
		: data_ { }
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
		stack tmp {};

		while( !data_.empty() )
		{
			auto min = pop_min( data_ );
			tmp.push( min );
		}

		data_ = tmp;
	}
};

auto main() -> int
{
	sort_stack<int> stack = { 3, 2, 4, 7, 6 };

	stack.sort1();
}