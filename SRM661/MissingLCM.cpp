// 2 "MissingLCM.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The least common multiple (denoted "lcm") of a non-empty sequence of positive integers is the smallest positive integer that is divisible by each of them.
For example, lcm(2)=2, lcm(4,6)=12, and lcm(1,2,3,4,5)=60.



Alice had a positive integer N.
Then she chose some positive integer M that was strictly greater than N.
Afterwards, she computed two values:
the value A = lcm(N+1, N+2, ..., M) and the value B = lcm(1, 2, ..., M).
She was surprised when she saw that A = B.



You are given the int N.
Find and return the smallest M Alice could have chosen.
(Such an M will always exist.)


DEFINITION
Class:MissingLCM
Method:getMin
Parameters:int
Returns:int
Method signature:int getMin(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 2

Alice needs to choose an M > 1 such that lcm(2,...,M) = lcm(1,...,M). We can see M=2 is the minimum value that works, since lcm(1,2) = lcm(2) = 2.

1)
2

Returns: 4



2)
3

Returns: 6

We have lcm(4,5,6) = lcm(1,2,3,4,5,6) = 60.

3)
4

Returns: 8



4)
5

Returns: 10



5)
42

Returns: 82

Oh... that doesn't fit the pattern.

6)
999999

Returns: 1999966



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

class MissingLCM {
	public:
	int getMin(int N) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 6; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 8; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 10; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arg0 = 42; int Arg1 = 82; verify_case(5, Arg1, getMin(Arg0)); }
	void test_case_6() { int Arg0 = 999999; int Arg1 = 1999966; verify_case(6, Arg1, getMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	MissingLCM ___test;
	___test.run_test(-1);
}

// END CUT HERE
