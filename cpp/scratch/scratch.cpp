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

string urlify1( const string & input, const size_t length )
{
    if( input.length() == 0 ) return nullptr;

    auto output = string( length, ' ' );
    auto output_pos = 0;

    for( auto current : input )
    {
        if( current == ' ' )
        {
            output[ output_pos++ ] = '%';
            output[ output_pos++ ] = '2';
            output[ output_pos++ ] = '0';
        }
        else
        {
            output[ output_pos++ ] = current;
        }
    }

    _ASSERT( output.length() == length );

    return output;
}

int buffer_size( const string & s )
{
    auto length = s.length();

    for( auto character : s )
    {
        if( character == ' ' )
            length += 2;
    }

    return length;
}

auto main() -> int
{
    string input;

    cout << "Enter test input:";

    while( getline( cin, input ) )
    {
        const auto req_len = buffer_size( input );

        cout << input << " urlify: " << urlify1( input, req_len ) << endl;

        cout << "Enter test input:";
    }
}
