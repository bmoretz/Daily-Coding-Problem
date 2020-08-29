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
}