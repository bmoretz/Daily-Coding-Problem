#pragma once

#include <sstream>
#include <stack>
#include <memory>
#include <cassert>

#include "problem.h"

namespace hackerrank::stl
{
    struct vector_sort final : problem
    {
        explicit vector_sort( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = []() { return main(); };
        }

        static void read_vector( std::vector<int>& integers )
        {
            std::string buff;
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            std::getline( std::cin, buff );
            std::stringstream ss( buff );

            int tmp;

            while( ss >> tmp )
                integers.push_back( tmp );
        }

        static void print_sorted( std::vector<int> integers )
        {
            std::sort( integers.begin(), integers.end() );

            for( auto index = 0; index < integers.size(); ++index )
            {
                std::cout << integers[ index ];

                if( index < integers.size() - 1 )
                    std::cout << " ";
            }
        }

        static int main()
        {	
            int n;
            std::cin >> n;

            std::vector<int> integers;
            integers.reserve( n );
        	
            read_vector( integers );
            print_sorted( integers );

            return 0;
        }
    };

    struct vector_erase final : problem
    {
        explicit vector_erase( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = []() { return main(); };
        }

        static void read_vector( std::vector<int>& integers )
        {
            std::string buff;
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            std::getline( std::cin, buff );
            std::stringstream ss( buff );

            int tmp;

            while( ss >> tmp )
                integers.push_back( tmp );
        }

        static void process_erases( std::vector<int>& integers )
        {
            int position;
            std::cin >> position;
            integers.erase( integers.begin() + position - 1 );

            int start, stop;
            std::cin >> start >> stop;
            integers.erase( integers.begin() + start - 1, integers.begin() + stop - 1 );
        }

        static void print( std::vector<int> integers )
        {
            std::cout << integers.size() << std::endl;

            for( auto index = 0; index < integers.size(); ++index )
            {
                std::cout << integers[ index ];

                if( index < integers.size() - 1 )
                    std::cout << " ";
            }
        }

        static int main()
        {
            int n;
            std::cin >> n;

            std::vector<int> integers;
            integers.reserve( n );
        	
            read_vector( integers );
            process_erases( integers );
            print( integers );

            return 0;
        }
    };

    struct lower_bound final : problem
    {
        explicit lower_bound( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = []() { return main(); };
        }

        static void read_vector( std::vector<int>& integers )
        {
            std::string buff;
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            std::getline( std::cin, buff );
            std::stringstream ss( buff );

            int tmp;

            while( ss >> tmp )
                integers.push_back( tmp );
        }

        static void process_queries( std::vector<int>& integers )
        {
            std::string buff;
            int num;
            std::cin >> num; // throw away

            while( std::cin >> num )
            {
                const auto exists =
                    std::binary_search( integers.begin(), integers.end(), num );

                const auto bound =
                    std::lower_bound( integers.begin(), integers.end(), num );

                std::cout << ( exists ? "Yes" : "No" ) << " "
                    << std::distance( integers.begin(), bound ) + 1
                    << std::endl;
            }
        }

        static int main()
        {
            int n;
            std::cin >> n;

            std::vector<int> integers;
            integers.reserve( n );

            read_vector( integers );
            process_queries( integers );

            return 0;
        }
    };
}