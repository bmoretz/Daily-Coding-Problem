#include <memory>
#include <vector>
#include <iostream>
#include <utility>
#include <unordered_map>
#include <random>
#include <bitset>
#include <iomanip>
#include <string>
#include <ostream>
#include <string>
#include <sstream>

/* Draw Line.
 *
 * A monochrome screen is stored as a single array of bytes, allowing
 * eight consecutive pixels to be stored in one byte. The screen has
 * width w, where w is divisible by 8 (that is, no byte will be split
 * across rows). The height of the screen, of course, can be derived
 * from the length of the array and the width. Implement a function
 * that draws a horizontal line from (x1, y) to (x2, y).
 *
 * The method signature should look something like this:
 *
 * drawLine(byte[] screen, int width, int x1, int x2, int y)
 */

class byte_screen
{
	int width_;
	int height_;
	std::unique_ptr<std::byte[]> screen_;

public:

	byte_screen( const int width, const int height )
	{
		width_ = width; height_ = height;
		const auto size = ( width_ * height_ ) / 8;
		screen_ = std::make_unique<std::byte[]>( size );
	}

	auto draw_line( const int x1, const int x2, const int y ) const
	{
		const auto start_offset = x1 % 8;
		auto first_byte = x1 / 8;

		if( start_offset != 0 )
			++first_byte;

		const auto end_offset = x2 % 8;
		auto last_byte = x2 / 8;
		if( end_offset != 7 )
			--last_byte;

		for( auto b = first_byte; b <= last_byte; ++b )
			screen_.get()[ ( width_ / 8 ) * y + b ] = static_cast < std::byte > ( 0xFF );

		const auto start_mask = static_cast< std::byte >( 0xFF >> start_offset );
		const auto end_mask = static_cast< std::byte >( ~( 0xFF >> ( end_offset + 1 ) ) );

		if( ( x1 / 8 ) == ( x2 / 8 ) )
		{
			const auto mask = static_cast< std::byte >( start_mask & end_mask );
			screen_.get()[ ( width_ / 8 ) * y + ( x1 / 8 ) ] |= mask;
		}
		else
		{
			if( start_offset != 0 )
			{
				const auto byte_number = ( width_ / 8 ) * y + first_byte - 1;
				screen_.get()[ byte_number ] |= start_mask;
			}

			if( end_offset != 7 )
			{
				const auto byte_number = ( width_ / 8 ) * y + last_byte + 1;
				screen_.get()[ byte_number ] |= end_mask;
			}
		}
	}

	auto draw_line2( const int x1, const int x2, const int y ) const
	{
		const auto line_width = x2 - x1;

		if( line_width <= 0 ) return;

		const auto offset = width_ * y + x1;
		
		const auto num_bytes = static_cast<unsigned int>( line_width / 8 );
		unsigned int current_byte = 0;
		
		auto line_bytes = std::vector<std::byte>{};
		
		while( current_byte < num_bytes )
		{
			const auto mask = std::byte( std::pow(2, 8 ) - 1 );

			screen_.get()[ offset + current_byte ] = mask;
			++current_byte;
		}
	}
	
	[[nodiscard]] auto get_display() const
	{
		const auto size = static_cast< unsigned int >( width_ * height_ );

		std::ostringstream stm;
		stm << std::hex << std::uppercase;

		for( std::size_t index = 0; index < size; ++index )
		{
			if( index % width_ == 0 )
				stm << std::endl;

			stm << std::setw( 1 ) << std::setfill( '*' )
				<< unsigned( screen_.get()[ index ] );
		}

		stm << std::endl;
		
		return stm.str();
	}
};

auto main() -> int
{
	const auto screen = byte_screen( 24, 24 );

	std::cout << screen.get_display();

	screen.draw_line2( 2, 10, 0 );

	std::cout << screen.get_display();
}