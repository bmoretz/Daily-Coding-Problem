#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct override_ostream final : problem
{
    explicit override_ostream( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    class person {
    public:
        person( std::string first_name, std::string last_name ) :
            first_name_{std::move(first_name)},
            last_name_{std::move(last_name)}
    	{}
    	
        const std::string& get_first_name() const {
            return first_name_;
        }
    	
        const std::string& get_last_name() const {
            return last_name_;
        }

        friend std::ostream& operator<<( std::ostream& os, const person& person )
        {
            os << "first_name=" << person.get_first_name() << ","
                << "last_name=" << person.get_last_name();

            return os;
        }
    	
    private:
        std::string first_name_;
        std::string last_name_;
    };
	
    int main()
	{
        std::string first_name, last_name, event;
        std::cin >> first_name >> last_name >> event;
        const auto p = person( first_name, last_name );
        std::cout << p << " " << event << std::endl;
        return 0;
    }
};

auto main() -> int
{
	const auto problem =
		override_ostream{"overloading-ostream-operator-testcases"};

	return problem.run();
}
