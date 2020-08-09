#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/bitmanip.h"

namespace leetcode::bitmanip::tests
{
	class max_len_unique_prod_tests :
		public testing::Test
	{
	protected:
		void SetUp() override
		{
		}

		void TearDown() override
		{
		}
	};

	TEST_F( max_len_unique_prod_tests, case1 )
	{
		const auto input = std::vector<std::string>{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };

		const auto actual = max_len_unique_prod::max_product( input );

		const auto expected = 16;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( max_len_unique_prod_tests, case2 )
	{
		const auto input = std::vector<std::string>{ "a", "ab", "abc", "d", "cd", "bcd", "abcd" };

		const auto actual = max_len_unique_prod::max_product( input );

		const auto expected = 4;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( max_len_unique_prod_tests, case3 )
	{
		const auto input = std::vector<std::string>{ "a", "aa", "aaa", "aaaa" };

		const auto actual = max_len_unique_prod::max_product( input );

		const auto expected = 0;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( max_len_unique_prod_tests, case4 )
	{
		const auto input = std::vector<std::string>{
			"aebacbcecdcdaffdacbac", "afdffdaffacccaba", "fffaafccebbacffaddcad", "eefaffbddcbdabacda", "fcfbeecccc",
			"afdbeabfcedfadaddb", "bfdafdfdbbdaabba", "acaeabcddfaafadfcacd", "bcdfbfeadfdbdcf", "cebabfbadfcbc",
			"eefddeafbadfab", "fdccabcebbfeedbabdad", "bdabacbeecfdffbaa", "dbbc", "cfcfebfdeafdaceacfb", "ec",
			"bcaafadfe", "abbfecdcafecccd", "ec", "edededdbdcefcf", "edfcecdafcfaaab", "ebfbfdcacd", "dada",
			"bfeffcafdfccdcbaba", "dab", "ebcadee", "bbcdeacdcfdabfbadd", "eadcdcb", "cabebee", "bcdabeffafbbdd",
			"adacbacacfef", "cfe", "cbbfecfefaf", "ddfcfefcadfccdfffaef", "ab", "edadcf", "eedbcabeddbaeeead",
			"fddaddedefebaecdde", "cfeb", "eaeadebbf", "fbdffebe", "fecebacba", "cccaadfdfdeafde", "defbcceab", "adee",
			"caaddeaade", "bbeeecae", "bce", "ccdcafc", "aecaadaeb", "cebcbacdbec", "fccedeacec", "cacdafefcdff",
			"dbaebafaba", "dbfafefbfef", "dadeecaecdfefbd", "bded", "ffbeecfed", "bacc", "ebdeffba", "fceec",
			"badcaefccdf", "aadbbccbecf", "cdffafdaefdaaeebe", "efbfcdbec", "decaebfdddfcdfda", "ccbbcee", "ceceffbfab",
			"bdbfabaafa", "eaeabaefbaed", "efbcdbdadbafefcfe", "ab", "acefcdaadccebcef", "fcda", "ff", "eedaabecf",
			"eecbdacaedab", "ad", "ebddccbcabc", "dacad", "fcffdecbaeefcfd", "edadacdbabffbeafffdb", "daef",
			"efbfcfbbdcccaa", "bbebdca", "edb", "febfffac", "aefbdfbbdebfebfebfbd", "becbacdffebfecdfdadba", "fbefaf",
			"bef", "cddbacbdcff", "adbfebebcddbdfccdd", "abdebbc", "fcfeeccecdbefcfe", "acaabdcdecea", "ddeb",
			"bfedfafefaafbdacaaad", "cdcddaddaabcdc", "ffdccfad", "fbeaeabcad", "ecaaedffaaaadadd", "adb",
			"fbeeadefeabbbaaff", "efbcafedadfdd", "faca", "ecccfae", "aebddfbcdcccfcbcebbfb", "acffdebffaadbcfcdcefd",
			"becdbefaaacb", "edfbd", "fdfabecffdfe", "dfbaaeefdebaef", "ceeadafde", "fcdeecddacf", "add",
			"cbcadcfebceafffcabbdc", "bfccefbda", "eaceedcbcaabaadadba", "fbfadfbe", "aedceec", "dcac", "fda",
			"decfcadbcedbcaddacd", "aebcabaaecefa", "efdfacadbebfedfbecc", "fbbc", "fbfceeddcad",
			"eacefbacdddcbdeefdfe", "fea", "debaffddecfaa", "dc", "afadba", "cfaff", "ebeee", "bdfdddcdaedfd",
			"abdeceafe", "efedecedeeefdae", "aecbbb", "ececabaffdccede", "eccacfeabbdceb", "ea", "dfabaeebeebbcafafec",
			"cbdbefbbba", "bfbdfacfebabffa", "be", "feabdcbffdbfddec", "bbeecaba", "abdfedecdcdeeafeef", "dbbacb",
			"aebbbaceaeecfccfcaeb", "bffaffcadf", "dfaddcaabbdddffdb", "aaacfcecf", "accbdfcbbdeffacf", "fffabeccbcd",
			"dbadfefdadbaffee", "efbebeacebdedbeef", "cdeffacc", "ecfedbdccecbbaaa", "dfedb", "eddcfebecb",
			"cffbbbfedcfcd", "ebeeaaaabfbfdc", "dbaebbbdffdeceea", "efc", "acaacbdffcfaccbd", "bffaeeeeafaaceccd",
			"fbefcccbcdbfbacd", "ce", "abbfcedefacaeade", "daefbbdfeedefcade", "aacef", "cbc", "dabcfccaceaffffaed",
			"debfbcebebcecdf", "aaefaeaffdcfbfd", "cfdadec", "beefcfeddeabe", "bbbefcafdfcf", "cda", "fddbebdcae",
			"ecdffebecdcbabd", "dfa", "fdaabdccb", "beeec", "ababfab", "ecacb", "daaabdbdafdffabb",
			"daecdcecccddacbfdfadd", "eeefdfbdabebadeebeefd", "dbadabfcfbacdebddfbf", "beceefefdfdf",
			"dbcfcbfdcdbbcdcbddba", "fbafdbfaebddcabc", "deeefbcaff", "deabec", "bacadeaecbfadaccfefe",
			"edadeeffbfccba", "bfabdfffffcfbeaaaf", "caafeacc", "efaadbbbbf", "cbdf", "efdadddd", "abbfbab",
			"dbdbadcedbc", "bfdefcaceabffdebefdba", "dcadbdcdafdccbfdcacd", "cfaafebcabdb", "caefdafa", "eafcbcaaffffd",
			"adcfecaaaecdedee", "fddcddddca"
		};

		const auto actual = max_len_unique_prod::max_product( input );

		const auto expected = 50;

		EXPECT_EQ( actual, expected );
	}

	TEST_F( max_len_unique_prod_tests, case5 )
	{
		const auto input = std::vector<std::string>{ "a", "ab", "abc", "d", "cd", "bcd", "abcd" };

		const auto actual = max_len_unique_prod::max_product( input );

		const auto expected = 4;

		EXPECT_EQ( actual, expected );
	}
}