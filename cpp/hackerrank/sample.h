#pragma once

#include <sstream>
#include <stack>
#include <memory>
#include <cassert>

#include "problem.h"

namespace hackerrank::sample
{
	/// <summary>
	/// some simple problems that I use to test the problem
	/// solving framework.
	/// </summary>
	///
	/// 
	struct tutorial_string_stream final : problem
	{
		using problem::problem;

		explicit tutorial_string_stream(std::string&& name) :
			problem(std::move(name))
		{
			entry_point = []() { return main(); };
		}

		static std::vector<int> parse_integers(const std::string& str)
		{
			std::istringstream iss(str);
			std::vector<int> results;
			std::string integer;

			while (std::getline(iss, integer, ','))
				results.emplace_back(std::stoi(integer));

			return results;
		}

		static int main()
		{
			std::string str;
			std::cin >> str;
			auto integers = parse_integers(str);

			for (auto integer : integers)
			{
				std::cout << integer << "\n";
			}

			return 0;
		}
	};

	struct tutorial_string final : problem
	{
		explicit tutorial_string(std::string&& name)
			: problem(std::move(name))
		{
			entry_point = [this]() { return main(); };
		}

		int main()
		{
			std::string a, b;

			std::getline(std::cin, a);
			std::getline(std::cin, b);

			std::cout << a.size() << " " << b.size() << std::endl;
			std::cout << a + b << std::endl;

			std::swap(a[0], b[0]);
			std::cout << a << " " << b << std::endl;

			return 0;
		}
	};

	struct tutorial_struct final : problem
	{
		explicit tutorial_struct(std::string&& name)
			: problem(std::move(name))
		{
			entry_point = [this]() { return main(); };
		}

		struct student
		{
			int age;
			std::string first_name, last_name;
			int standard;
		};

		int main()
		{
			student st;

			std::cin >> st.age >> st.first_name >> st.last_name >> st.standard;
			std::cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

			return 0;
		}
	};

	struct box_it final : problem
	{
		explicit box_it( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}


		// The class should have the following functions : 

		using box_size = unsigned long long;

		//Implement the class Box  
		//l,b,h are integers representing the dimensions of the box
		class box
		{
			box_size l_{}, b_{}, h_{};

		public:

			box() { }

			box( const box_size l, const box_size b, const box_size h )
				: l_{ l }, b_{ b }, h_{ h }
			{
			}

			// Constructors: 
			// Box();
			// Box(int,int,int);
			// Box(Box);
			box( const box& other ) = default;

			// int getLength(); // Return box's length
			box_size getLength() const { return l_; }
			// int getBreadth (); // Return box's breadth
			box_size getBreath() const { return b_; }
			// int getHeight ();  //Return box's height
			box_size getHeight() const { return h_; }

			// long long CalculateVolume(); // Return the volume of the box	
			box_size CalculateVolume() const
			{
				return l_ * b_ * h_;
			}

			//Overload operator < as specified
			//bool operator<(Box& b)		
			bool operator<( const box& b )
			{
				return
					( l_ < b.l_ ) ||
					( b_ < b.b_&& l_ == b.l_ ) ||
					( h_ < b.h_&& b_ == b.b_ && l_ == b.l_ );
			}

			//Overload operator << as specified
			//ostream& operator<<(ostream& out, Box& B)
			friend std::ostream& operator<<( std::ostream& out, const box& other );
		};

		void check2()
		{
			int n;
			std::cin >> n;
			box temp;
			for( auto i = 0; i < n; i++ )
			{
				int type;
				std::cin >> type;
				if( type == 1 )
				{
					std::cout << temp << std::endl;
				}
				if( type == 2 )
				{
					int l, b, h;
					std::cin >> l >> b >> h;
					const box NewBox( l, b, h );
					temp = NewBox;
					std::cout << temp << std::endl;
				}
				if( type == 3 )
				{
					int l, b, h;
					std::cin >> l >> b >> h;
					box new_box( l, b, h );
					if( new_box < temp )
					{
						std::cout << "Lesser\n";
					}
					else
					{
						std::cout << "Greater\n";
					}
				}
				if( type == 4 )
				{
					std::cout << temp.CalculateVolume() << std::endl;
				}
				if( type == 5 )
				{
					const auto& new_box( temp );
					std::cout << new_box << std::endl;
				}
			}
		}

		int main()
		{
			check2();

			return 0;
		}
	};

	inline std::ostream& operator<<(std::ostream& out, const box_it::box& other)
	{
		out << other.getLength() << " " << other.getBreath() << " " << other.getHeight();

		return out;
	}

	struct fizz_buzz final : problem
	{
		explicit fizz_buzz( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

		void fizzBuzz( const int n )
		{
			for( auto index = 1; index < n + 1; ++index )
			{
				if( index % 3 == 0 )
					std::cout << "Fizz";

				if( index % 5 == 0 )
					std::cout << "Buzz";

				if( index % 3 != 0 && index % 5 != 0 )
					std::cout << index;

				std::cout << std::endl;
			}
		}

		int main()
		{
			std::string n_temp;
			std::getline( std::cin, n_temp );

			const auto n = std::stoi( ltrim( rtrim( n_temp ) ) );

			fizzBuzz( n );

			return 0;
		}

		std::string ltrim( const std::string& str ) {
			auto s( str );

			return s.erase( 0, s.find_first_not_of( ' ' ) );;
		}

		std::string rtrim( const std::string& str ) {
			auto s( str );

			return s.substr( s.find_first_not_of( ' ' ) );;
		}
	};

	struct inheritance final : problem
	{
		explicit inheritance( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class Triangle {
		public:
			
			void triangle() {
				std::cout << "I am a triangle\n";
			}

			virtual void description() = 0;
		};

		class Isosceles : public Triangle {
		public:
			
			void isosceles() {
				std::cout << "I am an isosceles triangle\n";
			}

			void description() override
			{
				std::cout << "In an isosceles triangle two sides are equal" << std::endl;
			}
		};

		static int main() {
			Isosceles isc;
			isc.isosceles();
			isc.description();
			isc.triangle();
			return 0;
		}
	};

	struct ra_inheritance final : problem
	{
		explicit ra_inheritance( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

		class rectangle
		{
		protected:
			int width_ = 0, height_ = 0;

		public:
			virtual ~rectangle() = default;

			virtual void read_input() = 0;
			virtual void display()
			{
				std::cout << width_ << " " << height_ << std::endl;
			}
		};

		class rectangle_area : public rectangle
		{
		public:
			void read_input() override
			{
				std::cin >> width_ >> height_;
			}

			void display() override
			{
				std::cout << width_ * height_ << std::endl;
			}
		};

		int main() {
			rectangle_area r_area;

			r_area.read_input();
			r_area.rectangle::display();
			r_area.display();

			return 0;
		}
	};

	struct mult_inheritance final : problem
	{
		explicit mult_inheritance( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

		class tri {
		public:
			void triangle() {
				std::cout << "I am a triangle\n";
			}
		};

		class iso : public tri {
		public:
			void isosceles() {
				std::cout << "I am an isosceles triangle" << std::endl;
			}
		};

		class equ : public iso
		{
		public:
			void equilateral()
			{
				std::cout << "I am an equilateral triangle" << std::endl;
			}
		};

		int main() {
			equ eqr;
			eqr.equilateral();
			eqr.isosceles();
			eqr.triangle();

			return 0;
		}
	};
}
