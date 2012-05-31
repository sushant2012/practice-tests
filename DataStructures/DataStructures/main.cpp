//#include <algorithm>
//#include <vector>
//#include <utility>
//#include <iterator>
//#include "List.h"
//#include <functional>
//#include <assert.h>
//#include "duplicate.h"
#include <iostream>
using namespace std;

void reverse(char p[])
{
	if (*p=='\0')
		return;
	reverse(p+1);
	cout << *p;
}

int main(int argc, char *argv[])
{
	char a[] = "My name is Sushant";
	reverse(a);
	return 0;
}
