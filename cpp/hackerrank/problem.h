#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <map>
#include <cstdio>
#include <vector>

namespace hackerrank
{
	namespace fs = std::filesystem;

	struct test_case
	{
		int case_number;
		fs::path input, output;
	};

	struct problem
	{
		std::string problem_desc;
		fs::path working_dir;

		const std::basic_string<char> root = "hackerrank";
		const std::basic_string<char> tests_dir = "input";
		const std::basic_string<char> validation_dir = "output";
		const std::basic_string<char> debug_dir = "debug";

		std::vector<std::pair<fs::path, fs::path>> test_cases;

		virtual int main() = 0;

		explicit problem( std::string&& name ) :
			problem_desc( std::move( name ) )
		{
			working_dir = fs::current_path() / root / problem_desc;
		}

		static int get_case_number( std::string file_name );
		static std::map<int, fs::path> get_files( const fs::path& path );
		[[nodiscard]] std::vector<test_case> find_test_cases() const;
		void execute_test_case( const std::vector<test_case>::value_type& test, const fs::path& debug_file );

		template<typename... Args>
		static std::string string_format( const char* fmt, Args ... args );

		bool run();

		static auto strip_feeds( std::string& str ) -> void;

		static std::vector<std::basic_string<char>> read_file( std::ifstream& fs );

		static bool compare_files( const fs::path& p1, const fs::path& p2 );
	};

	template <typename ... Args>
	std::string problem::string_format( const char* fmt, Args ... args )
	{
		const size_t size = snprintf( nullptr, 0, fmt, args... );
		std::string buf;
		buf.reserve( size + 1 );
		buf.resize( size );
		snprintf( &buf[ 0 ], size + 1, fmt, args... );
		return buf;
	}

	inline int problem::get_case_number( std::string file_name )
	{
		file_name.erase( std::remove_if( file_name.begin(),
			file_name.end(),
			[]( const unsigned char c ) { return !std::isdigit( c ); } ),
			file_name.end() );

		return std::stoi( file_name );
	}

	inline std::map<int, fs::path> problem::get_files( const fs::path& path )
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

	inline std::vector<test_case> problem::find_test_cases() const
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

				continue;
			}

			test_cases.emplace_back( test_case{ test_number, test.second, validation->second } );
		}

		return test_cases;
	}

	inline void problem::execute_test_case( const std::vector<test_case>::value_type& test,
		const fs::path& debug_file )
	{
		// redirect std i/o to test case / debug files.
		const auto prev_in = std::cin.rdbuf();
		const auto new_in = std::ifstream( test.input );
		std::cin.rdbuf( new_in.rdbuf() );

		const auto prev_out = std::cout.rdbuf();
		auto new_out = std::ofstream( debug_file );
		std::cout.rdbuf( new_out.rdbuf() );

		// execute the problem to build output file.
		main();

		// flush debug fstream and redirect back to std i/o
		new_out.flush();
		new_out.close();

		std::cin.rdbuf( prev_in );
		std::cout.rdbuf( prev_out );
	}

	inline bool problem::run()
	{
		auto all_passed = true;
		auto test_cases = find_test_cases();

		std::cout << "********************************************************" << std::endl;
		std::cout << std::endl << std::endl;

		for( const auto& test : test_cases )
		{
			auto debug_path = working_dir / debug_dir;

			if( !exists( debug_path ) )
				create_directory( debug_path );
			
			auto debug_file = debug_path / string_format( "debug%i.txt", test.case_number );
			
			execute_test_case( test, debug_file );

			std::cout << "TEST RESULTS: Case " << test.case_number << std::endl;

			const auto test_result = compare_files( debug_file, test.output );

			if( test_result )
			{
				std::cout << "GREAT SUCCESS! VERY NICE" << std::endl;
			}
			else
			{
				std::cout << "TRY AGAIN, VANILLA FACE!" << std::endl;
			}

			std::cout << std::endl << std::endl;
			all_passed &= test_result;
		}

		std::cout << "********************************************************" << std::endl;

		return all_passed;
	}

	inline auto problem::strip_feeds( std::string& str ) -> void
	{
		str.erase( std::remove( str.begin(), str.end(), '\n' ), str.end() );
		str.erase( std::remove( str.begin(), str.end(), '\r' ), str.end() );
	}

	inline std::vector<std::basic_string<char>> problem::read_file( std::ifstream& fs )
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

	inline bool problem::compare_files( const fs::path& p1, const fs::path& p2 )
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
}