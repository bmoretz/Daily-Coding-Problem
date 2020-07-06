#pragma once

#include <sstream>
#include <stack>
#include <memory>
#include <cassert>
#include <numeric>

#include "problem.h"

namespace hackerrank::oo_design
{
    struct virtual_functions final : problem
    {
        explicit virtual_functions( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = []() { return main(); };
        }

        class Person
        {
        protected:
            std::string name_;
            int age_;

        public:
            Person() = default;

            std::istringstream virtual getdata()
            {
                std::string buff;
                std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
                std::getline( std::cin, buff );
                std::istringstream iss( buff );

                iss >> name_ >> age_;

                return iss;
            }

            void virtual putdata()
            {
                std::cout << name_ << " " << age_ << " ";
            }
        };

        class Professor : public Person
        {
            int publications_;

        public:

            static int cur_id;

            Professor()
                : Person()
            { }

            std::istringstream getdata() override
            {
                auto iss = Person::getdata();

                iss >> publications_;

                return iss;
            }

            void putdata() override
            {
                Person::putdata();

                std::ostringstream oss;

                oss << publications_ << " " << ++cur_id << std::endl;

                std::cout << oss.str();
            }
        };

        class Student : public Person
        {
            int marks_[ 6 ];

        public:

            static int cur_id;

            Student()
                : Person()
            { }

            std::istringstream getdata() override
            {
                auto iss = Person::getdata();

                for( auto index = 0; index < 6; ++index )
                {
                    iss >> marks_[ index ];
                }

                return iss;
            }

            void putdata() override
            {
                Person::putdata();

                std::ostringstream oss;

                const auto total = std::accumulate(
                    std::begin( marks_ ),
                    std::end( marks_ ),
                    0 );

                oss << total << " " << ++cur_id << std::endl;

                std::cout << oss.str();
            }
        };

        static int main()
        {
            int n, val;
            std::cin >> n;
            const auto per = std::unique_ptr<Person* []>( new Person * [ n ] );

            for( auto i = 0; i < n; i++ )
            {
                std::cin >> val;

                if( val == 1 )
                    per[ i ] = new Professor;
                else
                    per[ i ] = new Student;

                per[ i ]->getdata();
            }

            for( auto i = 0; i < n; i++ )
                per[ i ]->putdata();

            return 0;
        }
    };
	
    int virtual_functions::Student::cur_id = 0;
    int virtual_functions::Professor::cur_id = 0;

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
}