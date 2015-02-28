// 2 "FoxAndSouvenirTheNext.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel just returned home from her trip to New Fox City.
She has brought a bunch of souvenirs.
You are given their values in a vector <int> value.


Now she wants to give each souvenir either to her mother or to her father.
She would like to divide the souvenirs in a fair way.
More precisely:

The total number of souvenirs given to her mother must be the same as the total number of souvenirs given to her father.
At the same time, the total value of souvenirs given to her mother must be the same as the total value of souvenirs given to her father.



Return "Possible" if she can reach her goal, and "Impossible" otherwise.

DEFINITION
Class:FoxAndSouvenirTheNext
Method:ableToSplit
Parameters:vector <int>
Returns:string
Method signature:string ableToSplit(vector <int> value)


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-Each element in value will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: "Possible"

One valid solution is to give the souvenirs with values 1 and 4 to her mother and the other two to her father. Each parent receives two souvenirs, and as 1+4 = 2+3, the total value is also the same for both parents.

1)
{1,1,1,3}

Returns: "Impossible"

There is no valid solution. Note that {1,1,1} and {3} is not a valid way to split the souvenirs: even though the total value is the same, the number of souvenirs is not.

2)
{1,1,2,3,5,8}

Returns: "Possible"

We have 1+1+8 = 2+3+5.

3)
{2,3,5,7,11,13}

Returns: "Impossible"

The sum of values is an odd number, so it is impossible.

4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}

Returns: "Possible"



5)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}

Returns: "Impossible"



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include "string.h"

using namespace std;

typedef long long LL;

class FoxAndSouvenirTheNext {
	public:
	string ableToSplit(vector <int> value) {
		int sz = value.size();
		int count[1300][51] = {0};
		count[0][0] = 1;
		for (int i = 0; i < sz; i++) {
			int n = value[i];
//			cerr << i << endl;
			int nextCount[1300][51] = {0};
			for (int j = 0; j < 1300; j++) {
				for (int k = 0; k < 51; k++) {
					if (count[j][k]) {
//						cerr << j+n << " " << k+1 << endl;
						nextCount[j+n][k+1] = 1;
						nextCount[j][k] = 1;
					}
				}
			}
			memcpy(count, nextCount, sizeof(nextCount));
		}

#if 0
		for (int j = 0; j < 1300; j++) {
			for (int k = 0; k < 51; k++) {
				if (count[j][k])
					cerr << j << " " << k << " " << endl;
			}
		}
#endif

		int sum = 0;
		for (int i = 0; i < sz; i++) {
			sum += value[i];
		}
		if (sum % 2) return "Impossible";

		int have;
		if (sz % 2) {
			return "Impossible";
		} else {
			have = sz / 2;
		}

		if (count[sum / 2][have]) return "Possible";
		else return "Impossible";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, ableToSplit(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, ableToSplit(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,2,3,5,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, ableToSplit(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,5,7,11,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(3, Arg1, ableToSplit(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(4, Arg1, ableToSplit(Arg0)); }
	void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(5, Arg1, ableToSplit(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	FoxAndSouvenirTheNext ___test;
	___test.run_test(-1);
}

// END CUT HERE
