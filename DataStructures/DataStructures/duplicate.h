#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include "List.h"
#include <functional>
#include <assert.h>

namespace duplicate {

	struct plusone {
		int count;

		plusone() : count(1) {
		}

		int operator()() {
			return count++;
		}
	};

	struct sum {
		int s1, s2;

		sum() : s1(0), s2(0) {
		}

		void operator()(int x) {
			s1 += x;
			s2 += x*x;
		}
	};

	void test() {

		vector<int> v(100);
		generate(v.begin(), v.end(), plusone());
		int i = rand() % 100, j = rand() % 100;
		assert(i != j);
		cout << "Missing: " << v[i] << endl;
		cout << "Repeatd: " << v[j] << endl;
		v[i] = v[j];
		sum s = for_each(v.begin(), v.end(), sum());

		long C1 = 100 * 101 / 2;
		long C2 = 100 * 101 * 201 / 6;
		long S1 = s.s1;
		long S2 = s.s2;
		long D1 = C1 - S1;
		long D2 = C2 - S2;
		long M = (D1 + D2 / D1) / 2;
		long D = -(D1 - D2 / D1) / 2;

		cout << "N(N+1)/2      : " << C1 << endl;
		cout << "N(N+1)(2N+1)/6: " << C2 << endl;
		cout << "N(N+1)/2      : " << s.s1 << endl;
		cout << "N(N+1)(2N+1)/6: " << s.s2 << endl;
		cout << "Missing: " << M << endl;
		cout << "Repeatd: " << D << endl;
		//transform(v.begin(), v.end(), v.begin(), bind2nd(modulus<int>(), 100));
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
		cout << endl;
		//List::test();
	}
}
