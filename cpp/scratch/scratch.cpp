#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

/* Route Between Nodes:
 *
 * Given a directed graph, design an algorithm to find out whether there is
 * a route between nodes.
 */

struct has_route
{
	class node;

	using node_list = std::vector<const node*>;

	using node_ptr = node*;
	
	class node
	{
		char name_;
		node_list children_{ };

	public:

		node() = delete;
		
		explicit node( const char name )
			: name_{ name }
		{  }

		void add_edge( const node* other )
		{
			children_.push_back( other );
		}

		[[nodiscard]] const char& name() const { return name_; }
		
		[[nodiscard]] const node_list& children() const
		{
			return children_;
		}
	};

	struct edge
	{
		char from{}, to{};

		edge( const char& first, const char& second )
		{
			from = first;
			to = second;
		}
	};
	
	class graph
	{
		std::unordered_map<char, std::unique_ptr<node>> vertices_{ };

	public:

		graph() = delete;
		
		graph( const std::initializer_list<char>& vertices )
		{
			for( const auto& vertex : vertices )
				vertices_[ vertex ] = std::make_unique<node>( vertex );
		}

		void connect( const std::vector<edge>& edge_list )
		{
			for( const auto& edge : edge_list )
				vertices_[ edge.from ]->add_edge( vertices_[ edge.to ].get() );
		}

		const node& operator[]( const char vertex ) const
		{
			return *vertices_.at( vertex );
		}
	};

	static bool has_route1( const graph& graph,
		const char& first,
		const char& second )
	{
		if( first == second ) return true;
		
		auto seen = std::stack<const node*>{ };
		
		seen.push( &graph[ first ] );

		while( !seen.empty() )
		{
			const auto current = seen.top();

			seen.pop();
			
			for( const auto& node : current->children())
			{
				if( node->name() == second )
					return true;

				seen.push( node );
			}
		}
		
		return false;
	}

	static bool has_route2( const graph& graph,
		const char& first,
		const char& second)
	{
		if( first == second ) return true;

		auto seen = std::queue<const node*>{ };

		seen.emplace( &graph[ first ] );

		while( !seen.empty() )
		{
			const auto current = seen.front();

			seen.pop();

			for( const auto& node : current->children() )
			{
				if( node->name() == second )
					return true;

				seen.emplace( node );
			}
		}
		
		return false;
	}
};

/*
 *			A
 *		/		\
 *	 B 		|		D
 *		\
 *			C
 *				\
 *					E
 *						\
 *							F
 */

std::unique_ptr<has_route::graph> build_graph()
{
	auto vertices = std::initializer_list{ 'A', 'B', 'C', 'D', 'E', 'F' };

	auto graph = std::make_unique<has_route::graph>( vertices );

	graph->connect( {
		{ 'A', 'B' },
		{ 'A', 'C' },
		{ 'A', 'D' },
		{ 'B', 'C' },
		{ 'C', 'E' },
		{ 'E', 'F' }
	} );
	 
	return graph;
}

auto main() -> int
{
	const auto g = build_graph();

	const auto f = 'A', l = 'F';

	const auto result = has_route::has_route2( *g, f, l );

	std::cout << "has path " << f << " -> " << l << " ? " <<
		result;
}