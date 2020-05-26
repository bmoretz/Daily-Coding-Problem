#pragma once

#include <algorithm>
#include <memory>
#include <ostream>
#include <cassert>

namespace data_structures::heap
{
	template<typename Ty>
	class heap
	{
		std::unique_ptr<Ty[]> data_{};
		std::size_t size_{}, capacity_{};

		/// <summary>
		/// ensure capacity
		///
		/// This function ensures that the underlying array has enough
		/// storage for the incoming element.
		/// </summary>
		void ensure_capacity()
		{
			if( capacity_ <= size_ )
				resize( size_ << 1 );
		}

		/// <summary>
		/// shift down
		///
		/// ensures the heap invariant is maintained by the element at index by
		/// swapping it with its parent until we reach the cut-off point (specified by
		/// bound, or 0, the start of the underlying array).
		/// </summary>
		/// <complexity>
		/// O(log n) in the size of the array.
		/// </complexity>
		/// <param name="index">index of the element to bind.</param>
		/// <param name="bound">boundary to stop the ordering procedure.</param>
		void shift_down( std::size_t index, 
			const std::size_t bound = 0 )
		{
			std::size_t parent = std::floor( size_ >> 1 );

			while( bound <= index && 
				data_.get()[ index ] < data_.get()[ parent ] )
			{
				std::swap( data_[ index ], data_[ parent ] );

				index >>= 1; parent >>= 1;
			}
		}

		void shift_up( std::size_t index,
			const std::size_t bound )
		{
			using std::min;
			
			auto left = min( index + 1, size_ ),
				right = min( index + 2, size_ );

			auto next = left == right ? left :
				data_.get()[ left ] < data_.get()[ right ] ? left : right;
			
			while( index < bound &&
				data_.get()[ index ] > data_.get()[ next ] )
			{
				std::swap( data_[ index ], data_[ next ] );
				
				index = next;
				next <<= 1;
			}
		}
		
	public:
		
		explicit heap( const std::size_t capacity = 1 )
			: capacity_{ capacity }
		{
			data_ = std::make_unique<Ty[]>( capacity_ );
		}

		/// <summary>
		/// push
		///
		/// This function inserts a new element in the underlying array and
		/// maintains the heap invariant that all "child nodes" of a given
		/// element are smaller than its parent.
		/// </summary>
		void push( const Ty& value )
		{
			ensure_capacity();
			
			data_.get()[ size_ ] = value;

			shift_down( size_ );

			++size_;
		}

		/// <summary>
		/// resize
		///
		/// creates a new underlying array of the desired size, then
		/// copies the old values (excluding and accumulated "junk"
		/// values that may be present in the old array by offsetting with
		/// the "size" backing field instead of "capacity"), and then
		/// swaps the new array in for data, leaving the old one to be
		/// cleaned-up.
		/// </summary>
		/// <param name="new_size"></param>
		void resize( const std::size_t new_size )
		{
			auto new_data = std::make_unique<Ty[]>( new_size );

			std::copy( data_.get(), data_.get() + size_, new_data.get() );

			capacity_ = new_size;

			data_ = std::move( new_data );
		}

		Ty pop()
		{
			if( !size_ )
				throw std::runtime_error( "cannot pop from a empty heap." );

			const Ty value = data_.get()[ 0 ];

			if( size_ > 1 )
			{
				std::swap( data_[ 0 ], data_[ size_ - 1 ] );

				shift_up( 0, size_ );
			}
			
			--size_;
			
			return value;
		}

		[[nodiscard]] const Ty& peek() const
		{
			if( empty() )
				throw std::runtime_error( "unable to peek an empty heap." );
			
			return data_.get()[ 0 ];
		}
		
		[[nodiscard]] std::size_t size() const { return size_; }
		[[nodiscard]] bool empty() const { return !size_; }
	};

}