#include <bits/stdc++.h>

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
    static bool is_cyclic( int course, const std::map<int, std::vector<int>>& courses,
        std::vector<bool>& checked, std::vector<bool>& path )
    {
        if( checked[ course ] ) return false;
        if( path[ course ] ) return true;

        if( courses.find( course ) == courses.end() ) return false;

        path[ course ] = true;

        auto result = false;

        for( auto child : courses.at( course ) )
        {
            result = is_cyclic( child, courses, checked, path );

            if( result )
                break;
        }

        path[ course ] = false;
        checked[ course ] = true;

        return result;
    }

public:

    static bool can_finish( const int num_courses, 
        const std::vector<std::vector<int>>& prerequisites )
    {
        std::map<int, std::vector<int>> courses;

        for( auto& pre : prerequisites )
        {
            const auto c = pre.at( 0 );
            const auto p = pre.at( 1 );

            courses[ c ].push_back( p );
        }

        auto checked = std::vector<bool>( num_courses );
        auto path = std::vector<bool>( num_courses );

        for( auto course = 0; course < num_courses; ++course )
        {
            if( is_cyclic( course, courses, checked, path ) )
            {
                return false;
            }
        }

        return true;
    }
};

auto main() -> int
{
    const auto prereqs = std::vector<std::vector<int>>{ {0, 1} };
    const auto actual = course_schedule::can_finish( 2, prereqs );
	
    const auto expected = 3;
	
	return 0;
}
