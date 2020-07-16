#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct cpp_preprocessor final : problem
{
	explicit cpp_preprocessor( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}
	
	#define toStr(x) #x
	#define io(s) std::cin >> s
	#define foreach(list, index) for(int index = 0; index < list.size(); index++)
	#define FUNCTION(name, op) void name(int &x, int y){ if(!(x op y)) x = y; }
	#define INF 1e9

	#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
	#error Missing preprocessor definitions
	#endif

	FUNCTION( minimum, < )
		FUNCTION( maximum, > )

	int main() {
		int n; std::cin >> n;
		std::vector<int> v( n );
		foreach( v, i ) {
			io( v )[ i ];
		}
		int mn = INF;
		int mx = -INF;
		foreach( v, i ) {
			minimum( mn, v[ i ] );
			maximum( mx, v[ i ] );
		}
		int ans = mx - mn;
		std::cout << toStr( Result = ) << ' ' << ans;
		return 0;
	}
};

auto main() -> int
{
	const auto problem =
		cpp_preprocessor{"preprocessor-solution-testcases"};

	return problem.run();
}
