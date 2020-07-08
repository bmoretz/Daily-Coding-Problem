#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct pretty_print final : problem
{
    explicit pretty_print( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    int main()
    {
        int n;
        std::cin >> n;

    	while( n-- )
    	{
            double A, B, C;
            std::cin >> A >> B >> C;

    		std::ostringstream oss;
    		
            oss << std::nouppercase
                << std::showbase
                << std::right
                << std::hex
                << static_cast< long long > ( A )
    			<< std::endl;
    		
            oss << std::showpos
                << std::setw( 15 )
                << std::setfill( '_' )
                << std::right
    			<< std::fixed
                << std::setprecision( 2 )
    			<< B
    			<< std::endl;

            oss << std::setiosflags( std::ios::uppercase )
    			<< std::noshowpos
    			<< std::setprecision( 9 )
    			<< std::setw( 9 )
    			<< std::scientific
    			<< C
    			<< std::endl;
    		
            std::cout << oss.str();
    	}
    	
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
		pretty_print{"prettyprint-testcases"};

	return problem.run(6);
}
