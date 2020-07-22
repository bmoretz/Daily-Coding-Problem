#pragma once

#include "problem.h"

namespace hackerrank::lang
{
	struct cpp_template final : problem
	{
		explicit cpp_template( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		template <class T>
		class floating
		{
			T value_;

		public:
			explicit floating( T val )
			{
				value_ = val;
			}

			T add( T other ) const
			{
				return value_ + other;
			}
		};

		template <>
		class floating<int>
		{
			int value_;

		public:
			explicit floating( const int val ) { value_ = val; }

			[[nodiscard]] int add( const int other ) const
			{
				return value_ + other;
			}
		};

		template <>
		class floating<std::string>
		{
			std::string value_;

		public:

			explicit floating( const std::string& val )
			{
				value_ = val;
			}

			std::string concatenate( const std::string& other )
			{
				return value_.append( other );
			}
		};

		static int main()
		{
			int n;
			std::cin >> n;

			for( auto index = 0; index < n; index++ )
			{
				std::string type;
				std::cin >> type;

				if( type == "float" )
				{
					double element1, element2;
					std::cin >> element1 >> element2;

					floating<double> floating( element1 );
					std::cout << floating.add( element2 ) << std::endl;
				}
				else if( type == "int" )
				{
					int element1, element2;
					std::cin >> element1 >> element2;
					floating<int> integer( element1 );
					std::cout << integer.add( element2 ) << std::endl;
				}
				else if( type == "string" )
				{
					std::string element1, element2;
					std::cin >> element1 >> element2;
					floating<std::string> str( element1 );
					std::cout << str.concatenate( element2 ) << std::endl;
				}
			}

			return 0;
		}
	};

	struct cpp_preprocessor final : problem
	{
		explicit cpp_preprocessor( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = [this]() { return main(); };
		}

#define toStr(x) #x
#define io(s) std::cin >> s
#define foreach(list, index) for(int index = 0; index < list.size(); index++)
#define FUNCTION(name, op) void name(int &x, int y){ if(!(x op y)) x = y; }
#define INF 1e9

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

		FUNCTION( minimum, < )
			FUNCTION( maximum, > )

		int main()
		{
			int n;
			std::cin >> n;
			std::vector<int> v( n );

			foreach( v, i )
			{
				io( v )[ i ];
			}

			int mn = INF;
			int mx = -INF;

			foreach( v, i )
			{
				minimum( mn, v[ i ] );
				maximum( mx, v[ i ] );
			}

			const auto ans = mx - mn;
			std::cout << toStr( Result = ) << ' ' << ans;
			return 0;
		}
	};

	struct cpp_operator_overloading final : problem
	{
		explicit cpp_operator_overloading( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class matrix
		{
		public:
			std::vector<std::vector<int>> a;

			matrix() = default;

			matrix( const int rows, const int cols )
			{
				a.resize( rows );

				for( auto row = 0; row < rows; ++row )
				{
					a[ row ].resize( cols );
				}
			}

			matrix operator+( const matrix& other )
			{
				const auto rows = a.size(), cols = a[ 0 ].size();
				matrix result( rows, cols );

				for( auto row = 0; row < rows; ++row )
				{
					for( auto col = 0; col < cols; ++col )
					{
						result.a[ row ][ col ] = a[ row ][ col ] + other.a[ row ][ col ];
					}
				}

				return result;
			}
		};

		static int main()
		{
			int cases;
			std::cin >> cases;
			for( auto k = 0; k < cases; k++ )
			{
				matrix x;
				matrix y;
				matrix result;
				int n, m, i, j;
				std::cin >> n >> m;
				for( i = 0; i < n; i++ )
				{
					std::vector<int> b;
					int num;
					for( j = 0; j < m; j++ )
					{
						std::cin >> num;
						b.push_back( num );
					}
					x.a.push_back( b );
				}
				for( i = 0; i < n; i++ )
				{
					std::vector<int> b;
					int num;
					for( j = 0; j < m; j++ )
					{
						std::cin >> num;
						b.push_back( num );
					}
					y.a.push_back( b );
				}
				result = x + y;
				for( i = 0; i < n; i++ )
				{
					for( j = 0; j < m; j++ )
					{
						std::cout << result.a[ i ][ j ] << " ";
					}
					std::cout << std::endl;
				}
			}

			return 0;
		}
	};

	struct overload_operators final : problem
	{
		explicit overload_operators( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		class complex
		{
		public:
			int a, b;

			complex() = default;

			complex( const int r, const int i )
			{
				a = r;
				b = i;
			}

			void input( const std::string& s )
			{
				auto v1 = 0;
				auto i = 0;

				while( s[ i ] != '+' )
				{
					v1 = v1 * 10 + s[ i ] - '0';
					i++;
				}

				while( s[ i ] == ' ' || s[ i ] == '+' || s[ i ] == 'i' )
				{
					i++;
				}

				auto v2 = 0;

				while( i < s.length() )
				{
					v2 = v2 * 10 + s[ i ] - '0';
					i++;
				}

				a = v1;
				b = v2;
			}

			complex operator+( const complex& other ) const
			{
				return complex( a + other.a, ( b + other.b ) );
			}

			friend std::ostream& operator<<( std::ostream& os, const complex& obj )
			{
				os << obj.a << "+i" << obj.b;

				return os;
			}
		};

		static int main()
		{
			complex x{};
			complex y{};
			
			std::string s1, s2;
			std::cin >> s1;
			std::cin >> s2;
			x.input( s1 );
			y.input( s2 );

			const auto z = x + y;
			std::cout << z << std::endl;

			return 0;
		}
	};

	struct workshop_optimization final : problem
	{
		explicit workshop_optimization( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		struct workshop
		{
			int end_time;
			int start_time;
			int duration;

			bool operator<( const workshop& r ) const
			{
				return end_time < r.end_time;
			}
		};

		struct available_workshops
		{
			int n;
			workshop* a;
		};

		static available_workshops* initialize( const int* start_time, const int* duration, const int n )
		{
			const auto ptr = new available_workshops;
			ptr->n = n;
			ptr->a = new workshop[ n ];

			for( auto i = 0; i < n; i++ )
			{
				ptr->a[ i ].start_time = start_time[ i ];
				ptr->a[ i ].duration = duration[ i ];
				ptr->a[ i ].end_time = start_time[ i ] + duration[ i ];
			}

			return ptr;
		}

		static int calculate_max_workshops( available_workshops* ptr )
		{
			std::sort( ptr->a, ptr->a + ptr->n );
			auto m = 1;
			auto end_time = ptr->a[ 0 ].end_time;

			for( auto i = 1; i < ptr->n; i++ )
			{
				if( ptr->a[ i ].start_time >= end_time )
				{
					m += 1;
					end_time = ptr->a[ i ].end_time;
				}
			}

			return m;
		}

		static int main()
		{
			int n;
			std::cin >> n;
			const auto start_time = new int[ n ];
			const auto duration = new int[ n ];

			for( auto i = 0; i < n; i++ )
			{
				std::cin >> start_time[ i ];
			}

			for( auto i = 0; i < n; i++ )
			{
				std::cin >> duration[ i ];
			}

			const auto ptr = initialize( start_time, duration, n );
			std::cout << calculate_max_workshops( ptr ) << std::endl;

			return 0;
		}
	};

	struct template_specialization final : problem
	{
		explicit template_specialization( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		enum class fruit { apple, orange, pear };

		enum class color { red, green, orange };

		template <typename T>
		struct traits;

		template <>
		struct traits<fruit>
		{
			static std::string name( int index );
		};

		template <>
		struct traits<color>
		{
			static std::string name( int index );
		};

		static int main()
		{
			auto t = 0;
			std::cin >> t;

			for( auto index = 0; index != t; ++index )
			{
				int index1;
				std::cin >> index1;
				int index2;
				std::cin >> index2;

				std::cout << traits<color>::name( index1 ) << " ";
				std::cout << traits<fruit>::name( index2 ) << "\n";
			}

			return 0;
		}
	};

	inline std::string template_specialization::traits<template_specialization::fruit>::name( const int index )
	{
		switch( index )
		{
		case 0: return "apple";
		case 1: return "orange";
		case 2: return "pear";

		default:;
		}

		return "unknown";
	}

	inline std::string template_specialization::traits<template_specialization::color>::name( const int index )
	{
		switch( index )
		{
		case 0: return "red";
		case 1: return "green";
		case 2: return "orange";

		default:;
		}

		return "unknown";
	}

	struct variadic_template final : problem
	{
		explicit variadic_template( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		template <bool... Digits>
		struct ReversedBinaryValue;

		template <>
		struct ReversedBinaryValue<>
		{
			static constexpr int value = 0;
		};

		template <bool first, bool... digits>
		struct ReversedBinaryValue<first, digits...>
		{
			static constexpr int value = first + 2 * ReversedBinaryValue<digits...>::value;
		};

		template <bool...Digits>
		static int reversed_binary_value()
		{
			return ReversedBinaryValue<Digits...>::value;
		}

		template <int N, bool...Digits>
		struct check_values
		{
			static void check( int x, int y )
			{
				check_values<N - 1, 0, Digits...>::check( x, y );
				check_values<N - 1, 1, Digits...>::check( x, y );
			}
		};

		template <bool...Digits>
		struct check_values<0, Digits...>
		{
			static void check( const int x, const int y )
			{
				const int z = reversed_binary_value<Digits...>();
				std::cout << ( z + 64 * y == x );
			}
		};

		static int main()
		{
			int t;
			std::cin >> t;

			for( auto i = 0; i != t; ++i )
			{
				int x, y;
				std::cin >> x >> y;
				check_values<6>::check( x, y );
				std::cout << std::endl;
			}

			return 0;
		}
	};
}