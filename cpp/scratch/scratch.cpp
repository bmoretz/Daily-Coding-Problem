#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct lower_bound final : problem
{
    explicit lower_bound( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    static void read_vector( std::vector<int>& integers )
    {
        std::string buff;
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        std::getline( std::cin, buff );
        std::stringstream ss( buff );

        int tmp;

        while( ss >> tmp )
            integers.push_back( tmp );
    }

    static void process_queries( std::vector<int>& integers )
    {
        std::string buff;
        int num;
        std::cin >> num; // throw away
    	
    	while( std::cin >> num )
    	{
            const auto exists = 
                std::binary_search( integers.begin(), integers.end(), num );
    		
            const auto bound = 
                std::lower_bound( integers.begin(), integers.end(), num );

            std::cout << ( exists ? "Yes" : "No" ) << " "
    				  << std::distance( integers.begin(), bound ) + 1
    				  << std::endl;
    	}
    }

    int main()
    {
        int n;
        std::cin >> n;

    	std::vector<int> integers;
        integers.reserve( n );
    	
        read_vector( integers );
        process_queries( integers );
    	
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
		lower_bound{"cpp-lower-bound-testcases"};

	return problem.run(0);
}
