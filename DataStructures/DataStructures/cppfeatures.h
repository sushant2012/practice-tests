#include <iostream>

using namespace std;

namespace cppfeautures
{
	class Base
	{
	public:
		virtual void print(){cout << "Base" << endl;}
	};
	
	class A : virtual public Base
	{
	public:
		virtual void print(){cout << "A" << endl;}
	};
	
	class B : virtual public Base
	{
	public:
		//virtual void print(){cout << "B" << endl;}
	};
	
	class D : public A, public B
	{
	public:
		//virtual void print(){cout << "D" << endl;}
	};
	
	void test()
	{
		D d;
		Base &b = d;
		b.print();
	}

}