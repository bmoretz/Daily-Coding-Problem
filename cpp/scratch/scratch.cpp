#include <bits/stdc++.h>
#include <array>

/* 915. Partition Array into Disjoint Intervals.

Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12] 

Note:

2 <= A.length <= 30000
0 <= A[i] <= 10^6
It is guaranteed there is at least one way to partition A as described.
*/

class disjoint_intervals
{
	
public:

	static int partition_disjoint( const std::vector<int>& arr )
	{
		const int n = arr.size();

		std::vector<int> max_left( n ), min_right( n );

		auto max = arr[ 0 ];
		for( auto index = 0ULL; index < n; ++index )
		{
			max = std::max( max, arr[ index ] );
			
			max_left[ index ] = max;
		}

		auto min = arr[ n - 1 ];
		for( auto index = n - 1; index >= 0; --index )
		{
			min = std::min( min, arr[ index ] );
			min_right[ index ] = min;
		}

		for( auto index = 1; index < n; ++index )
		{
			if( max_left[ index - 1 ] <= min_right[ index ] )
				return index;
		}

		return 0;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<int>{ 5, 0, 3, 8, 6 };
	const auto input2 = std::vector<int>{ 1, 1, 1, 0, 6, 12 };

	const auto input3 = std::vector<std::vector<int>>
	{
		{ -5, 4 },
		{ -6, -5 },
		{ 4, 6 }
	};

	const auto input4 = std::vector<std::vector<int>>
	{
		{ -5, 4 },
		{ -6, -5 },
		{ 4, 6 },
		{ 4, 6 },
		{ -5, 2 }
	};
	
	const auto result = disjoint_intervals::partition_disjoint( input3, 2 );
	
	return 0;
}