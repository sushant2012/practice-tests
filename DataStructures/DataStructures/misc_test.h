#include <iostream>

using namespace std;

void testEndian()
{
	int s = sizeof(int);
	int n = 0xFFFFFFFF;
	for(int i=0; i<s; ++i)
	{
		char* c = (char*)&n;
		printf("%p\n",c+i);
	}
}

void testHiding()
{
	class A
	{
	public:
		virtual void func(int a) { cout << "A" << endl;}
	};

	class B : public A
	{
	public:
		//void func(int a) { cout << "B1" << endl;}
		void func(int a, int b){ cout << "B" << endl;}
	};

	A a;
	B b;
	a.func(1);
	//b.func(1);
	b.func(1, 2);
}
