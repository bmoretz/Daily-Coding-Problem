#include <bits/stdc++.h>

/* 202. Happy Number.

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

*/

class happy_number
{
	static int get_sqr_sum_digits( int num )
	{
		auto total_sum = 0;

		while( num > 0 )
		{
			const auto digit = num % 10;
			num = num / 10;
			total_sum += digit * digit;
		}

		return total_sum;
	}
	
public:

	static bool is_happy( int n )
	{
		auto seen = std::set<int>();

		while( n != 1 && seen.find( n ) == seen.end() )
		{
			seen.insert( n );
			n = get_sqr_sum_digits( n );
		}
		
		return n == 1;
	}
};

auto main() -> int
{

	auto result = happy_number::is_happy( 19 );
	
	return 0;
}