#include <bits/stdc++.h>

#include "../leetcode/tree.h"
using namespace leetcode::tree;

/*100. Same Tree.

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

class gen_parens_iter
{
    static bool is_valid( const std::string& input )
    {
        auto balance = 0;

        for( auto chr : input )
        {
            if( chr == '(' )
            {
                ++balance;
            }
            else
            {
                if( balance == 0 )
                    return false;

                --balance;
            }
        }

        return balance == 0;
    }

public:

    static std::vector<std::string> generate_parenthesis( const int n )
    {
        const auto len = 2 * n;

        auto candidates = std::vector<std::string>();

        candidates.emplace_back(len, ' ');
        candidates.emplace_back(len, ' ');

        auto seen = std::set<std::string>();

        for( auto index = 0; index < len; ++index )
        {
            auto temp = std::vector<std::string>();

            for( auto str : candidates )
            {
                str[ index ] = '(';

                if( index < len - 1 )
                {
                    temp.emplace_back( str.begin(), str.end() );
                }
                else
                {
                    if( is_valid( str ) && seen.find( str ) == seen.end() )
                    {
                        seen.insert( str );
                    }
                }

                str[ index ] = ')';

                if( index < len - 1 )
                {
                    temp.emplace_back( str.begin(), str.end() );
                }
                else
                {
                    if( is_valid( str ) && seen.find( str ) == seen.end() )
                    {
                        seen.insert( str );
                    }
                }
            }

            candidates = temp;
        }

        return std::vector<std::string>( seen.begin(), seen.end() );
    }
};

auto main() -> int
{
    auto l_tree = build_tree_in_order( std::vector<std::string>{ "1", "2" } );
    auto r_tree = build_tree_in_order( std::vector<std::string>{ "1", "", "2" } );

    const auto actual = equal_trees_iter::is_same_tree( l_tree.get(), r_tree.get() );

    const auto expected = false;
	
	return 0;
}