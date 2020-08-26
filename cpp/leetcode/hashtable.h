#pragma once

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::hashtable
{
	/* 1287. Element Appearing More Than 25% In Sorted Array.

	Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time.

	Return that integer.

	Example 1:

	Input: arr = [1,2,2,6,6,6,6,7,10]
	Output: 6

	Constraints:

	1 <= arr.length <= 10^4
	0 <= arr[i] <= 10^5
	*/

	struct element_with_most_appearances
	{
		static int find_special_integer( const std::vector<int>& arr )
		{
			std::unordered_map<int, int> counts;
			auto max_freq = -1;

			for( auto cur : arr )
			{
				counts[ cur ]++;

				if( max_freq == -1 || counts[ cur ] > counts[ max_freq ] )
				{
					max_freq = cur;
				}
			}

			return max_freq;
		}
	};


	/* 1152. Analyze User Website Visit Pattern.

	We are given some website visits: the user with name username[i]
	visited the website website[i] at time timestamp[i].

	A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of
	their visits.  (The websites in a 3-sequence are not necessarily distinct.)

	Find the 3-sequence visited by the largest number of users. If there is more than
	one solution, return the lexicographically smallest such 3-sequence.

	Example 1:

	Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"],
	timestamp = [1,2,3,4,5,6,7,8,9,10],
	website = ["home","about","career","home","cart","maps","home","home","about","career"]

	Output: ["home","about","career"]

	Explanation:

	The tuples in this example are:

	["joe", 1, "home"]
	["joe", 2, "about"]
	["joe", 3, "career"]
	["james", 4, "home"]
	["james", 5, "cart"]
	["james", 6, "maps"]
	["james", 7, "home"]
	["mary", 8, "home"]
	["mary", 9, "about"]
	["mary", 10, "career"]
	The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
	The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
	The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
	The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
	The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.

	Note:

	3 <= N = username.length = timestamp.length = website.length <= 50
	1 <= username[i].length <= 10
	0 <= timestamp[i] <= 10^9
	1 <= website[i].length <= 10
	Both username[i] and website[i] contain only lowercase characters.
	It is guaranteed that there is at least one user who visited at least 3 websites.
	No user visits two websites at the same time.
	*/

	class visitor_patterns
	{
		static std::unordered_map<std::basic_string<char>, std::vector<std::pair<int, std::basic_string<char>>>>
			build_user_map( const std::vector<std::string>& username, const std::vector<int>& timestamp, const std::vector<std::string>& website )
		{
			auto map = std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>();

			// generate keys of users to timestamp/website
			for( auto index = 0ULL; index < username.size(); ++index )
			{
				const auto value = std::make_pair( timestamp[ index ], website[ index ] );
				map[ username[ index ] ].push_back( value );
			}

			return map;
		}

	public:

		static std::vector<std::string> most_visited_pattern(
			const std::vector<std::string>& username,
			const std::vector<int>& timestamp,
			const std::vector<std::string>& website )
		{
			auto sequences = std::set<std::vector<std::string>>();
			auto counts = std::map<std::vector<std::string>, int>();

			const auto map = build_user_map( username, timestamp, website );

			for( const auto& iter : map )
			{
				auto visits = iter.second;

				// order by timestamp
				std::sort( visits.begin(), visits.end(),
					[]( const std::pair<int, std::string>& left, const std::pair<int, std::string>& right )
					{
						return left.first < right.first;
					} );

				sequences.clear();

				// all possible sequences of websites for each user
				for( auto i = 0ULL; i < visits.size(); ++i )
				{
					for( auto j = 0ULL; j < i; j++ )
					{
						for( auto k = 0ULL; k < j; k++ )
						{
							sequences.insert( {
								visits[ k ].second,
								visits[ j ].second,
								visits[ i ].second
							} );
						}
					}
				}

				// increment the counter
				for( const auto& seq : sequences )
					counts[ seq ]++;
			}

			return std::max_element( counts.begin(), counts.end(), []( auto& p1, auto& p2 )
				{
					return ( ( p1.second == p2.second ) ?
						( p1.first > p2.first ) :
						( p1.second < p2.second ) );
				} )->first;
		}
	};

	/*1207. Unique Number of Occurrences.

	Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

	Example 1:

	Input: arr = [1,2,2,1,1,3]
	Output: true
	Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
	Example 2:

	Input: arr = [1,2]
	Output: false
	Example 3:

	Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
	Output: true

	Constraints:

	1 <= arr.length <= 1000
	-1000 <= arr[i] <= 1000
	*/

	class unique_occurrences
	{
		static std::unordered_map<int, int> to_map( const std::vector<int>& values )
		{
			std::unordered_map<int, int> map;

			for( auto val : values )
			{
				++map[ val ];
			}

			return map;
		}

	public:
		
		static bool unique( const std::vector<int>& values )
		{
			const auto map = to_map( values );

			auto unique = std::set<int>();

			for( auto& [key, value] : map )
			{
				unique.insert( value );
			}

			return unique.size() == map.size();
		}
	};
}