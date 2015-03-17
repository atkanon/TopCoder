// 2 "CountryGroup.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Some people are sitting in a row.
Each person came here from some country.
You have a theory that people from the same country are all sitting together.
You decided to test this theory.
You asked each person the same question: "How many people from your country (including you) are here?"



You are given a vector <int> a containing their answers.
The answers are given in the order in which the people sit in the row.
(Note that some of the answers may be incorrect.
See the examples for clarification.)



If all the answers are consistent with your theory, return the number of different countries that are present.
(Given that all answers are consistent with the theory, the number of countries can always be uniquely determined.)
Otherwise, return -1.


DEFINITION
Class:CountryGroup
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> a)


CONSTRAINTS
-The number of elements in a will be between 1 and 100, inclusive.
-All elements of a will be between 1 and 100, inclusive.


EXAMPLES

0)
{2,2,3,3,3}

Returns: 2

These answers are consistent with your theory. The first two people are from one country, the other three are from a different country. Thus, there are two countries and the correct return value is 2.

1)
{1,1,1,1,1}

Returns: 5

Here, each person comes from a different country.

2)
{3,3}

Returns: -1

These answers do not correspond to your theory. In particular, they are not even correct: there are only two people but each of them claims that there are three people from their country.

3)
{4,4,4,4,1,1,2,2,3,3,3}

Returns: 5



4)
{2,1,2,2,1,2}

Returns: -1

These answers do not correspond to your theory. It is possible that these are people from four different countries, but even if that were the case, we can tell that people from some countries are not sitting together. For example, consider the leftmost person. According to her answer, there are two people from her country. However, the person sitting next to her cannot be from the same country.

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

class CountryGroup {
	public:
	int solve(vector <int> a) {
		int sz = a.size();

		int n = -1;
		int cnt = 0;
		int res = 0;
		for (int i = 0; i < sz; i++) {
			if (n == -1) {
				n = a[i];
			}
			if (n != a[i]) return -1;
			cnt++;
			
			if (cnt == n) {
				cnt = 0;
				n = -1;
				res++;
			}
		}
		if (n != -1) return -1;
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {4,4,4,4,1,1,2,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {2,1,2,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	CountryGroup ___test;
	___test.run_test(-1);
}

// END CUT HERE
