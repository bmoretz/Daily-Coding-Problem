#pragma once

#include <sstream>
#include "problem.h"

namespace hackerrank::arr
{
	struct variable_sized_arrays final : problem
	{
		using problem::problem;

		static std::vector<std::basic_string<char>> split( const std::string& str, const std::string& delimiter )
		{
			size_t pos_start = 0, pos_end;
			const auto delimiter_length = delimiter.length();
			std::vector<std::string> result;

			while( ( pos_end = str.find( delimiter, pos_start ) ) != std::string::npos )
			{
				auto token = str.substr( pos_start, pos_end - pos_start );
				pos_start = pos_end + delimiter_length;
				result.push_back( token );
			}

			result.push_back( str.substr( pos_start ) );

			return result;
		}

		std::vector<std::vector<int>> read_vectors( const std::size_t num_vectors,
			const bool has_count = true ) const
		{
			auto vectors = std::vector<std::vector<int>>( num_vectors );

			for( size_t v = 0; v < num_vectors; v++ )
			{
				std::string buff;
				std::vector<int> tmp;

				if( std::getline( std::cin, buff ) )
				{
					auto pieces = split( buff, " " );
					auto size = size_t();

					if( has_count )
					{
						size = std::stoi( pieces.front() );
						tmp.reserve( size );
						pieces.erase( pieces.begin() );
					}

					for( const auto& val : pieces )
					{
						tmp.push_back( std::stoi( val ) );
					}
				}

				vectors[ v ] = tmp;
			}

			return vectors;
		}

		std::vector<int> read_vector() const
		{
			std::string buff;
			std::vector<int> result;

			if( std::getline( std::cin, buff ) )
			{
				for( const auto& val : split( buff, " " ) )
				{
					result.push_back( std::stoi( val ) );
				}
			}

			return result;
		}

		int main() override
		{
			auto sizes = read_vector();

			const auto vectors = read_vectors( sizes[ 0 ] );
			const auto queries = read_vectors( sizes[ 1 ], false );

			std::ostringstream out;

			for( auto index = 0; index < queries.size(); ++index )
			{
				const auto row = queries[ index ][ 0 ];
				const auto col = queries[ index ][ 1 ];

				out << vectors.at( row ).at( col );

				if( index != queries.size() - 1 )
					out << std::endl;
			}

			std::cout << out.str();

			return 0;
		}
	};
}
