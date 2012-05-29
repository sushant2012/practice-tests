#include <boost\thread.hpp>
#include <algorithm>
#include <iostream>

using namespace std;

namespace boost_thread
{
	int count = 0;
	void wait(int seconds=250) 
	{
		boost::this_thread::sleep(boost::posix_time::millisec(seconds)); 
	}

	boost::mutex m;

	void print(int tid)
	{
		m.lock();
		for(int i=0; i<20; i++)
		{
			cout << boost::this_thread::get_id() << ": " << i << endl;
			//wait();
		}
		//m.unlock();
	}

	void printEven()
	{
		for(int i=0; i<30; i+=2)
		{
			count += 2;
			cout << "ODD : " << count << endl;
			wait();
		}
	}

	void printOdd()
	{
		for(int i=1; i<30; i+=2)
		{
			count +=2;
			cout << "EVEN: " << count << endl;
			wait();
		}
	}

	void test()
	{
		boost::thread t1(print, 100); 
		boost::thread t2(print, 200); 
		t1.join();
		t2.join();
	}
}
