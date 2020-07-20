#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct template_specialization final : problem
{
    explicit template_specialization( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    enum class fruit { apple, orange, pear };
    enum class color { red, green, orange };

    template <typename T> struct Traits;
	
    template <>
    struct Traits<fruit> {
        static std::string name( int index ) {
            switch( index ) {
            case 0:return "apple";
            case 1: return "orange";
            case 2: return "pear";
            }
            return "unknown";
        }
    };
	
    template <>
    struct Traits<color> {
        static std::string name( int index ) {
            switch( index ) {
            case 0:return "red";
            case 1: return "green";
            case 2: return "orange";
            }
            return "unknown";
        }
    };
	
    int main()
    {
        auto t = 0; std::cin >> t;

        for( auto i = 0; i != t; ++i ) 
        {
            int index1; std::cin >> index1;
            int index2; std::cin >> index2;
            std::cout << Traits<color>::name( index1 ) << " ";
            std::cout << Traits<fruit>::name( index2 ) << "\n";
        }
    	
        return 0;
    }
};

auto main() -> int
{
    const auto problem =
        template_specialization{ "cpp-class-template-specialization-testcases" };

    return problem.run();
}
