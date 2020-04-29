#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>

/* Min Stack.
 *
 * Design a stack which, in addition to push and pop, has a
 * min function which returns the minimum element?
 *
 * Push, pop and min should all operate in N(1) time.
 */

template<typename Ty>
class min_stack1
{
    std::vector<Ty> data_, min_;


    explicit min_stack1()
        : data_{ }, min_ { }
    { }

public:
	void push_back( Ty item )
	{
        data_.push_back( item );

        min_.push_back( min_.empty() || item < min_.back() ? item : min_.back() );
	}

	Ty pop()
	{
        const auto item = data_.pop();

		min_.pop();
		
		return item;
	}

    Ty min() const { return min_.back(); }
};

auto main() -> int
{
}