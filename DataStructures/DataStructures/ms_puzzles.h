/* 
 * File:   ms_puzzles.h
 * Author: sushant
 *
 * Created on June 1, 2012, 1:10 PM
 */

#ifndef MS_PUZZLES_H
#define	MS_PUZZLES_H

namespace ms_puzzles {

#include <iostream>
	using namespace std;

	//reverse a c-string without using a loop construct like while, for etc.

	void reverse(char p[]) {
		if (*p == '\0')
			return;
		reverse(p + 1);
		cout << *p;
	}

	void test() {
		char a[] = "My name is Sushant";
		reverse(a);
	}
}

#endif	/* MS_PUZZLES_H */

