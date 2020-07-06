#include <bits/stdc++.h>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct hotel_prices final : problem
{
    explicit hotel_prices( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    class HotelRoom {
    public:
        HotelRoom( int bedrooms, int bathrooms )
            : bedrooms_( bedrooms ), bathrooms_( bathrooms ) {}

        virtual int get_price() {
            return 50 * bedrooms_ + 100 * bathrooms_;
        }
    	
    private:
        int bedrooms_;
        int bathrooms_;
    };

    class HotelApartment : public HotelRoom {
    public:
        HotelApartment( int bedrooms, int bathrooms )
            : HotelRoom( bedrooms, bathrooms ) {}

		int get_price() override	
        {
            return HotelRoom::get_price() + 100;
        }
    };

    int main() {
        int n;
        std::cin >> n;
        std::vector<HotelRoom*> rooms;
        for( auto i = 0; i < n; ++i ) {
            std::string room_type;
            int bedrooms;
            int bathrooms;
            std::cin >> room_type >> bedrooms >> bathrooms;
            if( room_type == "standard" ) {
                rooms.push_back( new HotelRoom( bedrooms, bathrooms ) );
            }
            else {
                rooms.push_back( new HotelApartment( bedrooms, bathrooms ) );
            }
        }

        auto total_profit = 0;
        for( auto room : rooms ) {
            total_profit += room->get_price();
        }

        std::cout << total_profit << std::endl;

        for( auto room : rooms ) {
            delete room;
        }

        rooms.clear();

        return 0;
    }
};

auto main() -> int
{
	const auto problem =
		hotel_prices{"hotel-prices-testcases"};

	return problem.run();
}