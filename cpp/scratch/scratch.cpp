#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#include <tuple>

/* Generic Stack.
 *
 * Write a stack implementation for a generic value type. The maximal size
 * of the stack is defined in the class (hard-wired). Provide the following
 * functions:
 *
 * + Constructor;
 * + Destructor (if necessary);
 * + top: show last element;
 * + pop: remove last element (without returning it);
 * + push: insert new element;
 * + clear: delete all entries;
 * + size: number of elements
 */

template<typename Ty>
class stack
{
    friend std::ostream& operator<<( std::ostream& out, const stack& stack );
	
    std::unique_ptr<Ty[]> data_;
    std::size_t size_{}, capacity_{};

public:

    explicit stack( const std::size_t capacity = 1)
        : capacity_{ capacity }
    {
        data_ = std::make_unique<Ty[]>( capacity_ );
    }

	explicit stack( const std::initializer_list<Ty>& init_list )
    {
        resize( init_list.size() );

        for( const auto& value : init_list )
            push( value );
    }
	
	void resize( const std::size_t new_size )
    {
        auto new_data = std::make_unique<Ty[]>( new_size );

        std::copy( data_.get(), data_.get() + size_, new_data.get() );
        std::swap( data_, new_data );

        capacity_ = new_size;
    }
	
	void push( const Ty& value )
    {
        if( size_ >= capacity_ )
            resize( capacity_ * 2 );

        data_.get()[ size_++ ] = value;
    }

	[[nodiscard]] Ty pop()
    {
        if( size_ == 0 )
            throw std::runtime_error( "CANNOT POP EMPTY STACK" );
    	
	    return data_.get()[ --size_ ];
    }
	
    [[nodiscard]] Ty top() { return data_.get()[ size_ ]; }

	void clear() { resize( 0 ); }
    [[nodiscard]] auto size() const { return size_; }
    [[nodiscard]] auto empty() const { return size_ == 0; }
};

std::ostream& operator<<( std::ostream& out, const stack<int>& stack )
{
    for( auto index = static_cast< int >( stack.size_ - 1 ); index >= 0; index-- )
    {
        std::cout << stack.data_[ index ];
    }

    return std::cout;
}

auto main() -> int
{
    auto s = stack<int> { 5, 4, 3, 2, 1 };

	for( auto value : { 1, 2, 3, 4, 5 } )
	{
        s.push( value );
	}
	
    std::cout << s;
}