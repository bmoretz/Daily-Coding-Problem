#include <bits/stdc++.h>
#include <array>

/* 826. Most Profit Assigning Work.

We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100 
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] separately.
Notes:

1 <= difficulty.length = profit.length <= 10000
1 <= worker.length <= 10000
difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
*/

class assign_work
{

public:

	static int maxProfitAssignment( const std::vector<int>& difficulty,
		const std::vector<int>& profit, std::vector<int>& workers )
	{
		std::priority_queue<std::pair<int, int>> pq;

		for( auto index = 0; index < profit.size(); index++ )
		{
			pq.push( { profit[ index ], difficulty[ index ] } );
		}

		std::sort( workers.begin(), workers.end() );

		auto result = 0;

		for( int index = workers.size() - 1; index >= 0; index-- )
		{
			while( index < workers.size() && !pq.empty() && pq.top().second > workers[ index ] )
			{
				pq.pop();
			}

			if( !pq.empty() ) 
			{
				result += pq.top().first;
			}
		}

		return result;
	}
};

auto main() -> int
{
	auto input1 = std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>
	{
		{ 2, 4, 6, 8, 10 },
		{ 10, 20, 30, 40, 50 },
		{ 4, 5, 6, 7 }
	};

	auto input2 = std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>
	{
		{ 85, 47, 57 },
		{ 24, 66, 99 },
		{ 40, 25, 25 }
	};

	auto input3 = std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>
	{
		{ 13, 37, 58 },
		{ 4, 90, 96 },
		{ 34, 73, 45 }
	};
	
	const auto result = assign_work::maxProfitAssignment(
		std::get<0>(input1 ), 
		std::get<1>( input1 ), 
		std::get<2>( input1 ) 
	);
	
	return 0;
}