// scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

/* Urlify.
 *
 * Write a method to replace all spaces in a string with '%20'.
 * 
 * You may assume that the string has sufficient space at the end
 * to hold the additional characters, and that you are given the
 * "true" length of the string.
 * 
 * Use a character array and perform this operation in place.
 */

using namespace std;

string urlify1( string input, const size_t length )
{
    if( input.length() == 0 ) return input;

    size_t n_spaces = 1;

    for( auto index = 0; index < input.length(); index++ )
    {
        if( input[ index ] == ' ' )
        {
            for( auto sub = ( n_spaces * 2 - 1 ) + length; sub > index + 2; sub-- )
            {
                input[ sub ] = input[ sub - 2 ];
                input[ sub - 1 ] = input[ sub - 3 ];
            }

            input[ index++ ] = '%';
            input[ index++ ] = '2';
            input[ index ] = '0';

            n_spaces++;
        }
    }

    return input;
}

string to_buffer( const string & s )
{
	auto output = string( s );

    for( auto character : s )
    {
        if( character == ' ' )
            output += "  ";
    }

    return output;
}

auto main() -> int
{
    string input;

    cout << "Enter test input:";

    while( getline( cin, input ) )
    {
        cout << input << " urlify: " << urlify1( to_buffer( input ), input.length() ) << endl;

        cout << "Enter test input:";
    }
}
