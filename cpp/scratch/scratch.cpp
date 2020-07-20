#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct variadic_template final : problem
{
    explicit variadic_template( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    template <bool... Digits> struct ReversedBinaryValue;

    template <>
    struct ReversedBinaryValue<> {
        static constexpr int value = 0;
    };

    template <bool first, bool... digits>
    struct ReversedBinaryValue<first, digits...> {
        static constexpr int value = first + 2 * ReversedBinaryValue<digits...>::value;
    };

    template <bool...Digits>
    static int reversed_binary_value()
    {
        return ReversedBinaryValue<Digits...>::value;
    }
	
    template <int N, bool...Digits>
    struct check_values
	{
        static void check( int x, int y )
        {
            check_values<N - 1, 0, Digits...>::check( x, y );
            check_values<N - 1, 1, Digits...>::check( x, y );
        }
    };

    template <bool...Digits>
    struct check_values<0, Digits...> {
        static void check( const int x, const int y )
        {
	        const int z = reversed_binary_value<Digits...>();
            std::cout << ( z + 64 * y == x );
        }
    };
	
    int main()
    {
        int t; std::cin >> t;

        for( auto i = 0; i != t; ++i ) 
        {
            int x, y;
            std::cin >> x >> y;
            check_values<6>::check( x, y );
            std::cout << "\n";
        }
    	
        return 0;
    }
};

auto main() -> int
{
    const auto problem =
        variadic_template{ "cpp-variadics-testcases" };

    return problem.run();
}
