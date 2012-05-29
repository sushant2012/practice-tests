#include <iostream>
#include "hr_time.h"

using namespace std;

namespace cracking
{
	void reverse(char* s)
	{
		cout << s << endl;
		CStopWatch w;
		w.startTimer();
		int size = 0;
		char *p = s;
		while(*p != 0 ) {
			++size; p++;
		}
		int mid = size/2;
		for(int i=0; i<mid; ++i) {
			char t = s[i];
			s[i] = s[size-1-i];
			s[size-1-i] = t;
		}
		w.stopTimer();
		cout << s << endl;
		cout << w.getElapsedTime() << endl;
	}

	void reverse2(char* s)
	{
		cout << s << endl;
		char *p(s), *q(s);
		while(*q) q++;
		--q;
		while(p<q) {
			char t = *p;
			*p = *q;
			*q = t;
			p++, q--;
		}
		cout << s << endl;
	}

	void test()
	{
		char s[] = "SUSHANT SHARMA";
		cracking::reverse(s);
		cracking::reverse2(s);
	}
}