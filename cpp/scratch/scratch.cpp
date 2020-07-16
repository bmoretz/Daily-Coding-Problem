#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct cpp_template final : problem
{
	explicit cpp_template( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}

	template<class T>
	class add_elements
	{
		T value_;

	public:
		explicit add_elements( T val )
		{
			value_ = val;
		}

		T add( T other )
		{
			return value_ + other;
		}
	};

	template<>
	class add_elements<int>
	{
		int value_;

	public:
		explicit add_elements( int val ) { value_ = val; }

		int add( const int other )
		{
			return value_ + other;
		}
	};

	template<>
	class add_elements<std::string>
	{
		std::string value_;

	public:

		explicit add_elements( const std::string& val )
		{
			value_ = val;
		}

		std::string concatenate( const std::string& other )
		{
			return value_.append( other );
		}
	};
	
	int main()
	{
		int n, i;
		std::cin >> n;
		
		for( i = 0; i < n; i++ ) {
			std::string type;
			std::cin >> type;
			
			if( type == "float" ) {
				double element1, element2;
				std::cin >> element1 >> element2;

				add_elements<double> myfloat( element1 );
				std::cout << myfloat.add( element2 ) << std::endl;
			}
			else if( type == "int" ) {
				int element1, element2;
				std::cin >> element1 >> element2;
				add_elements<int> myint( element1 );
				std::cout << myint.add( element2 ) << std::endl;
			}
			else if( type == "string" ) {
				std::string element1, element2;
				std::cin >> element1 >> element2;
				add_elements<std::string> mystring( element1 );
				std::cout << mystring.concatenate( element2 ) << std::endl;
			}
		}
		
		return 0;
	}
};

auto main() -> int
{
	const auto problem =
		cpp_template{"c-class-templates-testcases"};

	return problem.run();
}
