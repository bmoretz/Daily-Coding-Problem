#pragma once

#include <vector>

namespace problems::bitmanip
{
	/* Insertion.
	 *
	 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
	 * Write a method to insert M into N such that M starts at bit j and ends at
	 * bit i. You can assume that the bits j through i have enough space to fit all of M.
	 * That is, if M = 10011, you can assume that there are at least 5 bit between j and
	 * i. You would not, for example, have j = 3 and i = 2, because M could not fully fit
	 * between bit 3 and bit 2.
	 *
	 * EXAMPLE:
	 *
	 * Input: N = 10000000000, M = 10011, i = 2, j = 6
	 * Output: M = 10001001100
	 */

	 /// <summary>
	 /// insertion 1
	 ///
	 /// this approach finds the number of digits in n, saves the top value by
	 /// shifting n down by the length - the length of the middle (j + i). Then
	 /// we can simply combine n and m into one binary string by shifting the top
	 /// up by its length and or'ing it together with m. Finally, we extract the bottom
	 /// (bits 0 - i), by and'ing it with 2^i, and then the result is just the OR result
	 /// of these two.
	 /// </summary>
	 /// <param name="n">first (master) binary digit</param>
	 /// <param name="m">second binary digit (to be inserted)</param>
	 /// <param name="i">index of where m should start in n</param>
	 /// <param name="j">index of where m should end in m</param>
	 /// <returns>n + m inserted at positions i-j</returns>
	static auto insertion1( const int n, const int m, const int i, const int j )
	{
		// total number of bits.
		const auto length = static_cast< int >( log2( n ) );
		// length of the middle
		const auto mid = i + j - 1;
		// split out the top: n|0's
		const auto top = ( n >> mid ) << mid;

		// n|m|0's
		const auto nm = top | m << i;

		// 0's|n
		const auto bottom = n & static_cast< int >( pow( 2, i ) );

		// n|m|n
		const auto combined = nm | bottom;

		return combined;
	}

	/* Binary to String.
	 *
	 * Given a real number between 0 and 1 (e.g., 0.72) that is passed in as
	 * a double, print the binary representation. If the number cannot be
	 * represented accurately in binary with at most 32 characters, print
	 * "ERROR".
	 */

	 /// <summary>
	 /// decimal to binary (string)
	 ///
	 /// this approach just converts the decimal (float) number to its base 10
	 /// (decimal) representation by dividing it by .1f and checking if the delta
	 /// is < epsilon (error threshold). Once we have a decimal number, the number
	 /// of binary digits = log2( N ), so we start there and for each power of 2
	 /// that is less than the number, we put a 1 in that digits place, and then
	 /// subtract that amount from the base 10. Continue until we have no digits
	 /// left to examine.
	 /// </summary>
	 /// <param name="dec">floating point number</param>
	 /// <returns>binary string representation.</returns>
	static auto dec_to_bin( const std::float_t dec )
	{
		// must be in range (0,1)
		if( dec >= 1 || dec <= 0 )
			return std::string( "ERROR" );

		// convert to base 10
		auto n = dec, rem = dec;
		const auto epsilon = 0.1e-30;

		while( rem > epsilon )
		{
			n /= 0.1f;
			rem = n - static_cast< int >( n );  // NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions)
		}

		auto n_digits = std::ceil( log2( n ) );

		// must be 0 <= length <= 32 digits.
		if( n_digits < 0 || n_digits > 32 )
			return std::string( "ERROR" );

		auto result = std::string( "." );

		while( n_digits )
		{
			const auto cur = static_cast< int >( pow( 2, n_digits ) );

			if( n >= cur )
			{
				result += "1";
				n -= cur;
			}
			else
			{
				result += "0";
			}

			--n_digits;
		}

		return result;
	}

	/* Flip Bit to Win.
	 *
	 * You have an integer and you can flip exactly one bit from a
	 * 0 to 1. Write code to find the lengths of the longest sequence
	 * of 1's you could create.
	 *
	 * EXAMPLE:
	 *
	 * Input: 1755 (or: 11011101111)
	 * Output: 8
	 */

	 /// <summary>
	 /// flip bit to win
	 ///
	 /// This approach first calculates how many digits we are working with,
	 /// (n), and then we negate the binary of the passed in number (we shift the
	 /// negation to ensure the loop captures the last 1 if the bit is set). Then we
	 /// iterate over the digits (0->n) until we find a 1 in the negation,
	 /// this will give us the length of all the distinct groups in the passed
	 /// in number. Once we have this, we can calculate the distinct adjacent
	 /// sums (std::transform). The result will be the max adjacent sum + 1 (for
	 /// the flipped bit to join them).
	 /// </summary>
	 /// <complexity>
	 /// O(n) where n = # of digits in the number.
	 /// </complexity>
	 /// <param name="num">binary digits to work with</param>
	 /// <returns>max adjacent sum by flipping a bit (0 -> 1)</returns>
	static auto flip_to_win( const int num )
	{
		const auto n = static_cast< int >( ceil( log2( num ) ) );
		const auto neg = ~num << 1;

		auto counter = 0;
		auto parts = std::vector<int>();

		for( auto index = 0; index < n; ++index )
		{
			const auto mask = 1 << ( n - index );

			if( ( neg & mask ) == mask )
			{
				parts.push_back( counter );
				counter = 0;
			}
			else
			{
				++counter;
			}
		}

		parts.push_back( counter );

		auto results = std::vector<int>( parts.size() / 2 + 1 );

		std::transform(
			parts.begin(), parts.end() - 1,
			parts.begin() + 1,
			std::back_inserter( results ),
			std::plus<>() );

		const auto max_sum = *std::max_element( results.begin(), results.end() );

		return  max_sum + 1;
	}


	/* Next Number.
	 *
	 * Given a positive integer, print the next smallest and the next
	 * largest number that have the same number of 1 bits in their
	 * binary representation.
	 */

	class next_number
	{
		static bool get_bit( const int num, const int pos )
		{
			const auto mask = 1 << pos;

			return ( num & mask ) >> pos;
		}

		/// <summary>
		/// returns the number of binary digits in the passed in number.
		/// </summary>
		/// <param name="num">number</param>
		/// <returns>number of binary digits</returns>
		static int length( const int num )
		{
			return static_cast< int >( std::floor( log2( num ) ) );
		}

		/// <summary>
		/// returns the first occurence of a one in the binary
		/// representation of the passed in number starting at the
		/// 'start' offset.
		/// </summary>
		/// <param name="num">number to evaluate</param>
		/// <param name="start">starting offset</param>
		/// <returns>position of next 1</returns>
		static int next_one( const int num, const int start )
		{
			auto position = start;

			while( get_bit( num, position ) != 1 )
				--position;

			return position;
		}

		/// <summary>
		/// returns the previous 1 in the binary representation
		/// of the passed in number starting at the specified
		/// starting index.
		/// </summary>
		/// <param name="num">num to evaluate</param>
		/// <param name="start">starting offset</param>
		/// <returns>position of 1 digit</returns>
		static int prev_one( const int num, const int start )
		{
			auto min_one = start;

			for( auto index = start; index < length( num ); ++index )
			{
				const auto mask = 1 << index;

				if( ( num & 1 << index ) == mask )
					break;

				++min_one;
			}

			return min_one;
		}

		/// <summary>
		/// counts the number of 1s starting at a given index
		/// </summary>
		/// <param name="num">number</param>
		/// <param name="start">starting offset</param>
		/// <returns>number of 1's in the binary</returns>
		static int count_ones( const int num, const int start )
		{
			auto num_ones = 0;

			for( auto index = start; index > -1; index-- )
			{
				const auto mask = 1 << index;

				if( ( num & mask ) == mask )
					num_ones++;
			}

			return num_ones;
		}

		/// <summary>
		/// next larger
		///
		/// this approach first counts the total number of 1's in the binary
		/// representation (starting 1 below the MSB). If the digit directly below
		/// the MSB is a 0 and we have 1's below that digit, then we know we can
		/// have a larger number by simply setting bit N-1 to 1, and then setting
		/// the next 1 after that to a zero. Otherwise, we must increment the MSB
		/// to n+1, and then we can simply clear the rest of the bits, and starting
		/// at index 0 flip 0's to 1's in order to get the smallest possible number
		/// with n-1 bit set and n-1 remaining 1's to set.
		/// </summary>
		/// <param name="num"></param>
		/// <param name="n"></param>
		/// <returns></returns>
		static auto larger( const int num, const int n )
		{
			const auto num_ones = count_ones( num, n - 1 );

			auto next_larger = 0;

			if( get_bit( num, n - 1 ) == 0 && num_ones > 0 )
			{
				const auto exchange_bit = next_one( num, n - 1 );

				next_larger = num ^ 1 << exchange_bit;
				next_larger |= 1 << ( exchange_bit + 1 );
			}
			else
			{
				next_larger = 1 << ( n + 1 );

				for( auto index = 0; index < num_ones; ++index )
					next_larger |= 1 << index;
			}

			return next_larger;
		}

		/// <summary>
		/// next smaller
		///
		/// similar logic to the next larger routine. we first count the
		/// number of one's starting at n-1. If there are no zeros remaining
		/// in the binary representation then we know we have the smallest possible
		/// number with n 1's in it's binary representation. Otherwise, we check
		/// the MSB-1 for a 1, which would mean that if we have a zero below that
		/// we can set that bit to zero and flip the next 1 to a zero. Finally,
		/// if we can clear the MSB and find a zero below it to swap with that
		/// handles all the cases.
		/// </summary>
		/// <param name="num"></param>
		/// <param name="n"></param>
		/// <returns></returns>
		static auto smaller( const int num, const int n )
		{
			const auto num_ones = count_ones( num, n - 1 );
			const auto num_zeros = n - num_ones;

			// no zeros to switch, this is the smallest
			// number with n 1's.
			if( num_zeros == 0 )
				return num;

			const auto next_zero = next_one( ~num, n - 1 );

			auto next_smallest = 0;

			if( get_bit( num, n - 1 ) == 1 && num_zeros > 0 )
			{
				const auto exchange_bit = next_one( ~num, n - 2 );

				next_smallest = num ^ 1 << ( n - 1 );
				next_smallest |= 1 << exchange_bit;
			}
			else
			{
				next_smallest = num ^ ( 1 << n );
				next_smallest |= 1 << next_zero;
			}

			return next_smallest;
		}

	public:

		static auto get_next( const int num )
		{
			const auto n = length( num );

			return std::make_tuple( smaller( num, n ), larger( num, n ) );
		}
	};

	/* Conversion.
	 *
	 * Write a function to determine the number of bits you would
	 * need to flip to convert integer A to integer B.
	 *
	 * EXAMPLE:
	 *
	 * Input: 29 (or: 11101), 15 (or: 01111)
	 * Output: 2
	 */

	/// <summary>
	/// conversion 1
	///
	/// this approach just and's A & B to get the digits that are
	/// both 1's (the digits that don't need to be changed), then
	/// negates that result so that the digits that need to be
	/// changed are 1's. Then we can simply sum the number of 1's
	/// to get our result.
	/// </summary>
	/// <param name="a">A</param>
	/// <param name="b">B</param>
	/// <returns>number of digits that need to be flipped to 1 so that
	/// they equal.</returns>
	static auto conversion1( const int a, const int b )
	{
		const auto need_changed = ~( a & b );
		const auto digits = std::ceil( log2( std::max( a, b ) ) );

		auto ctr = 0;

		for( auto index = 0; index < digits; ++index )
		{
			const auto mask = 1 << index;

			if( ( need_changed & ( 1 << index ) ) == mask )
				++ctr;
		}

		return ctr;
	}

	/* Pairwise Swap.
	 *
	 * Write a program to swap odd and even bits in an integer with as
	 * few instructions as possible (e.g., bit 0 and bit 1 are swapped,
	 * bit 22 and bit 3 are swapped, and so on).
	 */

	static auto pairwise_swap( const int num )
	{
		// masks to get the odd/even numbers in the digit, i.e,

		// BIN: 01010101010101010101010101010101
		static const auto even_mask = 0xaaaaaaaa;
		// BIN: 10101010101010101010101010101010
		static const auto odd_mask = 0x55555555;

		return ( ( num & even_mask ) >> 1 ) | ( ( num & odd_mask ) << 1 );
	}

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
}