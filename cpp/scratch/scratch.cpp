#include <bits/stdc++.h>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct exception_handling final : problem
{
    explicit exception_handling( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

	int largest_proper_divisor( const int n )
    {
        if( n == 0 )
            throw std::invalid_argument( "largest proper divisor is not defined for n=0" );
    	
        auto largest = 0;

    	for( auto index = n - 1; index > 0; --index )
    	{
	        const auto result = n % index;

            if( result == 0 )
            {
                largest = index;
                break;
            }
    	}
    	
        return largest;
    }
	
    void process_input( const int n )
    {
        try
        {
            const auto d = largest_proper_divisor( n );
            std::cout << "result=" << d << std::endl;
        }
        catch( const std::invalid_argument& iae )
        {
            std::cout << iae.what() << std::endl;
        }

        std::cout << "returning control flow to caller" << std::endl;
    }

    int main() {
        int n;
        std::cin >> n;
        process_input( n );
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
		exception_handling{"cpp-exception-handling-testcases"};

	return problem.run();
}