#include <bits/stdc++.h>
#include <array>

/* 547. Friend Circles.

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example,
if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
 

Example 2:

Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

 

Constraints:

1 <= N <= 200
M[i][i] == 1
M[i][j] == M[j][i]
*/

class friend_circles
{
	static void dfs( const std::vector<std::vector<int>>& grid,
	                 std::vector<bool>& visited,
	                 const int row )
    {
        for( auto col = 0; col < grid.size(); ++col )
        {
            if( grid[ row ][ col ] == 1 && visited[ col ] == 0 )
            {
                visited[ col ] = 1;
                dfs( grid, visited, col );
            }
        }
    }

public:

    int find_circle_num( const std::vector<std::vector<int>>& grid )
    {
        const int num_rows = grid.size();
        const int num_cols = grid[ 0 ].size();

        if( num_rows <= 0 || num_cols <= 0 ) return 0;

        auto visited = std::vector<bool>( num_rows, false );
        auto num_groups = 0;

        for( auto row = 0; row < num_rows; ++row )
        {
            if( !visited[ row ] )
            {
                dfs( grid, visited, row );
                num_groups++;
            }
        }

        return num_groups;
    }
};

auto main() -> int
{
	auto input1 = std::vector<std::string>{ };
	
	return 0;
}
