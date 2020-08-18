#include <bits/stdc++.h>

/* 763. Partition Labels.

A string S of lowercase English letters is given. We want to partition this string into as many parts as
possible so that each letter appears in at most one part, and return a list of
integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

class partition_labels
{

public:

	/// <summary>
	/// partition labels
	///
	/// greedy approach
	/// </summary>
	/// <param name="str">input string</param>
	/// <returns>size of maximum length partitions</returns>
    static std::vector<int> partitionLabels( const std::string& str )
    {
        std::map<char, std::size_t> last;

    	for( auto index = std::size_t(); index < str.size(); ++index )
    	{
            last[ str[ index ] ] = index;
    	}

        std::vector<int> result;
        auto start = std::size_t(), stop = std::size_t();

        for( auto index = std::size_t(); index < str.size(); ++index )
        {
            stop = std::max( stop, last[ str.at( index ) ] );
            const auto current_len = stop - start;

            if( index == stop || index == str.size() - 1 )
            {
                result.push_back( current_len + 1 );
                start = stop = index + 1;
            }
        }

        return result;
    }
};

auto main() -> int
{
    const auto input = std::string("ab");

    const auto actual = partition_labels::partitionLabels( input );
	
    return 0;
}