// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A 8x8 chessboard is usually marked as follows: rows are marked by digits, 1 through 8, and columns are marked by letters, 'a' through 'h'. A cell is described by its column mark and then its row mark, like "e4".

While working on a chess program, you need to convert these descriptions into your internal cell numbers and back. Internally, cells are numbered row-by-row from 1 to 64 in your program, i.e., cell "a1" has number 1, cell "b1" has number 2, cell "c1" has number 3, ..., cell "h8" has number 64.

Given a String cell, describing either the cell mark or the cell number, change the notation (i.e., if you're given the mark you need to return the number, and vice versa).

DEFINITION
Class:Chessboard
Method:changeNotation
Parameters:string
Returns:string
Method signature:string changeNotation(string cell)


CONSTRAINTS
-cell will contain either a cell mark or a cell number.
-If cell contains a cell mark, it will contain exactly 2 characters: a lowercase letter between 'a' and 'h', inclusive, followed by a digit between '1' and '8', inclusive.
-If cell contains a cell number, it will be an integer between 1 and 64, inclusive, without leading zeros.


EXAMPLES

0)
"1"

Returns: "a1"

1)
"2"

Returns: "b1"

2)
"26"

Returns: "b4"

3)
"c1"

Returns: "3"

4)
"e4"

Returns: "29"

5)
"h8"

Returns: "64"

*/
// END CUT HERE
//#line 59 "Chessboard.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
static const double EPS = 1e-8;
typedef long long LL;

class Chessboard {
	public:
	string changeNotation(string cell) {
		string s;
		if(cell.length() == 2 && (cell[0] >= 'a' && cell[0] <= 'z')){
			int a = cell[0]-'a', b = cell[1]-'1';
			int n = a+1+b*8;
			stringstream ss;
			ss << n;
			s = ss.str();
		}else{
			s = "aa";
			stringstream ss(cell);
			int n; ss >> n;
			int a = (n-1)/8, b = (n-1)%8;
			s[0] = b+'a';
			s[1] = a+'1';
		}
		return s;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1"; string Arg1 = "a1"; verify_case(0, Arg1, changeNotation(Arg0)); }
	void test_case_1() { string Arg0 = "2"; string Arg1 = "b1"; verify_case(1, Arg1, changeNotation(Arg0)); }
	void test_case_2() { string Arg0 = "26"; string Arg1 = "b4"; verify_case(2, Arg1, changeNotation(Arg0)); }
	void test_case_3() { string Arg0 = "c1"; string Arg1 = "3"; verify_case(3, Arg1, changeNotation(Arg0)); }
	void test_case_4() { string Arg0 = "e4"; string Arg1 = "29"; verify_case(4, Arg1, changeNotation(Arg0)); }
	void test_case_5() { string Arg0 = "h8"; string Arg1 = "64"; verify_case(5, Arg1, changeNotation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Chessboard ___test;
  ___test.run_test(-1);
}
// END CUT HERE
