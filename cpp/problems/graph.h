#pragma once

#include <memory>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

namespace graph_problems
{
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

		/// <summary>
		/// has_route1
		///
		/// This is a simple depth-first search of the graph that
		/// starts at the first node and traverses the graph (deep-wise)
		/// until it finds the second node, or traversed all nodes without
		/// finding it.
		/// </summary>
		/// <param name="graph">graph to search</param>
		/// <param name="first">node 1</param>
		/// <param name="second">node 2</param>
		/// <complexity>
		///		<run-time>O(M + N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <returns>true iff there is a path from 1 -> 2</returns>
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

				for( const auto& node : current->children() )
				{
					if( node->name() == second )
						return true;

					seen.push( node );
				}
			}

			return false;
		}

		/// <summary>
		/// has_route2
		///
		/// This is a simple breadth-first search of the graph that
		/// starts at the first node and traverses the graph (breath-wise)
		/// until it finds the second node, or traversed all nodes without
		/// finding it.
		/// </summary>
		/// <param name="graph">graph to search</param>
		/// <param name="first">node 1</param>
		/// <param name="second">node 2</param>
		/// <complexity>
		///		<run-time>O(M + N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// <returns>true iff there is a path from 1 -> 2</returns>
		static bool has_route2( const graph& graph,
			const char& first,
			const char& second )
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

	/* Build Order.
	 *
	 * You are given a list of projects and a list of dependencies (which is a
	 * list of pairs of projects, where the second project is dependent on the first
	 *
	 * project). All of a project's dependencies must be built before the project is.
	 * Find a build order that will allow the projects to be built. If there is no
	 * valid build order, return an error.
	 *
	 * EXAMPLE:
	 *
	 * Input:
	 * projects: a, b, c, d, e, f
	 * dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
	 * Output: f, e, a, b, d, c
	 */

	class build_order
	{
		using node_list = std::vector<char>;
		using build_list = std::unordered_map<char, std::unique_ptr<node_list>>;

		inline static const std::string cycle_err =
			"CYCLICAL PROJECT REFERENCE DETECTED. CANNOT CONTINUE BUILD.";

		std::unique_ptr<build_list> projects_;

		static std::vector<char> dfs( const build_list& projects,
			const char node, std::set<char>& seen )
		{
			auto path = std::vector<char>();
			auto stack = std::stack<char>( { node } );

			auto loop_detect = std::set<char>();

			while( !stack.empty() )
			{
				const auto v = stack.top();
				stack.pop();

				loop_detect.insert( v );

				for( const auto u : *projects.at( v ) )
				{
					if( loop_detect.find( u ) != loop_detect.end() )
						throw std::runtime_error( cycle_err );

					if( seen.find( u ) == seen.end() )
						stack.push( u );
				}

				path.insert( path.begin(), v );
				seen.insert( v );
			}

			return path;
		}

		bool topological_sort( std::vector<std::pair<int, char>>& order, std::string& value ) const
		{
			std::set<char> seen;
			auto label = projects_->size();

			for( [[maybe_unused]] const auto& [key, v_not_used] : *projects_ )
			{
				if( seen.find( key ) != seen.end() )
					continue;

				try
				{
					auto path = dfs( *projects_, key, seen );

					for( const auto& node : path )
						order.emplace_back( --label, node );
				}
				catch( std::runtime_error& e )
				{
					value = e.what();
					return false;
				}
			}

			std::sort( order.begin(), order.end(),
				[]( auto& left, auto& right ) {
					return left.first < right.first;
				} );

			return true;
		}
		
	public:

		build_order()
		{
			projects_ = std::make_unique<build_list>();
		}

		build_order( const std::initializer_list<char>& projects,
			const std::initializer_list<std::pair<char, char>>& dependencies )
			: build_order()
		{
			for( const auto& project : projects )
				add_project( project );

			for( const auto& dependency : dependencies )
				add_dependency( dependency.first, dependency.second );
		}

		void add_project( const char project ) const
		{
			projects_->insert( std::make_pair( project, std::make_unique<node_list>() ) );
		}

		void add_dependency( const char project, const char dependency ) const
		{
			projects_->at( project )->push_back( dependency );
		}

		/// <summary>
		/// build order
		///
		/// This approach uses a topological sort to generate the build
		/// order of the project list. We use a dfs approach to traverse all nodes
		/// in the graph, and label them in descending order. During the dfs, if we
		/// see a node twice in the same dfs call we throw an error as we have
		/// encountered a cyclic reference in the project definition. Global seen
		/// list ensure we only traverse each node once giving us a runtime of O(N + M).
		/// </summary>
		/// <complexity>
		///		<run-time>O(M + N)</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// <returns></returns>
		[[nodiscard]] std::string get_build_order() const
		{
			std::vector<std::pair<int, char>> order;
			std::string value;

			if( !topological_sort( order, value ) ) return value;

			if( order.begin() == order.end() )
				return std::string();

			auto result = std::accumulate( order.begin(), order.end() - 1, std::string{},
				[]( std::string& r, auto& project )
				{
					return std::move( r ) + project.second + ", ";
				} );


			result += order.back().second;

			return result;
		}
	};
}