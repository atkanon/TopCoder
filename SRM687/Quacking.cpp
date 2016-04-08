// 2 "Quacking.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Ducks have started mysteriously appearing in your room.
All ducks make the same sound: "quack".
Each duck makes the sound one or more times, one after another.
For example, valid sounds for a single duck are "quack", "quackquackquackquack", "quackquack", etc.



You have lost count of how many ducks are in your room.
The ducks are quacking, and the sounds of their quacks are getting mixed up.
You have recorded the sounds, obtaining a string of characters.
When you later listened to the recording, you realized that the quacking of each individual duck forms a (not necessarily contiguous) subsequence of the recording.
You also noticed that each letter in the recording belongs to exactly one duck.
For example, if there were two ducks, you may have recorded "quqacukqauackck".



You are given a string s that contains an arbitrary recording.
Find and return the smallest number of ducks that could have produced the recording.
Note that it is possible that the given recording is not a valid recording of quacking ducks.
In such case, return -1.


DEFINITION
Class:Quacking
Method:quack
Parameters:string
Returns:int
Method signature:int quack(string s)


CONSTRAINTS
-s will have between 5 and 2,500 characters, inclusive.
-Each character of s will be 'q', 'u', 'a', 'c', or 'k'.


EXAMPLES

0)
"quqacukqauackck"

Returns: 2

This is the same as the one from the problem statement.

1)
"kcauq"

Returns: -1

A backward duck is not a real duck.

2)
"quackquackquackquackquackquackquackquackquackquack"

Returns: 1

A single duck can make arbitrarily many quack sounds.

3)
"qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk"

Returns: 10



4)
"quqaquuacakcqckkuaquckqauckack"

Returns: 3

This is one possible solution with 3 ducks.

Mixed: quqaquuacakcqckkuaquckqauckack
Duck1: ____q_u__a___ck_______________
Duck2: __q__u_ac_k_q___ua__ckq_u__ack
Duck3: qu_a_______c___k__qu___a_ck___

Here, we can verify that each letter comes from exactly one duck.

5)
"quackqauckquack"

Returns: -1

Note that the second quack is misspelled.

*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include "string.h"

using namespace std;

typedef long long LL;

class Quacking {
	public:
	int quack(string s) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "quqacukqauackck"; int Arg1 = 2; verify_case(0, Arg1, quack(Arg0)); }
	void test_case_1() { string Arg0 = "kcauq"; int Arg1 = -1; verify_case(1, Arg1, quack(Arg0)); }
	void test_case_2() { string Arg0 = "quackquackquackquackquackquackquackquackquackquack"; int Arg1 = 1; verify_case(2, Arg1, quack(Arg0)); }
	void test_case_3() { string Arg0 = "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk"; int Arg1 = 10; verify_case(3, Arg1, quack(Arg0)); }
	void test_case_4() { string Arg0 = "quqaquuacakcqckkuaquckqauckack"; int Arg1 = 3; verify_case(4, Arg1, quack(Arg0)); }
	void test_case_5() { string Arg0 = "quackqauckquack"; int Arg1 = -1; verify_case(5, Arg1, quack(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Quacking ___test;
	___test.run_test(-1);
}

// END CUT HERE
