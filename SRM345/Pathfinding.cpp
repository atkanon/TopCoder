// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Recently you have been working on the pathfinding module for your AI system.  Your objective is to find the shortest path for an agent that wants to travel between two points on a plane.  The agent will start at the point (0,0), and travel to the point (x,y).  You decided that the agent will move either on horizontal of vertical lines such that, at every moment, at least one coordinate of the agent is an integer.

  There is yet another restriction however.  Each line will only allow movement in one direction.  All horizontal lines with odd y-coordinates will be directed toward decreasing values of x, and all other horizontal lines toward increasing values of x.  Similarly, all vertical lines with odd x-coordinates will be directed toward decreasing values of y, and all other vertical lines toward increasing values of y.


Given x and y, return the distance that the agent must travel.

DEFINITION
Class:Pathfinding
Method:getDirections
Parameters:int, int
Returns:int
Method signature:int getDirections(int x, int y)


CONSTRAINTS
-x and y will both be between -10^6 and 10^6, inclusive.


EXAMPLES

0)
0
-4

Returns: 8

A possible path from (0,0) to (0,-4) is through the points (1,0), (1,-3), (-1,-3) and (-1,-4). 

1)
5
-4

Returns: 9



2)
5
4

Returns: 9



3)
-1
-4

Returns: 7



4)
0
0

Returns: 0



*/
// END CUT HERE
//#line 68 "Pathfinding.cpp"
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

class Pathfinding {
	public:
	int getDirections(int x, int y) {
		if ((x || y) == 0) return 0;
		if (y%2) {
			if (x%2) {
				if (x > 0) {
					if (y > 0) {
						return x+y+2;
					} else {
						return x-y;
					}
				} else {
					if (y > 0) {
						return -x+y;
					} else {
						return -x-y+2;
					}
				}
			} else {
				if (x > 0) {
					if (y > 0) {
						return x+y;
					} else {
						return x-y+2;
					}
				} else {
					if (y > 0) {
						return -x+y;
					} else {
						return -x-y+2;
					}
				}
			}
		} else {
			if (x%2) {
				if (x > 0) {
					if (y > 0) {
						return x+y;
					} else {
						return x-y;
					}
				} else {
					if (y > 0) {
						return -x+y+2;
					} else {
						return -x-y+2;
					}
				}
			} else {
				if (x > 0) {
					if (y > 0) {
						return x+y;
					} else {
						return x-y;
					}
				} else {
					if (y > 0) {
						return -x+y;
					} else {
						return -x-y+4;
					}
				}
			}
		}
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = -4; int Arg2 = 8; verify_case(0, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = -4; int Arg2 = 9; verify_case(1, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 9; verify_case(2, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -1; int Arg1 = -4; int Arg2 = 7; verify_case(3, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(4, Arg2, getDirections(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Pathfinding ___test;
  ___test.run_test(-1);
}
// END CUT HERE
