#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;


struct inheritance final : problem
{
    explicit inheritance( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }
	
    class Triangle {
    public:
        void triangle() {
            std::cout << "I am a triangle\n";
        }

        virtual void description() = 0;
    };

    class Isosceles : public Triangle {
    public:
        void isosceles() {
            std::cout << "I am an isosceles triangle\n";
        }

    	void description() override
        {
            std::cout << "In an isosceles triangle two sides are equal" << std::endl;
        }
    };

    int main() {
        Isosceles isc;
        isc.isosceles();
        isc.description();
        isc.triangle();
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
        inheritance{"inheritance-introduction-testcases"};

	return problem.run();
}
