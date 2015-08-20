// 2 "LuckySum.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A lucky number is a positive integer such that each of its digits is a 4 or a 7.
A lucky sum is the sum of two (not necessarily distinct) lucky numbers.
Cat loves lucky sums!



Cat has a string note.
Each character in note is either a digit or a question mark.
A number matches note if it can be produced from note by changing each question mark to a single digit.
Note that the number produced this way must not have any leading zeros: after the changes, note[0] must be between '1' and '9', inclusive.



Find and return the smallest lucky sum that matches note.
If there are no lucky sums that match note, return -1.


DEFINITION
Class:LuckySum
Method:construct
Parameters:string
Returns:long long
Method signature:long long construct(string note)


CONSTRAINTS
-note will contain between 1 and 14 characters, inclusive.
-Each character of note will be either a digit ('0'-'9') or a question mark ('?').
-The first character of note will not be '0'.
-At least one character of note will be '?'.


EXAMPLES

0)
"?"

Returns: 8

4+4=8, which is the smallest lucky sum.

1)
"?1"

Returns: 11

4+7=11

2)
"4?8"

Returns: 448

4+444=448

3)
"2??"

Returns: -1

The numbers that match this note are the numbers 200 through 299. None of these numbers is a lucky sum.

4)
"??????????????"

Returns: 11888888888888



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

class LuckySum {
	public:
	long long construct(string note) {
        long len = note.length();
        for (long i = len - 1; i >= 0; i--) {
            char c = note[i];
        }
        
        return 0;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	LuckySum ___test;
	___test.run_test(-1);
}

// END CUT HERE
