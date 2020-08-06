#include <bits/stdc++.h>

/* 121. Best Time to Buy and Sell Stock.

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

struct buy_and_sell_stock
{
	static int max_profit( const std::vector<int>& prices )
	{
		if( prices.empty() ) return 0;
		
		auto max_profit = 0;
		auto buy_price = prices.at( 0 ), sell_price = -1;
		
		for( auto index = 1; index < prices.size(); ++index )
		{
			if( prices.at( index ) < buy_price )
			{
				buy_price = prices.at( index );
				sell_price = -1;
			}
			else if( prices.at( index ) > sell_price )
			{
				sell_price = prices.at( index );
			}

			max_profit = std::max( max_profit, sell_price - buy_price );
		}

		return max_profit;
	}
};

auto main() -> int
{
	auto input1 = std::vector<int>{ 7, 1, 5, 3, 6, 4 }; // 5
	auto input2 = std::vector<int>{ 7, 6, 4, 3, 1 }; // 0
	auto input3 = std::vector<int>{ 7 }; // 0
	auto input4 = std::vector<int>{ 7, 1, 3 }; // 2
	auto input5 = std::vector<int>{ 7, 1, 3, 2, 9, 4 }; // 8
	auto input6 = std::vector<int>{ 7, 1, 3, 2, 9, 4, 2, 2, 1, 2, 6 }; // 8
	auto input7 = std::vector<int>{ 7, 1, 3, 2, 9, 4, 2, 2, 1, 2, 6, 7, 8, 9, 10 }; // 9
	
	const auto result = buy_and_sell_stock::max_profit( input2 );

	std::cout << result;
	
	return 0;
}