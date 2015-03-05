// 2 "NumberGameAgain.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In this problem, you are going to play a simple number game.
The rules of the game are as follows:

You have a single variable called x. Initially, x is set to 1.
In each step, you can change the value of x either to 2x or to 2x+1.
You are given a list of forbidden values. If at any moment your x is on the list, you lose the game.
You are also given a target value y. If at any moment your x is equal to y, you win the game. (Note that the previous item applies sooner: if y is forbidden, you lose the game when you reach it.)
If at any moment winning the game becomes impossible, you lose the game.




For example, assume that the forbidden values are 4 and 7, and the goal is 12.
You can win the game as follows: change x from 1 to 2*1+1=3, then from 3 to 2*3=6, and then from 6 to 2*6=12.



You are given a vector<long long> table.
The elements of table are the forbidden values.



You are also given a int k.
Consider all possible goals y between 2 and (2^k)-1, inclusive.
For how many of these goals is it possible to win the game?
Compute and return the answer to that question.


DEFINITION
Class:NumberGameAgain
Method:solve
Parameters:int, vector<long long>
Returns:long long
Method signature:long long solve(int k, vector<long long> table)


CONSTRAINTS
-k will be between 2 and 40, inclusive.
-The number of elements in table will be between 0 and 20, inclusive.
-all numbers in table will be between 2 and 2^k - 1, inclusive.
-all numbers in table will be distinct.


EXAMPLES

0)
3
{2,4,6}

Returns: 2

There are three forbidden values: 2, 4, and 6.
As k=3, we are considering y between 2 and (2^3)-1 = 7.
This is how the game would end for each of these y's:

For y=2 we cannot win the game because 2 is forbidden.
For y=3 we can win the game: we change x from 1 to 3.
For y=4 we cannot win the game because 4 is forbidden.
For y=5 we cannot win the game. We would need to change x from 1 to 2 and then from 2 to 5, but we cannot do that because 2 is forbidden.
For y=6 we cannot win the game because 6 is forbidden.
For y=7 we can win the game: we change x from 1 to 3, and then from 3 to 7.

Thus, within the specified range there are two values of y for which we can win the game.


1)
5
{2,3}

Returns: 0

In this case, we will always reach a forbidden value after the very first step of the game. Therefore, there is no y for which we can win the game.

2)
5
{}

Returns: 30

With no forbidden values we can win this game for any y between 2 and 31, inclusive.

3)
40
{2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}

Returns: 549755748288



4)
40
{}

Returns: 1099511627774



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

class NumberGameAgain {
	public:
	long long solve(int k, vector<long long> table) {
		int sz = table.size();

		LL yMin = 2;
		LL yMax = 1;
		for (int i = 0; i < k; i++) yMax *= 2;
		yMax--;

		int invalid[21] = {0};
		for (int i = 0; i < sz; i++) {
			LL val = table[i];
			while (1) {
				if (val == 1) break;
				if (val % 2) {
					val = (val - 1) / 2;
				} else {
					val = val / 2;
				}
				for (int j = 0; j < sz; j++) {
					if (val == table[j]) invalid[i] = 1;
				}
			}
		}

		vector<LL> ext;
		for (int i = 0; i < sz; i++) {
			if (!invalid[i]) ext.push_back(table[i]);
		}
		int extSize = ext.size();

		// debug
//		for (int i = 0; i < extSize; i++) cerr << ext[i] << endl;

		LL minus = 0;
		for (int i = 0; i < extSize; i++) {
			LL lower = ext[i];
			LL upper = ext[i]; 
			while (1) {
				if (yMax <= upper) {
					if (yMax < lower) break;
					minus += (yMax - lower + 1);
					break;
				} else {
					minus += (upper - lower + 1);
				}

				lower = lower * 2;
				upper = upper * 2 + 1;
			}
		}

		return yMax - yMin + 1 - minus;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long Arr1[] = {2,4,6}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; long Arr1[] = {2,3}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 30LL; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 40; long Arr1[] = {2,4,8,16,32141531,2324577,1099511627775,2222222222,33333333333,4444444444,2135}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 549755748288LL; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 40; long Arr1[] = {}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1099511627774LL; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	NumberGameAgain ___test;
	___test.run_test(-1);
}

// END CUT HERE
