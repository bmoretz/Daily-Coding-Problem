// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>

/* Palindrome Permutation.
 *
 *Given a string, write a function to check if it is a permutation of a
 *palindrome.
 *
 *A palindrome is a word or phrase that is the same forwards and backwards.
 *A permutation is a rearrangement of letters. The palindrome does not need
 *to be limited to just dictionary words.
 *
 *EXAMPLE:
 *
 *Input: Tact Coa
 *Output: True (permutations: "taco cat", "atco cta", etc.)
 */

using namespace std;

map<char, int> char_map( const string & input )
{
    map<char, int> map;

    if( input.empty() ) return map;

    for( auto character : input )
    {
        if( character == ' ' )
            continue;

        const auto current = tolower( character );

        if( map.find( current ) != map.end() )
            map[ current ]++;
        else
            map[ current ] = 1;
    }

    return map;
}

bool is_palindrome_permutation(const string & input)
{
    if( input.empty() ) return false;

    auto map = char_map( input );

    auto n_odd = 0;

    for( auto iter = map.begin(); iter != map.end(); ++iter )
    {
        if( iter->second % 2 == 1 )
            n_odd++;
    }

    return n_odd <= 1;
}

auto main() -> int
{
    string input;

    cout << "Enter test input:";

    while( getline( cin, input ) )
    {
        cout << input << " is palindrome permutation?: " << is_palindrome_permutation(input) << endl;

        cout << "Enter test input:";
    }
}
