#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <list>

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

	std::string name_;
	std::size_t tag_{ };

protected:

	void set_tag( const std::size_t tag )
	{
		tag_ = tag;
	}

	void clear_tag() { tag_ = std::size_t(); }
	
public:
	
	explicit animal( std::string& name )
	{
		name_ = std::move( name );
	}
};

class dog : public animal
{
	explicit dog(std::string& name )
		: animal(name)
	{  }
};

class cat : public animal
{
};

class animal_shelter
{
	template<typename A>
	class queue
	{
		std::list<A> animals_ {};

		public:

		[[nodiscard]] std::size_t size() const { return animals_.size(); }
		[[nodiscard]] bool empty() const { return animals_.empty(); }

		A& peek() { return animals_.front(); }
		
		void enqueue( const A& animal )
		{
			animals_.push_back( animal );
		}

		A& dequeue()
		{
			auto& item = animals_.front();

			animals_.pop_front();

			return item;
		}
	};
	
	queue<dog> dogs_ {};
	queue<cat> cats_ {};

	std::size_t counter_ {};

public:

	animal_shelter() = default;
	
	animal_shelter( const std::initializer_list<dog>& dogs,
		const std::initializer_list<cat>& cats )
	{
		for( const auto& dog : dogs )
			enqueue( dog );

		for( const auto& cat : cats )
			enqueue( cat );
	}
	
	void enqueue( const dog& dog )
	{
		static_cast< animal >( dog ).set_tag( ++counter_ );
		dogs_.enqueue( dog );
	}
	
	void enqueue( const cat& cat )
	{
		static_cast< animal >( cat ).set_tag( ++counter_ );
		cats_.enqueue( cat );
	}

	[[nodiscard]] std::size_t size() const { return dogs_.size() + cats_.size(); }
	[[nodiscard]] bool empty() const { return dogs_.empty() && cats_.empty(); }
	
	animal& dequeue_any()
	{
		if( cats_.empty() )
			return dogs_.dequeue();

		if( dogs_.empty() )
			return cats_.dequeue();

		if( cats_.peek().tag_ < dogs_.peek().tag_ )
			return cats_.dequeue();

		return dogs_.dequeue();
	}

	dog& dequeue_dog() { return dogs_.dequeue(); }
	cat& dequeue_cat() { return cats_.dequeue(); }
};

auto main() -> int
{
	auto shelter = animal_shelter{ };

}