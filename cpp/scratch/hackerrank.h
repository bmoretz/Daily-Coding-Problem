#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <map>
#include <cstdio>

namespace hackerrank
{
	namespace fs = std::filesystem;

	struct test_case
	{
		int case_number;
		fs::path input, output;
	};

	struct runner
	{
		std::string problem_desc;
		fs::path working_dir;

		const std::basic_string<char> root = "hackerrank";
		const std::basic_string<char> tests_dir = "input";
		const std::basic_string<char> validation_dir = "output";
		const std::basic_string<char> debug_dir = "debug";

		std::vector<std::pair<fs::path, fs::path>> test_cases;

		virtual int main() = 0;

		explicit runner( std::string&& name ) :
			problem_desc( std::move( name ) )
		{
			working_dir = fs::current_path() / root / problem_desc;
		}

		static int get_case_number( std::string file_name );
		static std::map<int, fs::path> get_files( const fs::path& path );

		[[nodiscard]] auto find_test_cases() const
		{
			auto test_sets = get_files( working_dir / tests_dir ),
				validation_sets = get_files( working_dir / validation_dir );

			std::vector<test_case> test_cases;

			for( const auto& test : test_sets )
			{
				const auto test_number = test.first;

				auto validation = validation_sets.find( test_number );

				if( validation == validation_sets.end() )
				{
					std::cout << "WARNING: UNABLE TO FIND MATCHING VALIDATION SET FOR TEST CASE: " <<
						test_number << std::endl;

					break;
				}

				test_cases.emplace_back( test_case{ test_number, test.second, validation->second } );
			}

			return test_cases;
		}

		void execute_test_case( const std::vector<test_case>::value_type& test )
		{
			// redirect std i/o to test case / debug files.
			const auto prev_in = std::cin.rdbuf();
			const auto new_in = std::ifstream( test.input );
			std::cin.rdbuf( new_in.rdbuf() );

			const auto prev_out = std::cout.rdbuf();
			auto new_out = std::ofstream( debug_dir );
			std::cout.rdbuf( new_out.rdbuf() );

			// execute the problem to build output file.
			main();

			// flush debug fstream and redirect back to std i/o
			new_out.flush();
			new_out.close();

			std::cin.rdbuf( prev_in );
			std::cout.rdbuf( prev_out );
		}
		
		template<typename... Args>
		static std::string string_format( const char* fmt, Args... args )
		{
			const size_t size = snprintf( nullptr, 0, fmt, args... );
			std::string buf;
			buf.reserve( size + 1 );
			buf.resize( size );
			snprintf( &buf[ 0 ], size + 1, fmt, args... );
			return buf;
		}
		
		void run()
		{
			auto test_cases = find_test_cases();

			std::cout << "********************************************************" << std::endl;
			std::cout << std::endl << std::endl;
			
			for( const auto& test : test_cases )
			{
				auto debug_file = working_dir / debug_dir / string_format( "debug%i.txt", test.case_number );
				
				execute_test_case( test );

				std::cout << "TEST RESULTS: Case " << test.case_number << std::endl;

				const auto test_result = compare_files( debug_dir, test.output.string() );

				if( test_result )
					std::cout << "GREAT SUCCESS! VERY NICE" << std::endl;
				else
					std::cout << "TRY AGAIN, VANILLA FACE!" << std::endl;

				std::cout << std::endl << std::endl;
			}

			std::cout << "********************************************************" << std::endl;
		}

		static auto strip_feeds( std::string& str ) -> void
		{
			str.erase( std::remove( str.begin(), str.end(), '\n' ), str.end() );
			str.erase( std::remove( str.begin(), str.end(), '\r' ), str.end() );
		}

		static std::vector<std::string> read_file( std::ifstream& fs )
		{
			std::vector<std::string> content;
			std::string buff;

			while( std::getline( fs, buff ) )
			{
				strip_feeds( buff );
				content.push_back( buff );
			}

			return content;
		}

		static bool compare_files( const std::string& p1, const std::string& p2 );
	};

	inline int runner::get_case_number( std::string file_name )
	{
		file_name.erase( std::remove_if( file_name.begin(),
			file_name.end(),
			[]( const unsigned char c ) { return !std::isdigit( c ); } ),
			file_name.end() );

		return std::stoi( file_name );
	}

	inline std::map<int, fs::path> runner::get_files( const fs::path& path )
	{
		std::map<int, fs::path> files;

		for( const auto& entry : fs::directory_iterator( path ) )
		{
			auto case_number = get_case_number( entry.path().filename().string() );
			auto case_info = std::make_pair( case_number, entry.path() );

			files.insert( case_info );
		}

		return files;
	}

	inline bool runner::compare_files( const std::string& p1, const std::string& p2 )
	{
		std::ifstream f1( p1, std::ifstream::binary | std::ifstream::ate );
		std::ifstream f2( p2, std::ifstream::binary | std::ifstream::ate );

		//seek back to beginning and use std::equal to compare contents

		f1.seekg( 0, std::ifstream::beg );
		f2.seekg( 0, std::ifstream::beg );

		auto are_equal = true;

		const auto lines1 = read_file( f1 );
		const auto lines2 = read_file( f2 );

		return lines1 == lines2;
	}

	class input_parser
	{
		std::ifstream reader_;

	public:

		explicit input_parser( std::string&& file_path );

		template<class Integer, int N>
		auto read_array( const std::string& delimiter = " " );

		template<class Integer>
		auto read_vector( bool has_size_prefix, const std::string& delimiter = " " );

		template<class Integer>
		auto read_vectors( int count, bool has_size_prefix );

		static auto split( const std::string& str, const std::string& delimiter );
	};

	inline input_parser::input_parser( std::string&& file_path )
	{
		reader_.open( file_path );
	}

	inline auto input_parser::split( const std::string& str, const std::string& delimiter )
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

	template <class Integer, int N>
	auto input_parser::read_array( const std::string& delimiter )
	{
		auto arr = std::make_unique<Integer[]>( N );

		if( reader_ )
		{
			std::string buff;
			auto index = std::size_t();

			if( std::getline( reader_, buff ) )
			{
				for( const auto& val : split( buff, delimiter ) )
				{
					arr.get()[ index++ ] = std::stoi( val );
				}
			}
		}

		return std::move( arr );
	}

	template <class Integer>
	auto input_parser::read_vector( const bool has_size_prefix,
		const std::string& delimiter )
	{
		std::vector<Integer> result = { };

		if( reader_ )
		{
			std::string buff;

			if( std::getline( reader_, buff ) )
			{
				auto pieces = split( buff, delimiter );
				auto size = size_t();

				if( has_size_prefix )
				{
					size = std::stoi( pieces.front() );
					pieces.erase( pieces.begin() );
				}

				for( const auto& val : pieces )
				{
					result.push_back( std::stoi( val ) );
				}
			}
		}

		return result;
	}

	template <class Integer>
	auto input_parser::read_vectors( int count,
		const bool has_size_prefix )
	{
		std::vector<std::vector<Integer>> result;

		while( count > 0 )
		{
			result.push_back( read_vector<Integer>( has_size_prefix ) );
			--count;
		}

		return result;
	}
}