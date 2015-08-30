// 2 "GoodString.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Chandan loves to play with strings.
He just learned a new operation: inserting one string X into another string Y.



When inserting X into Y, it is also allowed to place X at the beginning or at the end of Y.
For example, there are exactly five ways how to insert the string "ab" into the string "????":
you can produce one of the strings "ab????", "?ab???", "??ab??", "???ab?", and "????ab".



According to Chandan, a good string is a string that can be constructed in the following way:
Initially, he takes the empty string "".
Then, he performs a sequence of zero or more steps.
In each step he inserts the string "ab" anywhere into the current string.



According to the above definition, the strings "ab", "aabb", and "aababb" are good while the strings "aab", "ba", and "abbb" are not good.



Chandan's friend Ravi came up with a string s.
Ravi asked Chandan whether it is a good string.
Return "Good" (quotes for clarity) if the string is good, or "Bad" if the string is not good.


DEFINITION
Class:GoodString
Method:isGood
Parameters:string
Returns:string
Method signature:string isGood(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each element of s will be either 'a' or 'b'.


EXAMPLES

0)
"ab"

Returns: "Good"

Chandan can start with an empty string and insert "ab".

1)
"aab"

Returns: "Bad"



2)
"aabb"

Returns: "Good"

Chandan can construct this string as follows: "" -> "ab" -> "aabb".

3)
"ababab"

Returns: "Good"

One way to construct this string is to append "ab" to the current string three times.

4)
"abaababababbaabbaaaabaababaabbabaaabbbbbbbb"

Returns: "Bad"



5)
"aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb"

Returns: "Good"



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

class GoodString {
	public:
	string isGood(string s) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "Good"; verify_case(0, Arg1, isGood(Arg0)); }
	void test_case_1() { string Arg0 = "aab"; string Arg1 = "Bad"; verify_case(1, Arg1, isGood(Arg0)); }
	void test_case_2() { string Arg0 = "aabb"; string Arg1 = "Good"; verify_case(2, Arg1, isGood(Arg0)); }
	void test_case_3() { string Arg0 = "ababab"; string Arg1 = "Good"; verify_case(3, Arg1, isGood(Arg0)); }
	void test_case_4() { string Arg0 = "abaababababbaabbaaaabaababaabbabaaabbbbbbbb"; string Arg1 = "Bad"; verify_case(4, Arg1, isGood(Arg0)); }
	void test_case_5() { string Arg0 = "aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb"; string Arg1 = "Good"; verify_case(5, Arg1, isGood(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	GoodString ___test;
	___test.run_test(-1);
}

// END CUT HERE
