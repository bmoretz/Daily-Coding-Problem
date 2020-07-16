#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct cpp_operator_overloading final : problem
{
	explicit cpp_operator_overloading( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}

	class Matrix
	{
	public:
        std::vector<std::vector<int>> a;

        Matrix() = default;
		
        Matrix( const int rows, const int cols )
        {
            a.resize( rows );

            for( auto row = 0; row < rows; ++row )
            {
                a[ row ].resize( cols );
            }
        }
		
		Matrix operator+( const Matrix& other )
		{
            const auto rows = a.size(), cols = a[ 0 ].size();
            Matrix result( rows, cols );
			
			for( auto row = 0; row < rows; ++row )
			{
				for( auto col = 0; col < cols; ++col )
				{
                    result.a[ row ][ col ] = a[ row ][ col ] + other.a[ row ][ col ];
				}
			}

            return result;
		}
	};
	
	int main() {
		
        int cases, k;
        std::cin >> cases;
        for( k = 0; k < cases; k++ ) {
            Matrix x;
            Matrix y;
            Matrix result;
            int n, m, i, j;
            std::cin >> n >> m;
            for( i = 0; i < n; i++ ) {
                std::vector<int> b;
                int num;
                for( j = 0; j < m; j++ ) {
                    std::cin >> num;
                    b.push_back( num );
                }
                x.a.push_back( b );
            }
            for( i = 0; i < n; i++ ) {
                std::vector<int> b;
                int num;
                for( j = 0; j < m; j++ ) {
                    std::cin >> num;
                    b.push_back( num );
                }
                y.a.push_back( b );
            }
            result = x + y;
            for( i = 0; i < n; i++ ) {
                for( j = 0; j < m; j++ ) {
                    std::cout << result.a[ i ][ j ] << " ";
                }
                std::cout << std::endl;
            }
        }
		
		return 0;
	}
};

auto main() -> int
{
	const auto problem =
		cpp_operator_overloading{"operator-overloading-testcases"};

	return problem.run();
}
