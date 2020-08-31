#include <bits/stdc++.h>
#include <array>

/*692. Top K Frequent Words.

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]

Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.

Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

*/

class top_k_frequent
{
	static std::unordered_map<std::string, int> to_frequency_map( const std::vector<std::string>& words )
	{
		std::unordered_map<std::string, int> frequency;

		for( const auto& word : words )
		{
			frequency[ word ]++;
		}

		return frequency;
	}

	static auto to_priority_queue( const std::unordered_map<std::string, int>& freq )
	{
		auto compare = []( const std::pair<std::size_t, std::string>& left, const std::pair<std::size_t, std::string>& right )
		{
			if( left.first < right.first ) return true;
			if( left.first == right.first && left.second > right.second ) return true;

			return false;
		};

		std::priority_queue<std::pair<int, std::string>,
			std::vector<std::pair<int, std::string>>,
			decltype( compare )> queue( compare );

		for( auto& [k, v] : freq )
		{
			queue.push( std::make_pair( v, k ) );
		}

		return queue;
	}
	
public:

	/// <summary>
	/// top k frequent words
	///
	/// the approach here is to create a freq counter in a map (str->int), then insert the key/value pairs from the freq table
	/// into a heap with a custom comparer (first priority is the freq, then break freq ties with the lexicographical ordering of
	/// the keys).
	/// </summary>
	/// <param name="words">list of words</param>
	/// <param name="k">top k to return</param>
	/// <returns>top k most frequent</returns>
	static std::vector<std::string> topKFrequent( const std::vector<std::string>& words, 
		const std::size_t k )
	{	
		if( words.size() < k ) return words;

		const auto freq = to_frequency_map( words );
		auto queue = to_priority_queue( freq );

		auto result = std::vector<std::string>();

		for( auto index = 0; index < k; ++index )
		{
			result.push_back( queue.top().second );
			queue.pop();
		}
		
		return result;
	}
};

auto main() -> int
{
	const auto input1 = std::vector<std::string>
	{
		"i", "love", "leetcode", "i", "love", "coding"
	};

	const auto input2 = std::vector<std::string>
	{
		"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"
	};
	
	const auto result = top_k_frequent::topKFrequent( input2, 4 );
	
	return 0;
}