// 2 "ABBADiv1.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One day, Jamie noticed that many English words only use the letters A and B.
Examples of such words include "AB" (short for abdominal), "BAA" (the noise a sheep makes), "AA" (a type of lava), and "ABBA" (a Swedish pop sensation).

Inspired by this observation, Jamie created a simple game.
You are given two strings: initial and target.
The goal of the game is to find a sequence of valid moves that will change initial into target.
There are two types of valid moves:

Add the letter A to the end of the string.
Add the letter B to the end of the string and then reverse the entire string. (After the reversal the newly-added B becomes the first character of the string).


Return "Possible" (quotes for clarity) if there is a sequence of valid moves that will change initial into target.
Otherwise, return "Impossible".

DEFINITION
Class:ABBADiv1
Method:canObtain
Parameters:string, string
Returns:string
Method signature:string canObtain(string initial, string target)


CONSTRAINTS
-The length of initial will be between 1 and 49, inclusive.
-The length of target will be between 2 and 50, inclusive.
-target will be longer than initial.
-Each character in initial and each character in target will be either 'A' or 'B'.


EXAMPLES

0)
"A"
"BABA"

Returns: "Possible"

Jamie can perform the following moves:

Initially, the string is "A".
Jamie adds a 'B' to the end of the string and then reverses the string. Now the string is "BA".
Jamie adds a 'B' to the end of the string and then reverses the string. Now the string is "BAB".
Jamie adds an 'A' to the end of the string. Now the string is "BABA".

Since there is a sequence of moves which starts with "A" and creates the string "BABA", the answer is "Possible".

1)
"BAAAAABAA"
"BAABAAAAAB"

Returns: "Possible"

Jamie can add a 'B' to the end of the string and then reverse the string.

2)
"A"
"ABBA"

Returns: "Impossible"



3)
"AAABBAABB"
"BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"

Returns: "Possible"



4)
"AAABAAABB"
"BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"

Returns: "Impossible"



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

using namespace std;

typedef long long LL;

class ABBADiv1 {
	public:
	string canObtain(string initial, string target) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "A"; string Arg1 = "BABA"; string Arg2 = "Possible"; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BAAAAABAA"; string Arg1 = "BAABAAAAAB"; string Arg2 = "Possible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arg1 = "ABBA"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAABBAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AAABAAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ABBADiv1 ___test;
	___test.run_test(-1);
}

// END CUT HERE
