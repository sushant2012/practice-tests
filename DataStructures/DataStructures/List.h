#include <iostream>
//#include "hr_time.h"
#include <string>
#include <iomanip>

using namespace std;

namespace List
{
	template<typename T>
	struct List
	{
		struct Node
		{
			T key;
			Node* next;

			Node() : key(T()), next(0) {}
			Node(const T& key) : key(key), next(0) {}
			Node(const T& key, Node* next) : key(key), next(next) {}
		};

		List<T>();
		List<T>(const T* start, const T* end);
		~List<T>();

		size_t size() {return _size;}
		Node* head() {return _head;}
		Node* tail() {return _tail;}


		void insert(const T& key);
		void remove(const T& key);
		void reverse();
		void rotate(size_t r = 1);
		void print();

	private:
		Node* _head;
		Node* _tail;
		size_t _size;
	};

	template<typename T>
	void List<T>::reverse()
	{
//		if (_size == 0 || _size == 1)
//			return;
//		else if (_size == 2)
//		{
//			_head->next->next = _head;
//			_head = _head->next;
//			_head->next->next = 0;
//			return;
//		}
//		else
//		{
			Node* t, *y = _head, *r = 0;
			
			while (y != 0)
			{
				t = y->next;
				y->next = r;
				r = y;
				y = t;
			}
			_head = r;
//		}
		
	}
	
	template<typename T>
	List<T>::~List()
	{
		if (_head == 0)
			return;
		Node *p = _head, *q = p;
		while(q != 0) {
			q = p->next;
			delete p;
			p = q;
		}
	}

	template<typename T>
	List<T>::List() : _head(NULL), _tail(0), _size(0)
	{
	}

	template<typename T>
	List<T>::List(const T* start, const T* end) : _head(0), _tail(0), _size(0)
	{
		Node *t = new Node(), *dummy = t;
		while(start != end) {
			t->next = new Node(*start++);
			t = t->next;
			_size++;
		}
		_tail = t->next = new Node(*end);
		_head = dummy->next;
		_size++;
		delete dummy;
	}

	template<typename T>
	void List<T>::print()
	{
		Node* p = _head;
		while(p != 0) {
			cout << p->key << ", ";
			p = p->next;
		}
		cout << endl;
	}

	void test()
	{
		//CStopWatch sw;
		//sw.startTimer();
		//string s = "SUSHANTSHARMATANUSOHAMHUMA";
		//string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		string s = "ABC";
		List<char> list(&s[0], &s[s.length()-1]);
		//sw.stopTimer();
		//cout << setw(25) << setprecision(12) << sw.getElapsedTime() << endl;
		cout << "Size: " << list.size() << endl;
		list.print();
		list.reverse();
		list.print();
	}
}
