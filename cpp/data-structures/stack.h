#pragma once

#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>

namespace data_structures::stack
{
    template<typename Ty>
    class stack
    {
        std::unique_ptr<Ty[]> data_;
        std::size_t size_{}, capacity_{};

    public:

        explicit stack( const std::size_t capacity = 0 )
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

            if( new_size < size_ )
                size_ = new_size;

            std::copy( data_.get(), data_.get() + size_, new_data.get() );
            std::swap( data_, new_data );

            capacity_ = new_size;
        }

        void push( const Ty& value )
        {
            if( size_ >= capacity_ )
                resize( size_ == 0 ? 1 : capacity_ * 2 );

            data_.get()[ size_++ ] = value;
        }

        [[nodiscard]] Ty pop()
        {
            if( size_ == 0 )
                throw std::runtime_error( "CANNOT POP EMPTY STACK" );

            return data_.get()[ --size_ ];
        }

        [[nodiscard]] Ty top() { return data_.get()[ size_ - 1 ]; }

        void clear() { resize( 0 ); }
        [[nodiscard]] auto size() const { return size_; }
        [[nodiscard]] auto empty() const { return size_ == 0; }
    };
}
