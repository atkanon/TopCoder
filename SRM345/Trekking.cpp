// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are planning a small trek over at the local mountain range.  It will involve walking for several days and spending the nights in a tent.  The mountains are not very friendly (they're steep and rocky), and therefore many locations are not suitable for setting up a camp.  You will be given a string trail which represents the locations in the order in which you are visiting them.  trail[i] is '.' if it's possible to camp at the i-th location, and '^' otherwise.

You have several alternative plans to follow, given in the vector <string> plans.  plans[i][j] is lowercase 'w' if according to the i-th plan you are going to walk through location j, and uppercase 'C' if you are going to camp there.  A plan is invalid if it involves camping at a location that's not suitable for it.

Given trail and plans return the minimum number of nights that must be spent in the mountains, according to one of the valid plans.  If all plans are invalid, return -1

DEFINITION
Class:Trekking
Method:findCamps
Parameters:string, vector <string>
Returns:int
Method signature:int findCamps(string trail, vector <string> plans)


CONSTRAINTS
-trail will contain between 2 and 50 characters, inclusive.
-trail will contain only the characters '.' and '^'.
-plans will contain between 2 and 50 elements, inclusive.
-Each element of plans will contain the same number of characters as trail.
-Each element of plans will contain only the characters 'w' and 'C'.


EXAMPLES

0)
"^^....^^^..."
{"CwwCwwCwwCww",
 "wwwCwCwwwCww",
 "wwwwCwwwwCww"}

Returns: 2

The first plan is not valid because it involves camping in the first visited location, which is not suitable for camping.  The other two plans are valid, but the third involves only two camps, so it's the best one.

1)
"^^^^"
{"wwww",
 "wwwC"
}

Returns: 0



2)
"^^.^^^^"
{"wwCwwwC",
 "wwwCwww",
 "wCwwwCw"}

Returns: -1



3)
"^^^^....^.^.^."
{"wwwwCwwwwCwCwC",
 "wwwwCwwCwCwwwC",
 "wwwCwwwCwwwCww",
 "wwwwwCwwwCwwwC"}

Returns: 3



4)
".............."
{"CwCwCwCwCwCwCw",
 "CwwCwwCwwCwwCw"}

Returns: 5



*/
// END CUT HERE
//#line 81 "Trekking.cpp"
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

class Trekking {
	public:
	int findCamps(string trail, vector <string> plans) {
		int sz = plans.size(), len = trail.length();
		int res = 1<<29;
		for (int i = 0; i < sz; i++) {
			int cnt = 0;
			for (int j = 0; j < len; j++) {
				if (plans[i][j] == 'C' && trail[j] == '^') break;
				if (plans[i][j] == 'C') cnt++;
				if (j == len-1) res = min(res, cnt);
			}
		}
		return (res == 1<<29 ? -1 : res);
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "^^....^^^..."; string Arr1[] = {"CwwCwwCwwCww",
 "wwwCwCwwwCww",
 "wwwwCwwwwCww"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "^^^^"; string Arr1[] = {"wwww",
 "wwwC"
}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "^^.^^^^"; string Arr1[] = {"wwCwwwC",
 "wwwCwww",
 "wCwwwCw"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "^^^^....^.^.^."; string Arr1[] = {"wwwwCwwwwCwCwC",
 "wwwwCwwCwCwwwC",
 "wwwCwwwCwwwCww",
 "wwwwwCwwwCwwwC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, findCamps(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = ".............."; string Arr1[] = {"CwCwCwCwCwCwCw",
 "CwwCwwCwwCwwCw"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(4, Arg2, findCamps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Trekking ___test;
  ___test.run_test(-1);
}
// END CUT HERE
