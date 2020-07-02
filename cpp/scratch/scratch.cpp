#include <bits/stdc++.h>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct box_it final : problem
{
	explicit box_it( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}


	// The class should have the following functions : 

	//Implement the class Box  
	//l,b,h are integers representing the dimensions of the box
	class Box
	{
		int l_, b_, h_;

	public:

		Box()
		{

		}

		Box( const int l, const int b, const int h )
			: l_{ l }, b_{ b }, h_{ h }
		{
		}

		// Constructors: 
		// Box();
		// Box(int,int,int);
		// Box(Box);
		Box( const Box& other )
			: l_{ other.l_ },
			b_{ other.b_ },
			h_{ other.h_ }
		{ }

		// int getLength(); // Return box's length
		int getLength() const { return l_; }
		// int getBreadth (); // Return box's breadth
		int getBreath() const { return b_; }
		// int getHeight ();  //Return box's height
		int getHeight() const { return h_; }
		// long long CalculateVolume(); // Return the volume of the box	
		long long CalculateVolume() const
		{
			return l_ * b_ * h_;
		}

		//Overload operator < as specified
		//bool operator<(Box& b)		
		bool operator<( const Box& b )
		{
			return CalculateVolume() < b.CalculateVolume();
		}

		//Overload operator << as specified
		//ostream& operator<<(ostream& out, Box& B)
		friend std::ostream& operator<<( std::ostream& out, const Box& other );
	};
	
	void check2()
	{
		int n;
		std::cin >> n;
		Box temp;
		for( int i = 0; i < n; i++ )
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
				Box NewBox( l, b, h );
				temp = NewBox;
				std::cout << temp << std::endl;
			}
			if( type == 3 )
			{
				int l, b, h;
				std::cin >> l >> b >> h;
				Box NewBox( l, b, h );
				if( NewBox < temp )
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
				Box NewBox( temp );
				std::cout << NewBox << std::endl;
			}

		}
	}

	int main()
	{
		check2();

		return 0;
	}
};

std::ostream& operator<<( std::ostream& out, const box_it::Box& other )
{
	out << other.getLength() << " " << other.getBreath() << " " << other.getHeight();

	return out;
}

auto main() -> int
{
	const auto problem =
		box_it{"box-it-testcases"};

	return problem.run();
}
