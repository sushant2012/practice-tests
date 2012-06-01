/* 
 * File:   simple_list.h
 * Author: sushant
 *
 * Created on June 1, 2012, 1:12 PM
 */

#ifndef SIMPLE_LIST_H
#define	SIMPLE_LIST_H


namespace simple_list {

#include <iostream>
	
	using namespace std;
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
		void insert(int key);
		void print();
		~slist();
	};

	void slist::insert(int key) {
		if (!_head) {
			_head = new snode(key);
			return;
		}
		snode * q(_head), *p;
		while(q && p=q->next) q = p;
		q->next = new snode(key);
	}
	
	slist::~slist()
	{
		snode* p(_head), *q;
		while(p)
		{
			q = p;
			p = q->next;
			delete q;
		}
	}
	
	void slist::print()
	{
		snode* p(_head);
		while(p)
		{
			cout << p->key << ",";
			p = p->next;
		}
	}
}



#endif	/* SIMPLE_LIST_H */

