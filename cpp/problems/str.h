#pragma once

#include <string>
#include <map>

namespace str_problems
{
	class str
	{
	public:
		static bool is_unique1( const std::string & str );
		static bool is_unique2( const std::string & str );

		static bool is_permutation1( const std::string & p, const std::string & q );
		static bool is_permutation2( std::string p, std::string q );

		static std::string urlify1( std::string input, size_t length );
	};

	class utility
	{
	public:
		static std::map<char, int> char_map( const std::string & s );
	};
}