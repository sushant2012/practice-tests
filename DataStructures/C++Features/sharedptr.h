#include <iostream>
#include <memory>

using namespace std;

namespace sharedptr
{
	void* Create() {
		int *a = new int[100];
		cout << "Create void pointer!" << endl;
		return a;
	}

	void Destroy(void* a) {
		cout << "Call delete[] on void pointer!" << endl;
		delete[] a;
	}

	void test()
	{
		shared_ptr<void> sh(Create(), Destroy);
	}
}
