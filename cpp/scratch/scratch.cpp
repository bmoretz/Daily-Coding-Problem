#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct mult_inheritance final : problem
{
    explicit mult_inheritance( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    class tri {
    public:
        void triangle() {
            std::cout << "I am a triangle\n";
        }
    };

    class iso : public tri {
    public:
        void isosceles() {
            std::cout << "I am an isosceles triangle" << std::endl;
        }
    };

	class equ : public iso
	{
	public:
		void equilateral()
		{
            std::cout << "I am an equilateral triangle" << std::endl;
		}
	};
	
    int main() {
        equ eqr;
        eqr.equilateral();
        eqr.isosceles();
        eqr.triangle();
    	
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
        mult_inheritance{"multi-level-inheritance-cpp-testcases"};

	return problem.run();
}
