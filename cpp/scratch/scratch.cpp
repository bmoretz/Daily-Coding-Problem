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
		const auto size = width_ * height_;
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
			screen_.get()[ width_ * y + ( x1 / 8 ) ] |= mask;
		}
		else
		{
			if( start_offset != 0 )
			{
				const auto byte_number = width_ * y + first_byte - 1;
				screen_.get()[ byte_number ] |= start_mask;
			}

			if( end_offset != 7 )
			{
				const auto byte_number = width_ * y + last_byte + 1;
				screen_.get()[ byte_number ] |= end_mask;
			}
		}
	}
	
	[[nodiscard]] auto get_display() const
	{
		const auto size = static_cast< unsigned int >( width_ * height_ );

		std::ostringstream stm;
		
		for( std::size_t index = 0; index < size; ++index )
		{
			if( index % width_ == 0 )
				stm << std::endl;

			stm << std::setw( 8 ) << std::setfill( '0' )
				<< std::bitset<8>( unsigned( screen_.get()[ index ] ) ).to_string();
		}

		stm << std::endl;
		
		return stm.str();
	}
};

auto main() -> int
{
	const auto screen = byte_screen( 5, 5 );

	std::cout << screen.get_display();

	screen.draw_line( 0, 40, 2 );

	std::cout << screen.get_display();
}