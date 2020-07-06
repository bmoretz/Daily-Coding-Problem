#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

struct abstract_classes final : problem
{
    explicit abstract_classes( std::string&& name )
        : problem( std::move( name ) )
    {
        entry_point = [this]() { return main(); };
    }

    struct Node {
        Node* next;
        Node* prev;
        int value;
        int key;
        Node( Node* p, Node* n, int k, int val ) :prev( p ), next( n ), key( k ), value( val ) {};
        Node( int k, int val ) :prev( NULL ), next( NULL ), key( k ), value( val ) {};
    };

    class Cache {

    protected:
        std::map<int, Node*> mp; //map the key to the node in the linked list
        int cp;  //capacity
        Node* tail; // double linked list tail pointer
        Node* head; // double linked list head pointer
        virtual void set( int, int ) = 0; //set function
        virtual int get( int ) = 0; //get function
    };

    static void unlink( Node* node )
    {    	
        const auto new_next = node->next;
        const auto new_prev = node->prev;

        node->next->prev = new_prev;
        node->prev->next = new_next;

        delete node;
    }

	class LRUCache : public Cache
	{
	public:

        int length = 0;
    	
		explicit LRUCache( const int capacity )
		{
            head = new Node( 0, 0 );
            tail = new Node( 0, 0 );

            head->next = tail;
            head->prev = tail;

            tail->next = head;
            tail->prev = head;
			
            this->cp = capacity;
		}

    	~LRUCache()
		{
            delete head;
            delete tail;
		}
    	
		void set( const int key, const int value ) override
		{
            const auto existing = mp.find( key );

			if( existing == mp.end() )
			{
				const auto new_node = new Node(
                    head, head->next, key, value );
				
                mp.insert( std::make_pair( key, new_node ) );

				head->next->prev = mp[ key ];
                head->next = mp[ key ];

                length++;
				
                if( length > cp )
                {
                    const auto to_remove = tail->prev->key;
                    mp.erase( to_remove );

                    unlink( tail->prev );

                    length--;
                }
			}
            else
            {
                existing->second->value = value;
                existing->second->next = head->next;
            	
                head->next = existing->second;
            }
		}

		int get( const int key ) override
		{
            const auto location = mp.find( key );

            return location == mp.end() ? -1 : location->second->value;
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

auto main() -> int
{
	const auto problem =
		abstract_classes{"abstract-classes-polymorphism-testcases"};

	return problem.run(0);
}
