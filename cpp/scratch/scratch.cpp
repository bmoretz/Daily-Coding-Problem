#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct stl_set final : problem
{
    explicit stl_set( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    static void process_queries()
    {
        std::set<int> values{};

        int op, n;

        while( std::cin >> op >> n )
        {
            const auto exists = values.find( n ) != values.end();
        	
            switch( op )
            {
            case 1: values.insert( n ); break;
            case 2: if( exists ) values.erase( n ); break;
            case 3: std::cout << ( exists ? "Yes" : "No" ) << std::endl; break;

            default:
                break;
            }
        }
    }

    int main()
    {
        int n;
        std::cin >> n;

        process_queries();
    	
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
		stl_set{"cpp-sets-testcases"};

	return problem.run(0);
}
