#include <bits/stdc++.h>

/* 318. Maximum Product of Word Lengths.

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words
do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".

Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.

Constraints:

0 <= words.length <= 10^3
0 <= words[i].length <= 10^3
words[i] consists only of lowercase English letters.
*/

struct max_len_unique_prod
{
    static std::unordered_map<std::string, std::bitset<26>> to_char_map( const std::vector<std::basic_string<char>>& unique_words )
    {
        std::unordered_map<std::string, std::bitset<26>> char_map;

        for( const auto& word : unique_words )
        {
            auto characters = std::bitset<26>();

            for( auto chr : word )
            {
                characters |= static_cast<long>( 1 ) << chr - 'a';
            }

            char_map[ word ] = characters;
        }

        return char_map;
    }

    static int maxProduct( const std::vector<std::string>& words )
    {
    	// remove any duplicates
        //const auto unique_words = std::set( words.begin(), words.end() );
    	
    	// build a lookup of words -> character bit sets
        const auto char_map = to_char_map( words );
    	
        auto max_len = std::size_t();

        for( auto outer = std::size_t(); outer < words.size(); ++outer )
        {
            const auto& left = words[ outer ];

            for( auto inner = outer + 1; inner < words.size(); ++inner )
            {
                const auto& right = words[ inner ];

                if( ( char_map.at( left ) & char_map.at( right ) ) == 0 )
                {
                    max_len = std::max( max_len, left.size() * right.size() );
                }
            }
        }

        return max_len;
    }
};

auto main() -> int
{
    auto input1 = std::vector<std::string>{ "abcw","baz","foo","bar","xtfn","abcdef" };
    auto input2 = std::vector<std::string>{ "a","ab","abc","d","cd","bcd","abcd" };
    auto input3 = std::vector<std::string>{ "a","aa","aaa","aaaa" };
    auto input4 = std::vector<std::string>{ "aebacbcecdcdaffdacbac","afdffdaffacccaba","fffaafccebbacffaddcad","eefaffbddcbdabacda","fcfbeecccc","afdbeabfcedfadaddb","bfdafdfdbbdaabba","acaeabcddfaafadfcacd","bcdfbfeadfdbdcf","cebabfbadfcbc","eefddeafbadfab","fdccabcebbfeedbabdad","bdabacbeecfdffbaa","dbbc","cfcfebfdeafdaceacfb","ec","bcaafadfe","abbfecdcafecccd","ec","edededdbdcefcf","edfcecdafcfaaab","ebfbfdcacd","dada","bfeffcafdfccdcbaba","dab","ebcadee","bbcdeacdcfdabfbadd","eadcdcb","cabebee","bcdabeffafbbdd","adacbacacfef","cfe","cbbfecfefaf","ddfcfefcadfccdfffaef","ab","edadcf","eedbcabeddbaeeead","fddaddedefebaecdde","cfeb","eaeadebbf","fbdffebe","fecebacba","cccaadfdfdeafde","defbcceab","adee","caaddeaade","bbeeecae","bce","ccdcafc","aecaadaeb","cebcbacdbec","fccedeacec","cacdafefcdff","dbaebafaba","dbfafefbfef","dadeecaecdfefbd","bded","ffbeecfed","bacc","ebdeffba","fceec","badcaefccdf","aadbbccbecf","cdffafdaefdaaeebe","efbfcdbec","decaebfdddfcdfda","ccbbcee","ceceffbfab","bdbfabaafa","eaeabaefbaed","efbcdbdadbafefcfe","ab","acefcdaadccebcef","fcda","ff","eedaabecf","eecbdacaedab","ad","ebddccbcabc","dacad","fcffdecbaeefcfd","edadacdbabffbeafffdb","daef","efbfcfbbdcccaa","bbebdca","edb","febfffac","aefbdfbbdebfebfebfbd","becbacdffebfecdfdadba","fbefaf","bef","cddbacbdcff","adbfebebcddbdfccdd","abdebbc","fcfeeccecdbefcfe","acaabdcdecea","ddeb","bfedfafefaafbdacaaad","cdcddaddaabcdc","ffdccfad","fbeaeabcad","ecaaedffaaaadadd","adb","fbeeadefeabbbaaff","efbcafedadfdd","faca","ecccfae","aebddfbcdcccfcbcebbfb","acffdebffaadbcfcdcefd","becdbefaaacb","edfbd","fdfabecffdfe","dfbaaeefdebaef","ceeadafde","fcdeecddacf","add","cbcadcfebceafffcabbdc","bfccefbda","eaceedcbcaabaadadba","fbfadfbe","aedceec","dcac","fda","decfcadbcedbcaddacd","aebcabaaecefa","efdfacadbebfedfbecc","fbbc","fbfceeddcad","eacefbacdddcbdeefdfe","fea","debaffddecfaa","dc","afadba","cfaff","ebeee","bdfdddcdaedfd","abdeceafe","efedecedeeefdae","aecbbb","ececabaffdccede","eccacfeabbdceb","ea","dfabaeebeebbcafafec","cbdbefbbba","bfbdfacfebabffa","be","feabdcbffdbfddec","bbeecaba","abdfedecdcdeeafeef","dbbacb","aebbbaceaeecfccfcaeb","bffaffcadf","dfaddcaabbdddffdb","aaacfcecf","accbdfcbbdeffacf","fffabeccbcd","dbadfefdadbaffee","efbebeacebdedbeef","cdeffacc","ecfedbdccecbbaaa","dfedb","eddcfebecb","cffbbbfedcfcd","ebeeaaaabfbfdc","dbaebbbdffdeceea","efc","acaacbdffcfaccbd","bffaeeeeafaaceccd","fbefcccbcdbfbacd","ce","abbfcedefacaeade","daefbbdfeedefcade","aacef","cbc","dabcfccaceaffffaed","debfbcebebcecdf","aaefaeaffdcfbfd","cfdadec","beefcfeddeabe","bbbefcafdfcf","cda","fddbebdcae","ecdffebecdcbabd","dfa","fdaabdccb","beeec","ababfab","ecacb","daaabdbdafdffabb","daecdcecccddacbfdfadd","eeefdfbdabebadeebeefd","dbadabfcfbacdebddfbf","beceefefdfdf","dbcfcbfdcdbbcdcbddba","fbafdbfaebddcabc","deeefbcaff","deabec","bacadeaecbfadaccfefe","edadeeffbfccba","bfabdfffffcfbeaaaf","caafeacc","efaadbbbbf","cbdf","efdadddd","abbfbab","dbdbadcedbc","bfdefcaceabffdebefdba","dcadbdcdafdccbfdcacd","cfaafebcabdb","caefdafa","eafcbcaaffffd","adcfecaaaecdedee","fddcddddca" };
    auto input5 = std::vector<std::string>{ "a","ab","abc","d","cd","bcd","abcd" };

    const auto result = max_len_unique_prod::maxProduct( input4 );

    std::cout << result << std::endl;
	
    return 0;
}