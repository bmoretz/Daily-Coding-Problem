#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
#include <stack>

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

	/* 653. Two Sum IV - Input is a BST.

	Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

	Example 1:

	Input:
		5
	   / \
	  3   6
	 / \   \
	2   4   7

	Target = 9

	Output: True


	Example 2:

	Input:
		5
	   / \
	  3   6
	 / \   \
	2   4   7

	Target = 28

	Output: False
	*/

	class two_sum_bst
	{

	public:

		static std::vector<int> flatten( const tree_node* root )
		{
			std::vector<int> results;

			flatten( root, results );

			return results;
		}

		static void flatten( const tree_node* root, std::vector<int>& results )
		{
			if( root == nullptr ) return;

			flatten( root->left.get(), results );
			results.push_back( root->val );
			flatten( root->right.get(), results );
		}

		static bool find_target( const tree_node* root, const int k )
		{
			auto numbers = flatten( root );

			std::set<int> targets( numbers.begin(), numbers.end() );

			for( auto num : numbers )
			{
				const auto target = k - num;

				if( target != num && targets.find( target ) != targets.end() )
				{
					return true;
				}
			}

			return false;
		}
	};

	/* 94. Binary Tree Inorder Traversal.

	Given a binary tree, return the in-order traversal of its nodes' values.

	Example:

	Input: [1,null,2,3]
	   1
		\
		 2
		/
	   3

	Output: [1,3,2]
	Follow up: Recursive solution is trivial, could you do it iteratively?
	*/
	
	class binary_tree_traversal
	{
		static void traverse_inorder( tree_node* root, std::vector<int>& result )
		{
			if( !root ) return;

			traverse_inorder( root->left.get(), result );

			result.push_back( root->val );

			traverse_inorder( root->right.get(), result );
		}

	public:

		static std::vector<int> inorder_traversal1( tree_node* root )
		{
			std::vector<int> result;

			traverse_inorder( root, result );

			return result;
		}

		static std::vector<int> inorder_traversal2( tree_node* root )
		{
			std::vector<int> result;

			auto stack = std::stack<tree_node*>();
			auto node = root;
			
			while( node || !stack.empty() )
			{
				while( node )
				{
					stack.push( node );
					node = node->left.get();
				}

				node = stack.top();

				result.push_back( node->val );

				stack.pop();

				node = node->right.get();
			}

			return result;
		}
	};

	/* 863. All Nodes Distance K in Binary Tree.

	We are given a binary tree (with root node root), a target node, and an integer value K.

	Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

	Example 1:

	Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

	Output: [7,4,1]

	Explanation:
	The nodes that are a distance 2 from the target node (with value 5)
	have values 7, 4, and 1.

	Note that the inputs "root" and "target" are actually TreeNodes.
	The descriptions of the inputs above are just serializations of these objects.

	Note:

	The given tree is non-empty.
	Each node in the tree has unique values 0 <= node.val <= 500.
	The target node is a node in the tree.
	0 <= K <= 1000.
	*/

	class binary_tree_distance
	{
		static void get_hierarchy( tree_node* root,
			std::unordered_map<tree_node*, tree_node*>& map,
			int level = 0 )
		{
			if( !root ) return;

			if( root->left )
			{
				map[ root->left.get() ] = root;
				get_hierarchy( root->left.get(), map );
			}

			if( root->right )
			{
				map[ root->right.get() ] = root;
				get_hierarchy( root->right.get(), map );
			}
		}

		static void search( tree_node* node, const int k,
			const std::unordered_map<tree_node*, tree_node*>& nodes,
			std::set<tree_node*>& visited,
			std::vector<int>& result )
		{
			if( !node ) return;
			if( visited.find( node ) != visited.end() ) return;

			visited.insert( node );

			if( k == 0 )
			{
				result.push_back( node->val );

				return;
			}

			if( node->left )
				search( node->left.get(), k - 1, nodes, visited, result );

			if( node->right )
				search( node->right.get(), k - 1, nodes, visited, result );

			if( nodes.find( node ) != nodes.end() )
			{
				const auto parent = nodes.at( node );

				if( parent )
					search( parent, k - 1, nodes, visited, result );
			}
		}

	public:

		static std::vector<int> distanceK( tree_node* root,
			tree_node* target, const int k )
		{
			std::unordered_map<tree_node*, tree_node*> tree_map;

			get_hierarchy( root, tree_map );

			std::set<tree_node*> visited;
			std::vector<int> result;

			search( target, k, tree_map, visited, result );

			return result;
		}
	};

	/* 965. Univalued Binary Tree.

	A binary tree is univalued if every node in the tree has the same value.

	Return true if and only if the given tree is univalued.

	Example 1:

	Input: [1,1,1,1,1,null,1]
	Output: true
	Example 2:

	Input: [2,2,2,5,2]
	Output: false

	Note:

	The number of nodes in the given tree will be in the range [1, 100].
	Each node's value will be an integer in the range [0, 99].
	*/

	class is_univalued
	{
		static bool is_unival( tree_node* node )
		{
			if( !node ) return false;

			auto left_sub = true;

			if( node->left )
			{
				if( node->val != node->left->val )
					return false;

				left_sub = is_unival( node->left.get() );
			}

			auto right_sub = true;

			if( node->right )
			{
				if( node->val != node->right->val )
					return false;

				right_sub = is_unival( node->right.get() );
			}

			return left_sub && right_sub;
		}

	public:

		static bool is_unival_tree( tree_node* root )
		{
			if( !root ) return false;

			return is_unival( root );
		}
	};

	/* 285. Inorder Successor in BST.

	Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

	The successor of a node p is the node with the smallest key greater than p.val.



	Example 1:


	Input: root = [2,1,3], p = 1
	Output: 2
	Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
	Example 2:


	Input: root = [5,3,6,2,4,null,null,1], p = 6
	Output: null
	Explanation: There is no in-order successor of the current node, so the answer is null.


	Note:

	If the given node has no in-order successor in the tree, return null.+
	It's guaranteed that the values of the tree are unique.
	*/

	class in_order_successor
	{
	public:

		static tree_node* inorderSuccessor( tree_node* root, tree_node* p )
		{
			if( !root || !p ) return nullptr;

			auto queue = std::queue<tree_node*>();;

			queue.push( root );

			auto diff = INT_MAX;
			tree_node* result = nullptr;

			while( !queue.empty() )
			{
				const auto node = queue.front();
				queue.pop();

				const auto delta = node->val - p->val;

				if( delta > 0 && node != p && delta < diff )
				{
					diff = delta;
					result = node;
				}

				if( node->left )
					queue.push( node->left.get() );

				if( node->right )
					queue.push( node->right.get() );
			}

			return result;
		}
	};

	/* 543. Diameter of Binary Tree.

	Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree
	is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

	Example:
	Given a binary tree
			  1
			 / \
			2   3
		   / \
		  4   5

	Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

	Note: The length of path between two nodes is represented by the number of edges between them.
	*/

	class tree_diameter
	{
	public:
		static int diameter_of_binary_tree( tree_node* root )
		{
			if( root == nullptr ) return 0;

			auto depths = std::unordered_map<tree_node*, int>();
			auto stack = std::stack<tree_node*>();

			stack.push( root );

			auto max_width = 0;

			while( !stack.empty() )
			{
				auto node = stack.top();

				if( node->left &&
					depths.find( node->left.get() ) == depths.end() )
				{
					stack.push( node->left.get() );
				}
				else if( node->right.get() &&
					depths.find( node->right.get() ) == depths.end() )
				{
					stack.push( node->right.get() );
				}
				else
				{
					stack.pop();

					auto left = depths[ node->left.get() ],
						right = depths[ node->right.get() ];

					depths[ node ] = std::max( left, right ) + 1;
					max_width = std::max( max_width, left + right );
				}
			}

			return max_width;
		}
	};

	/*103. Binary Tree Zigzag Level Order Traversal.

	Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right,
	then right to left for the next level and alternate between).

	For example:

	Given binary tree [3,9,20,null,null,15,7],
		3
	   / \
	  9  20
		/  \
	   15   7

	return its zigzag level order traversal as:
	[
	  [3],
	  [20,9],
	  [15,7]
	]
	*/

	class zig_zag_level_order
	{
	public:

		static std::vector<std::vector<int>> zigzag_level_order( tree_node* root )
		{
			// process nodes in level order with a queue, the
			// key -> level, value -> node
			auto queue = std::queue<std::pair<int, tree_node*>>();

			if( root != nullptr )
				queue.push( std::make_pair( 0, root ) );

			auto result = std::vector<std::vector<int>>();

			while( !queue.empty() )
			{
				const auto& [level, node] = queue.front();

				if( node->left != nullptr )
				{
					queue.push( std::make_pair( level + 1, node->left.get() ) );
				}

				if( node->right != nullptr )
				{
					queue.push( std::make_pair( level + 1, node->right.get() ) );
				}

				// ensure the result vector has storage space
				if( result.size() <= level )
				{
					result.push_back( {} );
				}

				// if its an odd row, put the value at the front
				if( level % 2 == 1 )
				{
					result[ level ].insert( result[ level ].begin(), node->val );
				}
				else
				{
					// normal ordering
					result[ level ].push_back( node->val );
				}

				queue.pop();
			}

			return result;
		}
	};

	/*236. Lowest Common Ancestor of a Binary Tree.

	Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

	According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
	p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

	Example 1:

	Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
	Output: 3
	Explanation: The LCA of nodes 5 and 1 is 3.
	Example 2:

	Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
	Output: 5
	Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
	Example 3:

	Input: root = [1,2], p = 1, q = 2
	Output: 1

	Constraints:

	The number of nodes in the tree is in the range [2, 105].
	-109 <= Node.val <= 109
	All Node.val are unique.
	p != q
	p and q will exist in the tree.
	*/

	class lowest_common_ancestor_bfs
	{
		static std::unordered_map<tree_node*, tree_node*> get_hierarchy( tree_node* root )
		{
			auto map = std::unordered_map<tree_node*, tree_node*>();
			auto queue = std::queue<std::pair<tree_node*, tree_node*>>();

			// push the root node into the queue
			queue.push( std::make_pair( nullptr, root ) );

			while( !queue.empty() )
			{
				// current node
				const auto& [parent, node] = queue.front();

				// if we haven't seen this node before
				if( map.find( node ) == map.end() )
				{
					// store it's parent
					map[ node ] = parent;

					// process children

					if( node->left )
					{
						queue.push( std::make_pair( node, node->left.get() ) );
					}

					if( node->right )
					{
						queue.push( std::make_pair( node, node->right.get() ) );
					}
				}

				queue.pop();
			}

			return map;
		}

	public:

		static tree_node* lowest_common_ancestor( tree_node* root, tree_node* p, tree_node* q )
		{
			// get the hierarchy of the tree [node->parent] form
			auto hierarchy = get_hierarchy( root );

			auto seen = std::set<tree_node*>();

			auto node = p;
			// start at p, process
			// all of its parent nodes from lowest
			// to the root
			while( node != nullptr )
			{
				seen.insert( node );

				node = hierarchy[ node ];
			}

			node = q;
			// now process q
			// the first result that we find
			// will be the solution
			while( node != nullptr )
			{
				if( seen.find( node ) != seen.end() )
					return node;

				node = hierarchy[ node ];
			}

			// no common ancestors
			return nullptr;
		}
	};
}
