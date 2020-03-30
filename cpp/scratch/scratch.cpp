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

size_t count_spaces( const string & input, const size_t length )
{
    if( input.empty() ) return 0;

    auto n_spaces = size_t();

    for( auto index = size_t(); index < length; ++index )
    {
        if( input[ index ] == ' ' )
            n_spaces++;
    }

    return n_spaces;
}

void urlify( string & input, const int length )
{
    if( input.length() == 0 ) return;

    const auto n_spaces = count_spaces( input, length );
    const auto offset = n_spaces * 2;

    auto encountered = 0, position = length - 1;

    do
    {
	    const auto current = input[ position ];
        const auto new_position = position + offset - ( encountered * 2 );

        if( current == ' ' ) 
        {
            input[ new_position ] = '0';
            input[ new_position - 1 ] = '2';
            input[ new_position - 2 ] = '%';

            encountered++;
        } else
        {
			input[ new_position ] = input[ position ];
        }

        position--;

    } while( position != -1 );
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
        auto buffer = to_buffer( input );
        urlify( buffer, input.length() );

        cout << input << " urlify: " << buffer << endl;

        cout << "Enter test input:";
    }
}
