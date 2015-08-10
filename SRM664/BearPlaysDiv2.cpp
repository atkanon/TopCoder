// 2 "BearPlaysDiv2.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a little bear who loves to play.
Today he is playing by moving some stones between three piles of stones.
Initially, the piles contain A, B, and C stones, respectively.
Limak's goal is to produce three equal piles.

Limak will try reaching his goal by performing a sequence of zero or more operations.
In each operation he will start by choosing two unequal piles.
Let's label their sizes X and Y in such a way that X < Y.
He will then double the size of the smaller chosen pile by moving some stones between the two chosen piles.
Formally, the new sizes of the two chosen piles will be X+X and Y-X.

You are given the ints A, B, and C.
Return "possible" (quotes for clarity) if there is a sequence of operations that will make all three piles equal.
Otherwise, return "impossible".

DEFINITION
Class:BearPlaysDiv2
Method:equalPiles
Parameters:int, int, int
Returns:string
Method signature:string equalPiles(int A, int B, int C)


CONSTRAINTS
-A, B and C will be between 1 and 500, inclusive.


EXAMPLES

0)
10
15
35

Returns: "possible"

One valid sequence of operations looks as follows:

The initial pile sizes are 10, 15, and 35.
For the first operation Limak will choose the piles with 15 and 35 stones. After doubling the size of the smaller pile the new sizes of these two piles will be 30 and 20.
After the first operation the pile sizes are 10, 30, and 20.
For the second operation Limak will choose the piles with 10 and 30 stones. After doubling the size of the smaller pile the new sizes of these two piles will be 20 and 20.
After the second operation each pile has 20 stones, which means that Limak has reached his goal.


1)
1
1
2

Returns: "impossible"

No matter what Limak does, there will always be two piles with a single stone each and one pile with 2 stones.

2)
4
6
8

Returns: "impossible"



3)
18
18
18

Returns: "possible"

Sometimes Limak can reach his goal without making any operations.

4)
225
500
475

Returns: "possible"



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

class BearPlaysDiv2 {
	public:
	string equalPiles(int A, int B, int C) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 15; int Arg2 = 35; string Arg3 = "possible"; verify_case(0, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; string Arg3 = "impossible"; verify_case(1, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 8; string Arg3 = "impossible"; verify_case(2, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 18; int Arg2 = 18; string Arg3 = "possible"; verify_case(3, Arg3, equalPiles(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 225; int Arg1 = 500; int Arg2 = 475; string Arg3 = "possible"; verify_case(4, Arg3, equalPiles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	BearPlaysDiv2 ___test;
	___test.run_test(-1);
}

// END CUT HERE
