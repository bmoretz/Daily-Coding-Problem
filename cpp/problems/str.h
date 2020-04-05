#pragma once

#include <string>
#include <map>
#include <vector>

namespace str_problems
{
	/*
	 * Is Unique.
	 *
	 * Implement an algorithm to determine if a string has all unique characters.
	 *
	 * What if you cannot use additional data structures?
	 */
	
	class unique1
	{
	public:
		static bool is_unique( const std::string & str );
	};

	class unique2
	{
	public:
		static bool is_unique( const std::string & str );
	};

	/* Check Permutation.
	 *
	 * Given two strings, write a method to decide if one is a permutation of the other.
	 */
	
	class is_permutation1
	{
	public:
		static bool is_permutation( const std::string & p, const std::string & q );
		static std::map<char, int> char_map( const std::string & s );
	};

	class is_permutation2
	{
	public:
		static bool is_permutation( std::string p, std::string q );
	};

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
	
	class urlify1
	{
	public:
		static std::string urlify( std::string input, size_t length );
	};

	class urlify2
	{
	public:
		static size_t count_spaces( const std::string & input, size_t length );
		static std::string urlify( std::string input, size_t length );
	};

	/* Palindrome Permutation.
	 *
	 * Given a string, write a function to check if it is a permutation of a
	 * palindrome. A palindrome is a word or phrase that is the same forwards
	 * and backwards. A permutation is a rearrangement of letters. The palindrome
	 * does not need to be limited to just dictionary words.
	 *
	 * EXAMPLE:
	 * Input: Tact Coa
	 * Output: True (permutations: "taco cat", "atco cta", etc.)
	 */
	
	class palperm1
	{
	public:
		static std::map<char, int> char_map( const std::string & input );
		static bool is_palindrome_permutation( const std::string & input );
	};

	/* One Away.
	 *
	 * There are three types of edits that can be performed on strings:
	 *
	 * insert a character,
	 * remove a character,
	 * replace a character
	 *
	 * Given two strings, write a function to check if they are one edit (or zero edits) away.
	 *
	 * EXAMPLE:
	 *
	 * pale, ple -> true
	 * pales, pale -> true
	 * pale, bale -> true
	 * pale, bake -> false
	 */
	
	class one_away1
	{
	public:
		static bool one_away( const std::string & str1, const std::string & str2 );
	};

	/* String Compression.
	 *
	 * Implement a method to perform basic string compression using the counts of repeated characters.
	 *
	 * For example, the string "aabbccccaaa" would become a2b1c5a3.
	 *
	 * If the "compressed" string would not become smaller than the original string, your method
	 * should return the original string. You can assume the string has only uppercase and
	 * lowercase letters (a-z).
	 */
	
	class compress_str1
	{
	public:
		static std::string compressed( const std::string & input );
	};

	/* String Rotation.
	 *
	 * Assume you have a method isSubstring which checks if one word is a
	 * substring of another. Given two strings, s1 and s2, write code to check
	 * if s2 is a rotation of s1 using only one call to isSubstring.
	 *
	 * e.g.,
	 * "waterbottle" is a rotation of "erbottlewat"
	 */
	
	class string_rotation1
	{
		static std::vector<std::string> get_rotations( const std::string & input );
		static bool is_substring( const std::string & haystack, const std::string & needle );
	public:
		static bool is_rotation( const std::string & s1, const std::string & s2 );
	};
}
