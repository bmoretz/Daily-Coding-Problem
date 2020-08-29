#include <bits/stdc++.h>
#include <array>

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

	static std::vector<std::string> findItinerary( const std::vector<std::vector<std::string>>& tickets,
		const std::string& starting_location = "JFK" )
	{
		auto flights = build_graph( tickets );

		std::vector<std::string> itinerary;

		build_itinerary( flights, starting_location, itinerary );

		std::reverse( itinerary.begin(), itinerary.end() );
		
		return itinerary;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::vector<std::string>>
	{
		{ "MUC", "LHR" },
		{ "JFK", "MUC" },
		{ "SFO", "SJC" },
		{ "LHR", "SFO" }
	};

	const auto input2 = std::vector<std::vector<std::string>>
	{
		{ "JFK", "SFO" },
		{ "JFK", "ATL" },
		{ "SFO", "ATL"},
		{ "ATL","JFK" },
		{ "ATL", "SFO" }
	};

	const auto input3 = std::vector<std::vector<std::string>>
	{
		{ "JFK", "KUL" },
		{ "JFK", "NRT" },
		{ "NRT", "JFK"}
	};

	const auto input4 = std::vector<std::vector<std::string>>
	{
		{ "EZE", "AXA" },
		{ "TIA", "ANU" },
		{ "ANU", "JFK" },
		{ "JFK", "ANU" },
		{ "ANU", "EZE" },
		{ "TIA", "ANU" },
		{ "AXA", "TIA" },
		{ "TIA", "JFK" },
		{ "ANU", "TIA" },
		{ "JFK", "TIA" }
	};
	
	const auto result = reconstruct_itinerary::findItinerary( input4 );
	
	return 0;
}