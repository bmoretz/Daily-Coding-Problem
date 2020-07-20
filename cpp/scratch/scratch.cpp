#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct workshop_optimization final : problem
{
    explicit workshop_optimization( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    struct workshop
    {
        int end_time;
        int start_time;
        int duration;

        bool operator<( const workshop& r ) const
        {
            return end_time < r.end_time;
        }
    };

    struct available_workshops
    {
        int n;
        workshop* a;
    };

    static available_workshops* initialize( const int* start_time, const int* duration, const int n )
    {
        const auto ptr = new available_workshops;
        ptr->n = n;
        ptr->a = new workshop[ n ];

        for( auto i = 0; i < n; i++ )
        {
            ptr->a[ i ].start_time = start_time[ i ];
            ptr->a[ i ].duration = duration[ i ];
            ptr->a[ i ].end_time = start_time[ i ] + duration[ i ];
        }

        return ptr;
    }

    int calculate_max_workshops( available_workshops* ptr ) const
    {
        std::sort( ptr->a, ptr->a + ptr->n );
        auto m = 1;
        auto end_time = ptr->a[ 0 ].end_time;

        for( auto i = 1; i < ptr->n; i++ )
        {
            if( ptr->a[ i ].start_time >= end_time )
            {
                m += 1;
                end_time = ptr->a[ i ].end_time;
            }
        }

        return m;
    }

    int main()
    {
        int n;
        std::cin >> n;
        const auto start_time = new int[ n ];
        const auto duration = new int[ n ];

        for( auto i = 0; i < n; i++ )
        {
            std::cin >> start_time[ i ];
        }

        for( auto i = 0; i < n; i++ )
        {
            std::cin >> duration[ i ];
        }

        const auto ptr = initialize( start_time, duration, n );
        std::cout << calculate_max_workshops( ptr ) << std::endl;

        return 0;
    }
};

auto main() -> int
{
    const auto problem =
        workshop_optimization{ "attending-workshops-testcases" };

    return problem.run();
}
