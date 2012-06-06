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
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <unordered_map>

using namespace std;

namespace ms_puzzles {
	
	namespace arrays
	{
		int randno() { return rand()%200-100; }
		void test_permutation()
		{
			vector<int> v1(30), v2(30);
			generate(v1.begin(), v1.end(), [](){return rand()%200-100;});
			copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ",")); cout << endl;
			transform(v1.begin(), v1.end(), v1.begin(), bind2nd(modulus<int>(), 100));
			copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ",")); cout << endl;
			v2 = v1;
			copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ",")); cout << endl;
			random_shuffle(v2.begin(), v2.end());
			copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ",")); cout << endl;
			
			unordered_map<int, int> count;
			for_each(v1.begin(), v1.end(), [&count](int x) {count[x]++;});
			for_each(count.begin(), count.end(), [](auto x))
			for(auto x: count) {
				cout << x.first << ", "      << x.second << endl;
			}
			
			
			
		}

#define SIZE 7
		
	  void print_array(int a[][SIZE], int R, int C, int div=10)
		{
			for(int i=0; i<R; ++i)
			{
				for(int j=0; j<C;++j)
				{
					printf("%2d ", a[i][j]%div);
				}
				printf("\n");
			}
			printf("\n");
		}
		
		void test_zero_one()
	    {
			int R(SIZE), C(SIZE), r, c;
			int a[SIZE][SIZE];
			for(int i=0; i<R*C; ++i)
			{
				r = i/R;
				c = i%C;
				a[r][c] = 0;
			}

			int rn = rand()%SIZE;

			//Radomly set rn elements to 1
			for(int i=0; i<rn; ++i)
			{
			      a[rand()%SIZE][rand()%SIZE] = 1;
			}
			a[5][3] = 1;
			print_array(a, R, C);
			
			for(int i=0; i<SIZE; ++i)
			{
				for(int j=0; j<SIZE; ++j)
				{
				        if (a[i][j]%10==1)
					{
					        a[0][j] = 10 + a[0][j]%10;
					        a[i][0] = 10 + a[i][0]%10;
					}
				}
			}
			print_array(a, R, C);
			for(int i=0; i<SIZE; ++i)
			{
				for(int j=0; j<SIZE; ++j)
				{
				        if ( a[0][j]/10 == 1 || a[i][0]/10 == 1 )
				        {
					        int t = a[i][j]/10;
					        a[i][j] = t*10 + 1;
				        }
				}
			}
			print_array(a, R, C);
		}
	}
	
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

