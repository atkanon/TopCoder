// 2 "BalancedSubstrings.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem deals with binary strings: strings in which each character is either '0' or '1'.
The characters are interpreted as zeros and ones.



Assume that we have a binary string of length N.
Imagine the string as a horizontal lever of length N-1.
The weight of the lever is negligible.
On the lever, the points with integer coordinates are numbered from 0 (one end of the lever) to N-1 (the other end).
Our string represents the distribution of weights on this lever.
For each i, if character i of our string is '0', the corresponding point is empty, and if the character is '1', there is a unit weight at that point.
Suppose that we place a fulcrum under the point number i.
We say that element i of the string is a balance point if the lever is balanced on the fulcrum: the moments of force on either side cancel each other out.
A string is called a balanced string if it has at least one balance point.
Note that the balance point must be one of the marked points (see examples below).



A formal definition follows.
For each valid index i we can compute the torque at i as follows:

For each element to the left of i, take its value, multiply it by its distance from i, and add all those results together to obtain the value A.
For each element to the right of i, take its value, multiply it by its distance from i, and add all those results together to obtain the value B.
The torque at i is computed as (A - B).

We say that index i is a balance point if the torque at i is exactly zero.
(Note that the value of the element at index i isn't used in the definition and therefore it can be arbitrary.)



For example, the string "10100001" is a balanced string.
Its balance point is the (0-based) index i=3.
If we put the fulcrum under the lever at this position, we see "101" to the left and "0001" to the right.
On the left side we get A = 1*3 + 0*2 + 1*1 = 4, and on the right side we get B = 0*1 + 0*2 + 0*3 + 1*4 = 4, hence A-B is exactly zero.



The string "0001" is also a balanced string, as its last character is a balance point.
The string "11" is not a balanced string, as neither of its two characters is a balance point.



You are given a string s that is a binary string.
Return the number of nonempty substrings of s that are balanced.



Substrings that consist of the same characters but occur elsewhere in s are considered different substrings.
If they are balanced, each of them should be counted separately.
For example, the string "00000" contains four distinct occurrences of the substring "00".


DEFINITION
Class:BalancedSubstrings
Method:countSubstrings
Parameters:string
Returns:int
Method signature:int countSubstrings(string s)


CONSTRAINTS
-s will have between 1 and 2,500 characters, inclusive.
-Each character in s will be '0' or '1'.


EXAMPLES

0)
"011"

Returns: 4

The balanced substrings in this case are {"0", "1", "1", "01"}

1)
"10111"

Returns: 10

The balanced substrings are {"1", "0", "1", "1", "1", "10", "01", "101", "111", "0111"}

2)
"00000"

Returns: 15

All substrings in this case are balanced.

3)
"0000001000000"

Returns: 91



4)
"100110001001"

Returns: 49



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

class BalancedSubstrings {
	public:
	int countSubstrings(string s) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "011"; int Arg1 = 4; verify_case(0, Arg1, countSubstrings(Arg0)); }
	void test_case_1() { string Arg0 = "10111"; int Arg1 = 10; verify_case(1, Arg1, countSubstrings(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = 15; verify_case(2, Arg1, countSubstrings(Arg0)); }
	void test_case_3() { string Arg0 = "0000001000000"; int Arg1 = 91; verify_case(3, Arg1, countSubstrings(Arg0)); }
	void test_case_4() { string Arg0 = "100110001001"; int Arg1 = 49; verify_case(4, Arg1, countSubstrings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	BalancedSubstrings ___test;
	___test.run_test(-1);
}

// END CUT HERE
