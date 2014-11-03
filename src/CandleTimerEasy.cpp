// 2 "CandleTimerEasy.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You have a lot of candles.
The candles burn at a uniform rate: if you ignite a candle of length L, it will burn completely in L units of time.
You can also ignite a candle at both ends, which makes it burn twice as fast.



You have arranged some candles into the shape of a tree.
You want to use the tree to measure time.
At the beginning, you will ingite some leaves of the tree (all at the same time).
Then you will just wait and watch the flames spread across the entire tree.
(Whenever a flame reaches an inner node of the tree, it spreads to all branches that meet at that node.)
Note that you are not allowed to light new flames during the process.
The time you will measure is the time between the moment when you lighted the fire(s) and the moment when the last part of the tree finished burning.



You are given a description of the tree as three vector <int>s: a, b, and len, with N elements each.
The nodes of the tree are numbered 0 through N, inclusive.
For each valid i, there is a candle between the nodes a[i] and b[i] with length len[i].



Compute and return the number of different times you can measure when following the above procedure.

DEFINITION
Class:CandleTimerEasy
Method:differentTime
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int differentTime(vector <int> A, vector <int> B, vector <int> len)


CONSTRAINTS
-A will contain between 1 and 19 elements, inclusive.
-A, B and len will contain same number of elements.
-Each element in A will be between 0 and |A|, inclusive.
-Each element in B will be between 0 and |A|, inclusive.
-Each element in len will be between 1 and 1000, inclusive.
-A, B and len will describe a tree.


EXAMPLES

0)
{0,1}
{1,2}
{10,1}

Returns: 2

This tree looks the same as a single candle of length 11. If we light it on one end, we will measure the time 11. If we light it on both ends, we will measure the time 5.5.

1)
{0,0,0}
{1,2,3}
{1,1,1}

Returns: 2

This time we have 3 ends. If we ignite all of them the time is 1, otherwise the time is 2.

2)
{0,0,0}
{1,2,3}
{1,2,3}

Returns: 4

We can get 4 different outcomes: 2.5, 3, 4, 5.

3)
{0,1,1,2,3,3,2,4}
{1,2,3,4,5,6,7,8}
{5,3,2,4,6,8,7,1}

Returns: 7



4)
{0,0,0,0}
{1,2,3,4}
{123,456,789,1000}

Returns: 8



5)
{0}
{1}
{1000}

Returns: 2



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

class CandleTimerEasy {
	public:
	int differentTime(vector <int> A, vector <int> B, vector <int> len) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,1,2,3,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,3,2,4,6,8,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(3, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(4, Arg3, differentTime(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, differentTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	CandleTimerEasy ___test;
	___test.run_test(-1);
}

// END CUT HERE
