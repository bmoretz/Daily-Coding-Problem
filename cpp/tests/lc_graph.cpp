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
}