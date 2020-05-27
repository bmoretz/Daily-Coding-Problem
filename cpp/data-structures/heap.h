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

		/// <summary>
		/// shift up
		///
		/// ensures that the heap invariant is maintained by swapping the
		/// element at index is lower than its child nodes. If we start at
		/// zero then we look at the left child (1), and then the right child (2)
		/// by shifting, this ensures that in the initial case we look at both
		/// the left and right child to get the min of the two. After the initial
		/// case, we skip by a power of two so that the operation maintains its
		/// logarithmic run-time.
		/// </summary>
		/// <param name="index">starting index</param>
		/// <param name="bound">boundary to stop the ordering procedure.</param>
		void shift_up( std::size_t index,
			const std::size_t bound )
		{
			auto next =
				index == 0 ? 1 : index << 1;

			while( index < bound && next < size_ &&
				data_.get()[ index ] > data_.get()[ next ] )
			{
				std::swap( data_[ index ], data_[ next ] );

				index = next; next <<= 1;
			}
		}

	public:

		explicit heap( const std::size_t capacity = 1 )
			: capacity_{ capacity }
		{
			data_ = std::make_unique<Ty[]>( capacity_ );
		}

		void push( const Ty& value );
		void resize( std::size_t new_size );

		Ty pop();

		[[nodiscard]] const Ty& peek() const
		{
			if( empty() )
				throw std::runtime_error( "unable to peek an empty heap." );

			return data_.get()[ 0 ];
		}

		[[nodiscard]] std::size_t size() const { return size_; }
		[[nodiscard]] bool empty() const { return !size_; }
	};

	/// <summary>
	/// push
	///
	/// This function inserts a new element in the underlying array and
	/// maintains the heap invariant that all "child nodes" of a given
	/// element are smaller than its parent.
	/// </summary>
	template <typename Ty>
	void heap<Ty>::push( const Ty& value )
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
	/// <param name="new_size">new backing array size.</param>	
	template <typename Ty>
	void heap<Ty>::resize(const std::size_t new_size)
	{
		auto new_data = std::make_unique<Ty[]>(new_size);

		std::copy(data_.get(), data_.get() + size_, new_data.get());

		capacity_ = new_size;

		data_ = std::move(new_data);
	}

	template <typename Ty>
	Ty heap<Ty>::pop()
	{
		if (!size_)
			throw std::runtime_error("cannot pop from a empty heap.");

		const Ty value = data_.get()[0];

		size_--;

		std::swap(data_[0], data_[size_]);
		shift_up(0, size_);

		return value;
	}
}
