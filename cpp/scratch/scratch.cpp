#include <bits/stdc++.h>

/*677. Map Sum Pairs.

Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
 
Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

Constraints:

1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.
*/

class map_sum
{
    struct trie_node
    {
        std::unordered_map<char, std::unique_ptr<trie_node>> children;
        std::unordered_map<std::string, int> values;
    };

    std::unique_ptr<trie_node> root_;

public:

    map_sum()
    {
        root_ = std::make_unique<trie_node>();
    }

    void insert( const std::string& key, const int val ) const
    {
        auto node = root_.get();

        for( auto chr : key )
        {
            if( node->children.find( chr ) == node->children.end() )
            {
                node->children[ chr ] = std::make_unique<trie_node>();
            }

            node = node->children[ chr ].get();
            node->values[ key ] = val;
        }
    }

    int sum( const std::string& prefix ) const
    {
        auto node = root_.get();

        for( auto chr : prefix )
        {
            if( node->children.find( chr ) == node->children.end() )
            {
                return 0;
            }

            node = node->children[ chr ].get();

        }

        auto result = 0;

        for( auto& [k, v] : node->values )
        {
            result += v;
        }

        return result;
    }
};

auto main() -> int
{
    auto input = std::vector<std::vector<int>>
    {
        { 2, 9, 10 },
        { 3, 7, 15 },
        { 5, 12, 12 },
        { 15, 20, 10 },
        { 19, 24, 8 }
    };
	
    const auto actual = skyline::get_skyline( input );

    const auto expected = std::vector<std::vector<int>>
    {
        {2, 10},
        {3, 15},
        {7, 12},
        {12, 0},
        {15, 10},
        {20, 8},
    	{24, 0}
    };
	
	return 0;
}