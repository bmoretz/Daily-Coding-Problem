﻿#include <bits/stdc++.h>

/* 895. Maximum Frequency Stack.

Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned. 

Example 1:

Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 
Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
 
*/

class frequency_stack
{
    std::unordered_map<int, std::stack<int>> group_;
    std::unordered_map<int, int> freq_;
    int max_freq_;

public:

    frequency_stack()
        : max_freq_{ 0 }
    { }

    void push( const int value )
    {
        freq_[ value ]++;
        group_[ freq_[ value ] ].push( value );
        max_freq_ = std::max( max_freq_, freq_[ value ] );
    }

    int pop()
    {
        const auto val = group_[ max_freq_ ].top();

        group_[ max_freq_ ].pop();
        freq_[ val ]--;

        if( group_[ max_freq_ ].empty() )
            --max_freq_;

        return val;
    }
};

auto main() -> int
{
    auto fs = frequency_stack();

    fs.push( 5 );
	fs.push( 7 );
    fs.push( 5 );
    fs.push( 7 );
    fs.push( 4 );
    fs.push( 5 );

    {
        const auto actual = fs.pop();
        const auto expected = 5;
    }

    {
        const auto actual = fs.pop();
        const auto expected = 7;
    }

    {
        const auto actual = fs.pop();
        const auto expected = 5;
    }

    {
        const auto actual = fs.pop();
        const auto expected = 4;
    }
	
	return 0;
}