#pragma once

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::graph
{
	/*332. Reconstruct Itinerary.

	Given a list of airline tickets represented by pairs of departure and arrival airports
	[from, to], reconstruct the itinerary in order. All of the tickets belong to a man who
	departs from JFK. Thus, the itinerary must begin with JFK.

	Note:

	If there are multiple valid itineraries, you should return the itinerary that has the smallest
	lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a
	smaller lexical order than ["JFK", "LGB"].

	All airports are represented by three capital letters (IATA code).
	You may assume all tickets form at least one valid itinerary.
	One must use all the tickets once and only once.

	Example 1:

	Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
	Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

	Example 2:

	Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
	Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
	Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
	             But it is larger in lexical order.
	*/

	class reconstruct_itinerary
	{
		using graph = std::unordered_map<std::string, std::priority_queue<std::string, std::vector<std::string>, std::greater<>>>;

		static graph build_graph( const std::vector<std::vector<std::string>>& tickets )
		{
			graph flights;

			for( const auto& ticket : tickets )
			{
				flights[ ticket[ 0 ] ].emplace( ticket[ 1 ] );
			}

			return flights;
		}

		static void build_itinerary( graph& flights, const std::string& airport, std::vector<std::string>& itinerary )
		{
			while( !flights[ airport ].empty() )
			{
				auto destination = flights[ airport ].top();

				flights[ airport ].pop();

				build_itinerary( flights, destination, itinerary );
			}

			itinerary.emplace_back( airport );
		}

	public:

		static std::vector<std::string> find_itinerary( const std::vector<std::vector<std::string>>& tickets,
			const std::string& starting_location = "JFK" )
		{
			auto flights = build_graph( tickets );

			std::vector<std::string> itinerary;

			build_itinerary( flights, starting_location, itinerary );

			std::reverse( itinerary.begin(), itinerary.end() );

			return itinerary;
		}
	};

	/* 127. Word Ladder.

	Given two words (beginWord and endWord), and a dictionary's word list, find the
	length of shortest transformation sequence from beginWord to endWord, such that:

	Only one letter can be changed at a time.
	Each transformed word must exist in the word list.
	Note:

	Return 0 if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
	You may assume no duplicates in the word list.
	You may assume beginWord and endWord are non-empty and are not the same.
	Example 1:

	Input:
	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot","dot","dog","lot","log","cog"]

	Output: 5

	Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	return its length 5.
	Example 2:

	Input:
	beginWord = "hit"
	endWord = "cog"
	wordList = ["hot","dot","dog","lot","log"]

	Output: 0

	Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
	*/

	class word_ladder
	{
		static std::string to_wildcard( const std::string& str, const std::size_t index )
		{
			return str.substr( 0, index ) + '*' + str.substr( index + 1, str.size() );
		}

		static std::unordered_map<std::string, std::vector<std::string>> to_word_graph( const std::vector<std::string>& word_list )
		{
			std::unordered_map<std::string, std::vector<std::string>> graph;

			for( auto& word : word_list )
			{
				for( auto char_index = 0ULL; char_index < word.size(); ++char_index )
				{
					const auto new_word = to_wildcard( word, char_index );

					graph[ new_word ].push_back( word );
				}
			}

			return graph;
		}

		static int find_word_path( const std::string& begin_word, const std::string& end_word,
			std::unordered_map<std::string, std::vector<std::string>> word_graph )
		{
			auto queue = std::queue<std::pair<std::string, int>>();
			auto visited = std::set<std::string>();

			queue.push( std::make_pair( begin_word, 1 ) );
			visited.insert( begin_word );

			while( !queue.empty() )
			{
				const auto& [word, level] = queue.front();

				for( auto char_index = 0ULL; char_index < word.size(); ++char_index )
				{
					const auto wildcard = to_wildcard( word, char_index );

					for( auto& adj_word : word_graph[ wildcard ] )
					{
						if( adj_word == end_word )
						{
							return level + 1;
						}

						if( visited.find( adj_word ) == visited.end() )
						{
							visited.insert( adj_word );
							queue.push( { adj_word, level + 1 } );
						}
					}
				}

				queue.pop();
			}

			return 0;
		}

	public:

		static int ladder_length( const std::string& begin_word, const std::string& end_word,
			const std::vector<std::string>& word_list )
		{
			const auto word_graph = to_word_graph( word_list );

			return find_word_path( begin_word, end_word, word_graph );
		}
	};

	/* 785. Is Graph Bipartite?

	Given an undirected graph, return true if and only if it is bipartite.

	Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

	The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

	Example 1:

	Input: [[1,3], [0,2], [1,3], [0,2]]
	Output: true
	Explanation:

	\The graph looks like this:
	0----1
	|    |
	|    |
	3----2

	We can divide the vertices into two groups: {0, 2} and {1, 3}.

	Example 2:
	Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
	Output: false
	Explanation:
	The graph looks like this:
	0----1
	| \  |
	|  \ |
	3----2
	We cannot find a way to divide the set of nodes into two independent subsets.

	Note:

	graph will have length in range [1, 100].
	graph[i] will contain integers in range [0, graph.length - 1].
	graph[i] will not contain i or duplicate values.
	The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
	*/

	class is_graph_bipartite
	{
		static int RED_NODE;
		static int BLUE_NODE;

		static bool color_graph( std::vector<std::vector<int>>& graph,
			std::unordered_map<int, int>& colors,
			const int start )
		{
			auto stack = std::stack<int>();

			colors[ start ] = BLUE_NODE;
			stack.push( start );

			while( !stack.empty() )
			{
				const auto node = stack.top();
				stack.pop();

				for( auto edge : graph[ node ] )
				{
					if( colors.find( edge ) == colors.end() )
					{
						colors[ edge ] = !colors[ node ];
						stack.push( edge );
					}
					else if( colors[ edge ] == colors[ node ] )
					{
						return false;
					}
				}
			}

			return true;
		}

	public:

		static bool is_bipartite( std::vector<std::vector<int>>& graph )
		{
			if( graph.size() < 2 ) return false;

			std::unordered_map<int, int> colors;

			for( auto node = std::size_t(); node < graph.size(); ++node )
			{
				if( colors.find( node ) != colors.end() )
					continue;

				if( !color_graph( graph, colors, node ) )
				{
					return false;
				}
			}

			return true;
		}
	};

	int is_graph_bipartite::BLUE_NODE = 0;
	int is_graph_bipartite::RED_NODE = 1;
}