// 2 "Cyclemin.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A rotation of a string S is the operation of moving its first character to the end.
For example, if we rotate the string "abcde" we get the string "bcdea".

A cyclic shift of a string S is any string that can be obtained from S by a sequence of zero or more rotations.
For example, the strings "abcde", "cdeab", and "eabcd" are some of the cyclic shifts of the string "abcde".

Given two equally long strings, the smaller one is the one with a smaller character at the first index where they differ.
For example, "cable" < "cards" because 'b' < 'r'.

You are given a string s of lowercase letters and an int k.
You are allowed to change at most k letters of s into some other lowercase letters.
Your goal is to create a string that will have the smallest possible cyclic shift.
Compute and return that cyclic shift.

DEFINITION
Class:Cyclemin
Method:bestmod
Parameters:string, int
Returns:string
Method signature:string bestmod(string s, int k)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be between 'a' and 'z', inclusive.
-k will be between 0 and the length of s, inclusive.


EXAMPLES

0)
"aba"
1

Returns: "aaa"

We are allowed to change at most 1 character. Clearly, the optimal change is to change the 'b' into an 'a'.

1)
"aba"
0

Returns: "aab"

We are not allowed to change anything. In this case, the answer is the smallest cyclic shift of the given string s.

2)
"bbb"
2

Returns: "aab"



3)
"sgsgaw"
1

Returns: "aasgsg"

The optimal solution is to change the 'w' into an 'a', and then to take the cyclic shift that starts with the last two letters of s.

4)
"abacaba"
1

Returns: "aaaabac"



5)
"isgbiao"
2

Returns: "aaaisgb"



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

class Cyclemin {
	public:
	string bestmod(string s, int k) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; int Arg1 = 1; string Arg2 = "aaa"; verify_case(0, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "aba"; int Arg1 = 0; string Arg2 = "aab"; verify_case(1, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "bbb"; int Arg1 = 2; string Arg2 = "aab"; verify_case(2, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "sgsgaw"; int Arg1 = 1; string Arg2 = "aasgsg"; verify_case(3, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abacaba"; int Arg1 = 1; string Arg2 = "aaaabac"; verify_case(4, Arg2, bestmod(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "isgbiao"; int Arg1 = 2; string Arg2 = "aaaisgb"; verify_case(5, Arg2, bestmod(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Cyclemin ___test;
	___test.run_test(-1);
}

// END CUT HERE
