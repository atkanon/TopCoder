// 2 "ThePermutationGameDiv2.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alice and Bob are playing a game called "The Permutation Game".
The game is parameterized with the int N.
At the start of the game, Alice chooses a positive integer x, and Bob chooses a permutation of the first N positive integers.
Let p be Bob's permutation.
Alice will start at 1, and apply the permutation to this value x times.
More formally, let f(1) = p[1], and f(m) = p[f(m-1)] for all m >= 2.
Alice's final value will be f(x).

Alice wants to choose the smallest x such that f(x) = 1 for any permutation Bob can provide.

Compute and return the value of such x.


DEFINITION
Class:ThePermutationGameDiv2
Method:findMin
Parameters:int
Returns:long long
Method signature:long long findMin(int N)


NOTES
-The return value will fit into a signed 64-bit integer.
-A permutation of the first N positive integers is a sequence of length N that contains each of the integers 1 through N exactly once. The i-th (1-indexed) element of a permutation p is denoted by p[i].


CONSTRAINTS
-N will be between 1 and 35 inclusive.


EXAMPLES

0)
2

Returns: 2

 
Bob can choose the permutations {1,2} or {2,1}.
If Alice chooses 1, then, Bob can choose the permutation {2,1}, which would would make f(1) = 2.
However, if Alice chooses 2, no matter which permutation Bob chooses, Alice will get f(2) = 1.
Thus the answer in this case is 2.


1)
3

Returns: 6



2)
6

Returns: 60



3)
11

Returns: 27720



4)
25

Returns: 26771144400



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

class ThePermutationGameDiv2 {
	public:
	long long findMin(int N) {
		int factors[36] = {0};
		for (int i = 2; i <= N; i++) {
			int t[36] = {0};
			int v = i;
			while (v > 1) {
				for (int j = 2; j <= N; j++) {
					if (v % j == 0) {
						v /= j;
						t[j]++;
						break;
					}
				}
			}
			for (int j = 2; j <= N; j++) factors[j] = max(factors[j], t[j]);
		}

		LL res = 1;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < factors[i]; j++) res *= i;
		}
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 6LL; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 60LL; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 11; long long Arg1 = 27720LL; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 25; long long Arg1 = 26771144400LL; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ThePermutationGameDiv2 ___test;
	___test.run_test(-1);
}

// END CUT HERE
