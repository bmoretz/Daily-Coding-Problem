#pragma once

#include <map>
#include <vector>

namespace leetcode::arr
{
	/*
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	Example:

	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
	 */

	class two_sum1
	{
		static std::map<int, int> to_lookup( const std::vector<int>& numbers )
		{
			std::map<int, int> lookup;

			for( auto index = 0; index < numbers.size(); ++index )
			{
				lookup.insert( std::make_pair( numbers.at( index ), index ) );
			}

			return lookup;
		}

	public:

		static std::vector<int> twoSum( const std::vector<int>& numbers, const int target )
		{
			auto lookup = to_lookup( numbers );

			for( auto index = 0; index < numbers.size(); ++index )
			{
				const auto match = target - numbers.at( index );
				const auto key = lookup.find( match );

				if( key != lookup.end() && key->second != index )
				{
					return std::vector<int>{ index, key->second };
				}
			}

			return std::vector<int>();
		}
	};
}
