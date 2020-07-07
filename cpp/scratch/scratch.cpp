#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct stl_map final : problem
{
    explicit stl_map( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    static void process_queries()
    {
        std::map<std::string, int> values{};

        int op;
        std::string name;
    	
        while( std::cin >> op >> name )
        {
            const auto exists = values.find( name ) != values.end();
        	
            switch( op )
            {
            case 1:
            {
                int marks;
                std::cin >> marks;

                if( !exists )
                {
                    values.insert( std::make_pair( name, marks ) );
                }
                else
                {
                    values[ name ] += marks;
                }
            } break;

            case 2:
            {
                if( exists )
                {
                    values.erase( name );
                }
            } break;
            	
            case 3:
            {
                if( exists )
                {
                    std::cout << values[ name ] << std::endl;
                }
                else
                {
                    std::cout << 0 << std::endl;
                }
            		
            } break;
            	
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
		stl_map{"cpp-maps-testcases"};

	return problem.run(0);
}
