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
#include <sstream>
#include <random>
#include <ctime>

/* Random Node.
 *
 * You are implementing a binary tree class from scratch which, in addition
 * to insert, find, and delete has a method getRandomNode() which returns a
 * random node from the tree. All nodes should be equally likely to be chosen.
 * Design and implement an algorithm for getRandomNode, and explain how you
 * would implement the rest of the methods.
 */

template<typename Ty>
class random_node
{
	struct tree_node;

	using tree_node_ptr = std::unique_ptr<tree_node>;

	struct tree_node
	{
		Ty value;
		tree_node_ptr left{}, right{};
		const tree_node* parent{};
		std::size_t size{};
		
		explicit tree_node( Ty value, 
			const tree_node* parent = nullptr )
			: value{ value }, parent{ parent },
				size{ 1 }
		{  }

		tree_node( const tree_node& other )
			: value{ other.value }, parent{ other.parent },
			size{ other.size }
		{
			if( other.left )
				left = std::make_unique<tree_node>( other.left->value );

			if( other.right )
				right = std::make_unique<tree_node>( other.right->value );
		}
		
		tree_node( tree_node&& other ) noexcept
			: value{ other.value }, parent{ other.parent },
			  size{ other.size }
		{
			left = std::move( other.left );
			right = std::move( other.right );
		}
		
		void insert_child( Ty value )
		{
			if( value <= this->value )
			{
				left = std::make_unique<tree_node>( value, this );
			}
			else
			{
				right = std::make_unique<tree_node>( value, this );
			}
		}
	};

	mutable std::mt19937 gen_ ;
	tree_node_ptr root_;

public:
	
	explicit random_node( const unsigned int seed = std::random_device{}( ) )
		: gen_{ seed }
	{ }

	random_node( const std::initializer_list<Ty>& values,
		const unsigned int seed = std::random_device{}() )
		: random_node( seed )
	{
		for( const auto& val : values )
			insert( val );
	}
	
	void insert( Ty value )
	{
		if( !root_ )
		{
			root_ = std::make_unique<tree_node>( value );
			return;
		}

		tree_node *node = root_.get(),
			*parent{};

		while( node )
		{
			++node->size;
			parent = node;

			node = value <= node->value ?
				node->left.get() : node->right.get();
		}

		parent->insert_child( value );
	}

	[[nodiscard]] auto next( const std::size_t min, const std::size_t max ) const -> std::size_t
	{
		using uniform = std::uniform_int_distribution<std::mt19937::result_type>;

		const uniform distribution( min, max );

		return distribution( gen_ );
	}
	
	[[nodiscard]] auto pick_random() const -> tree_node& { return pick_random( *root_ ); }

	[[nodiscard]] auto pick_random( tree_node& node ) -> tree_node&
	{
		const auto rnd = next( 1, node.size );
		
		if( rnd == node.size )
			return node;

		if( node.left && rnd <= node.left->size )
		{
			return pick_random( *node.left );
		}
		
		return pick_random( *node.right );
	}
};

auto main() -> int
{
	auto tree = random_node<int>();
	
	const auto values = 
		std::vector<int>{ 4, 2, 6, 1, 3, 5, 7, 10 };

	for( auto val : values )
	{
		tree.insert( val );
	}

	for( auto index = std::size_t(); index < 20; ++index )
	{
		const auto rnd = tree.pick_random();

		std::cout << rnd.value << std::endl;
	}
}