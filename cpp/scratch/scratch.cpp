#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <string>
#include <tuple>
#include <set>
#include <iterator>
#include <numeric>
#include <ostream>

/* Build Order.
 *
 * You are given a list of projects and a list of dependencies (which is a
 * list of pairs of projects, where the second project is dependent on the first
 * 
 * project). All of a project's dependencies must be built before the project is.
 * Find a build order that will allow the projects to be built. If there is no
 * valid build order, return an error.
 *
 * EXAMPLE:
 *
 * Input:
 * projects: a, b, c, d, e, f
 * dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
 * Output: f, e, a, b, d, c
 */

class build_order
{
    using node_list = std::vector<char>;
    using build_list = std::unordered_map<char, std::unique_ptr<node_list>>;

    inline static const std::string cycle_err = 
        "CYCLICAL PROJECT REFERENCE DETECTED. CANNOT CONTINUE BUILD.";

	std::unique_ptr<build_list> projects_;

    static std::vector<char> dfs( const build_list& projects,
        const char node, std::set<char>& seen )
    {
        auto path = std::vector<char>();
        auto stack = std::stack<char>( { node } );

        auto loop_detect = std::set<char>();

        while( !stack.empty() )
        {
            const auto v = stack.top();
            stack.pop();

            loop_detect.insert( v );

            for( const auto u : *projects.at( v ) )
            {
                if( loop_detect.find( u ) != loop_detect.end() )
                    throw std::runtime_error( cycle_err );

                if( seen.find( u ) == seen.end() )
                    stack.push( u );
            }

            path.insert( path.begin(), v );
            seen.insert( v );
        }

        return path;
    }

public:

    build_order()
    {
        projects_ = std::make_unique<build_list>();
    }

    build_order( const std::initializer_list<char>& projects,
        const std::initializer_list<std::pair<char, char>>& dependencies )
        : build_order()
    {
        for( const auto& project : projects )
            add_project( project );

        for( const auto& dependency : dependencies )
            add_dependency( dependency.first, dependency.second );
    }

    void add_project( const char project ) const
    {
        projects_->insert( std::make_pair( project, std::make_unique<node_list>() ) );
    }

    void add_dependency( const char project, const char dependency ) const
    {
        projects_->at( project )->push_back( dependency );
    }

    bool topological_sort( std::vector<std::pair<int, char>>& order, std::string& value ) const
    {
        std::set<char> seen;
        auto label = projects_->size();

        for( [[maybe_unused]] const auto& [key, v_not_used] : *projects_ )
        {
            if( seen.find( key ) != seen.end() )
                continue;

            try
            {
                auto path = dfs( *projects_, key, seen );

                for( const auto& node : path )
                    order.emplace_back( --label, node );
            }
            catch( std::runtime_error& e )
            {
                value = e.what();
                return true;
            }
        }

        std::sort( order.begin(), order.end(),
            []( auto& left, auto& right ) {
                return left.first < right.first;
            } );

        return false;
    }

    [[nodiscard]] std::string get_build_order() const
    {
        std::vector<std::pair<int, char>> order;
        std::string value;

        if( topological_sort( order, value ) ) return value;

        auto result = std::accumulate( order.begin(), order.end() - 1, std::string{},
            []( std::string r, auto& project )
        {
	        return std::move( r ) + std::string( 1, project.second ) + " ,";
        } );

        if( order.begin() != order.end() )
            result += order.back().second;

        return result;
    }
};

auto main() -> int
{
    auto builder = build_order( 
        { 'A', 'B', 'C', 'D', 'E', 'F' }, // projects
		{
			{'A', 'D'},
        	{'F', 'B'},
			{ 'B', 'D' },
            { 'F', 'A' },
            { 'D', 'C' },
			{ 'B', 'A' }
		} );

    const auto order = builder.get_build_order();

    std::cout << order;
}