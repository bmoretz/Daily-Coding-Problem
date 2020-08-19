#include <bits/stdc++.h>

/* 253. Meeting Rooms II.

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
(si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class meeting_rooms_ii
{

public:

	static int schedule( const std::vector<std::vector<int>>& intervals )
    {
		auto cmp = []( std::vector<int> left, std::vector<int> right ) { return left.front() > right.front(); };
		std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype( cmp )> meetings{ cmp };
		
		for( const auto& interval : intervals )
		{
			meetings.push( interval );
		}

		std::vector<std::vector<int>> rooms;

		while( !meetings.empty() )
		{
			auto meeting = meetings.top();

			for( auto index = 0ULL; index < rooms.size() + 1; ++index )
			{
				if( rooms.size() <= index )
					rooms.emplace_back();
				
				const auto free_at = rooms[ index ].empty() ? 0 : rooms[ index ].back();
				const auto meeting_start = meeting.at( 0 );
				const auto meeting_end = meeting.at( 1 );
				
				if( free_at == 0 || free_at <= meeting_start )
				{
					// book it
					const auto meeting_end = meeting.at( 1 );
					rooms[ index ].push_back( meeting_end );
					break;
				}
			}
			
			meetings.pop();
		}
		
		return rooms.size();
    }
};

auto main() -> int
{
    const auto input1 = std::vector<std::vector<int>> { { 0, 30 }, { 5, 10 }, { 15, 20 } };
	const auto input2 = std::vector<std::vector<int>>{ { 7, 10 }, { 2, 4 } };
	const auto input3 = std::vector<std::vector<int>>{ { } };
	const auto input4 = std::vector<std::vector<int>>{ { 6, 15 }, { 13, 20 }, { 6, 17 } };
	const auto input5 = std::vector<std::vector<int>>{ { 2, 15 }, { 36, 45 }, { 9, 29 }, { 16, 23 }, { 4, 9 } };
	const auto input6 = std::vector<std::vector<int>>{ { 490, 946 }, { 132, 833 }, { 677, 836 }, { 77, 995 }, { 499, 585 }, { 72, 883 }, { 863, 900 }, { 193, 981 } };
	
    const auto actual = meeting_rooms_ii::schedule( input6 );
	
    return 0;
}