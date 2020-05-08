#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

/* Route Between Nodes:
 *
 * Given a directed graph, design an algorithm to find out whether there is
 * a route between nodes.
 */

struct has_route
{
	class node;

	using node_ptr = std::unique_ptr<node>;
	using node_list = std::vector<std::reference_wrapper<node_ptr>>;
	
	class node
	{
		node_list children_{ };
		
	public:

		void add_edges( const node_list&& other )
		{
			for( const auto& edge : other )
			{
				children_.push_back( edge );
			}
		}
	};

	class graph
	{
		std::unordered_map<std::string, node_ptr> vertices_{ };
		
	public:

		graph() = delete;
		
		graph( const std::initializer_list<std::string>& vertices,
			const std::initializer_list<std::pair<std::string, std::string>>& edges )
		{
			for( const auto& vertex : vertices )
				vertices_[ vertex ] = std::make_unique<node>();

			for( const auto& edge : edges )
				vertices_[ edge.first ]->add_edges( { vertices_[ edge.second ] } );
		}
	};
	
	static bool has_route1( const graph& graph, 
		const std::string& first, 
		const std::string& second )
	{

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
 */

std::unique_ptr<has_route::graph> build_graph()
{
	auto graph = std::make_unique<has_route::graph>( {}, {} );
	
	return graph;
}

auto main() -> int
{
	const auto g = build_graph();

	auto result = has_route::has_route1( *g, "A", "B" );

}