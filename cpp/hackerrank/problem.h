#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <map>
#include <cstdio>
#include <vector>
#include <functional>

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

		std::function<int()> entry_point;
		
		const std::basic_string<char> root = "hackerrank";
		const std::basic_string<char> tests_dir = "input";
		const std::basic_string<char> validation_dir = "output";
		const std::basic_string<char> debug_dir = "debug";

		std::vector<std::pair<fs::path, fs::path>> test_cases;

		explicit problem( std::string&& name ) :
			problem_desc( std::move( name ) )
		{
			working_dir = fs::current_path() / root / problem_desc;
		}

		static int get_case_number( std::string file_name );
		static std::map<int, fs::path> get_files( const fs::path& path );
		void execute_test_case( const std::vector<test_case>::value_type& test, const fs::path& debug_file ) const;
		
		[[nodiscard]] std::vector<test_case> find_test_cases() const;
		[[nodiscard]] bool run( int test_case = -1 ) const;
		
		template<typename... Args>
		static std::string string_format( const char* fmt, Args ... args );

		static auto strip_feeds( std::string& str ) -> void;
		static std::vector<std::basic_string<char>> read_file( std::ifstream& fs );
		static bool compare_files( const fs::path& p1, const fs::path& p2, std::string& detail );
		static std::string get_failure_detail( const std::vector<std::string>& actual,
			const std::vector<std::string>& expected );
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
		const fs::path& debug_file ) const
	{
		// redirect std i/o to test case / debug files.
		const auto prev_in = std::cin.rdbuf();
		const auto new_in = std::ifstream( test.input );
		std::cin.rdbuf( new_in.rdbuf() );

		const auto prev_out = std::cout.rdbuf();
		auto new_out = std::ofstream( debug_file );
		std::cout.rdbuf( new_out.rdbuf() );

		// execute the problem to build output file.
		const auto result = entry_point();

		// flush debug fstream and redirect back to std i/o
		new_out.flush();
		new_out.close();

		std::cin.rdbuf( prev_in );
		std::cout.rdbuf( prev_out );
	}

	inline bool problem::run( const int test_case ) const
	{
		auto all_passed = true;
		auto test_cases = find_test_cases();

		for( const auto& test : test_cases )
		{
			if( test_case > 0 && test.case_number != test_case )
				continue;

			std::cout << "********************************************************" << std::endl;
			std::cout << std::endl;
			
			auto debug_path = working_dir / debug_dir;

			if( !exists( debug_path ) )
				create_directory( debug_path );
			
			auto debug_file = debug_path / string_format( "debug%i.txt", test.case_number );
			
			execute_test_case( test, debug_file );

			std::cout << "TEST RESULTS: Case " << test.case_number << " RESULTS: ";

			std::string detail;
			const auto test_result = compare_files( debug_file, test.output, detail );

			if( test_result )
			{
				std::cout << "GREAT SUCCESS! VERY NICE" << std::endl;
			}
			else
			{
				std::cout << "TRY AGAIN, VANILLA FACE!" << std::endl;
				std::cout << detail;
			}

			std::cout << std::endl;
			
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


	inline bool problem::compare_files( const fs::path& p1, const fs::path& p2, 
		std::string& detail )
	{
		std::ifstream f1( p1, std::ifstream::binary | std::ifstream::ate );
		std::ifstream f2( p2, std::ifstream::binary | std::ifstream::ate );

		//seek back to beginning and use std::equal to compare contents

		f1.seekg( 0, std::ifstream::beg );
		f2.seekg( 0, std::ifstream::beg );

		const auto lines1 = read_file( f1 );
		const auto lines2 = read_file( f2 );

		if( lines1 == lines2 )
		{
			return true;
		}
		
		detail = get_failure_detail( lines1, lines2 );

		return false;
	}

	static std::string build_line( const std::string& l, const std::string& r, 
		const std::size_t width )
	{
		const auto padding = width > l.length() ? 
			width - l.length() : 0ULL;
		
		return l + std::string( padding, ' ' ) + r;
	}
	
	inline std::string problem::get_failure_detail( const std::vector<std::string>& actual, 
		const std::vector<std::string>& expected )
	{
		auto max_width = std::size_t{};

		for( const auto& line : actual )
			max_width = std::max( max_width, line.length() );

		max_width += 5; // buffer
		std::ostringstream oss;

		oss << std::endl << std::endl << 
			build_line( "ACTUAL:", "EXPECTED:", max_width )
				<< std::endl;

		const auto num_lines = 
			std::max( actual.size(), expected.size() );

		for( auto index = std::size_t{}; index < num_lines; ++index )
		{
			auto left = index < actual.size() ?
				actual[ index ] : "";

			auto right = index < expected.size() ?
				expected[ index ] : "";

			oss << build_line( left, right, max_width ) << std::endl;
		}

		return oss.str();
	}
}
