#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

/* Sum Lists.
 *
 *You have two numbers represented by a linked list, where each node
 *contains a single digit. The digits are stored in reverse order,
 *such that the 1's digit is at the head of the list. Write a function
 *that adds the two numbers and returns the sum as a linked list.
 *
 *EXAMPLE:
 *
 *Input: ( 7 -> 1 -> 6 ) + ( 5 -> 9 -> 2 ). That is, 617 + 295.
 *Output: 2 -> 1 -> 9. That is, 912.
 *
 *FOLLOW-UP:
 *Suppose the digits are stored in forward order. Repeat the problem.
 *
 *EXAMPLE:
 *
 *Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
 *Output: 9 -> 1 -> 2. That is, 912.
 *
 */

class sum_list
{	
	struct list_node
	{
		explicit list_node( const int value )
			: value{ value }, prev( nullptr )
		{ }

		int value;

		std::unique_ptr<list_node> next;
		list_node* prev;
	};

	class list_iterator
	{
		list_node* node_;

	public:

		typedef list_iterator self_type;
		typedef list_iterator* pointer;
		typedef list_iterator& reference;
		
		explicit list_iterator( list_node * node )
			: node_( node )
		{ }

		reference operator++()
		{
			if( node_ )
				node_ = node_->next.get();
			
			return *this;
		}

		reference operator--()
		{
			if( node_ )
				node_ = node_->prev;

			return *this;
		}
		
		int& operator*() const { return node_->value; }
		int operator->() const { return node_->value; }

		bool operator==( const self_type& other ) const { return node_ == other.node_; }
		bool operator!=( const self_type& other ) const { return node_ != other.node_; }
	};
	
	class num_list
	{
		std::unique_ptr<list_node> head_ {};
		list_node* tail_{};
		
	public:

		using iterator = list_iterator;

		[[nodiscard]] bool empty() const { return !head_->next; }
		
		[[nodiscard]] iterator begin() const { return iterator( head_->next.get() ); }
		
		[[nodiscard]] iterator end() const { return iterator( tail_ ); }

		[[nodiscard]] iterator rbegin() const { return iterator( tail_ ); }

		[[nodiscard]] iterator rend() const { return iterator( head_.get() ); }
		
		explicit num_list()
		{
			head_ = std::make_unique<list_node>( 0 );
			head_->prev = head_.get();
			tail_ = head_->next.get();
		}

		explicit num_list( const std::vector<int>& values )
			: num_list()
		{
			for( const auto& value : values )
			{
				
				push_back( value );
			}
		}
		
		num_list( const std::initializer_list<int>& values )
		{
			for( const auto& value : values )
			{
				push_back( value );
			}
		}
		
		num_list( num_list& other )
		{
			head_ = std::move( other.head_ );
			tail_ = other.tail_;
		}

		num_list( const num_list& other )
			: num_list()
		{
			for( auto item : other )
			{
				push_back( item );
			}
		}

		num_list( num_list&& other ) noexcept
			: num_list()
		{
			std::swap( head_, other.head_ );
			std::swap( tail_, other.tail_ );
		}

		num_list& operator=( const num_list& other )
		{
			if( this == &other ) return *this;

			auto temp( other );

			std::swap( temp, *this );

			return *this;
		}

		num_list& operator=( num_list&& other ) noexcept
		{
			if( this == &other )
				return *this;

			head_ = std::move( other.head_ );
			tail_ = other.tail_;
			
			return *this;
		}

		void push_front( int value ) const
		{
			auto new_node = std::make_unique<list_node>( value );

			if( head_->next )
			{
				new_node->next = std::move( head_->next );
				new_node->next->prev = new_node.get();
			}

			new_node->prev = head_.get();
			head_->next = std::move( new_node );
		}
		
		void push_back( int value )
		{
			auto node = head_.get();
			
			while( node->next )
				node = node->next.get();
			
			node->next = std::make_unique<list_node>( value );
			node->next->prev = node;
			
			tail_ = node->next.get();
		}

		[[nodiscard]] std::vector<int> get_values() const
		{
			std::vector<int> values;

			auto node = head_.get();

			while( node )
			{
				values.push_back( node->value );
				node = node->next.get();
			}

			return values;
		}

		[[nodiscard]] std::string to_string() const
		{
			const auto values = get_values();

			std::stringstream ss{};
			std::copy( values.begin(), values.end(),
				std::ostream_iterator<int>( ss, " -> " ) );

			return ss.str();
		}
		
		bool operator==( const num_list& other )
		{
			return *this == other;
		}
	};

	using list_pointer = std::unique_ptr<num_list>;
	
	list_pointer num_one_, num_two_;
	
public:

	explicit sum_list()
		: num_one_{ nullptr }, num_two_{ nullptr }
	{ }

	explicit sum_list( const std::vector<int>& one, 
		const std::vector<int>& two )
	{
		num_one_ = std::make_unique<num_list>( one );
		num_two_ = std::make_unique<num_list>( two );	
	}

	[[nodiscard]] list_pointer sum_backward() const
	{
		auto result = std::make_unique<num_list>();
		
		const auto left = num_one_.get();
		const auto right = num_two_.get();
		
		auto l_digit = num_one_->rbegin();
		auto r_digit = num_two_->rbegin();

		auto remainder = 0;

		while( l_digit != left->rend() || r_digit != right->rend() || remainder )
		{
			const auto num1 = l_digit == left->end() ? 0 : *l_digit;
			const auto num2 = r_digit == right->end() ? 0 : *r_digit;

			const auto digit = num1 + num2 + remainder;

			result->push_back( digit % 10 );

			remainder = digit > 9 ? 1 : 0;

			--l_digit;
			--r_digit;
		}

		return result;
	}

	[[nodiscard]] list_pointer forward_sum() const
	{
		auto result = std::make_unique<num_list>();

		const auto left = num_one_.get();
		const auto right = num_two_.get();

		auto l_digit = num_one_->begin();
		auto r_digit = num_two_->begin();

		while( l_digit != left->end() || r_digit != right->end() )
		{
			if( l_digit != left->end() )
				++l_digit;
			else
				left->push_front( 0 );

			if( r_digit != right->end() )
				++r_digit;
			else
				right->push_front( 0 );
		}
		

		l_digit = num_one_->rbegin();
		r_digit = num_two_->rbegin();
		
		auto remainder = 0;

		while( l_digit != left->rend() || r_digit != right->rend() || remainder )
		{
			auto le = l_digit == left->rend();
			auto re = r_digit == right->rend();
			
			const auto num1 = l_digit != left->end() ? *l_digit : 0;
			const auto num2 = r_digit != right->end() ? *r_digit : 0;

			const auto digit = num1 + num2 + remainder;

			result->push_front( digit % 10 );

			remainder = digit > 9 ? 1 : 0;

			--l_digit;
			--r_digit;
		}

		return result;
	}

	void display_values() const
	{
		std::cout << num_one_->to_string() << std::endl;
		std::cout << num_two_->to_string() << std::endl;
	}
};

void test_harness()
{
	std::cout << "Enter test input to build list, c when complete:" << std::endl;

	std::string input;

	const auto list = sum_list();

	while( getline( std::cin, input ) )
	{
		try
		{
			if( input == "c" ) break;

			const auto value = std::stoi( input );
			//list.push_back( value );
		}
		catch( const std::exception& ex )
		{
			std::cout << ex.what();
		}
	}

	list.display_values();

	std::cout << "enter value to partition list around:";
	std::getline( std::cin, input );

	list.display_values();
}

void list_base()
{
	const auto list = sum_list{ { 9, 6 }, { } };

	list.display_values();

	const auto result = list.forward_sum();

	std::cout << result->to_string();
}

auto main() -> int
{
	list_base();
}