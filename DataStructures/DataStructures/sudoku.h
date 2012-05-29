#include <iostream>
#include <array>
#include <set>

using namespace std;

namespace sudoku {
	class sudoku
	{
	public:
		sudoku(array<array<set<int>,9>,9>& in) : a(in) {};

	private:
		array<array<set<int>,9>,9> a;
	};
}