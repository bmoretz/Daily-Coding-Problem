#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>

namespace leetcode::tree
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

		tree_node& operator=( const tree_node& other ) noexcept
		{
			if( this == &other )
				return *this;

			val = other.val;
			left.reset( other.left.get() );
			right.reset( other.right.get() );

			return *this;
		}

		tree_node& operator=( tree_node&& other ) noexcept
		{
			if( this == &other )
				return *this;

			val = other.val;
			left = std::move( other.left );
			right = std::move( other.right );

			return *this;
		}

		~tree_node() = default;
	};

	static std::unique_ptr<tree_node> build_tree_in_order( const std::vector<std::string>& values )
	{
		if( values.size() == std::size_t() ) return nullptr;

		std::queue<tree_node*> nodes;

		auto index = std::size_t();

		const auto root_value = std::stoi( values[ index++ ] );
		auto root = std::make_unique<tree_node>( root_value );
		nodes.push( root.get() );

		while( index < values.size() )
		{
			auto node = nodes.front();

			if( index < values.size() && !values[ index ].empty() )
			{
				node->left = std::make_unique<tree_node>( std::stoi( values[ index ] ) );
				nodes.push( node->left.get() );
			}

			index++;

			if( index < values.size() && !values[ index ].empty() )
			{
				node->right = std::make_unique<tree_node>( std::stoi( values[ index ] ) );
				nodes.push( node->right.get() );
			}

			index++;

			nodes.pop();
		}

		return std::move( root );
	}

	static std::vector<std::string> flatten_tree( const tree_node* root )
	{
		std::vector<std::string> result;

		auto queue = std::queue<const tree_node*>();

		queue.push( root );

		while( !queue.empty() )
		{
			const auto top = queue.front();

			if( top )
				result.push_back( std::to_string( queue.front()->val ) );
			else
				result.emplace_back( "" );

			if( top && ( top->left || top->right ) )
			{
				queue.push( top->left ? top->left.get() : nullptr );
				queue.push( top->right ? top->right.get() : nullptr );
			}
			
			queue.pop();
		}

		return result;
	}
	
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
		int t{};
		std::unordered_map<std::string, int> trees;
		std::unordered_map<int, int> count;
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
			key << std::to_string( node->val ) << ","
				<< preorder( node->left.get() ) << ","
				<< preorder( node->right.get() );

			if( trees.find( key.str() ) != trees.end() && trees.at( key.str() ) == 1 )
			{
				result.push_back( node );
			}

			trees[ key.str() ]++;

			return key.str();
		}
	};

	/* 107. Binary Tree Level Order Traversal II.

	Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

	For example:
	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7
	return its bottom-up level order traversal as:
	[
	  [15,7],
	  [9,20],
	  [3]
	]
	*/

	struct level_order_ii
	{
		static void traverse( const tree_node* node, int level, std::map<int, std::vector<int>>& results )
		{
			if( node == nullptr ) return;

			results[ level++ ].push_back( node->val );

			traverse( node->left.get(), level, results );
			traverse( node->right.get(), level, results );
		}

		static std::vector<std::vector<int>> level_order_bottom( const tree_node* root )
		{
			auto level_order = std::map<int, std::vector<int>>();

			traverse( root, 0, level_order );

			auto result = std::vector<std::vector<int>>();

			for( auto level = level_order.size(); level > 0; --level )
			{
				result.push_back( level_order[ level - 1 ] );
			}

			return result;
		}
	};

	/* 1123. Lowest Common Ancestor of Deepest Leaves.

	Given a rooted binary tree, return the lowest common ancestor of its deepest leaves.

	Recall that:

	The node of a binary tree is a leaf if and only if it has no children
	The depth of the root of the tree is 0, and if the depth of a node is d, the depth of each of its children is d+1.
	The lowest common ancestor of a set S of nodes is the node A with the largest depth such that every node in S is in the subtree with root A.


	Example 1:

	Input: root = [1,2,3]
	Output: [1,2,3]
	Explanation:
	The deepest leaves are the nodes with values 2 and 3.
	The lowest common ancestor of these leaves is the node with value 1.
	The answer returned is a TreeNode object (not an array) with serialization "[1,2,3]".
	Example 2:

	Input: root = [1,2,3,4]
	Output: [4]
	Example 3:

	Input: root = [1,2,3,4,5]
	Output: [2,4,5]


	Constraints:

	The given tree will have between 1 and 1000 nodes.
	Each node of the tree will have a distinct value between 1 and 1000.
	*/

	class lowest_common_ancestor
	{
	public:

		static const tree_node* lca_deepest_leaves( const tree_node* root )
		{
			if( !root ) return nullptr;

			if( height( root->left.get() ) == height( root->right.get() ) ) return root;

			return height( root->left.get() ) > height( root->right.get() ) ?
				lca_deepest_leaves( root->left.get() ) :
				lca_deepest_leaves( root->right.get() );
		}

		static int height( const tree_node* node )
		{
			if( !node ) return 0;

			const auto left = height( node->left.get() );
			const auto right = height( node->right.get() );

			return left > right ? left + 1 : right + 1;
		}
	};

	/* 919. Complete Binary Tree Inserter.

	A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

	Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

	CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
	CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
	CBTInserter.get_root() will return the head node of the tree.


	Example 1:

	Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
	Output: [null,1,[1,2]]
	Example 2:

	Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
	Output: [null,3,4,[1,2,3,4,5,6,7,8]]


	Note:

	The initial given tree is complete and contains between 1 and 1000 nodes.
	CBTInserter.insert is called at most 10000 times per test case.
	Every value of a given or inserted node is between 0 and 5000.
	*/

	class complete_binary_tree
	{
		tree_node* root_ = nullptr;

	public:

		explicit complete_binary_tree( tree_node* root )
		{
			root_ = root;
		}

		int insert( int v ) const
		{
			auto q = std::queue<tree_node*>();
			q.push( root_ );

			tree_node* cur = nullptr;

			while( !q.empty() )
			{
				cur = q.front();
				q.pop();

				if( cur->left )
				{
					q.push( cur->left.get() );
				}
				else
				{
					cur->left = std::make_unique<tree_node>( v );
					break;
				}

				if( cur->right )
				{
					q.push( cur->right.get() );
				}
				else
				{
					cur->right = std::make_unique<tree_node>( v );
					break;
				}
			}

			return cur ? cur->val : -1;
		}

		tree_node* get_root() const
		{
			return root_;
		}
	};
}