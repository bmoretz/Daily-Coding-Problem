#include <bits/stdc++.h>
#include <array>

/* 957. Prison Cells After N Days.

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]

Explanation: 

The following table summarizes the state of the prison on each day:

Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 
Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9

*/

class prison_cells
{
	static int to_hashkey( const std::vector<int>& cells )
	{
		auto state_key = 0x0;

		for( auto cell : cells )
		{
			state_key <<= 1;
			state_key = ( state_key | cell );
		}

		return state_key;
	}
	
	static std::vector<int> next_day( const std::vector<int>& cells )
	{
		const auto num_cells = cells.size();

		auto new_cells = std::vector<int>( num_cells );
		
		for( auto index = 0; index < num_cells; ++index )
		{
			const auto prev = index > 0 ? cells[ index - 1 ] : -1;
			const auto next = index < num_cells - 1 ? cells[ index + 1 ] : -1;

			new_cells[ index ] = prev == 1 && next == 1 || prev == 0 && next == 0 ? 1 : 0;
		}

		return new_cells;
	}
	
public:

	static std::vector<int> prisonAfterNDays( const std::vector<int>& cells, 
		const int days )
	{
		const auto num_cells = cells.size();
		auto current = cells;

		std::map<int, int> cell_map;
		auto is_memory = false;
		auto day = days;
		
		while( day > 0 )
		{
			if( !is_memory )
			{
				auto key = to_hashkey( current );

				if( cell_map.find( key ) != cell_map.end() )
				{
					day %= cell_map[ key ] - day;
					is_memory = true;
				}
				else
				{
					cell_map[ key ] = day;
				}
			}

			if( day > 0 )
			{
				day -= 1;
				current = next_day( current );
			}
		}

		return current;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>
	{
		0, 1, 0, 1, 1, 0, 0, 1
	};

	const auto input2 = std::vector<int>
	{
		4, 5, 6, 7, 0, 1, 2
	};

	const auto input3 = std::vector<int>
	{
		1, 2
	};
	
	const auto result = prison_cells::prisonAfterNDays( input1, 7 );
	
	return 0;
}