#include <utility>
#include <random>
#include <memory>

namespace tree_problems
{
	/* Random Node.
	 *
	 * Implement a binary tree class which, in addition to the usual operations,
	 * has a method pick_random() which returns a random node from the tree. All
	 * nodes should be equally likely to be chosen.
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

			explicit tree_node( const Ty& value,
				const tree_node* parent = nullptr ) :
				value{ value }, parent{ parent }, size{ 1 }
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

		mutable std::mt19937 gen_;
		tree_node_ptr root_;

	public:

		explicit random_node( const unsigned int seed = std::random_device{}( ) )
			: gen_{ seed }
		{ }

		random_node( const std::initializer_list<Ty>& values,
			const unsigned int seed = std::random_device{}( ) )
			: random_node( seed )
		{
			for( const auto& val : values )
				insert( val );
		}

		/// <summary>
		/// insert node
		///
		/// this approach for insertion increments the nodes it passes on the way
		/// down the tree to keep track of the total size of each node (total size =
		/// the node + all its children) in constant time. This approach does *not* keep
		/// the tree balanced or enforce any other invariants other than the node size and
		/// basic left <= current < right.
		/// </summary>
		/// <param name="value">value to insert</param>
		void insert( const Ty& value )
		{
			if( !root_ )
			{
				root_ = std::make_unique<tree_node>( value );
				return;
			}

			tree_node* node = root_.get(),
				* parent{};

			while( node )
			{
				++node->size;
				parent = node;

				node = value <= node->value ?
					node->left.get() : node->right.get();
			}

			parent->insert_child( value );
		}

		[[nodiscard]] auto next( const std::size_t& min, const std::size_t& max ) const -> std::size_t
		{
			using uniform = std::uniform_int_distribution<std::mt19937::result_type>;

			const uniform distribution( min, max );

			return distribution( gen_ );
		}

		// forward the root to the recursive version.
		[[nodiscard]] auto pick_random() const -> Ty& { return pick_random( *root_ ); }

		/// <summary>
		/// pick random
		///
		/// This routine looks at the "total" size of the node, which is maintained by
		/// the insert to be the the current node + the total number of nodes below it,
		/// so the root have the size of the total tree. Each call to pick random, we
		/// generate a uniform number between 1 and the the node size, this gives us
		/// a 1/n chance of picking the current node (and 1/1 for a leaf so we always
		/// exit). If the number is [1, left-size] we traverse left, otherwise we traverse
		/// right, and then re-roll with that node's size.
		/// 
		/// </summary>
		/// <complexity>
		///		<run-time>O(E[N/2])</run-time>
		///		<space>O(E[N/2])</space>
		/// </complexity>
		/// <param name="node">the starting node</param>
		/// <returns>a node between [node, children] with equal probability</returns>
		[[nodiscard]] auto pick_random( tree_node& node ) const -> Ty&
		{
			const auto rnd = next( 1, node.size );

			if( rnd == node.size )
				return node.value;

			if( node.left && rnd <= node.left->size )
			{
				return pick_random( *node.left );
			}

			return pick_random( *node.right );
		}
	};
}

auto main() -> int
{
}