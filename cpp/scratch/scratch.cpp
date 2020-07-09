#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct stl_dequeue final : problem
{
    explicit stl_dequeue( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    void print_k_max( const std::vector<int>& vector, const int n, const int k )
    {
        std::deque<int> dequeue;
    	
        for( auto index = 0; index < k; index++ )
        {
            while( !dequeue.empty() && vector[ index ] >= vector[ dequeue.back() ] )
            {
                dequeue.pop_back();
            }

            dequeue.push_back( index );
        }

        for( auto index = k; index < n; index++ )
        {
            std::cout << vector[ dequeue.front() ] << " ";

            while( !dequeue.empty() && dequeue.front() <= index - k )
            {
                dequeue.pop_front();
            }
        	
            while( !dequeue.empty() && vector[ index ] >= vector[ dequeue.back() ] )
            {
                dequeue.pop_back();
            }
        	
            dequeue.push_back( index );

        }

        std::cout << vector[ dequeue.front() ] << std::endl;
    }

    int main()
    {
        int t;
        std::cin >> t;

        while( t-- )
        {
            int n, k;
            std::cin >> n >> k;

            int tmp;
            std::vector<int> vector = { };
            vector.resize( n );
        	
            for( auto index = 0; index < n; index++ )
            {
                std::cin >> tmp;
                vector.at( index ) = tmp;
            }

            print_k_max( vector, n, k );
        }

        return 0;
    }
};

auto main() -> int
{
	const auto problem =
        stl_dequeue{"deque-stl-testcases"};

	return problem.run();
}
