//#include "simple_list.h"
//#include "ms_puzzles.h"
//#include "BSTree.h"
//#include "ms_puzzles.h"
//#include <vector>

#include "graphs.h"
#include "cppfeatures.h"
#include <iomanip>

void print_matrix(vector<vector<int> >& a, int row, int col)
{
	cout << "    ";
	for(int i=0; i<col; ++i)
		cout << "[" << setw(2) << i << "]";
	cout << endl;
	
	for(int i=0; i<row; ++i)
	{
		cout << "["<< setw(2) << i <<"]";
		for(int j=0; j<col; ++j)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void get_sorted_matrix(vector<vector<int> >& a, int row, int col, int mod)
{	
	a[0][0] = rand()%mod + 1;
	for(int j=1; j<col;++j)
	{
		a[0][j] = a[0][j-1] + rand()%mod;
		a[j][0] = a[j-1][0] + rand()%mod;
	}
	for(int i = 1; i<row; ++i)
	{
		for(int j=1; j<col; ++j)
		{
			int t = a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
			a[i][j] = t+rand()%(mod);
		}
	}
}

int max(int a, int b)
{
	return a>b?a:b;
}
int min(int a, int b)
{
	return a<b?a:b;
}

void found(bool flag, int r, int c)
{
	char result[][10] = {"FOUND", "NOT FOUND"};
	cout << "Result: " << result[(int)flag] << " at (" << r << "," << c <<")" << endl;
}

bool binary_search_col(vector<vector<int> >& a, int row, int& from, int& to, int n)
{
	if (n == a[row][from])
	{
		from = to = from;
		return true;
	}
	else if (n == a[row][to])
	{
		from = to = to;
		return true;
	}
	else
	{
		
	}
}

bool binary_search_row(vector<vector<int> >& a, int col, int from, int to)
{
	
}

void matrix_search_2(vector<vector<int> >& a, int row, int col, int n)
{
	
}
void matrix_search(vector<vector<int> >& a, int row, int col, int n)
{
	print_matrix(a, row, col);
	cout << "Search for: " << n << endl;
	
	//2D binary search
	if (n>=a[0][0] && n<=a[row-1][col-1])
	{
		if (n==a[0][0])
			found(true, 0, 0);
		else if (n==a[row-1][col-1])
			found(true, row-1,col-1);
		else
		{
			int r1(0), r2(row), c1(0), c2(col);
			int r, c;
			r = (r1+r2)/2;
			c = (c1+c2)/2;
			int past[6] = {r1,c1,r,c,r2,c2};
			do
			{
				past[0]=r1;past[1]=c1;past[2]=r;past[3]=c;past[4]=r2;past[5]=c2;
				r = (r1+r2)/2;
				c = (c1+c2)/2;
				cout << "(r1,c1)(r,c)(r2,c2) = "<< r1 << " "<< c1 << " "<< r << " "<< c << " "<< r2 << " "<< c2 << " "<<endl;
				if(n == a[r][c])
				{
					found(true, r, c);
					return;
				}
				else if (n<a[r][c])
				{
					r2 = r; c2 = c;
				}
				else
				{
					r1 = r; c1 = c;
				}
			}
			while(past[0]!=r1 || past[1]!=c1 || past[2]!=r || past[3]!=c || past[4]!=r2 || past[5]!=c2);
			
			
				
				
		}
	}
	else
	{
		found(false, -1, -1);
	}
}

double fact(double n)
{
	if (n==1)
	{
		cout << setw(3) << 1 << ": " << 1 << endl;
		return 1;
	}
	else
	{
		double f = n*fact(n-1);
		cout << setw(3) << n << ": " << f << endl;
		return f;
	}
}

void test_factorial()
{
	fact(30);
}

void test_matrix_search()
{
#define ROW 10
#define COL 10
#define MOD 100
	int row = ROW, col = COL, mod = MOD;
	vector<vector<int> > a(row, vector<int>(col));
	get_sorted_matrix(a, row, col, mod);
	print_matrix(a, row, col);
	int n;
	while(cin >> n)
	{
		matrix_search(a, row, col, n);
	}
}

int main(int argc, char *argv[])
{
	cppfeautures::test();
	//test_factorial();
	//test_matrix_search();
	//simple_list::test();
	//ms_puzzles::bit_stream::test();
	//ms_puzzles::arrays::test_zero_one();
	//ms_puzzles::arrays::test_permutation();
	//ms_puzzles::recursive::test_TOH();
	//ms_puzzles::recursive::test_permutation();
	//graphs::test();
	return 0;
}	
