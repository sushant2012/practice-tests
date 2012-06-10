/* 
 * File:   simple_list.h
 * Author: sushant
 *
 * Created on June 1, 2012, 1:12 PM
 */

#ifndef SIMPLE_LIST_H
#define	SIMPLE_LIST_H

#include <iostream>
using namespace std;

namespace simple_list {

	struct snode {
		int key;
		snode* next;

		snode(int key) : key(key), next(0) {
		}
	};

	struct dnode {
		int key;
		dnode* next;
		dnode* prev;

		dnode(int key, dnode * prev) : key(key), next(0), prev(prev) {
		}
	};

	class slist {
		snode* _head;
	public:
		slist() : _head(0){}
		void insert(int key);
		void reverse();
		void skip_reverse(int m, int n);
		void print();
		~slist();
	};

	void slist::insert(int key) {
		if (!_head) {
			_head = new snode(key);
			return;
		}
		snode * q(_head), *p;
		while (q && (p = q->next)) q = p;
		q->next = new snode(key);
	}

	slist::~slist() {
		snode * p(_head), *q;
		while (p) {
			q = p;
			p = q->next;
			delete q;
		}
	}

	void slist::reverse()
	{
		snode* t, *curr(_head), *rhead(0);
		while(curr)
		{
			t = curr->next;
			curr->next = rhead;
			rhead = curr;
			curr = t;
		}
		_head = rhead;
	}
	
	void slist::skip_reverse(int s, int r)
	{
		int ss=0, rr=0;
		if (ss>s || rr>r) return;
		snode* curr(_head), *tail;
		while (curr)
		{
			while (ss < s && curr)
			{
				tail = curr;
				curr = curr->next;
				ss++;
			}
			if (ss < s) return;
			ss = 0;
			snode* t, *rev(0), *head(curr);
			while (curr && rr < r)
			{
				t = curr->next;
				curr->next = rev;

				rev = curr;
				curr = t;

				rr++;
			}
			if (rr == 0) return;
			tail->next = rev;
			head->next = curr;
			rr = 0;
		}
	}
	
	void slist::print() {
		snode * p(_head);
		while (p) {
			std::cout << p->key << ",";
			p = p->next;
		}
		cout << endl;
	}

	void test() {
		slist sl;
		for (int i = 0; i < 2; ++i)
			sl.insert(i + 1);
		sl.print();
		sl.reverse();cout << "Reverse:" << endl;
		sl.print();
		sl.reverse();
		sl.skip_reverse(1,3);cout << "Skip Reverse:" << endl;
		sl.print();
	}
}



#endif	/* SIMPLE_LIST_H */

