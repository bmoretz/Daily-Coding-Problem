#include <bits/stdc++.h>

/* 151. Reverse Words in a String.

Given an input string, reverse the string word by word.
*/

struct reverse_string
{
	static void trim( std::string& str )
	{
		while( !str.empty() && std::isspace( str.front() ) )
			str.erase( 0, 1 );

		while( !str.empty() && std::isspace( str.back() ) )
			str.erase( str.size() - 1, 1 );
	}
	
	static std::string reverse_words( std::string& input )
	{
		if( input.empty() ) return input;
		
		trim( input );

		auto pos = std::size_t();
		std::string buff, result;

		while( pos < input.size() )
		{
			if( std::isspace( input.at( pos ) ) )
			{
				if( !result.empty() )
					result.insert( 0, " " );
				
				result.insert( 0, buff );
				buff.clear();
				++pos;
				
				while( std::isspace( input.at( pos ) ) )
					++pos;
			}
			
			buff.push_back( input.at( pos++ ) );
		}

		if( !buff.empty() )
		{
			if( !result.empty() )
				result.insert( 0, " " );
			
			result.insert( 0, buff);
		}
		
		return result;
	}
};

auto main() -> int
{
	std::string input1 = "       the    sky     is    blue            ";
    const auto input2 = "  hello world!  ";
	const auto input3 = "a good   example";
	const auto input4 = "                   ";
	const auto input5 = "                      blue               ";
	
	const auto result = reverse_string::reverse_words( input1 );

	std::cout << result;
	
	return 0;
}