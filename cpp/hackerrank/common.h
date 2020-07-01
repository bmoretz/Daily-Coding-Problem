#pragma once

#include <cassert>
#include <functional>
#include <string>
#include <sstream>
#include <iostream>

namespace hackerrank
{
	struct conversion
	{
		std::function<int( std::string )> to_int =
			[]( const std::string& str ) { return std::stoi( str ); };
	};

	struct parsing
	{
		template<typename T, std::size_t N>
		std::unique_ptr<T[]> read_array()
		{
			auto result = std::make_unique<T[]>( N );
			auto index = size_t();

			std::string buff;
			std::getline( std::cin, buff );
			std::stringstream ss( buff );

			T tmp;
			while( ss >> tmp )
			{
				result.get()[ index++ ] = tmp;
			}

			assert( index == N );

			return result;
		}
	};

	struct string_manipulation
	{
		std::vector<std::string> split( const std::string& string,
			const char delimiter = ' ' ) const
		{
			std::vector<std::string> result;
			std::stringstream ss( string );
			std::string item;

			while( std::getline( ss, item, delimiter ) ) {
				result.push_back( item );
			}

			return result;
		}
		
		static bool starts_with( const std::string& str, const std::string& pattern )
		{
			return str.rfind( pattern, 0 ) == 0;
		}

		static std::string extract_chunk( std::string& str, const char delimiter = ' ' )
		{
			const auto len = str.size();
			const auto position = str.find( delimiter, 0 );

			const auto end = position == std::string::npos ? len : position;
			const auto next = position == std::string::npos ? len : position + 1;

			auto chunk = str.substr( 0, end );
			str.erase( str.begin(), str.begin() + next );

			return chunk;
		}

		static void strip_characters( std::string& str, const std::vector<char>& chars )
		{
			str.erase( std::remove_if( str.begin(), str.end(),
				[chars]( const char c )
				{
					return std::find( chars.begin(), chars.end(), c ) != chars.end();
				} ), str.end() );
		}
	};
}
