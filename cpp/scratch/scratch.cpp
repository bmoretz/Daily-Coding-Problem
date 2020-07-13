#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <utility>
#include "../hackerrank/problem.h"

using namespace hackerrank;

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

auto main() -> int
{
	const auto problem =
        multiple_inherited_functions{"accessing-inherited-functions-testcases"};

	return problem.run();
}
