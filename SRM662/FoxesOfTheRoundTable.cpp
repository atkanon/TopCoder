// 2 "FoxesOfTheRoundTable.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are n foxes, numbered 0 through n-1.
You are given a vector <int> h with n elements.
The elements of h are the heights of those foxes.
Your task is to arrange all foxes around a round table.


Given an arrangement of foxes, let D be the largest height difference between adjacent foxes.
For example, suppose that four foxes with heights { 10, 30, 20, 40 } sit around the table in this order.
The height differences are |10-30|=20, |30-20|=10, |20-40|=20, and |40-10|=30.
(Note that the last fox is also adjacent to the first one, as this is a round table.)
Then, the value D is max(20,10,20,30) = 30.


Find an arrangement of the given foxes for which the value D is as small as possible.
Return a permutation of foxes that describes your arrangement.
I.e., return a vector <int> with n elements: the numbers of foxes in order around the table.
If there are multiple optimal solutions, you may return any of them.

DEFINITION
Class:FoxesOfTheRoundTable
Method:minimalDifference
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> minimalDifference(vector <int> h)


CONSTRAINTS
-h will contain between 3 and 50 elements, inclusive.
-Each element in h will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,99,50,50}

Returns: {0, 3, 1, 2 }

In the optimal solution the foxes with heights 1 and 99 mustn't be adjacent.
Hence, the heights of foxes have to be 1, 50, 99, 50, in this cyclic order, and the optimal value of D is 49.
One permutation that produces this order of foxes is 0, 3, 1, 2.

1)
{123,456,789}

Returns: {0, 1, 2 }

Whatever we do, the result will always be 789-123.

2)
{10,30,40,50,60}

Returns: {0, 1, 4, 3, 2 }

The permutation {0, 1, 4, 3, 2 } specifies that the heights of foxes are in the following order: 10, 30, 60, 50, 40.

3)
{1,2,3,4,8,12,13,14 }

Returns: {0, 1, 2, 3, 5, 6, 7, 4 }



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }

Returns: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }



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

class FoxesOfTheRoundTable {
	public:
	vector <int> minimalDifference(vector <int> h) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,99,50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, minimalDifference(Arg0)); }
	void test_case_1() { int Arr0[] = {123,456,789}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, minimalDifference(Arg0)); }
	void test_case_2() { int Arr0[] = {10,30,40,50,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 4, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, minimalDifference(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,8,12,13,14 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 5, 6, 7, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, minimalDifference(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, minimalDifference(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	FoxesOfTheRoundTable ___test;
	___test.run_test(-1);
}

// END CUT HERE
