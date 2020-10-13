#include <bits/stdc++.h>

#include "../leetcode/tree.h"
using namespace leetcode::tree;

/* 297. Serialize and Deserialize Binary Tree.

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
stored in a file or memory buffer, or transmitted across a network connection link to be
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be
serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need
to follow this format, so please be creative and come up with different approaches yourself.

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000
*/

class serialize_tree
{
    static inline std::string delimiter = ",";
    static inline std::string null_node = "#";

public:

    // Encodes a tree to a single string.
    static std::string serialize( tree_node* root )
    {
        std::string result;

        if( root == nullptr ) return result;

        // enqueue the root node
        auto queue = std::queue<tree_node*>();
        queue.push( root );

        while( !queue.empty() )
        {
            // process the front of the queue
            const auto node = queue.front();

            // if the node is null, insert a null delimiter
            if( node == nullptr )
            {
                result += null_node + delimiter;
            }
            else
            {
                // otherwise push both left/right nodes (even if null)
                // we will pick them up later in the above null processing
                // logic
                queue.push( node->left.get() );
                queue.push( node->right.get() );

                // update result set
                result += std::to_string( node->val ) + delimiter;
            }

            queue.pop();
        }

        // remove the empty nodes & trailing delim from the end, ex, "#,#,#,#,"
        if( !result.empty() )
            result.erase( result.find_last_not_of( null_node + delimiter ) + 1 );

        std::cout << result << std::endl;

        return result;
    }

    // Decodes your encoded data to tree.
    static tree_node* deserialize( const std::string& data )
    {
        if( data.empty() )
            return nullptr;

        auto queue = std::queue<std::string>();

        // process the values as strings
        // so we lose the null delimiters
        std::string token;
        std::stringstream ss( data );

        while( getline( ss, token, ',' ) )
        {
            std::cout << token;

            queue.push( token );
        }

        // new root
        auto nodes = std::queue<tree_node*>();

        // this can't be null_node
        const auto root = std::make_unique<tree_node>( std::stoi( queue.front() ) );
        nodes.push( root.get() );

        queue.pop();

        // we basically use two queues
        // synchronized to put the correct
        // values from the data into
        // the tree at the same position
        // as it was entered in the serialization process
        while( !queue.empty() )
        {
            const auto node = nodes.front();

            const auto left = queue.front();
            queue.pop();

            if( left != null_node )
            {
                node->left = std::make_unique<tree_node>( stoi( left ) );
                nodes.push( node->left.get() );
            }

            if( !queue.empty() )
            {
                auto right = queue.front();
                queue.pop();

                if( right != null_node )
                {
                    node->right = std::make_unique<tree_node>( stoi( right ) );
                    nodes.push( node->right.get() );
                }
            }

            nodes.pop();
        }

        return root.get();
    }
};

auto main() -> int
{
    const auto root = build_tree_in_order( { "1", "2", "3", "", "", "4", "5" } );
	
    const auto actual = serialize_tree::serialize( root.get() );

	
    const auto expected = 6;
	
	return 0;
}