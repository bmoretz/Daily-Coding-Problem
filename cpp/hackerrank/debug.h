#pragma once

#include <stack>
#include <cassert>
#include <random>

#include "problem.h"

namespace hackerrank::debug
{
	struct inherited_code final : problem
	{
		explicit inherited_code( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		struct bad_length_exception final :
			std::runtime_error
		{
			explicit bad_length_exception( const int length )
				: std::runtime_error( std::to_string( length ) )
			{
			}
		};

		static bool check_username( const std::string& username )
		{
			auto is_valid = true;
			const int n = username.length();

			if( n < 5 )
			{
				throw bad_length_exception( n );
			}

			for( auto i = 0; i < n - 1; i++ )
			{
				const auto index = static_cast< int >( i + 1 );

				if( username[ i ] == 'w' && username[ index ] == 'w' )
				{
					is_valid = false;
				}
			}

			return is_valid;
		}

		static int main()
		{
			int t;
			std::cin >> t;

			while( t-- )
			{
				std::string username;
				std::cin >> username;

				try
				{
					const auto is_valid = check_username( username );
					std::cout << ( is_valid ? "Valid" : "Invalid" ) << '\n';
				}
				catch( const bad_length_exception& e )
				{
					std::cout << "Too short: " << e.what() << '\n';
				}
			}

			return 0;
		}
	};

	struct exceptional_server final : problem
	{
		explicit exceptional_server( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class server
		{
			static int load_;

		public:
			static int compute( const long long A, const long long B )
			{
				load_ += 1;
				if( A < 0 )
				{
					throw std::invalid_argument( "A is negative" );
				}

				std::vector<int> v( A, 0 );
				int real = -1, cmplx = sqrt( -1 );
				if( B == 0 ) throw 0;
				real = ( A / B ) * real;
				const auto ans = v.at( B );
				return real + A - B * ans;
			}

			static int get_load()
			{
				return load_;
			}

			static void reset_load()
			{
				load_ = 0;
			}
		};

		static int main()
		{
			int t;
			std::cin >> t;
			while( t-- )
			{
				long long A, B;
				std::cin >> A >> B;

				try
				{
					const auto result = server::compute( A, B );

					std::cout << result << std::endl;
				}
				catch( const std::bad_alloc& )
				{
					std::cout << "Not enough memory" << std::endl;
				}
				catch( const std::out_of_range& )
				{
					std::cout << "Exception: vector::_M_range_check: __n "
						<< "(which is " << B << ")"
						<< " >= this->size() (which is " << A << ")"
						<< std::endl;
				}
				catch( const std::exception& ex )
				{
					std::cout << "Exception: " << ex.what() << std::endl;
				}
				catch( ... )
				{
					std::cout << "Other Exception" << std::endl;
				}
			}

			std::cout << server::get_load() << std::endl;
			server::reset_load();
			return 0;
		}
	};

	int exceptional_server::server::load_ = 0;

	struct hotel_prices final : problem
	{
		explicit hotel_prices( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class hotel_room
		{
		public:
			virtual ~hotel_room() = default;

			hotel_room( const int bedrooms, const int bathrooms )
				: bedrooms_( bedrooms ), bathrooms_( bathrooms )
			{
			}

			virtual int get_price()
			{
				return 50 * bedrooms_ + 100 * bathrooms_;
			}

		private:
			int bedrooms_;
			int bathrooms_;
		};

		class hotel_apartment : public hotel_room
		{
		public:
			
			hotel_apartment( const int bedrooms, const int bathrooms )
				: hotel_room( bedrooms, bathrooms )
			{
			}

			int get_price() override
			{
				return hotel_room::get_price() + 100;
			}
		};

		static int main()
		{
			int n;
			std::cin >> n;
			std::vector<hotel_room*> rooms;
			for( auto i = 0; i < n; ++i )
			{
				std::string room_type;
				int bedrooms;
				int bathrooms;
				std::cin >> room_type >> bedrooms >> bathrooms;
				if( room_type == "standard" )
				{
					rooms.push_back( new hotel_room( bedrooms, bathrooms ) );
				}
				else
				{
					rooms.push_back( new hotel_apartment( bedrooms, bathrooms ) );
				}
			}

			auto total_profit = 0;
			for( auto room : rooms )
			{
				total_profit += room->get_price();
			}

			std::cout << total_profit << std::endl;
			rooms.clear();

			for( auto room : rooms )
				delete room;
			
			return 0;
		}
	};

	struct exception_handling final : problem
	{
		explicit exception_handling( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		static int largest_proper_divisor( const int n )
		{
			if( n == 0 )
				throw std::invalid_argument( "largest proper divisor is not defined for n=0" );

			auto largest = 0;

			for( auto index = n - 1; index > 0; --index )
			{
				const auto result = n % index;

				if( result == 0 )
				{
					largest = index;
					break;
				}
			}

			return largest;
		}

		static void process_input( const int n )
		{
			try
			{
				const auto d = largest_proper_divisor( n );
				std::cout << "result=" << d << std::endl;
			}
			catch( const std::invalid_argument& iae )
			{
				std::cout << iae.what() << std::endl;
			}

			std::cout << "returning control flow to caller" << std::endl;
		}

		static int main() {
			int n;
			std::cin >> n;
			process_input( n );
			return 0;
		}
	};

	struct override_ostream final : problem
	{
		explicit override_ostream( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

		class person {
		public:
			person( std::string first_name, std::string last_name ) :
				first_name_{ std::move( first_name ) },
				last_name_{ std::move( last_name ) }
			{}

			const std::string& get_first_name() const {
				return first_name_;
			}

			const std::string& get_last_name() const {
				return last_name_;
			}

			friend std::ostream& operator<<( std::ostream& os, const person& person )
			{
				os << "first_name=" << person.get_first_name() << ","
					<< "last_name=" << person.get_last_name();

				return os;
			}

		private:
			std::string first_name_;
			std::string last_name_;
		};

		int main()
		{
			std::string first_name, last_name, event;
			std::cin >> first_name >> last_name >> event;
			const auto p = person( first_name, last_name );
			std::cout << p << " " << event << std::endl;
			return 0;
		}
	};
	
	struct message_factory final : problem
	{
		explicit message_factory( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class message {
			std::string text_;
			int order_;
		public:

			explicit message( std::string text, const int order ) :
				text_{ std::move( text ) }, order_{ order }
			{}

			const std::string& get_text() const {
				return text_;
			}

			bool operator <( const message& other ) const
			{
				return this->order_ < other.order_;
			}
		};

		class msg_factory
		{
			int counter_;

		public:
			explicit msg_factory()
				: counter_{ }
			{ }

			message create_message( const std::string& text ) {
				return message{ text, ++counter_ };
			}
		};

		class recipient {
		public:
			recipient() {}

			void receive( const message& msg ) {
				messages_.push_back( msg );
			}

			void print_messages() {
				fix_order();
				for( auto& msg : messages_ ) {
					std::cout << msg.get_text() << std::endl;
				}
				messages_.clear();
			}
		private:
			void fix_order() {
				std::sort( messages_.begin(), messages_.end() );
			}
			std::vector<message> messages_;
		};

		class network {
		public:
			static void send_messages( std::vector<message> messages, recipient& recipient ) {
				// simulates the unpredictable network, where sent messages might arrive in unspecified order
				const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
				std::default_random_engine e( seed );

				std::shuffle( messages.begin(), messages.end(), e );

				for( const auto& msg : messages ) {
					recipient.receive( msg );
				}
			}
		};

		static int main()
		{
			msg_factory message_factory;
			recipient recipient;
			std::vector<message> messages;
			std::string text;

			while( getline( std::cin, text ) ) {
				messages.push_back( message_factory.create_message( text ) );
			}

			network::send_messages( messages, recipient );
			recipient.print_messages();

			return 0;
		}
	};
}