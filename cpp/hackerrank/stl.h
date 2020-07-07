#pragma once

#include <sstream>
#include <set>
#include <map>

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

    struct stl_set final : problem
    {
        explicit stl_set( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = []() { return main(); };
        }

        static void process_queries()
        {
            std::set<int> values{};

            int op, n;

            while( std::cin >> op >> n )
            {
                const auto exists = values.find( n ) != values.end();

                switch( op )
                {
                case 1: values.insert( n ); break;
                case 2: if( exists ) values.erase( n ); break;
                case 3: std::cout << ( exists ? "Yes" : "No" ) << std::endl; break;

                default:
                    break;
                }
            }
        }

        static int main()
        {
            int n;
            std::cin >> n;

            process_queries();

            return 0;
        }
    };

    struct stl_map final : problem
    {
        explicit stl_map( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = [this]() { return main(); };
        }

        static void process_queries()
        {
            std::map<std::string, int> values{};

            int op;
            std::string name;

            while( std::cin >> op >> name )
            {
                const auto exists = values.find( name ) != values.end();

                switch( op )
                {
                case 1:
                {
                    int marks;
                    std::cin >> marks;

                    if( !exists )
                    {
                        values.insert( std::make_pair( name, marks ) );
                    }
                    else
                    {
                        values[ name ] += marks;
                    }
                } break;

                case 2:
                {
                    if( exists )
                    {
                        values.erase( name );
                    }
                } break;

                case 3:
                {
                    if( exists )
                    {
                        std::cout << values[ name ] << std::endl;
                    }
                    else
                    {
                        std::cout << 0 << std::endl;
                    }

                } break;

                default:
                    break;
                }
            }
        }

        int main()
        {
            int n;
            std::cin >> n;

            process_queries();

            return 0;
        }
    };
}