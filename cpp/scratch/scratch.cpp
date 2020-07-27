#include <bits/stdc++.h>

/* 652 - Find Duplicate Subtrees.
 
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to
return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

		1
	   / \
	  2   3
	 /   / \
	4   2   4
	   /
	  4
The following are two duplicate subtrees:

	  2
	 /
	4
and

	4
Therefore, you need to return above trees' root in the form of a list.

*/

struct find_dup_subtrees
{
	struct tree_node
	{
		int val;
		std::unique_ptr<tree_node> left, right;

		explicit  tree_node( const int x ) :
			val( x ), left( nullptr ), right( nullptr ) {}

		tree_node( const tree_node& other ) = delete;
		
		tree_node( tree_node&& other ) noexcept
			: val{ other.val }
		{
			left.swap( other.left );
			right.swap( other.right );
		}
		
		~tree_node() = default;

		bool operator==( const int value ) const
		{
			return val == value;
		}
	};

	int t{};
	std::map<std::string, int> trees;
	std::map<int, int> count;
	std::vector<tree_node*> result;

	std::vector<tree_node*> find_duplicate_subtrees( tree_node* root )
	{
		preorder( root );

		return result;
	}
	
	std::string preorder( tree_node* node )
	{
		if( node == nullptr ) return "#";

		std::ostringstream key;
		key << std::to_string( node->val ) << "," << preorder( node->left.get() ) << "," << preorder( node->right.get() );

		if( trees.find( key.str() ) != trees.end() && trees.at( key.str() ) == 1 )
		{
			result.push_back( node );
		}
		
		trees[ key.str() ]++;
		
		return key.str();
	}

	static std::unique_ptr<tree_node> build_tree( const std::vector<int>& values )
	{
		if( values.size() == std::size_t() ) return nullptr;
		
		std::queue<tree_node*> nodes;

		auto index = 0ULL;
		auto root = std::make_unique<tree_node>( values[ index++ ] );
		nodes.push( root.get() );
		
		while( index < values.size() )
		{
			auto node = nodes.front();

			while( node->val == NULL )
			{
				nodes.pop();
				node = nodes.front();
			}
			
			node->left = index < values.size() ?
				std::make_unique<tree_node>( values[ index++ ] ) : nullptr;

			if( node->left != nullptr )
				nodes.push( node->left.get() );
			
			node->right = index < values.size() ?
				std::make_unique<tree_node>( values[ index++ ] ) : nullptr;

			if( node->right != nullptr )
				nodes.push( node->right.get() );

			nodes.pop();
		}

		return std::move( root );
	}
};

auto main() -> int
{
	find_dup_subtrees sln;

	const auto input1 = std::vector<int>{ 1, 2, 3, 4, NULL, 4, NULL, NULL, 4 };
	const auto input2 = std::vector<int>{ 1, 2, 3, 4, NULL, 2, 4, NULL, NULL, 4 };
	const auto input3 = std::vector<int>{ 2, 1, 1 };
	const auto input4 = std::vector<int>{ 1, 2, 3, NULL, NULL, 2, 3 };
	
	const auto tree = find_dup_subtrees::build_tree( input1 );
	
	const auto result = sln.find_duplicate_subtrees( tree.get() );

	std::cout << "Result: ";
	
	for( auto dup : result )
		std::cout << dup->val << " ";
	
	std::cout << std::endl;

	return 0;
}
