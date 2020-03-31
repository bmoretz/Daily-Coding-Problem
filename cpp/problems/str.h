#pragma once

#include <string>
#include <map>

namespace str_problems
{
	class unique1
	{
	public:
		static bool is_unique( const std::string & str );
	};

	class unique2
	{
	public:
		static bool is_unique( const std::string & str );
	};

	class is_permutation1
	{
	public:
		static bool is_permutation( const std::string & p, const std::string & q );
		static std::map<char, int> char_map(const std::string& s);
	};

	class is_permutation2
	{
	public:
		static bool is_permutation( std::string p, std::string q );
	};

	class urlify1
	{
	public:
		static std::string urlify( std::string input, size_t length );
	};

	class urlify2
	{
	public:
		static size_t count_spaces(const std::string& input, size_t length);
		static std::string urlify(std::string input, size_t length);
	};

	class palperm1
	{
	public:
		static std::map<char, int> char_map( const std::string & input );
		static bool is_palindrome_permutation( const std::string & input );
	};
}