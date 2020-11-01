#pragma once

#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>

namespace data_structures::arr_queue
{
	template<typename Ty>
    class queue
    {
        // array to hold the elements
        std::vector<int> data_;

		// pointer to the head of the queue + size for
		// indexing, and then save the initial capacity.
        int head_, length_, capacity_;

    public:

        explicit queue( const int k )
            : head_{ 0 },
				length_{ 0 },
				capacity_{ k }
        {
            data_ = std::vector<int>( capacity_ );
        }
		
        bool en_queue( const int value )
        {
            if( is_full() )
                return false;

            const auto tail_index = ( head_ + length_ ) % capacity_;
        	
            data_[ tail_index ] = value;

            ++length_;

            return true;
        }

        bool de_queue()
        {
            if( is_empty() )
                return false;

        	// increment head pointer
            head_ = ( head_ + 1 ) % capacity_;
            length_--;

            return true;
        }

        [[nodiscard]] int front() const
        {
            return is_empty() ? -1 : data_[ head_ ];
        }

        [[nodiscard]] int rear() const
        {
            const auto tail_index = ( head_ + length_ - 1 ) % capacity_;
        	
            return is_empty() ? -1 :
        		data_[ tail_index ];
        }

        [[nodiscard]] bool is_empty() const
        {
            return length_ == 0;
        }

        [[nodiscard]] bool is_full() const
        {
            return length_ == capacity_;
        }
    };
}