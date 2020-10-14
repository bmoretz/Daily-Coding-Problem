#include <bits/stdc++.h>

/* 642. Design Search Autocomplete System.

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each
character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same
degree of hot, you need to use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, then just return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of
previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters
('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your
system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.
 
Example:

Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
The system have already tracked down the following sentences and their corresponding times:
"i love you" : 5 times
"island" : 3 times
"ironman" : 2 times
"i love leetcode" : 2 times
Now, the user begins another search:

Operation: input('i')
Output: ["i love you", "island","i love leetcode"]
Explanation:
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.

Operation: input(' ')
Output: ["i love you","i love leetcode"]
Explanation:
There are only two sentences that have prefix "i ".

Operation: input('a')
Output: []
Explanation:
There are no sentences that have prefix "i a".

Operation: input('#')
Output: []
Explanation:
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.

Note:

The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
Please use double-quote instead of single-quote when you write test cases even for a character input.
Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.
 
*/

class AutocompleteSystem
{
	struct node
	{
        std::unordered_map<char, node*> children;
        std::string str{};
        int count{};

        node() {  }
	};

    node* root_;
    node* current_;
    std::string current_search_;

    struct match_compare
    {
		bool operator()( const std::pair<std::string, int>& left,
            const std::pair<std::string, int>& right ) const
		{
	        return left.second < right.second ||
	            left.second == right.second && left.first > right.first;
	    }
    };
	
    std::priority_queue<std::pair<std::string, int>,
        std::vector<std::pair<std::string, int>>,
        match_compare> matches_;

	void insert( std::string& str, const int times ) const
	{
        auto current = root_;

		for( auto chr : str )
		{
			if( !current->children.count(chr) )
			{
                current->children[ chr ] = new node();
			}

            current = current->children[ chr ];
		}

        current->count += times;
        current->str = str;
	}

	void search( node* temp )
	{
		if( !temp->str.empty() )
		{
            matches_.push( { temp->str, temp->count } );
		}

		for( auto& cp : temp->children )
		{
            search( cp.second );
		}
	}
	
public:

    AutocompleteSystem( std::vector<std::string>& sentences, std::vector<int>& times )
    {
        root_ = new node();

    	for( auto index = 0; index < sentences.size(); ++index )
    	{
            insert( sentences[ index ], times[ index ] );
    	}

        current_ = root_;
    }

	std::vector<std::string> input( const char c )
    {
        matches_ = std::priority_queue<std::pair<std::string, int>,
            std::vector<std::pair<std::string, int>>,
            match_compare>();

    	if( c == '#' )
    	{
            insert( current_search_, 1 );
            current_search_ = "";
            current_ = root_;

            return { };
    	}

        current_search_ += c;

    	if( current_ && current_->children.count( c ) )
    	{
            current_ = current_->children[ c ];
    	}
    	else
    	{
            current_ = nullptr;
            return { };
    	}

        search( current_ );

        std::vector<std::string> results;

    	while( !matches_.empty() && results.size() < 3 )
    	{
            results.push_back( matches_.top().first );
            matches_.pop();
    	}
    	
        return results;
    }
};

auto main() -> int
{
    auto word_list = std::vector<std::string>{ "i love you","island","iroman","i love leetcode" };
    auto word_freq = std::vector<int>{ 5, 3, 2, 2 };
	
    auto ac = AutocompleteSystem( word_list, word_freq );

    auto r2 = ac.input( ' ' );
    auto r3 = ac.input( 'a' );
    auto r4 = ac.input( '#' );

    auto r5 = ac.input( 'i' );
    auto r6 = ac.input( ' ' );
    auto r7 = ac.input( 'a' );
    auto r8 = ac.input( '#' );
	
	return 0;
}