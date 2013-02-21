// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You will be given a vector <int> a and two ints lower and upper.  Return the number of integers between lower and upper, inclusive, that are multiples of all members of a.


DEFINITION
Class:CommonMultiples
Method:countCommMult
Parameters:vector <int>, int, int
Returns:int
Method signature:int countCommMult(vector <int> a, int lower, int upper)


CONSTRAINTS
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 100, inclusive.
-upper will be between 1 and 2000000000 (2*109), inclusive.
-lower will be between 1 and upper, inclusive.


EXAMPLES

0)
{1,2,3}
5
15

Returns: 2

The only numbers between 5 and 15 that are multiples of 1, 2 and 3 are 6 and 12.

1)
{1,2,4,8,16,32,64}
128
128

Returns: 1

128 is a multiple of all smaller powers of 2.

2)
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,49}
1
2000000000

Returns: 0



3)
{1,1,1}
1
2000000000

Returns: 2000000000



*/
// END CUT HERE
//#line 64 "CommonMultiples.cpp"
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
#define INF 2000000000
using namespace std;
static const double EPS = 1e-8;
typedef long long LL;

class CommonMultiples {
	public:
	LL gcd(LL m, LL n) {
		if (m == 0 || n == 0) return 0;
		while (m != n) {
			if (m > n) m = m-n;
			else n = n-m;
		}
		return m;
	}
	LL lcm(LL m, LL n) {
		if (m == 0 || n == 0) return 0;
		if (m > INF || n > INF) return 0;
		return (m/gcd(m, n))*n;
	}
	int countCommMult(vector <int> a, int lower, int upper) {
		int sz = a.size();
		LL m = 1;
		sort(a.begin(), a.end());
		for (int i = 0; i < sz; i++) {
			if (a[i] == 1) continue;
			if (i > 0 && a[i] == a[i-1]) continue;
			m = (lcm(m, LL(a[i])));
//			m *= a[i];
		}
		cout << m << endl;
		if (!m) return 0;
		return upper/m-(lower-1)/m;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 15; int Arg3 = 2; verify_case(0, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 128; int Arg2 = 128; int Arg3 = 1; verify_case(1, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 0; verify_case(2, Arg3, countCommMult(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2000000000; int Arg3 = 2000000000; verify_case(3, Arg3, countCommMult(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CommonMultiples ___test;
  ___test.run_test(-1);
}
// END CUT HERE
