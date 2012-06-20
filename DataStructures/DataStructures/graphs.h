/* 
 * File:   graphs.h
 * Author: sushant
 *
 * Created on June 11, 2012, 8:59 AM
 */

#ifndef GRAPHS_H
#define	GRAPHS_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

namespace graphs
{
	class graph
	{
		int _size;
		vector<vector<int> > _adj;
	public:
		graph(int size):_size(size){ _adj.assign(_size, vector<int>());}
		~graph(){};
		int size(){return _size;}
		bool is_edge(int u, int v) {vector<int>::iterator it =  find(_adj[u].begin(),_adj[u].end(),v); return it!=_adj[u].end();}
		void insert(int u, int v)
		{
			if (u>=-1 && u<_size && v>=-1 && v<_size)
			{
				_adj[u].push_back(v);
			}
		}
		void print()
		{
			int s = _adj.size();
			for(int i=0; i<s;++i)
			{
				int s2 = _adj[i].size();
				cout << "[" <<i<<"]";
				for(int j=0; j<s2;++j)
				{
					cout << "--" << _adj[i][j];
				}
				cout << endl;
			}
			cout << endl;
			for_each(_adj.begin(), _adj.end(), [](vector<int>& v) {cout << endl; for_each(v.begin(), v.end(), [](int x) {cout<<"->"<<x;});});
		}
	};
	
	void test()
	{
		graph g(10);
		g.insert(1,3);
		g.insert(1,2);
		g.insert(1,5);
		g.insert(2,7);
		g.insert(2,5);
		g.insert(2,3);
		g.insert(4,9);
		g.insert(0,8);
		g.print();
	}
}
#endif	/* GRAPHS_H */

