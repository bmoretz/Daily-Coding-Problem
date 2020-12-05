#include <bits/stdc++.h>

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

auto main() -> int
{
    const auto vectors = std::vector<std::vector<int>>{
        { }, {-1}
    };

    const auto iter = vector_iterator( vectors );
	
    {
        auto actual = iter.has_next();
        auto expected = true;
    }
	
	return 0;
}