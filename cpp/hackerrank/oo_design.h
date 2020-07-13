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

        class person
        {
        protected:
            std::string name_;
            int age_;

        public:

            std::istringstream virtual get_data()
            {
                std::string buff;
                std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
                std::getline( std::cin, buff );
                std::istringstream iss( buff );

                iss >> name_ >> age_;

                return iss;
            }

            void virtual put_data()
            {
                std::cout << name_ << " " << age_ << " ";
            }
        };

        class professor : public person
        {
            int publications_;

        public:

            static int cur_id;

            std::istringstream get_data() override
            {
                auto iss = person::get_data();

                iss >> publications_;

                return iss;
            }

            void put_data() override
            {
                person::put_data();

                std::ostringstream oss;

                oss << publications_ << " " << ++cur_id << std::endl;

                std::cout << oss.str();
            }
        };

        class student : public person
        {
            int marks_[ 6 ];

        public:

            static int cur_id;

            std::istringstream get_data() override
            {
                auto iss = person::get_data();

                for( auto index = 0; index < 6; ++index )
                {
                    iss >> marks_[ index ];
                }

                return iss;
            }

            void put_data() override
            {
                person::put_data();

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
            const auto per = std::unique_ptr<person* []>( new person * [ n ] );

            for( auto i = 0; i < n; i++ )
            {
                std::cin >> val;

                if( val == 1 )
                    per[ i ] = new professor;
                else
                    per[ i ] = new student;

                per[ i ]->get_data();
            }

            for( auto i = 0; i < n; i++ )
                per[ i ]->put_data();

            return 0;
        }
    };
	
    int virtual_functions::student::cur_id = 0;
    int virtual_functions::professor::cur_id = 0;

    struct override_ostream final : problem
    {
        explicit override_ostream( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = []() { return main(); };
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

        static int main()
        {
            std::string first_name, last_name, event;
            std::cin >> first_name >> last_name >> event;
            const auto p = person( first_name, last_name );
            std::cout << p << " " << event << std::endl;
            return 0;
        }
    };

    struct abstract_classes final : problem
    {
        explicit abstract_classes( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = [this]() { return main(); };
        }

        struct Node;

        using node_ptr = std::unique_ptr<Node>;

        class Cache;
        class LRUCache;

        class Node
        {
            friend class Cache;
            friend class LRUCache;

            Node* next_, * prev_;

            int value;
            int key;

        protected:

            void unlink()
            {
                const auto next = next_;
                const auto prev = prev_;

                next->prev_ = prev;
                prev->next_ = next;

                next_ = this;
                prev_ = this;
            }

        public:
            Node()
                : next_{ this }, prev_{ this },
                value{ }, key{ }
            {}

            Node( Node* p, Node* n, const int k, const int val ) :
                next_{ n }, prev_( p ),
                value( val ), key( k )
            { }

            Node( const int k, const int val ) :
                next_( nullptr ), prev_( nullptr ),
                value( val ), key( k )
            {}

            ~Node()
            {
                unlink();
            }
        };

        class Cache
        {
        protected:
            std::map<int, node_ptr> map_{};
            int capacity_;
            int length_;
            node_ptr head_{}, tail_{};

            virtual void set( int, int ) = 0;
            virtual int get( int ) = 0;

        public:

            explicit Cache( const int capacity )
                : capacity_{ capacity }, length_{ }
            {
                head_ = std::make_unique<Node>( 0, 0 );
                tail_ = std::make_unique<Node>( 0, 0 );

                head_->next_ = tail_.get();
                head_->prev_ = tail_.get();

                tail_->next_ = head_.get();
                tail_->prev_ = head_.get();
            }

            virtual ~Cache() = default;
        };

        class LRUCache : public Cache
        {
        public:

            explicit LRUCache( const int capacity )
                : Cache( capacity )
            {  }

            void set( const int key, const int value ) override
            {
                const auto existing = map_.find( key );

                if( existing == map_.end() )
                {
                    map_.insert( std::make_pair( key, std::make_unique<Node>(
                        head_.get(), head_->next_, key, value ) ) );

                    head_->next_->prev_ = map_[ key ].get();
                    head_->next_ = map_[ key ].get();

                    length_++;

                    if( length_ > capacity_ )
                    {
                        const auto to_remove = tail_->prev_->key;
                        map_.erase( to_remove );
                        length_--;
                    }
                }
                else
                {
                    existing->second->value = value;
                    existing->second->next_ = head_->next_;

                    head_->next_ = existing->second.get();
                }
            }

            int get( const int key ) override
            {
                const auto location = map_.find( key );

                return location == map_.end() ? -1 : location->second->value;
            }
        };

        int main()
        {
            int n, capacity;
            std::cin >> n >> capacity;
            LRUCache l( capacity );

            for( auto i = 0; i < n; i++ ) {
                std::string command;
                std::cin >> command;

                if( command == "get" ) {
                    int key;
                    std::cin >> key;
                    std::cout << l.get( key ) << std::endl;
                }
                else if( command == "set" ) {
                    int key, value;
                    std::cin >> key >> value;
                    l.set( key, value );
                }
            }

            return 0;
        }
    };


    struct multiple_inherited_functions final : problem
    {
        explicit multiple_inherited_functions( std::string&& name )
            : problem( std::move( name ) )
        {
            entry_point = [this]() { return main(); };
        }

        class A
        {
        public:
            A() {
                callA = 0;
            }
        private:
            int callA;
            void inc() {
                callA++;
            }

        protected:
            void func( int& a )
            {
                a = a * 2;
                inc();
            }
        public:
            int getA() {
                return callA;
            }
        };

        class B
        {
        public:
            B() {
                callB = 0;
            }
        private:
            int callB;
            void inc() {
                callB++;
            }
        protected:
            void func( int& a )
            {
                a = a * 3;
                inc();
            }
        public:
            int getB() {
                return callB;
            }
        };

        class C
        {
        public:
            C() {
                callC = 0;
            }
        private:
            int callC;
            void inc() {
                callC++;
            }
        protected:
            void func( int& a )
            {
                a = a * 5;
                inc();
            }
        public:
            int getC() {
                return callC;
            }
        };

        class D : public A, B, C
        {
            int val;
        public:
            //Initially val is 1
            D()
            {
                val = 1;
            }

            //Implement this function
            void update_val( int new_val )
            {
                while( new_val % 2 == 0 )
                {
                    A::func( val );
                    new_val /= 2;
                }

                while( new_val % 3 == 0 )
                {
                    B::func( val );
                    new_val /= 3;
                }

                while( new_val % 5 == 0 )
                {
                    C::func( val );
                    new_val /= 5;
                }
            }

            void check( const int new_val )

            {
                update_val( new_val );

                std::cout
                    << "Value = " << val << std::endl
                    << "A's func called " << getA() << " times" << std::endl
                    << "B's func called " << getB() << " times" << std::endl
                    << "C's func called " << getC() << " times";
            }
        };

        int main()
        {
            D d;
            int new_val;
            std::cin >> new_val;
            d.check( new_val );

            return 0;
        }
    };

}