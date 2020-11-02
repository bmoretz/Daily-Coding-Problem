#include <bits/stdc++.h>

/*752. Open the Lock.

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely
and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible. 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:

Input: deadends = ["0000"], target = "8888"
Output: -1
 

Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/

class open_the_lock
{
    static std::set<std::string> to_set( const std::vector<std::string>& deadends )
    {
        auto set = std::set<std::string>();

        for( auto deadend : deadends )
        {
            if( set.find( deadend ) == set.end() )
            {
                set.insert( deadend );
            }
        }

        return set;
    }

public:

    static int open_lock( const std::vector<std::string>& deadends, 
        const std::string& target )
    {
        // put all of the dead-ends in a set for O(1) lookups
        auto invalid = to_set( deadends );

        // queue to store the current number of moves + the current
        // state of the lock
        auto queue = std::queue<std::pair<int, std::string>>();

        const auto start = "0000";

        if( invalid.find( start ) == invalid.end() )
            queue.push( std::make_pair( 0, start ) );

        auto seen = std::set<std::string>();

        while( !queue.empty() )
        {
            const auto [moves, lock] = queue.front();

            // if the current state is the unlock key,
            // return the number of moves it took us to
            // reach this state
            if( lock == target )
            {
                return moves;
            }

            // iterate the number of characters in the string
            for( auto index = 0; index < 4; ++index )
            {
                // parse out the current state of the lock
                const auto pre = lock.substr( 0, index );
                const auto post = lock.substr( index + 1, lock.size() );
                const auto cur = lock[ index ] - '0';

                // we iterate both up and down ( from 0000 we add both 1000 and 9000 )
                // where index = 0
                for( auto dir = -1; dir <= 1; dir += 2 )
                {
                    const auto new_char = std::string( 1, '0' + ( cur + dir + 10 ) % 10 );
                    const auto new_state = pre + new_char + post;

                    // if it hasn't been seen before and if its a valid state
                    if( invalid.find( new_state ) == invalid.end() &&
                        seen.find( new_state ) == seen.end() )
                    {
                        seen.insert( new_state );
                        queue.push( make_pair( moves + 1, new_state ) );
                    }
                }
            }

            queue.pop();
        }

        return -1;
    }
};

auto main() -> int
{
    auto deadends = std::vector<std::string>
	{
        "0201","0101","0102","1212","2002"
    };
	
    auto actual = open_the_lock::open_lock( deadends, "0202" );
	
    const auto expected = 6;
	
	return 0;
}