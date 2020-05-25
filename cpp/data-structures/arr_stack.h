#pragma once

#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>

/// <summary>
/// Array based stack implementation.
/// </summary>
namespace data_structures::arr_stack
{
    template<typename Ty>
    class stack
    {
        std::unique_ptr<Ty[]> data_;
        std::size_t size_{}, capacity_{};

    public:

        explicit stack( const std::size_t capacity = 1 )
            : capacity_{ capacity }
        {
            data_ = std::make_unique<Ty[]>( capacity_ );
        }

        stack( const stack<Ty>& other )
            : stack<Ty>( other.capacity_ )
        {
            size_ = other.size_;

            std::copy( other.data_.get(), other.data_.get() + size_, data_.get() );
        }

    	stack( stack<Ty>&& other ) noexcept
        {
            swap( *this, other );
        	
            return *this;
        }
    	
        stack& operator=( const stack<Ty>& other );

        stack& operator=(stack<Ty>&& other) noexcept;

        explicit stack( const std::initializer_list<Ty>& init_list );

        void push( const Ty& value );
        void pop();
        void resize( std::size_t new_size );

        [[nodiscard]] Ty top() { return data_.get()[ size_ - 1 ]; }

        void clear() { resize( 0 ); }

        stack<Ty>& swap( stack<Ty>& other ) noexcept;

        [[nodiscard]] auto size() const { return size_; }
        [[nodiscard]] auto empty() const { return size_ == 0; }
    };

    template <typename Ty>
    auto stack<Ty>::operator=( const stack<Ty>& other ) -> stack<Ty>&
    {
        if( &other == this ) return *this;

        auto tmp( other );

        tmp.swap( *this );

        return *this;
    }

    template <typename Ty>
    stack<Ty>& stack<Ty>::operator=( stack<Ty>&& other ) noexcept
    {
        using std::swap;

        size_ = other.size_;
        capacity_ = other.capacity_;

        swap( other.data_, data_ );

        return *this;
    }

    template <typename Ty>
    stack<Ty>::stack( const std::initializer_list<Ty>& init_list )
    {
        resize( init_list.size() );

        for( const auto& value : init_list )
            push( value );
    }

    template <typename Ty>
    void stack<Ty>::resize( const std::size_t new_size )
    {
        auto new_data = std::make_unique<Ty[]>( new_size );

        if( new_size < size_ )
            size_ = new_size;

        std::copy( data_.get(), data_.get() + size_, new_data.get() );
        std::swap( data_, new_data );

        capacity_ = new_size;
    }

    template <typename Ty>
    stack<Ty>& stack<Ty>::swap( stack<Ty>& other ) noexcept
    {
        std::swap( data_, other.data_ );
        std::swap( size_, other.size_ );
        std::swap( capacity_, other.capacity_ );

        return *this;
    }

    template <typename Ty>
    void stack<Ty>::push( const Ty& value )
    {
        if( size_ >= capacity_ )
            resize( capacity_ << 1 );

        data_.get()[ size_++ ] = value;
    }

    template <typename Ty>
    void stack<Ty>::pop()
    {
        if( !size_ ) throw std::runtime_error( "CANNOT POP EMPTY STACK" );

        --size_;
    }
}