// 2 "FallingSand.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have a rectangular board that is placed vertically.
The board is divided into a grid of unit square cells.
Some grid cells contain obstacles and some cells contain a grain of sand.
All other cells are currently empty.



You are given the description of the board as a String[] board.
The elements of board correspond to rows of the grid in the order from top to bottom.
(E.g., board[0] represents the topmost row of cells.)
Each character in each element of board represents one cell.
The character 'x' represents a cell with an obstacle, 'o' is a grain of sand, and '.' (period) is an empty cell.



You would like to implement a simulation of falling sand.
The rules are as follows:

The obstacles don't move.
Whenever there is an empty cell immediately below a grain of sand, the grain of sand moves into the empty cell.




Return the final configuration of the board after all grains of sand reach their final locations.


DEFINITION
Class:FallingSand
Method:simulate
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> simulate(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will have length between 1 and 50, inclusive.
-All elements of board will have the same length.
-Each character in each element of board will be one of 'x', 'o', and '.'.


EXAMPLES

0)
{"ooooo",
 "..x..",
 "....x",
 ".....",
 "....o"}

Returns: {"..o..", "..x.o", "....x", ".....", "oo.oo" }


The return value is:



{"..o..", 
 "..x.o", 
 "....x", 
 ".....", 
 "oo.oo" }


1)
{"..o..", 
 "..x.o", 
 "....x", 
 ".....", 
 "oo.oo" }

Returns: {"..o..", "..x.o", "....x", ".....", "oo.oo" }



2)
{"ooooxooo.ooxo.oxoxoooox.....x.oo"}

Returns: {"ooooxooo.ooxo.oxoxoooox.....x.oo" }

Nothing changes in this case, since all the sand is already at the bottom of the grid. 

3)
{"o",
 ".",
 "o",
 ".",
 "o",
 ".",
 "."}

Returns: {".", ".", ".", ".", "o", "o", "o" }



4)
{"oxxxxooo",
 "xooooxxx",
 "..xx.ooo",
 "oooox.o.",
 "..x....."}

Returns: {"oxxxxooo", "x.oo.xxx", "..xxo...", ".oo.x.o.", "ooxo.ooo" }


Note the final configuration of sand in the second column from the right.



{"oxxxxooo", 
 "x.oo.xxx", 
 "..xxo...", 
 ".oo.x.o.", 
 "ooxo.ooo"}


5)
{"..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o.",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxx...xxx......xxx............",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o."}

Returns: {".................................", ".................................", "...ooo...ooo...ooooooooo...ooo...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxxoooxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxx...xxx......xxx............", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", ".................................", "ooo.........ooo.........ooo...ooo", "ooooooooooooooooooooooooooooooooo" }



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

class FallingSand {
	public:
	vector <string> simulate(vector <string> board) {
        long sz = board.size();
        long len = board[0].length();
        for (int i = 0; i < len; i++) {
            while (true) {
                bool flg = false;
                for (int j = 0; j < sz - 1; j++) {
                    if (board[j][i] == 'o' && board[j + 1][i] == '.') {
                        board[j][i] = '.';
                        board[j + 1][i] = 'o';
                        flg = true;
                    }
                }
                if (!flg) break;
            }
        }
        return board;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ooooo",
 "..x..",
 "....x",
 ".....",
 "....o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..o..", "..x.o", "....x", ".....", "oo.oo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, simulate(Arg0)); }
	void test_case_1() { string Arr0[] = {"..o..", 
 "..x.o", 
 "....x", 
 ".....", 
 "oo.oo" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..o..", "..x.o", "....x", ".....", "oo.oo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, simulate(Arg0)); }
	void test_case_2() { string Arr0[] = {"ooooxooo.ooxo.oxoxoooox.....x.oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ooooxooo.ooxo.oxoxoooox.....x.oo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, simulate(Arg0)); }
	void test_case_3() { string Arr0[] = {"o",
 ".",
 "o",
 ".",
 "o",
 ".",
 "."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".", ".", ".", ".", "o", "o", "o" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, simulate(Arg0)); }
	void test_case_4() { string Arr0[] = {"oxxxxooo",
 "xooooxxx",
 "..xx.ooo",
 "oooox.o.",
 "..x....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"oxxxxooo", "x.oo.xxx", "..xxo...", ".oo.x.o.", "ooxo.ooo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, simulate(Arg0)); }
	void test_case_5() { string Arr0[] = {"..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o.",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxxxxxxxx......xxx......xxx...",
 "...xxx...xxx......xxx............",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "...xxx...xxx...xxxxxxxxx...xxx...",
 "..o..o..o..o..o..o..o..o..o..o..o",
 "o..o..o..o..o..o..o..o..o..o..o..",
 ".o..o..o..o..o..o..o..o..o..o..o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".................................", ".................................", "...ooo...ooo...ooooooooo...ooo...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxxoooxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxx...xxx......xxx............", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", ".................................", "ooo.........ooo.........ooo...ooo", "ooooooooooooooooooooooooooooooooo" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, simulate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	FallingSand ___test;
	___test.run_test(-1);
}

// END CUT HERE
