//#include "simple_list.h"
//#include "ms_puzzles.h"
#include "BSTree.h"
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
	//simple_list::test();
	//ms_puzzles::bit_stream::test();
	//ms_puzzles::arrays::test_zero_one();
	//ms_puzzles::arrays::test_permutation();
	//ms_puzzles::recursive::test_TOH();
	trees::BSTree<int> tree;
	vector<int> v {0,1,2,3,4,5,6,7,8,9,10,11};
	trees::BSTree<int>::Link t;
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [&tree](int x){tree.insert(x);});
	cout << "Min: "<< ((t=tree.min())?t->key:-1) << endl;
	cout << "Max: "<< ((t=tree.max())?t->key:-1) << endl;
	cout<<"Intrav"<<endl;tree.intrav();
	cout<<"Pretrav"<<endl;tree.pretrav();
	cout<<"Postrav"<<endl;tree.postrav();
	cout<<"Leveltrav"<<endl;tree.leveltrav();
	
	return 0;
}
