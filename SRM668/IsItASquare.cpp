// 2 "IsItASquare.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// It's a bird! It's a plane! No, it's a square in a plane! Wait, is it really a square?


There are four distinct points in the plane.
You are given their coordinates in the vector <int>s x and y:
for each i between 0 and 3, inclusive, there is a point at (x[i], y[i]).


Return "It's a square" (quotes for clarity) if the four points are the vertices of a square.
Otherwise, return "Not a square".

DEFINITION
Class:IsItASquare
Method:isSquare
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string isSquare(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain 4 elements.
-y will contain 4 elements.
-Each element of x will be between 0 and 10,000, inclusive.
-Each element of y will be between 0 and 10,000, inclusive.
-The four points described by x and y will be distinct.


EXAMPLES

0)
{0, 0, 2, 2}
{0, 2, 0, 2}

Returns: "It's a square"



1)
{0, 1, 5, 6}
{1, 6, 0, 5}

Returns: "It's a square"

Note that the sides of the square do not have to be parallel to the coordinate axes.
Also note that the order in which the points are given does not have to be the same as the order in which you would encounter them when following the boundary of the square.

2)
{0, 0, 7, 7}
{0, 3, 0, 3}

Returns: "Not a square"



3)
{0, 5000, 5000, 10000}
{5000, 0, 10000, 5000}

Returns: "It's a square"



4)
{1, 2, 3, 4}
{4, 3, 2, 1}

Returns: "Not a square"



5)
{0, 5, 3, 8}
{0, 0, 4, 4}

Returns: "Not a square"



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

class IsItASquare {
	public:
	string isSquare(vector <int> x, vector <int> y) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "It's a square"; verify_case(0, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 6, 0, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "It's a square"; verify_case(1, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 3, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not a square"; verify_case(2, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 5000, 5000, 10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5000, 0, 10000, 5000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "It's a square"; verify_case(3, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not a square"; verify_case(4, Arg2, isSquare(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 5, 3, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not a square"; verify_case(5, Arg2, isSquare(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	IsItASquare ___test;
	___test.run_test(-1);
}

// END CUT HERE
