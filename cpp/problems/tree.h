#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

namespace tree_problems
{
	/* Minimal Tree.
	 *
	 * Given a sorted (increasing order) array with unique integer elements,
	 * write an algorithm to create a binary search tree with minimal height.
	 */

	class min_tree
	{
		struct node;

		using node_ptr = std::unique_ptr<node>;

		struct node
		{
			int value;
			node_ptr left, right;

			explicit node( const int& val )
				: value( val )
			{}
		};

		node_ptr root_;

		/// <summary>
		/// build_tree
		///
		/// Straight forward solution using a binary search type traversal of the array and
		/// a 'in-order' node loading (cur -> left -> right).
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <param name="values">The array of values</param>
		/// <param name="begin">start index</param>
		/// <param name="end">end index</param>
		/// <returns></returns>
		[[nodiscard]] node_ptr build_tree( const std::vector<int>& values, const int& begin, const int& end ) const
		{
			if( begin >= end )
				return nullptr;

			const auto mid = begin + int( ceil( ( end - begin ) / 2 ) );

			auto root = std::make_unique<node>( values[ mid ] );

			root->left = build_tree( values, begin, mid );

			root->right = build_tree( values, mid + 1, end );

			return root;
		}

		std::size_t num_children( const node* node ) const
		{
			if( node == nullptr ) return 0;

			return std::max( 1 + num_children( node->left.get() ),
				1 + num_children( node->right.get() ) );
		}

	public:

		min_tree() = delete;

		min_tree( const std::initializer_list<int>& init_values )
		{
			root_ = build_tree( init_values, 0, init_values.size() );
		}

		[[nodiscard]] std::size_t depth() const
		{
			return num_children( root_.get() );
		}
	};

	/* List of Depths.
	 *
	 * Given a binary tree, design an algorithm which creates a linked list of all the nodes
	 * at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).
	 */

	class list_of_depths
	{
		struct list_node;

		using list_node_ptr = std::unique_ptr<list_node>;

		struct list_node
		{
			int value;
			list_node_ptr next;

			explicit list_node( const int& val )
				: value{ val }
			{ }
		};

		struct tree_node;

		using tree_node_ptr = std::unique_ptr<tree_node>;

		struct tree_node
		{
			int value;
			tree_node_ptr left, right;

			explicit tree_node( const int& val )
				: value( val )
			{}
		};

		tree_node_ptr root_;

		[[nodiscard]] tree_node_ptr build_tree( const std::vector<int>& values, const int& begin, const int& end ) const
		{
			using std::ceil;

			if( begin >= end )
				return nullptr;

			const auto mid = begin + static_cast< int >( ceil( ( end - begin ) / 2 ) );

			auto root = std::make_unique<tree_node>( values[ mid ] );

			root->left = build_tree( values, begin, mid );

			root->right = build_tree( values, mid + 1, end );

			return root;
		}

		std::size_t num_children( const tree_node* node ) const
		{
			if( node == nullptr ) return 0;

			return std::max( 1 + num_children( node->left.get() ),
				1 + num_children( node->right.get() ) );
		}

	public:

		using list_map = std::map<std::size_t, list_node_ptr>;

		list_of_depths( const std::initializer_list<int>& init_values )
		{
			root_ = build_tree( init_values, 0, init_values.size() );
		}

		[[nodiscard]] std::size_t depth() const
		{
			return num_children( root_.get() );
		}

		/// <summary>
		/// Depth List 1
		///
		/// This approach uses a queue to (breath-first) traverse the tree and
		/// queue the next level nodes with level + 1 each tree node iteration. The
		/// resulting data structure is map that is indexed by tree level, with a
		/// linked list sentinel node at each level.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <returns></returns>
		[[nodiscard]] std::unique_ptr<list_map> build_node_list_bfs() const
		{
			using level_data = std::pair<std::size_t, tree_node*>;

			auto lists = std::make_unique<list_map>();

			if( !root_ )
				return lists;

			auto level = std::queue<level_data>{};
			level.push( level_data( 0, root_.get() ) );

			while( !level.empty() )
			{
				const auto current = level.front();

				if( current.first == lists->size() )
					lists->insert( std::make_pair(
						current.first,
						std::make_unique<list_node>( 0 )
					) );

				auto node = lists->at( current.first ).get();

				while( node->next )
					node = node->next.get();

				node->next = std::make_unique<list_node>( current.second->value );

				level.pop();

				if( current.second->left )
					level.push( std::make_pair(
						current.first + 1,
						current.second->left.get() ) );

				if( current.second->right )
					level.push( std::make_pair(
						current.first + 1,
						current.second->right.get() ) );
			}

			return lists;
		}

		/// <summary>
		/// Depth List 2
		///
		/// This approach uses a stack to (depth-first) traverse the tree and
		/// queue the next level nodes with level + 1 each tree node iteration. The
		/// resulting data structure is map that is indexed by tree level, with a
		/// linked list sentinel node at each level.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <returns></returns>
		[[nodiscard]] std::unique_ptr<list_map> build_node_list_dfs() const
		{
			using level_data = std::pair<std::size_t, tree_node*>;

			auto lists = std::make_unique<list_map>();

			if( !root_ )
				return lists;

			auto level = std::stack<level_data>{};
			level.push( level_data( 0, root_.get() ) );

			while( !level.empty() )
			{
				const auto current = level.top();

				if( current.first == lists->size() )
					lists->insert( std::make_pair(
						current.first,
						std::make_unique<list_node>( 0 )
					) );

				auto node = lists->at( current.first ).get();

				while( node->next )
					node = node->next.get();

				node->next = std::make_unique<list_node>( current.second->value );

				level.pop();

				if( current.second->left )
					level.push( std::make_pair(
						current.first + 1,
						current.second->left.get() ) );

				if( current.second->right )
					level.push( std::make_pair(
						current.first + 1,
						current.second->right.get() ) );
			}

			return lists;
		}
	};

	/* Check Balanced.
	 *
	 * Implement a function to check if a binary tree is balanced. For the purposes of
	 * this question, a balanced binary tree is defined to be a tree such that the heights
	 * of the two subtrees of any node never differ by more than one.
	 */

	struct is_balanced
	{
		struct tree_node;

		using tree_node_ptr = std::unique_ptr<tree_node>;

		struct tree_node
		{
			int value;
			tree_node_ptr left, right;

			explicit tree_node( const int& val )
				: value{ val }
			{  }
		};

		tree_node_ptr root;

		/// <summary>
		/// is_balanced1
		///
		/// Straight forward approach of comparing the heights of the sub-trees directly.
		///
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
		/// <returns></returns>
		[[nodiscard]] bool is_balanced1() const
		{
			if( !root ) return true;

			const auto left = height( root->left.get() );
			const auto right = height( root->right.get() );

			return std::abs( left - right ) <= 1;
		}

		[[nodiscard]] int height( const tree_node* node ) const
		{
			if( !node ) return 0;

			const auto l = 1 + height( node->left.get() );
			const auto r = 1 + height( node->right.get() );

			return std::max( l, r );
		}
	};

	/* Validate BST.
	 *
	 * Implement a function to check if a binary tree is a binary search tree.
	 */

	struct validate_bst
	{
		struct tree_node;

		using tree_node_ptr = std::unique_ptr<tree_node>;

		struct tree_node
		{
			int value;
			tree_node_ptr left, right;

			explicit tree_node( const int& val )
				: value{ val }
			{  }
		};

		/// <summary>
		/// is binary search tree
		///
		/// straight forward iteration of the nodes to check that every left node
		/// is less than (or equal) to its parent, and the right node is greater than
		/// the root node.
		/// </summary>
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="node">node to validate</param>
		/// <returns>true if meets binary tree criteria</returns>
		static auto is_bst( const tree_node* node )
		{
			if( !node ) return true;

			if( is_bst( node->left.get() ) && is_bst( node->right.get() ) )
			{
				const auto is_left = node->left ? node->value >= node->left->value : true;
				const auto is_right = node->right ? node->value < node->right->value : true;

				return is_left && is_right;
			}

			return false;
		}
	};

	/* Successor.
	 *
	 * Write an algorithm to find the "next" node (i.e., in-order successor) of a given
	 * node in a binary search tree. You may assume that each node has a link to its
	 * parent.
	 */

	struct successor
	{
		struct tree_node;

		using tree_node_ptr = std::unique_ptr<tree_node>;

		struct tree_node
		{
			tree_node* parent{};
			int value;
			tree_node_ptr left{ }, right{ };

			explicit tree_node( tree_node* parent, const int& val )
				: parent{ parent }, value{ val }
			{  }

			bool operator>=( const tree_node& other ) const { return value >= other.value; }
			bool operator<=( const tree_node& other ) const { return value <= other.value; }
			bool operator<( const tree_node& other ) const { return value < other.value; }
			bool operator>( const tree_node& other ) const { return value > other.value; }
			bool operator==( tree_node& other ) const { return value == other.value; }
		};

		static tree_node_ptr build_tree( const std::vector<int>& values,
			const int& begin, const int& end, tree_node* parent = nullptr )
		{
			using std::ceil;

			if( begin >= end ) return nullptr;

			const auto mid = begin + static_cast< int >( ceil( ( end - begin ) / 2 ) );

			auto node = std::make_unique<tree_node>( parent, values[ mid ] );

			node->left = build_tree( values, begin, mid, node.get() );
			node->right = build_tree( values, mid + 1, end, node.get() );

			return node;
		}

		/// <summary>
		/// successor
		///
		/// takes a binary tree node and gets the (in-order) successor node (if any). 
		/// </summary>
		/// <complexity>
		///		<run-time>O(log2 N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="node">binary tree node</param>
		/// <returns>successor (if any)</returns>
		static tree_node* get_successor( const tree_node& node )
		{
			tree_node* next = nullptr;

			if( !node.right )
			{
				next = node.parent;

				while( next && node >= *next )
					next = next->parent;
			}
			else if( node.right )
			{
				next = node.right.get();

				while( next->left )
					next = next->left.get();
			}

			return next;
		}
	};


	/* First Common Ancestor.
	 *
	 * Design an algorithm and write code to find the first common ancestor
	 * of two nodes in a binary tree. Avoid storing additional nodes in a data
	 * structure.
	 *
	 * NOTE: This is not necessarily a binary search tree.
	 */

	struct ancestor
	{
		struct tree_node;

		using tree_node_ptr = std::unique_ptr<tree_node>;

		struct tree_node
		{
			int value;
			tree_node_ptr left{}, right{};
			const tree_node* parent{};

			tree_node( const int val, const tree_node* parent )
				: value{ val },
				parent{ parent }
			{ }

			void insert_left( int val ) { left = std::make_unique<tree_node>( val, this ); }
			void insert_right( int val ) { right = std::make_unique<tree_node>( val, this ); }
		};

		/// <summary>
		/// common ancestor 1
		///
		/// This is a straight forward implementation that first
		/// gets the depth of both nodes, and then increments the node
		/// pointers until they are at the same depth level in the tree.
		/// Once the pointers are at the same level, we can walk the tree
		/// up uniformly until we find a common ancestor (there has to be
		/// one because eventually everything will walk up to the root. We
		/// can short circuit if one of the two nodes passed in has a null
		/// parent (its the root).
		/// </summary>
		/// <complexity>
		///		<run-time>O(tree height)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <param name="tree">root of the tree</param>
		/// <param name="first">node a</param>
		/// <param name="second">node b</param>
		/// <returns>first common ancestor</returns>
		static const tree_node* common_ancestor1( const tree_node& tree,
			const tree_node& first, const tree_node& second )
		{
			if( !( first.parent && second.parent ) ) return &tree;

			auto
				l_depth = get_depth( first ),
				r_depth = get_depth( second );

			auto l_node = &first, r_node = &second;

			// put both node pointers on the same level
			// so that we can walk up the tree in unison
			while( l_depth != r_depth )
			{
				if( l_depth > r_depth )
				{
					l_node = l_node->parent;
					l_depth--;
				}
				else
				{
					r_node = r_node->parent;
					r_depth--;
				}
			}

			while( l_node->parent != r_node->parent )
			{
				r_node = r_node->parent;
				l_node = l_node->parent;
			}

			return l_node->parent;
		}

		/// <summary>
		/// get depth
		///
		/// Returns the depth at which this tree node resides.
		/// </summary>
		/// <param name="tree_node">the node</param>
		/// <returns>the depth</returns>
		static int get_depth( const tree_node& tree_node )
		{
			auto depth = 0;
			auto node = &tree_node;

			while( node->parent )
			{
				node = node->parent;
				depth++;
			}

			return depth;
		}
	};
}