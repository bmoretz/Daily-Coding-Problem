#pragma once

#include <vector>
#include <list>

namespace problems::stack_queue
{
    /* Min Stack.
     *
     * Design a stack which, in addition to push and pop, has a
     * min function which returns the minimum element?
     *
     * Push, pop and min should all operate in N(1) time.
     */

    template<typename Ty>
    class min_stack
    {
        std::vector<Ty> data_, min_;

    public:

        /// <summary>
		/// min_stack
		///
		/// This approach to the min stack problem simply keeps a duplicate
		/// vector of n items, each which correspond to the minimum value in
		/// the stack when it has i items.
		/// <complexity>
		///		<run-time>O(1) for all operations</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>
        explicit min_stack()
            : data_{ }, min_{ }
        { }

		min_stack( const std::initializer_list<Ty>& init_list )
        {
			for( auto item : init_list )
			{
                push_back( item );
			}
        }

        [[nodiscard]] std::size_t size() const { return data_.size(); }

        [[nodiscard]] bool empty() const { return data_.empty(); }
    	
        void push_back( Ty item )
        {
            data_.push_back( item );

            min_.push_back( min_.empty() || item < min_.back() ? item : min_.back() );
        }

        [[nodiscard]] Ty pop()
        {
            Ty item = Ty();
        	
            if( !data_.empty() )
            {
                item = data_.back();

                data_.pop_back();
                min_.erase( min_.begin() );
            }

            return item;
        }

        [[nodiscard]] Ty min() const { return min_.front(); }
    };

    /* Stack of Plates.
     *
     *Imagine a (literal) stack of plates. If the stack gets too high, it might
     *topple. Therefore, in real life, we would likely start a new stack when the previous
     *stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this.
     *
     *Set of stacks should be composed of several stacks and should create a new stack once the
     *previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave
     *identically to a single stack (that is, pop() should  return the same values as it would
     *if there were just a single stack()).
     *
     *FOLLOW UP
     *
     *Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
     */

    template<typename Ty>
    class stack_of_stacks1
    {
        std::vector<std::list<Ty>> stacks_;
        std::size_t threshold_{}, elements_{ };

    public:
			
		/// <summary>
		/// stack of stacks, 1
		///
		/// This approach uses an internal vector of stacks each with size T,
		/// where T is the stack size threshold. The push/pop operations act
		/// as if the stacks get consolidated to the minimum size (of stacks)
		/// required to hold the N total elements.
		/// <complexity>
		///		<run-time>O(1) push, O(N) pop</run-time>
		///		<space>O(N)</space>
		/// </complexity>
		/// </summary>	
        explicit stack_of_stacks1( const std::size_t max_size )
            : threshold_{ max_size }
        { }

        stack_of_stacks1( const std::initializer_list<Ty>& init_list, std::size_t max_size )
            : stack_of_stacks1( max_size )
        {
            for( const auto& item : init_list )
            {
                push_back( item );
            }
        }

        void push_back( const Ty& item )
        {
            const auto stack = elements_ / threshold_;

            if( stacks_.size() <= stack )
                stacks_.resize( stack + 1 );

            stacks_[ stack ].push_back( std::move( item ) );

            elements_++;
        }

        [[nodiscard]] std::size_t size() const
        {
            return stacks_.size();
        }

        [[nodiscard]] bool empty() const { return elements_ == 0; }

        Ty pop() { return pop_at( 0 ); }

        Ty pop_at( const std::size_t index )
        {
            const auto value = stacks_[ index ].back();

            stacks_[ index ].pop_back();

            for( auto current = index; current < size() - 1; current++ )
            {
                stacks_[ current ].push_back( stacks_[ current + 1 ].front() );
                stacks_[ current + 1 ].pop_front();
            }

            if( stacks_.back().empty() )
                stacks_.pop_back();
        	
            elements_--;

            return value;
        }
    };

    /* Queue via Stacks.
     *
     * Implement a MyQueue class which implements a queue using two stacks.
     */

    template<typename Ty>
    class my_queue
    {
        class stack
        {
            std::vector<Ty> data_;

        public:
            explicit stack()
                : data_{ }
            { }

            void push( const Ty& value )
            {
                data_.push_back( value );
            }

            [[nodiscard]] bool empty() const { return data_.empty(); }

            Ty pop()
            {
                const auto value = data_.back();

                data_.pop_back();

                return value;
            }
        };

        stack data_{};

    public:

        /// <summary>
		/// my_queue
		///
		/// This approach uses a stack as the internal storage structure
		/// and then places the internal stack into a new temp stack on a
		/// dequeue operation, returning the top of the internal stack (first
		/// in), then rebalances the internal stack with the remaining n-1
		/// elements.
		/// <complexity>
		///		<run-time>O(N)</run-time>
		///		<space>O(1)</space>
		/// </complexity>
		/// </summary>
        my_queue() = default;

        my_queue( const std::initializer_list<Ty>& init_list )
        {
            for( const auto& value : init_list )
            {
                data_.push( value );
            }
        }

        [[nodiscard]] bool empty() const { return data_.empty(); }
    	
        void enqueue( Ty item )
        {
            data_.push( item );
        }

        Ty dequeue()
        {
            stack tmp;

            while( !data_.empty() )
                tmp.push( data_.pop() );

            const auto value = tmp.pop();

            data_ = stack();

            while( !tmp.empty() )
                data_.push( tmp.pop() );

            return value;
        }
    };

    /* Sort Stack.
     *
     * Write a program to sort a stack such that the smallest items are on the top. You
     * can use an additional temporary stack, but you may not copy the elements into any
     * other data structure (such as an array). The stack supports the following operations:
     *
     * push, pop, peek, and isEmpty
     */

    template<typename Ty>
    class sort_stack
    {
        class stack
        {
            std::vector<Ty> data_;

        public:

            explicit stack()
                : data_{ }
            {}

            void push( const Ty& item )
            {
                data_.push_back( item );
            }

            Ty pop()
            {
                const auto value = data_.back();

                data_.pop_back();

                return value;
            }

            [[nodiscard]] Ty peek() const { return data_.back(); }
            [[nodiscard]] bool empty() const { return data_.empty(); }
        };

        stack data_;

        /// <summary>
        /// pop_min
        ///
        /// This is the worker method for the sorting routing. Here we keep
        /// a running tally of the minimum element as we iterate over the
        /// internal stack, holding it out of the passed in stack each iteration,
        /// then we return the minimum element and the passed in stack now has
        /// n-1 elements.
        /// <complexity>
        ///		<run-time>O(N)</run-time>
        ///		<space>O(N)</space>
        /// </complexity>
        /// </summary>
        static Ty pop_min( stack& s )
        {
            Ty min = s.pop();

            stack tmp;

            while( !s.empty() )
            {
                auto cur = s.pop();

                if( cur < min )
                {
                    tmp.push( min );
                    min = cur;
                }
                else
                {
                    tmp.push( cur );
                }
            }

            s = tmp;

            return min;
        }

    public:

        sort_stack()
            : data_{ }
        {  }

        sort_stack( const std::initializer_list<Ty> init_values )
        {
            for( const auto& val : init_values )
            {
                push( val );
            }
        }

        void push( const Ty& item ) { data_.push( item ); }
        Ty pop() { return data_.pop(); }
        [[nodiscard]] Ty empty() { return data_.empty(); }

        void sort1()
        {
            stack tmp{};

            while( !data_.empty() )
            {
                auto min = pop_min( data_ );
                tmp.push( min );
            }

            data_ = tmp;
        }
    };

    /* Animal Shelter.
     *
     * An animal shelter, which holds only dogs and cats, operates on a strictly
     * "first in, first out" basis. People must adopt either the "oldest" (based on
     * arrival time) of all animals at the shelter, or they can select whether they
     * would prefer a dog or cat (and will receive the oldest animal of that type).
     * They cannot select which specific animal they would like. Create the data
     * structures to maintain this system and implement operations such as enqueue,
     * dequeueAny, dequeueDog and dequeueCat. You may use the built-in LinkedList data
     * structure.
     */

    class animal_shelter;

    class animal
    {
        friend animal_shelter;

        std::size_t tag_{ };

    protected:

        std::string name_;

        void set_tag( const std::size_t tag )
        {
            tag_ = tag;
        }

        void clear_tag() { tag_ = std::size_t(); }
    	
        explicit animal( std::string name )
            : name_{ std::move( name ) }
        { }

    public:

        [[nodiscard]] const std::string& name() const { return name_; }
    	
        bool operator==( const animal& other ) const
        {
            if( &other == this ) return true;

            return tag_ == other.tag_;
        }
    };

    class dog : public animal
    {
    public:
        explicit dog( const std::string& name )
            : animal( name )
        { }

        bool operator==( const dog& other ) const
        {
            return animal::operator==( other );
        }
    };

    class cat : public animal
    {
    public:
        explicit cat( const std::string& name )
            : animal( name )
        {  }

        bool operator==( const dog& other ) const
        {
            return animal::operator==( other );
        }
    };

    class animal_shelter
    {
        template<typename A>
        class queue
        {
            std::list<A> animals_{};

        public:

            [[nodiscard]] std::size_t size() const { return animals_.size(); }
            [[nodiscard]] bool empty() const { return animals_.empty(); }

            A& peek() { return animals_.front(); }

            void enqueue( const A& animal )
            {
                animals_.push_back( animal );
            }

            A dequeue()
            {
                auto item = animals_.front();

                animals_.pop_front();

                return item;
            }
        };

        queue<dog> dogs_{};
        queue<cat> cats_{};

        std::size_t counter_{};

    public:

        animal_shelter() = default;

        animal_shelter( const std::initializer_list<dog>& dogs,
            const std::initializer_list<cat>& cats )
        {
            for( auto dog : dogs )
                enqueue( dog );

            for( auto cat : cats )
                enqueue( cat );
        }

        void enqueue( dog& dog )
        {
            dynamic_cast< animal* >( &dog )->tag_ = ++counter_;
            dogs_.enqueue( dog );
        }

        void enqueue( cat& cat )
        {
            dynamic_cast< animal* >( &cat )->tag_ = ++counter_;

            cats_.enqueue( cat );
        }

        [[nodiscard]] std::size_t size() const { return dogs_.size() + cats_.size(); }
        [[nodiscard]] bool empty() const { return dogs_.empty() && cats_.empty(); }

        animal dequeue_any()
        {
            if( cats_.empty() )
                return dogs_.dequeue();

            if( dogs_.empty() )
                return cats_.dequeue();

            if( cats_.peek().tag_ < dogs_.peek().tag_ )
                return cats_.dequeue();

            return dogs_.dequeue();
        }

        dog dequeue_dog() { return dogs_.dequeue(); }
        cat dequeue_cat() { return cats_.dequeue(); }
    };


    /* Generic Stack.
     *
     * Write a stack implementation for a generic value type. The maximal size
     * of the stack is defined in the class (hard-wired). Provide the following
     * functions:
     *
     * + Constructor;
     * + Destructor (if necessary);
     * + top: show last element;
     * + pop: remove last element (without returning it);
     * + push: insert new element;
     * + clear: delete all entries;
     * + size: number of elements
     */

    template<typename Ty>
    class stack
    {
        std::unique_ptr<Ty[]> data_;
        std::size_t size_{}, capacity_{};

    public:

        explicit stack( const std::size_t capacity = 0 )
            : capacity_{ capacity }
        {
            data_ = std::make_unique<Ty[]>( capacity_ );
        }

        explicit stack( const std::initializer_list<Ty>& init_list )
        {
            resize( init_list.size() );

            for( const auto& value : init_list )
                push( value );
        }

        void resize( const std::size_t new_size )
        {
            auto new_data = std::make_unique<Ty[]>( new_size );

            if( new_size < size_ )
                size_ = new_size;
        	
            std::copy( data_.get(), data_.get() + size_, new_data.get() );
            std::swap( data_, new_data );
        	
            capacity_ = new_size;
        }

        void push( const Ty& value )
        {
            if( size_ >= capacity_ )
                resize( size_ == 0 ? 1 : capacity_ * 2 );

            data_.get()[ size_++ ] = value;
        }

        [[nodiscard]] Ty pop()
        {
            if( size_ == 0 )
                throw std::runtime_error( "CANNOT POP EMPTY STACK" );

            return data_.get()[ --size_ ];
        }
    	
        [[nodiscard]] Ty top() { return data_.get()[ size_ - 1 ]; }

        void clear() { resize( 0 ); }
        [[nodiscard]] auto size() const { return size_; }
        [[nodiscard]] auto empty() const { return size_ == 0; }
    };
}
