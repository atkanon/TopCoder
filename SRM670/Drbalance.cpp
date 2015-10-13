// 2 "Drbalance.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A plus/minus string is a string in which each character is either a '+' or a '-'.
The balance of a plus/minus string is computed as the number of '+' characters minus the number of '-' characters.
For example, the balance of the string "++-+" is 3-1 = 2, and the balance of the string "---" is 0-3 = -3.

The prefix of a string S is any string that can be obtained by removing some (possibly none, possibly all) characters from the end of S.
For example, the prefixes of the string "++-+" are the strings "++-+", "++-", "++", "+", and "".

Given a plus/minus string, its negativity is the number of its prefixes that have a negative balance.
For example, the negativity of the string "++-+" is 0, as none of its prefixes have a negative balance.
The negativity of the string "---" is 3.
Its three prefixes with a negative balance are "-", "--", and "---".

You are given a string s that is a plus/minus string.
You are also given an int k.
Your goal is to change s into a string with negativity at most k.
In other words, you want to change s into a string that has at most k prefixes that have a negative balance.

In order to change s you are going to perform a sequence of zero or more steps.
In each step you can change a single '-' character in s into a '+' or vice versa.
Compute and return the smallest number of steps needed.

DEFINITION
Class:Drbalance
Method:lesscng
Parameters:string, int
Returns:int
Method signature:int lesscng(string s, int k)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-k will be between 0 and the length of s, inclusive.
-Each character in s will be either '+' or '-'.


EXAMPLES

0)
"---"
1

Returns: 1

One step is sufficient.
If we change character 0 of s into a '+', we will obtain the string "+--".
This string has only one prefix with a negative balance - namely, the entire string "+--".
As k=1, we have reached our goal.

1)
"+-+-"
0

Returns: 0



2)
"-+-+---"
2

Returns: 1



3)
"-------++"
3

Returns: 3



4)
"-+--+--+--++++----+"
3

Returns: 2



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

class Drbalance {
	public:
    int calcNegativity(string s) {
        int negativity = 0;
        for (int i = 0; i <= s.length(); i++) {
            string t = s.substr(0, i);
            
            int pcnt = 0, mcnt = 0;
            for (int j = 0; j < t.length(); j++) {
                if (t[j] == '+') pcnt++;
                else if (t[j] == '-') mcnt++;
            }
            
            if (pcnt < mcnt) negativity++;
        }
        
        return negativity;
    }
	int lesscng(string s, int k) {
        int cnt = 0;
        while (calcNegativity(s) > k) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '-') {
                    s[i] = '+';
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+-+-"; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "-+-+---"; int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-------++"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "-+--+--+--++++----+"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, lesscng(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Drbalance ___test;
	___test.run_test(-1);
}

// END CUT HERE
