// 2 "Jumping.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Frog Suwako lives on a two-dimensional plane.
She likes to jump.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, y).
You are given the ints x and y.



Suwako wants to reach the desired destination in a specific way: using a series of jumps with pre-determined lengths.
You are given these lengths in a vector <int> jumpLenghts.
For example, if jumpLengths = { 2, 5 }, Suwako must make a jump of length exactly 2, followed by a jump of length exactly 5.



Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.
Return "Able" (quotes for clarity) if Suwako is able to reach her desired destination from (0, 0) using the desired sequence of jump lengths.
Otherwise, return "Not able".

DEFINITION
Class:Jumping
Method:ableToGet
Parameters:int, int, vector <int>
Returns:string
Method signature:string ableToGet(int x, int y, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000 and 1,000, inclusive.
-y will be between -1,000 and 1,000, inclusive.
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000, inclusive.


EXAMPLES

0)
5
4
{2, 5}

Returns: "Able"

One possibility is to jump from (0, 0) to (2, 0), and then from (2, 0) to (5, 4).

1)
3
4
{4}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 4 - it is too short.

2)
3
4
{6}

Returns: "Not able"

The distance from (0, 0) to (3, 4) is 5. You cannot get there using a single jump of length 6 - it is too long.

3)
0
1
{100, 100}

Returns: "Able"

Here, one possible solution looks as follows: Let t = sqrt(100*100 - 0.5*0.5). Suwoko will make her first jump from (0, 0) to (t, 0.5), and her second jump from (t, 0.5) to (0, 1).

4)
300
400
{500}

Returns: "Able"



5)
11
12
{1,2,3,4,5,6,7,8,9,10}

Returns: "Able"



6)
11
12
{1,2,3,4,5,6,7,8,9,100}

Returns: "Not able"



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

class Jumping {
	public:
	string ableToGet(int x, int y, vector <int> jumpLengths) {
		int sz = jumpLengths.size();

		if (sz == 1) {
			int len = jumpLengths[0];
			if (len*len == x*x + y*y) return "Able";
			else return "Not able";
		}		

		for (int i = 1; i < sz; i++) {
			int len1 = 0, len2 = 0;
			for (int j = 0; j < i; j++) {
				len1 += jumpLengths[j];
			}
			for (int j = i; j < sz; j++) {
				len2 += jumpLengths[j];
			}
			if ((len1 + len2)*(len1 + len2) >= x*x + y*y &&
				(len1 - len2)*(len1 - len2) <= x*x + y*y &&
				(len2 - len1)*(len2 - len1) <= x*x + y*y) {
				return "Able";
			}
		}
		return "Not able";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arr2[] = {2, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(0, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(1, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(2, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 1; int Arr2[] = {100, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(3, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 300; int Arg1 = 400; int Arr2[] = {500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(4, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Able"; verify_case(5, Arg3, ableToGet(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 11; int Arg1 = 12; int Arr2[] = {1,2,3,4,5,6,7,8,9,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Not able"; verify_case(6, Arg3, ableToGet(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Jumping ___test;
	___test.run_test(-1);
}

// END CUT HERE
