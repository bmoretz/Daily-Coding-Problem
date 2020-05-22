#pragma once

#pragma once

#include <algorithm>
#include <memory>
#include <ostream>
#include <vector>

namespace data_structures::heap
{
	template<typename Ty>
	class heap
	{
		std::unique_ptr<Ty[]> data_{};

		std::size_t size_{}, capacity_{};

	public:
		
		explicit heap( const std::size_t capacity = 1 )
			: capacity_{ capacity }
		{
			data_ = std::make_unique<Ty[]>( capacity_ );
		}

		void push( const Ty& value )
		{
			if( capacity_ <= size_ )
				resize( size_ << 1 );

			data_.get()[ size_ ] = value;
			
			std::size_t parent = std::floor( size_ >> 1 ),
				position = size_;
						
			while( position && data_.get()[ position ] < data_.get()[ parent ] )
			{
				auto tmp = data_.get()[ parent ];
				
				data_.get()[ parent ] = data_.get()[ position ];
				data_.get()[ position ] = tmp;

				
				position >>= 1; parent >>= 1;
			}

			++size_;
		}

		void resize( const std::size_t& new_size )
		{
			auto new_data = std::make_unique<Ty[]>( new_size );

			std::copy( data_.get(), data_.get() + new_size, new_data.get() );

			capacity_ = new_size;

			data_ = std::move( new_data );
		}

		void pop()
		{
			if( !size_ ) throw std::runtime_error( "CANNOT POP EMPTY HEAP" );
		}

		[[nodiscard]] Ty top() const { return data_.get()[ 0 ]; }
		[[nodiscard]] std::size_t size() const { return size_; }
		[[nodiscard]] bool empty() const { return size_; }
	};
}