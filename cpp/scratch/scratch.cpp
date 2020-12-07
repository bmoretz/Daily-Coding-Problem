#include <bits/stdc++.h>

/*309. Best Time to Buy and Sell Stock with Cooldown.

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

class buy_and_sell_stock_ii
{
public:
	
    static int max_profit( const std::vector<int>& prices )
    {
        if( prices.size() < 2 )
            return 0;

        const int N = prices.size();
        auto result = 0;

    	std::vector<int> buy( N, 0 );
        std::vector<int> sell( N, 0 );
    	
        buy[ 0 ] = -prices[ 0 ];

    	for( auto index = 1; index < N; ++index )
        {
            sell[ index ] = std::max( buy[ index - 1 ] + prices[ index ], sell[ index - 1 ] - prices[ index - 1 ] + prices[ index ] );

            //record the max sell[i]
    		if( result < sell[ index ] )
                result = sell[ index ];

            if( 1 == index )
            {
                buy[ index ] = buy[ 0 ] + prices[ 0 ] - prices[ 1 ];
            }
            else
            {
                buy[ index ] = std::max( sell[ index - 2 ] - prices[ index ], buy[ index - 1 ] + prices[ index - 1 ] - prices[ index ] );
            }
        }
    	
        return result;
    }
};

auto main() -> int
{
    const auto prices = std::vector<int>{ 1, 2, 3, 0, 2 };
	
    const auto actual = buy_and_sell_stock_ii::max_profit( prices );
    const auto expected = 3;
	
	return 0;
}