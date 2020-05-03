#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <list>

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
			: data_ { }
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

	stack data_ {};
	
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

auto main() -> int
{
	auto queue = my_queue<int>{ 1, 2, 3, 4, 5 };

	auto t1 = queue.dequeue();
	
}