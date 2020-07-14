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
            entry_point = []() { return main(); };
        }

        class a
        {
        public:
            a() {
                call_a_ = 0;
            }
        	
        private:
            int call_a_;
            void inc() {
                call_a_++;
            }

        protected:
            void func( int& a )
            {
                a = a * 2;
                inc();
            }
        public:
            int get_a() const
            {
                return call_a_;
            }
        };

        class b
        {
        public:
            b() { call_b_ = 0; }
        	
        private:
            int call_b_;
            void inc() { call_b_++; }
        	
        protected:

        	void func( int& a )
            {
                a = a * 3;
                inc();
            }
        	
        public:
        	
            int get_b() const
            {
                return call_b_;
            }
        };

        class c
        {
        public:
            c() {
                call_c_ = 0;
            }
        	
        private:
            int call_c_;
            void inc() {
                call_c_++;
            }
        protected:
            void func( int& a )
            {
                a = a * 5;
                inc();
            }
        public:
            int get_c() const
            {
                return call_c_;
            }
        };

        class d : a, b, c
        {
            int val_;
        	
        public:

            d() { val_ = 1; }
        	
            void update_val( int new_val )
            {
                while( new_val % 2 == 0 )
                {
                    a::func( val_ );
                    new_val /= 2;
                }

                while( new_val % 3 == 0 )
                {
                    b::func( val_ );
                    new_val /= 3;
                }

                while( new_val % 5 == 0 )
                {
                    c::func( val_ );
                    new_val /= 5;
                }
            }

            void check( const int new_val )
            {
                update_val( new_val );

                std::cout
                    << "Value = " << val_ << std::endl
                    << "A's func called " << get_a() << " times" << std::endl
                    << "B's func called " << get_b() << " times" << std::endl
                    << "C's func called " << get_c() << " times";
            }
        };

        static int main()
        {
            d d;
            int new_val;
            std::cin >> new_val;
            d.check( new_val );

            return 0;
        }
    };

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
                scroll_name_( std::move( name ) )
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
}