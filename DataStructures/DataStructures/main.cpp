#include "simple_list.h"
#include <functional>
#include <algorithm>

int main(int argc, char *argv[])
{
	simple_list::slist sl;
	int a[40];
	for(int i=0; i<40; ++i)
		sl.insert(i+1);
	
	sl.print();
	return 0;
}
