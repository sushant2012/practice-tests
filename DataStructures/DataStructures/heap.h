#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

namespace heap {

	template<typename T>
	class heap
	{
	private:
		static const string _mark;
		map<int, int> _inpath;
	public:
		heap(){}
		heap(typename vector<T>::iterator begin, typename vector<T>::iterator end) { while(begin!=end) push(*begin++); }
		~heap(){}

		void print();
		void pretty_print();

		T top()
		{
			if (_v.size() > 0 )
				return _v.front();
			else
				throw("Illegal call top() for empty heap!");
		}

		void push(const T& elem)
		{
			cout << "PUSH(" << elem << ")" << endl;
			_v.push_back(elem);
			_inpath.clear();
			//HEAPIFY = bubble up
			int j = _v.size()-1;
			int i = (j)/2;
			while(j>0) {
				if (_v[i]<_v[j]) {
					swap(_v[i], _v[j]);
					_inpath[i] = _inpath[j] = 1;
				}
				j = i;
				i = (j)/2;
			}
		}

		void pop()
		{
			cout << "POP()" << endl;
			_v.front() = _v.back();
			_v.pop_back();
			_inpath.clear();
			//HEAPIFY = bubble down
			unsigned int i = 0, ii(-1), j, k;
			while(i<_v.size() && ii!=i) {
				j = 2*i+1;
				k = j+1;
				ii = i;

				if (k<_v.size())
				{
					int m = _v[j] > _v[k]  ? j : k;
					if (_v[i] < _v[m]) {
						swap(_v[i], _v[m]);
						_inpath[i] = _inpath[m] = 1;
						i = m;
					}
				}

				else if (j<_v.size())
				{
					if (_v[i] < _v[j]) {
						swap(_v[i], _v[j]);
						_inpath[i] = _inpath[j] = 1;
						i = j;
					}
				}

				else
					break;
			}
			return;
		}

	private:
		std::vector<T> _v;
	};

	template<typename T>
	void heap<T>::print()
	{
		typename vector<T>::iterator s(_v.begin());
		while(s!=_v.end()) {
			cout << *s << ", ";
			s++;
		}
		cout << endl;
	}

	template<typename T>
	void heap<T>::pretty_print()
	{
		int level(0);
		long temp(static_cast<long>(_v.size()));
		unsigned int i(0), n(1), j(0);
		while(temp>0) {
			++level;
			temp = temp - n;
			n = n<<1;
		}
		n = 1;
		int len(1);
		while(level>0) {
			len = len*2;
			--level;
		}
		string cell = "    |";
		while (i<_v.size()) {
			cout << string( (len-n)*5/2, ' ');
			while(i<_v.size() && j<n)
			{
				int index = _inpath[i];
				printf("%c%2d%c ", _mark[index],_v[i++], _mark[index+2]);
				j++;
			}
			cout << endl;
			j = 0;
			n = n<<1;
		}
	}

	template<typename Iter>
	void print(Iter beg, Iter end)
	{
		Iter s(beg);
		while(s!=end) {
			cout << *s << ", ";
			s++;
		}
		cout << endl;
	}

	const string heap<int>::_mark = " [ ]";

	void test()
	{
		
		int a[] = {23, 45, 12, 3, 5, 8, 10, 22, 15, 31, 12, 15, 34, 75, 67, 55, 42, 71};

		vector<int> darr(a, a+18);
		print<vector<int>::iterator>(darr.begin(), darr.end());

		heap<int> myHeap(darr.begin(), darr.end());

		myHeap.print();
		myHeap.pretty_print();
		myHeap.pop();
		myHeap.pretty_print();
		myHeap.push(100);
		myHeap.pretty_print();
		myHeap.push(99);
		myHeap.pretty_print();
		myHeap.push(100);
		myHeap.pretty_print();
		myHeap.pop();
		myHeap.pretty_print();
		myHeap.push(99);
		myHeap.pretty_print();
		myHeap.push(110);
		myHeap.pretty_print();
		myHeap.push(92);
		myHeap.pop();
		myHeap.pretty_print();
		myHeap.pop();
		myHeap.pretty_print();
		myHeap.pop();
		myHeap.pretty_print();
	}
}
