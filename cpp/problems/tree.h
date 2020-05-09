#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include <cmath>

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
				: value( val ), left{ }, right{ }
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
}