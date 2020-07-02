#pragma once

#include <sstream>
#include <stack>
#include <memory>
#include <cassert>

#include "problem.h"

namespace hackerrank::str
{	
	/// <summary>
	/// https://www.hackerrank.com/challenges/attribute-parser/problem
	/// </summary>
	struct attribute_parser final : problem
	{
		explicit attribute_parser( std::string&& name )
			: problem( std::move( name ) )
		{
			entry_point = []() { return main(); };
		}

		using attribute = std::pair<std::string, std::string>;

		struct query
		{
			std::vector<std::string> tags;
			std::string attribute;
		};

		struct tag
		{
			std::string id;
			std::vector<attribute> attributes{};
			std::vector<std::unique_ptr<tag>> tags{};
		};

		static std::pair<int, int> get_arguments()
		{
			std::string buff;
			std::getline( std::cin, buff );
			std::istringstream iss{ buff };

			int num_tags, num_queries;
			iss >> num_tags >> num_queries;

			return std::make_pair( num_tags, num_queries );
		}

		static bool starts_with( const std::string& str, const std::string& pattern )
		{
			return str.rfind( pattern, 0 ) == 0;
		}

		static std::string extract_chunk( std::string& str, const char delimiter = ' ' )
		{
			const auto len = str.size();
			const auto position = str.find( delimiter, 0 );

			const auto end = position == std::string::npos ? len : position;
			const auto next = position == std::string::npos ? len : position + 1;

			auto chunk = str.substr( 0, end );
			str.erase( str.begin(), str.begin() + next );

			return chunk;
		}

		static void strip_characters( std::string& str, const std::vector<char>& chars )
		{
			str.erase( std::remove_if( str.begin(), str.end(),
				[chars]( const char c )
				{
					return std::find( chars.begin(), chars.end(), c ) != chars.end();
				} ), str.end() );
		}

		static std::vector<std::string> split( const std::string& string,
			const char delimiter = ' ' )
		{
			std::vector<std::string> result;
			std::stringstream ss( string );
			std::string item;

			while( std::getline( ss, item, delimiter ) ) {
				result.push_back( item );
			}

			return result;
		}

		static bool is_closing_tag( const std::string& line )
		{
			return std::count( line.begin(), line.end(), ' ' ) == 0;
		}

		static void display_not_found()
		{
			std::cout << "Not Found!" << std::endl;
		}

		static std::unique_ptr<tag> parse_tag( std::string input )
		{
			if( starts_with( input, "<" ) )
				input.erase( input.begin(), input.begin() + 1 );

			auto tag_id = extract_chunk( input );
			strip_characters( tag_id, { '>' } );

			std::vector<attribute> attributes;

			while( !input.empty() )
			{
				const auto key = extract_chunk( input );
				extract_chunk( input );

				auto value = extract_chunk( input );
				strip_characters( value, { '"', '>' } );

				attributes.emplace_back( attribute( key, value ) );
			}

			return std::make_unique<tag>( tag{ tag_id, attributes } );
		}

		static std::map<std::string, std::unique_ptr<tag>> read_tags( const std::size_t num_tags )
		{
			std::map<std::string, std::unique_ptr<tag>> results;
			std::stack<tag*> parsed;

			std::string buff;
			auto index = std::size_t();

			while( index < num_tags && std::getline( std::cin, buff ) )
			{
				if( is_closing_tag( buff ) && !parsed.empty() )
				{
					parsed.pop();
				}
				else
				{
					auto tag = parse_tag( buff );

					if( parsed.empty() )
					{
						parsed.push( tag.get() );
						results.insert( std::make_pair( tag->id, std::move( tag ) ) );
					}
					else
					{
						auto prev = parsed.top();

						prev->tags.push_back( std::move( tag ) );
						parsed.push( prev->tags.back().get() );
					}
				}

				index++;
			}

			return results;
		}

		static std::vector<query> read_queries( const std::size_t num_queries )
		{
			auto result = std::vector<query>{};
			auto index = std::size_t{ };
			auto buff = std::string{ };

			while( index < num_queries && std::getline( std::cin, buff ) )
			{
				auto tokens = split( buff, '~' );

				result.push_back( { split( tokens[ 0 ], '.' ), tokens[ 1 ] } );

				++index;
			}

			assert( num_queries == index );

			return result;
		}

		static void display_attribute( const tag& requested_tag, const query& query )
		{
			const auto requested_attribute = std::find_if(
				requested_tag.attributes.begin(),
				requested_tag.attributes.end(),
				[&query]( const attribute& attribute )
				{
					return attribute.first == query.attribute;
				} );

			if( requested_attribute == requested_tag.attributes.end() )
			{
				display_not_found();
				return;
			}

			std::cout << requested_attribute->second << std::endl;
		}

		static tag* evaluate_sub_tags( tag* requested_tag, const query& query )
		{
			for( auto index = 1ULL; index < query.tags.size(); ++index )
			{
				const auto sub_tag_id = query.tags[ index ];

				auto next = std::find_if(
					requested_tag->tags.begin(),
					requested_tag->tags.end(),
					[&sub_tag_id]( const auto& t )
					{
						return t->id == sub_tag_id;
					} );

				if( next == requested_tag->tags.end() )
					return nullptr;

				requested_tag = next->get();
			}

			return requested_tag;
		}

		static void display_results( const std::map<std::string, std::unique_ptr<tag>>& tags,
			const std::vector<query>& queries )
		{
			for( const auto& query : queries )
			{
				auto initial = query.tags[ 0 ];

				if( query.tags.empty() || tags.find( query.tags.front() ) == tags.end() )
				{
					display_not_found();
					continue;
				}

				auto requested_tag = tags.at( initial ).get();

				if( query.tags.size() > 1 )
					requested_tag = evaluate_sub_tags( requested_tag, query );

				if( requested_tag )
				{
					display_attribute( *requested_tag, query );
				}
				else
				{
					display_not_found();
				}
			}
		}

		static int main()
		{
			const auto params = get_arguments();

			const auto tags = read_tags( params.first );
			const auto queries = read_queries( params.second );

			display_results( tags, queries );

			return 0;
		}
	};
}