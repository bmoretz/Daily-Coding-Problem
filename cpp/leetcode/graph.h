#pragma once

#include <algorithm>
#include <queue>
#include <stack>
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

	/* 126. Word Ladder II.

	Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s)
	from beginWord to endWord, such that:

	Only one letter can be changed at a time
	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
	Note:

	Return an empty list if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
	You may assume no duplicates in the word list.
	You may assume beginWord and endWord are non-empty and are not the same.
	Example 1:

	Input:

	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot","dot","dog","lot","log","cog"]

	Output:
	[
	  ["hit","hot","dot","dog","cog"],
	  ["hit","hot","lot","log","cog"]
	]

	Example 2:

	Input:
	beginWord = "hit"
	endWord = "cog"
	wordList = ["hot","dot","dog","lot","log"]

	Output: []

	Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
	*/

	class word_ladder_ii {

		static std::string to_wildcard( const std::string& word, const int index )
		{
			return word.substr( 0, index ) + "*" + word.substr( index + 1, word.length() );
		}

		static std::unordered_map<std::string, std::vector<std::string>> to_graph( const std::vector<std::string>& word_list )
		{
			std::unordered_map<std::string, std::vector<std::string>> graph;

			for( auto& word : word_list )
			{
				for( auto index = std::size_t(); index < word.length(); ++index )
				{
					graph[ to_wildcard( word, index ) ].push_back( word );
				}
			}

			return graph;
		}

	public:

		static std::vector<std::vector<std::string>> find_ladders( const std::string& begin_word,
			const std::string& end_word,
			const std::vector<std::string>& word_list )
		{
			auto graph = to_graph( word_list );

			auto queue = std::queue<std::vector<std::string>>();
			queue.push( { begin_word } );
			std::set<std::string> seen;

			auto result = std::vector<std::vector<std::string>>();

			auto found = false;

			while( !queue.empty() )
			{
				auto len = queue.size();
				std::vector<std::string> seen_cur_level;

				for( auto level = 0; level < len; ++level )
				{
					auto current_level = queue.front();
					queue.pop();

					auto prev = current_level.back();

					for( auto index = 0; index < prev.size(); ++index )
					{
						const auto wc = to_wildcard( prev, index );

						for( auto& adj_word : graph[ wc ] )
						{
							if( seen.find( adj_word ) != seen.end() )
								continue;

							auto cur = current_level;

							cur.push_back( adj_word );
							seen_cur_level.push_back( adj_word );

							if( adj_word == end_word )
							{
								found = true;
								result.push_back( cur );
							}
							else
							{
								queue.push( cur );
							}
						}
					}
				}

				if( found )
					break;

				for( const auto& w : seen_cur_level )
					seen.insert( w );
			}

			return result;
		}
	};

	/* 207. Course Schedule.

	There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

	Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

	Example 1:

	Input: numCourses = 2, prerequisites = [[1,0]]
	Output: true
	Explanation: There are a total of 2 courses to take.
				 To take course 1 you should have finished course 0. So it is possible.
	Example 2:

	Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
	Output: false
	Explanation: There are a total of 2 courses to take.
				 To take course 1 you should have finished course 0, and to take course 0 you should
				 also have finished course 1. So it is impossible.

	Constraints:

	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
	You may assume that there are no duplicate edges in the input prerequisites.
	1 <= numCourses <= 10^5
	*/

	class course_schedule
	{
		static inline int CYCLE = -1;
		static inline int TO_VISIT = 0;
		static inline int SAFE = 1;

		static auto to_graph( const std::vector<std::vector<int>>& prerequisites )
		{
			auto graph = std::unordered_map<int, std::vector<int>>();

			for( auto& prerequisite : prerequisites )
			{
				const auto course = prerequisite[ 0 ];
				const auto req = prerequisite[ 1 ];

				graph[ course ].push_back( req );
			}

			return graph;
		}

		static bool is_safe( const int course,
			std::unordered_map<int, std::vector<int>>& graph,
			std::vector<int>& states )
		{
			// if we have already seen this course and determined
			// it is safe, then we can safely exit.
			if( states[ course ] == SAFE )
				return true;

			// otherwise, mark the course as HAVING a cycle
			states[ course ] = CYCLE;

			// check all the prerequisites for this courses
			for( auto adj : graph[ course ] )
			{
				// if any adj course has a cycle, then we can't finish
				if( states[ adj ] == CYCLE || !is_safe( adj, graph, states ) )
					return false;
			}

			// otherwise, mark this course safe and return
			states[ course ] = SAFE;
			return true;
		}

	public:

		/// <summary>
		/// can finish
		/// </summary>
		/// <param name="num_courses">number of courses</param>
		/// <param name="prerequisites">list of prerequisites</param>
		/// <returns>if we can take all the courses safely</returns>
		static bool can_finish( const int num_courses,
			const std::vector<std::vector<int>>& prerequisites )
		{
			// convert the course prerequisites to a graph.
			auto graph = to_graph( prerequisites );
			// keep track of the states of each course, all initially set
			// to 0 / to visit
			auto states = std::vector<int>( num_courses, TO_VISIT );

			for( auto course = 0; course < num_courses; ++course )
			{
				// if any course has a cycle, then we cannot finish.
				if( !is_safe( course, graph, states ) )
				{
					return false;
				}
			}

			return true;
		}
	};

	/* 675. Cut Off Trees for Golf Event.

	You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

	0 represents the obstacle can't be reached.
	1 represents the ground can be walked through.

	The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
	In one step you can walk in any of the four directions top, bottom, left and right also when standing in a point which is a tree you
	can decide whether or not to cut off the tree.

	You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And
	after cutting, the original place has the tree will become a grass (value 1).

	You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't
	cut off all the trees, output -1 in that situation.

	You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

	Example 1:

	Input:
	[
	 [1,2,3],
	 [0,0,4],
	 [7,6,5]
	]
	Output: 6


	Example 2:

	Input:
	[
	 [1,2,3],
	 [0,0,0],
	 [7,6,5]
	]
	Output: -1


	Example 3:

	Input:
	[
	 [2,3,4],
	 [0,0,5],
	 [8,7,6]
	]
	Output: 6
	Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.


	Constraints:

	1 <= forest.length <= 50
	1 <= forest[i].length <= 50
	0 <= forest[i][j] <= 10^9
	*/

	class trim_forest {

		static inline std::vector<int> all_dirs = { -1, 0, 1, 0, -1 };

		static int next_step( const std::vector<std::vector<int>>& forest,
			const int row, const int col,
			const int prev_row, const int prev_col )
		{
			if( row == prev_row && col == prev_col ) return 0;

			const auto num_rows = forest.size();
			const auto num_cols = forest[ 0 ].size();

			auto queue = std::queue<std::pair<int, int>>();

			queue.push( { row, col } );

			auto visited = std::vector<std::vector<int>>( num_rows, std::vector<int>( num_cols, 0 ) );

			visited[ row ][ col ] = 1;

			auto step = 0;

			while( !queue.empty() )
			{
				++step;

				const auto sz = queue.size();

				for( auto index = 0; index < sz; ++index )
				{
					const auto [cur_row, cur_col] = queue.front();
					queue.pop();

					for( auto dir = 0; dir < 4; ++dir )
					{
						auto next_row = cur_row + all_dirs[ dir ],
							next_col = cur_col + all_dirs[ dir + 1 ];

						if( next_row < 0 || next_row >= num_rows ) continue;
						if( next_col < 0 || next_col >= num_cols ) continue;
						if( visited[ next_row ][ next_col ] == 1 || forest[ next_row ][ next_col ] == 0 ) continue;

						if( next_row == prev_row && next_col == prev_col )
							return step;

						visited[ next_row ][ next_col ] = 1;
						queue.push( { next_row, next_col } );
					}

				}
			}

			return -1;
		}

	public:

		static int cut_off_trees( const std::vector<std::vector<int>>& forest )
		{
			if( forest.empty() || forest[ 0 ].empty() ) return 0;

			const auto num_rows = forest.size();
			const auto num_cols = forest[ 0 ].size();

			auto trees = std::vector<std::vector<int>>();

			for( auto row = 0; row < num_rows; ++row )
			{
				for( auto col = 0; col < num_cols; ++col )
				{
					const auto tree_size = forest[ row ][ col ];

					if( tree_size > 1 )
					{
						trees.push_back( { tree_size, row, col } );
					}
				}
			}

			std::sort( trees.begin(), trees.end() );

			auto answer = 0;

			for( auto index = 0, cur_row = 0, cur_col = 0;
				index < trees.size(); ++index )
			{
				const auto cur_tree = trees[ index ];
				const auto step = next_step( forest,
					cur_row, cur_col,
					cur_tree[ 1 ], cur_tree[ 2 ] );

				if( step == -1 )
					return -1;

				answer += step;

				cur_row = cur_tree[ 1 ];
				cur_col = cur_tree[ 2 ];
			}

			return answer;
		}
	};
}