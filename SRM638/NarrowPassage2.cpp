// 2 "NarrowPassage2.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a narrow passage.
Inside the passage there are some wolves.
You are given a vector <int> size that contains the sizes of those wolves, from left to right.



The passage is so narrow that some pairs of wolves cannot pass by each other.
More precisely, two adjacent wolves may swap places if and only if the sum of their sizes is maxSizeSum or less.
Assuming that no wolves leave the passage, what is the number of different permutations of wolves in the passage?
Note that two wolves are considered different even if they have the same size.



Let X be the number of permutations of wolves that can be obtained from their initial order by swapping a pair of wolves zero or more times.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:NarrowPassage2
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> size, int maxSizeSum)


CONSTRAINTS
-size will contain between 1 and 50 elements, inclusive.
-Each element in size will be between 1 and 1,000,000,000, inclusive.
-maxSizeSum will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1, 2, 3}
3

Returns: 2

From {1, 2, 3}, you can swap 1 and 2 to get {2, 1, 3}. But you can't get other permutations.

1)
{1, 2, 3}
1000

Returns: 6

Here you can swap any two adjacent wolves. Thus, all 3! = 6 permutations are possible.

2)
{1, 2, 3}
4

Returns: 3

You can get {1, 2, 3}, {2, 1, 3} and {2, 3, 1}.

3)
{1,1,1,1,1,1,1,1,1,1,1,1,1}
2

Returns: 227020758

All of these wolves are different, even though their sizes are the same. Thus, there are 13! different permutations possible.

4)
{2,4,6,1,3,5}
8

Returns: 60



5)
{1000000000}
1000000000

Returns: 1



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>

#define MOD 1000000007
using namespace std;

typedef long long LL;

class NarrowPassage2 {
	public:
	int count(vector <int> size, int maxSizeSum) {
		int n = size.size();
		if (!n) return 1;
		int t = min_element(size.begin(), size.end()) - size.begin();
		int k = 1;
		for (int i = t-1; i >= 0; i--) {
			if (size[t] + size[i] <= maxSizeSum) {
				k++;
			} else {
				break;
			}
		}
		for (int i = t+1; i < n; i++) {
			if (size[t] + size[i] <= maxSizeSum) {
				k++;
			} else {
				break;
			}
		}
		size.erase(t + size.begin());
//		printf("n: %d, t: %d, k: %d\n", n, t, k);
		return LL(count(size, maxSizeSum)) * k % MOD;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 6; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 227020758; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,4,6,1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 60; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = 1; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	NarrowPassage2 ___test;
	___test.run_test(-1);
}

// END CUT HERE
