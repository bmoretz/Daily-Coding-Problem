#include <bits/stdc++.h>

/* 1310. XOR Queries of a Subarray.

Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query i compute the XOR
of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array containing the result for the given queries.
 
Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]

Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8

Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
 

Constraints:

1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
*/

class xor_sub_query
{

public:

	/// <summary>
	/// xor queries, dynamic programming approach
	/// </summary>
    /// <param name="arr">array of integers</param>
    /// <param name="queries">array of query indexes</param>
    /// <returns>arr containing the results of the queries</returns>
    static std::vector<int> xor_queries( const std::vector<int>& arr, 
        const std::vector<std::vector<int>>& queries )
    {
        const auto n = arr.size();

        std::vector<int> lookup( n + 1, 0 );

    	// precompute lookup table
		for( auto index = std::size_t(); index < n; ++index )
		{
            lookup[ index + 1 ] = lookup[ index ] ^ arr[ index ];
		}

    	// calculate query results
        std::vector<int> results( queries.size() );
    	
    	for( auto index = std::size_t(); index < queries.size(); ++index )
    	{
            const std::size_t left = queries[ index ][ 0 ];
            const std::size_t right = queries[ index ][ 1 ];
    		
            results[ index ] = lookup[ right + 1 ] ^ lookup[ left ];
    	}
    	
        return results;
    }
};

auto main() -> int
{
    const auto input = std::vector<int>{ 1, 3, 4, 8 };
    const auto queries = std::vector<std::vector<int>>
	{
		{ 0, 1 }, { 1, 2 }, { 0, 3 }, { 3, 3 }
	};

    const auto actual = xor_sub_query::xor_queries( input, queries );
	
    return 0;
}