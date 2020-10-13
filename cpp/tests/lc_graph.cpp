#include "pch.h"
#include <gtest/gtest.h>

#include "../leetcode/graph.h"

namespace leetcode::graph::tests
{
    class reconstruct_itinerary_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( reconstruct_itinerary_tests, case1 )
    {
        const auto input1 = std::vector<std::vector<std::string>>
        {
            { "MUC", "LHR" },
            { "JFK", "MUC" },
            { "SFO", "SJC" },
            { "LHR", "SFO" }
        };

        const auto actual = reconstruct_itinerary::find_itinerary( input1 );
    	
        const auto expected = std::vector<std::string>
        {
        	"JFK",
        	"MUC",
        	"LHR",
        	"SFO",
        	"SJC"
        };
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( reconstruct_itinerary_tests, case2 )
    {
        const auto input1 = std::vector<std::vector<std::string>>
        {
            { "MUC", "LHR" },
            { "JFK", "MUC" },
            { "SFO", "SJC" },
            { "LHR", "SFO" }
        };

        const auto actual = reconstruct_itinerary::find_itinerary( input1 );

        const auto expected = std::vector<std::string>
        {
        	"JFK",
        	"MUC",
        	"LHR",
        	"SFO",
        	"SJC"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reconstruct_itinerary_tests, case3 )
    {
        const auto input = std::vector<std::vector<std::string>>
        {
            { "JFK", "KUL" },
            { "JFK", "NRT" },
            { "NRT", "JFK"}
        };
    	
        const auto actual = reconstruct_itinerary::find_itinerary( input );

        const auto expected = std::vector<std::string>
        {
        	"JFK",
        	"NRT",
        	"JFK",
        	"KUL"
        };

        EXPECT_EQ( actual, expected );
    }

    TEST_F( reconstruct_itinerary_tests, case4 )
    {
        const auto input = std::vector<std::vector<std::string>>
        {
            { "EZE", "AXA" },
            { "TIA", "ANU" },
            { "ANU", "JFK" },
            { "JFK", "ANU" },
            { "ANU", "EZE" },
            { "TIA", "ANU" },
            { "AXA", "TIA" },
            { "TIA", "JFK" },
            { "ANU", "TIA" },
            { "JFK", "TIA" }
        };

        const auto actual = reconstruct_itinerary::find_itinerary( input );

        const auto expected = std::vector<std::string>
        {
        	"JFK",
        	"ANU",
        	"EZE",
        	"AXA",
        	"TIA",
        	"ANU",
        	"JFK",
        	"TIA",
        	"ANU",
        	"TIA",
        	"JFK"
        };

        EXPECT_EQ( actual, expected );
    }

    class word_ladder_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( word_ladder_tests, case1 )
    {
        const auto input = std::tuple<std::string, std::string, std::vector<std::string>>
        {
            "hit", "cog",
            { "hot", "dot", "dog", "lot", "log", "cog" }
        };

        const auto actual = word_ladder::ladder_length( std::get<0>( input ), std::get<1>( input ), std::get<2>( input ) );
        const auto expected = 5;
    	
        EXPECT_EQ( actual, expected );
    }

    TEST_F( word_ladder_tests, case2 )
    {
        const auto input = std::tuple<std::string, std::string, std::vector<std::string>>
        {
            "hit", "pog",
            { "hot", "dot", "dog", "lot", "log", "cog", "pog" }
        };

        const auto actual = word_ladder::ladder_length( std::get<0>( input ), std::get<1>( input ), std::get<2>( input ) );
        const auto expected = 5;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( word_ladder_tests, case3 )
    {
        const auto input = std::tuple<std::string, std::string, std::vector<std::string>>
        {
            "hit", "zog",
            { "hot", "dot", "dog", "lot", "log", "cog", "pog", "poz" }
        };

        const auto actual = word_ladder::ladder_length( std::get<0>( input ), std::get<1>( input ), std::get<2>( input ) );
        const auto expected = 0;

        EXPECT_EQ( actual, expected );
    }


    TEST_F( word_ladder_tests, case4 )
    {
        const auto input = std::tuple<std::string, std::string, std::vector<std::string>>
        {
            "hit", "poz",
            { "hot", "dot", "dog", "lot", "log", "cog", "pog", "poz" }
        };

        const auto actual = word_ladder::ladder_length( std::get<0>( input ), std::get<1>( input ), std::get<2>( input ) );
        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    class word_ladder_ii_tests :
        public ::testing::Test {

    protected:
        void SetUp() override
        {
        }

        void TearDown() override
        {
        }
    };

    TEST_F( word_ladder_ii_tests, case1 )
    {
        const auto input = std::tuple<std::string, std::string, std::vector<std::string>>
        {
            "hit", "cog",
            { "hot", "dot", "dog", "lot", "log", "cog" }
        };

        const auto actual = word_ladder_ii::find_ladders( std::get<0>( input ), std::get<1>( input ), std::get<2>( input ) );

    	const auto expected = std::vector<std::vector<std::string>>
    	{
            { "hit","hot","dot","dog","cog" },
            { "hit","hot","lot","log","cog" }
        };

        EXPECT_EQ( actual, expected );
    }

    class course_schedule_tests :
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

    TEST_F( course_schedule_tests, case1 )
    {
        const auto prereqs = std::vector<std::vector<int>>
        {
            {0, 1}
        };

        const auto actual = course_schedule::can_finish( 2, prereqs );

        const auto expected = true;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( course_schedule_tests, case2 )
    {
        const auto prereqs = std::vector<std::vector<int>>
        {
            {1, 0},
            {0, 1}
        };

        const auto actual = course_schedule::can_finish( 2, prereqs );

        const auto expected = false;

        EXPECT_EQ( actual, expected );
    }

    class trim_forest_tests :
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

    TEST_F( trim_forest_tests, case1 )
    {
        const auto input = std::vector<std::vector<int>>
        {
            {1, 2, 3},
            {0, 0, 4},
            {7, 6, 5}
        };

        const auto actual = trim_forest::cut_off_trees( input );

        const auto expected = 6;

        EXPECT_EQ( actual, expected );
    }

    TEST_F( trim_forest_tests, case2 )
    {
        const auto input = std::vector<std::vector<int>>
        {
	        {65373036,2456655,62996182,77165169,11057485,52535331,63698310,27129253,84289874},
	        {18570009,29409292,57221123,27322139,5967050,25641409,59807085,41287955,67002016},
	        {59925393,84342153,95847740,96720219,95877289,6633239,96769252,68980562,99717888},
	        {38092644,69430191,46393504,75242757,38524238,92687163,72390599,86031769,97616262},
	        {63895259,13582559,38270398,10833444,47844868,78209342,89000764,505213,82251326},
	        {99638437,70547733,81264676,80087375,33825268,19488243,21385757,13931827,81384999},
	        {78687499,27054031,82935633,59857240,16454994,14764718,15186553,54119613,24432831},
	        {66192618,83872603,19246010,82241107,14604727,65304619,98680361,48033577,56249633},
	        {82869596,12875294,85175067,6220745,31624067,97537659,73504597,90040176,90033521}
        };

        const auto actual = trim_forest::cut_off_trees( input );

        const auto expected = 496;

        EXPECT_EQ( actual, expected );
    }
}