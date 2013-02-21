// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are a diamond hunter looking for diamonds in a peculiar mine. This mine is a string of '<' and '>' characters, and each diamond is a substring of the form "<>". Each time you find a diamond, you remove it and the residual mine is updated by removing the 2 characters from the string.

For example, if you have a mine like "><<><>>><", you can start by removing the first appearance of "<>" to get "><<>>><", then remove the only remaining diamond to get "><>><". Note that this produces a new diamond which you can remove to get ">><". Since there are no diamonds left, your expedition is done.

Given a string mine, return the number of diamonds that can be found. Note that the order in which you remove simultaneous appearances of diamonds is irrelevant; any order will lead to the same result.


DEFINITION
Class:DiamondHunt
Method:countDiamonds
Parameters:string
Returns:int
Method signature:int countDiamonds(string mine)


CONSTRAINTS
-mine will contain between 1 and 50 characters, inclusive.
-Each character of mine will be either '<' or '>'.


EXAMPLES

0)
"><<><>>><"

Returns: 3

The example from the problem statement.

1)
">>>><<"

Returns: 0

No diamonds here.

2)
"<<<<<<<<<>>>>>>>>>"

Returns: 9



3)
"><<><><<>>>><<>><<><<>><<<>>>>>><<<"

Returns: 14



*/
// END CUT HERE
//#line 58 "DiamondHunt.cpp"
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

class DiamondHunt {
	public:
	int countDiamonds(string mine) {
		int res = 0;
		while (1) {
			int len = mine.length();
			int flg = 0;
			for (int i = 0; i < len-1; i++) {
				if (mine[i] == '<' && mine[i+1] == '>') {
					res++;
					mine = mine.substr(0, i) + mine.substr(i+2, len);
					flg++;
					break;
				}
			}
			if (!flg) break;
		}
		return res;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "><<><>>><"; int Arg1 = 3; verify_case(0, Arg1, countDiamonds(Arg0)); }
	void test_case_1() { string Arg0 = ">>>><<"; int Arg1 = 0; verify_case(1, Arg1, countDiamonds(Arg0)); }
	void test_case_2() { string Arg0 = "<<<<<<<<<>>>>>>>>>"; int Arg1 = 9; verify_case(2, Arg1, countDiamonds(Arg0)); }
	void test_case_3() { string Arg0 = "><<><><<>>>><<>><<><<>><<<>>>>>><<<"; int Arg1 = 14; verify_case(3, Arg1, countDiamonds(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  DiamondHunt ___test;
  ___test.run_test(-1);
}
// END CUT HERE
