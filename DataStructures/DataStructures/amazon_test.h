/* 
 * File:   amazon_test.h
 * Author: sushant
 *
 * Created on May 17, 2012, 11:42 PM
 */

#ifndef AMAZON_TEST_H
#define AMAZON_TEST_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> L1;
queue<int> R1;
queue<int> L2;
queue<int> R2;

bool sameBSTArraysHelper(const vector<int>& V1, const vector<int>& V2, int i1, int i2) {
	if (i1 == V1.size() && i2 == V2.size())
		return true;
	do {
		cout << "First do: " << V1[i1] << endl;
		if (V1[i1] < L1.front())
			L1.push(V1[i1++]);
		else //if (V1[i1] >= R1.front())
			R1.push(V1[i1++]);
	} while ((L1.size() < 2 || R1.size() < 2) && i1 < V1.size());

	do {
		cout << "Second do: " << V2[i2] << endl;
		if (V2[i2] < L2.front())
			L2.push(V2[i2++]);
		else //if (V2[i2] >= R2.front())
			R2.push(V2[i2++]);
	} while ((L2.size() < 2 || R2.size() < 2) && i2 < V2.size());

	L1.pop();
	L2.pop();
	R1.pop();
	R2.pop();
	if (!(L1.empty() || L1.empty()) && L1.front() == L2.front() && !(R1.empty() || R1.empty()) && R1.front() == R2.front()) {
		return sameBSTArraysHelper(V1, V2, i1, i2);
	} else
		return false;
}

bool sameBSTArrays(const vector<int>& V1, const vector<int>& V2) {
	if (V1.size() != V2.size())
		return false;
	else if (V1[0] != V2[0])
		return false;
	else {
		L1.push(V1[0]);
		L2.push(V1[0]);
		R1.push(V1[0]);
		R2.push(V1[0]);
		return sameBSTArraysHelper(V1, V2, 1, 1);
	}
}

void test()
{
	vector<int> V1;
	for (int i = 0; i < 10; i++) {
		V1.push_back(rand()%200 - 100);
	}
	
	vector<int> V2(V1);
	
	for_each(V1.begin(), V1.end(), out); cout << endl;
	//random_shuffle(V2.begin(), V2.end());
	for_each(V2.begin(), V2.end(), out); cout << endl;
	
	if (sameBSTArrays(V1, V2))
		cout << "Same!" << endl;
	else
		cout << "Different!" << endl;
}
#endif	/* AMAZON_TEST_H */
