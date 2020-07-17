#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct overload_operators final : problem
{
	explicit overload_operators( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}

    class Complex
    {
    public:
        int a, b;

        Complex() = default;
		
        Complex( const int r, const int i )
        {
            a = r; b = i;
        }
			
        void input( std::string s )
        {
	        int v1 = 0;
	        int i = 0;
        	
            while( s[ i ] != '+' )
            {
                v1 = v1 * 10 + s[ i ] - '0';
                i++;
            }
        	
            while( s[ i ] == ' ' || s[ i ] == '+' || s[ i ] == 'i' )
            {
                i++;
            }

	        int v2 = 0;
            while( i < s.length() )
            {
                v2 = v2 * 10 + s[ i ] - '0';
                i++;
            }
            a = v1;
            b = v2;
        }

        Complex operator+( const Complex& other ) const
        {
            return Complex( a + other.a, (b + other.b) );
        }

        friend std::ostream& operator<<( std::ostream& os, const Complex& obj )
        {
            os << obj.a << "+i" << obj.b;

            return os;
        }
    };
	
    int main() {

        Complex x, y;
        std::string s1, s2;
        std::cin >> s1;
        std::cin >> s2;
        x.input( s1 );
        y.input( s2 );
        Complex z = x + y;
        std::cout << z << std::endl;

        return 0;
    }
};

auto main() -> int
{
    const auto problem =
        overload_operators{ "overload-operators-testcases" };

    return problem.run();
}
