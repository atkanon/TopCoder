// 2 "PeriodicJumping.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Frog Suwako lives on a two-dimensional plane.
Currently, she is located in the point (0, 0).
She would like to reach the point (x, 0).



Suwako jumps in a peculiar way: her jump lengths repeat in a periodic fashion.
The vector <int> jumpLengths contains one period of her jump lengths, starting with the length of the first jump she will make.
For example, if jumpLengths = { 2, 5 }, Suwako's jump lengths will be 2, 5, 2, 5, 2, 5, ...
Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.



You are given the int x and the vector <int> jumpLengths.
Return the smallest non-negative integer j such that Suwako can reach the desired destination after j jumps.
If there is no such j, return -1 instead.

DEFINITION
Class:PeriodicJumping
Method:minimalTime
Parameters:int, vector <int>
Returns:int
Method signature:int minimalTime(int x, vector <int> jumpLengths)


CONSTRAINTS
-x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-jumpLengths will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
15
{1,2,3,4,5,6,7,8,9,10}

Returns: 5

In 4 jumps Suwako cannot get far enough. In 5 jumps she can reach the destination as follows: (0,0) -> (1,0) -> (3,0) -> (6,0) -> (10,0) -> (15,0).


1)
5
{5}

Returns: 1

One jump is enough, since the distance between (0,0) and (5,0) is exactly 5.

2)
1
{10}

Returns: 2

Here Suwako needs two jumps. One possible solution is to land at (0.5, sqrt(10*10-0.5*0.5)) after the first jump.


3)
-10
{2,3,4,500,6,7,8}

Returns: 11



4)
-1000000000
{1}

Returns: 1000000000



5)
0
{19911120}

Returns: 0



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

class PeriodicJumping {
	public:
	bool check(int x, vector <int> jumpLengths) {
		int sz = jumpLengths.size();

		if (sz == 1) {
			if (x == jumpLengths[0]) return true;
			else return false;
		}
		LL L = 0;
		for (int i = 0; i < sz; i++) L += jumpLengths[i];
		if (L < x) return false;

		for (int i = 0; i < sz; i++) {
			LL m = jumpLengths[i];
			if (m > L - m + x) return false;
		}
		return true;
	}

	int minimalTime(int x, vector <int> jumpLengths) {
		if (x == 0) return 0;
		x = max(x, -x);

		int sz = jumpLengths.size();
		vector <int> vi;
		for (int i = 0; i < sz; i++) {
			vi.push_back(jumpLengths[i]);
			if (check(x, vi)) return i+1;
		}

		LL L = 0;
		LL m = -1;
		for (int i = 0; i < sz; i++) {
			L += jumpLengths[i];
			m = max(m, LL(jumpLengths[i]));
		}

		LL toTarget = max(2	* m - L - x, x - L);

		LL res = (1 + toTarget / L) * sz;
		toTarget %= L;

//		cerr << "res: " << res << endl;
//		cerr << "toTarget: " << toTarget << endl;

		for (int i = 0; i < sz; i++) {
			if (toTarget <= 0) break;
			res++;
			toTarget -= jumpLengths[i];
		}
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 15; int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -10; int Arr1[] = {2,3,4,500,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(3, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = -1000000000; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000000000; verify_case(4, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {19911120}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, minimalTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	PeriodicJumping ___test;
	___test.run_test(-1);
}

// END CUT HERE
