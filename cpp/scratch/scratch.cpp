#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct magic_spells final : problem
{
	explicit magic_spells( std::string&& name )
		: problem( std::move( name ) )
	{
		entry_point = [this]() { return main(); };
	}

	class spell
	{
		std::string scroll_name_{};

	public:

		spell() = default;

		explicit spell( std::string name ) :
			scroll_name_(std::move(name))
		{ }

		virtual ~spell() {}

		std::string reveal_scroll_name() const
		{
			return scroll_name_;
		}
	};

	class fireball final : public spell
	{
		int power_;
	public:

		explicit fireball( const int power ) : power_( power )
		{
		}

		void reveal_fire_power() const
		{
			std::cout << "Fireball: " << power_ << std::endl;
		}
	};

	class frostbite final : public spell
	{
		int power_;
	public:
		explicit frostbite( const int power ) : power_( power )
		{
		}

		void reveal_frost_power() const
		{
			std::cout << "Frostbite: " << power_ << std::endl;
		}
	};

	class thunderstorm final : public spell
	{
		int power;
	public:
		explicit thunderstorm( const int power ) : power( power )
		{ }

		void reveal_thunder_power() const
		{
			std::cout << "Thunderstorm: " << power << std::endl;
		}
	};

	class waterbolt final : public spell
	{
		int power_;

	public:

		explicit waterbolt( const int power ) : power_( power )
		{ }

		void reveal_water_power() const
		{
			std::cout << "Waterbolt: " << power_ << std::endl;
		}
	};

	class spell_journal
	{
	public:
		static std::string journal;

		static std::string read()
		{
			return journal;
		}
	};
	
	void counter_spell( spell* spell )
	{
		if( dynamic_cast< fireball* >( spell ) != nullptr )
		{
			dynamic_cast< fireball* >( spell )->reveal_fire_power();
		}
		else if( dynamic_cast< frostbite* >( spell ) != nullptr )
		{
			dynamic_cast< frostbite* >( spell )->reveal_frost_power();
		}
		else if( dynamic_cast< waterbolt* >( spell ) != nullptr )
		{
			dynamic_cast< waterbolt* >( spell )->reveal_water_power();
		}
		else if( dynamic_cast< thunderstorm* >( spell ) != nullptr )
		{
			dynamic_cast< thunderstorm* >( spell )->reveal_thunder_power();
		}
		else
		{
			auto spell_name = spell->reveal_scroll_name();
			auto journal = spell_journal::read();
			
			std::vector<std::vector<int> > dp( spell_name.size() + 1, std::vector<int>( journal.size() + 1 ) );
			for( auto i = 1; i <= spell_name.size(); i++ )
			{
				for( auto j = 1; j <= journal.size(); j++ )
				{
					if( spell_name[ i - 1 ] == journal[ j - 1 ] )
						dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ];
					else
						dp[ i ][ j ] = std::max( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] );
				}
			}
			
			std::cout << dp[ spell_name.size() ][ journal.size() ] << std::endl;
		}
	}

	class wizard
	{
	public:
		spell* cast()
		{
			spell* current;
			std::string s;
			std::cin >> s;
			int power;
			std::cin >> power;
			
			if( s == "fire" )
			{
				current = new fireball( power );
			}
			else if( s == "frost" )
			{
				current = new frostbite( power );
			}
			else if( s == "water" )
			{
				current = new waterbolt( power );
			}
			else if( s == "thunder" )
			{
				current = new thunderstorm( power );
			}
			else
			{
				current = new spell( s );
				std::cin >> spell_journal::journal;
			}
			
			return current;
		}
	};

	int main()
	{
		int n;
		std::cin >> n;
		wizard arawn;

		while( n-- )
		{
			const auto spell = arawn.cast();
			counter_spell( spell );
		}

		return 0;
	}
};

std::string magic_spells::spell_journal::journal = "";

auto main() -> int
{
	const auto problem =
		magic_spells{"magic-spells-testcases"};

	return problem.run();
}
