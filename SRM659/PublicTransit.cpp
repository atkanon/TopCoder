// 2 "PublicTransit.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Note that this problem has a time limit of 5 seconds.


The city of Gridlock is a grid of cells with R rows and C columns. Each cell has up to four neighbours: the cells directly above, below, to the left, and to the right. A citizen of Gridlock can travel from a cell to any of its neighbours in one minute.


The citizens of Gridlock are upset that it takes too long to get around, so they have decided to build a teleporter. The teleporter will consist of two identical booths, each located in some cell. If a citizen enters either booth, he or she may choose to teleport to the other booth instantly. It is allowed to build both booths in the same cell.


We define the distance between two cells as the minimum number of minutes needed to get from one cell to another. Let D be the maximum distance between any two cells. Place the teleporter in such a way that D is minimized, and return this minimum value.

DEFINITION
Class:PublicTransit
Method:minimumLongestDistance
Parameters:int, int
Returns:int
Method signature:int minimumLongestDistance(int R, int C)


CONSTRAINTS
-R is between 1 and 10, inclusive.
-C is between 1 and 10, inclusive.


EXAMPLES

0)
4
1

Returns: 1

The optimal solution is to connect cell (1, 1) to cell (4, 1). (All cell coordinates are 1-based.)

1)
2
2

Returns: 1



2)
5
3

Returns: 4



3)
8
2

Returns: 4



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

typedef long long LL;

class PublicTransit {
	public:
	int minimumLongestDistance(int R, int C) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, minimumLongestDistance(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, minimumLongestDistance(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, minimumLongestDistance(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 2; int Arg2 = 4; verify_case(3, Arg2, minimumLongestDistance(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	PublicTransit ___test;
	___test.run_test(-1);
}

// END CUT HERE
