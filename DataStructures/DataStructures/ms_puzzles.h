/* 
 * File:   ms_puzzles.h
 * Author: sushant
 *
 * Created on June 1, 2012, 1:10 PM
 */

#ifndef MS_PUZZLES_H
#define	MS_PUZZLES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

namespace ms_puzzles {

	namespace bit_stream
	{	
		struct bit_stream_t
		{
			void readBit(){bit = rand()%2;}
			void writeBit() {printf("[rem: %02d, div: %s] ", remainder, (remainder?"no":"yes"));}
			void updateStatus(){remainder = (remainder*2 + bit) % divider; divisible = 0 == remainder;}
			int remainder;
			int bit;
			bool divisible;
			int divider;
		};
		
		void DivTest(int divider)
		{
			bit_stream_t bitstream;
			bitstream.bit = 0;
			bitstream.remainder = 0;
			bitstream.divider = divider;
			while(true)
			{
				bitstream.readBit();
				bitstream.updateStatus();
				bitstream.writeBit();
			}
		}
		
		void test()
		{
			DivTest(5);
		}
	}
	namespace reverse {
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
}

#endif	/* MS_PUZZLES_H */

