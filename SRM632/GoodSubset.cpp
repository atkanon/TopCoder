// 2 "GoodSubset.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have some cards, each containing a positive integer.
You are given a vector <int> d.
Each element of d is one of those integers.
The integers are not necessarily distinct.



You are also given an int goodValue.
You are interested in non-empty subsets of cards with the following property:
The product of integers written on those cards is exactly equal to goodValue.



Let X be the number of subsets with the above property.
Compute and return the value (X modulo 1,000,000,007).


DEFINITION
Class:GoodSubset
Method:numberOfSubsets
Parameters:int, vector <int>
Returns:int
Method signature:int numberOfSubsets(int goodValue, vector <int> d)


CONSTRAINTS
-goodValue will be between 1 and 2,000,000,000, inclusive.
-d will contain between 1 and 100 elements, inclusive.
-Each element of d will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
10
{2,3,4,5}

Returns: 1

There is only one good subset:{2,5}.

1)
6
{2,3,4,5,6}

Returns: 2

There are two good subsets: {2,3} and {6}.

2)
1
{1,1,1}

Returns: 7

All non-empty subsets of this set of cards are good.

3)
12
{1,2,3,4,5,6,7,8,9,10,11,12}

Returns: 6



4)
5
{1,2,3,4}

Returns: 0



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <map>

#define MOD 1000000007

using namespace std;

typedef long long LL;

map<int, int> dp[101][2];

class GoodSubset {
	public:

	int calc(int x, int n, vector<int> d, int present) {
		if (dp[n][present].find(x) != dp[n][present].end()) {
//			cerr << n << " " << present << " " << x << " " << dp[n][present][x] << endl;
			return dp[n][present][x];
		}

		if (n == 0) {
			int res = 0;
			if (d[0] == x) res++;
			if (x == 1 && present) res++;
//			cerr << "in " << n << " " << present << " " << x << " " << res << endl;
			return dp[n][present][x] = res;
		}


		if (x % d[n]) {
			return dp[n][present][x] = calc(x, n-1, d, present);
//			return calc(x, n-1, d, present);
		} else {
			return dp[n][present][x] = (calc(x/d[n], n-1, d, 1) + calc(x, n-1, d, present)) % MOD;
//			return (calc(x/d[n], n-1, d, 1) + calc(x, n-1, d, present)) % MOD;
		}
	}

	int numberOfSubsets(int goodValue, vector <int> d) {
		int sz = d.size();

		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 2; j++) {
				for (map<int ,int>::iterator it = dp[i][j].begin(); it != dp[i][j].end();) {
					dp[i][j].erase(it++);
				}
			}
		}

		int res = calc(goodValue, sz-1, d, 0);
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 12; int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, numberOfSubsets(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, numberOfSubsets(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	GoodSubset ___test;
	___test.run_test(-1);
}

// END CUT HERE
