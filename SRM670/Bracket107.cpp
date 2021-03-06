// 2 "Bracket107.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Correct bracket sequences are strings in which each character is a '(' or a ')', the total number of opening brackets is the same as the total number of closing brackets, and each prefix contains at least as many opening as closing brackets.
For example, the shortest few correct bracket sequences are "", "()", "(())", and "()()".

The subsequence of a string S is any string that can be obtained by erasing zero or more characters of S.
For example, each of the strings "", "ace", and "abcde" is a subsequence of "abcde".

We will use LCS(S,T) to denote the length of a longest common subsequence of strings S and T.
In other words, LCS(S,T) is the largest k such that there is a string U of length k that is both a subsequence of S and a subsequence of T.
For example, LCS("abcde","bad") = 2.

You are given a string s that contains a correct bracket sequence.
You are looking for a string t with the following properties:

t will have the same length as s,
t will be a correct bracket sequence,
t will not be equal to s,
LCS(s,t) will be as large as possible.

Compute and return the number of strings with these properties.

DEFINITION
Class:Bracket107
Method:yetanother
Parameters:string
Returns:int
Method signature:int yetanother(string s)


NOTES
-You may assume that the answer for each valid test case fits into a signed 32-bit integer variable.


CONSTRAINTS
-s will contain between 4 and 50 characters, inclusive.
-Each character in s will be either '(' or ')'.
-s will be a correct bracket sequence.


EXAMPLES

0)
"(())"

Returns: 1

There is only one other correct bracket sequence of the same length.

1)
"(())()"

Returns: 3

There are four other correct bracket sequences of the same length: "((()))", "()(())", "()()()", and "(()())".
However, only in three of those four cases the length of the longest common subsequence is 5.
LCS( "(())()", "()(())" ) is only 4, therefore "()(())" is not a valid choice of the string t.

2)
"()()()"

Returns: 3



3)
"(((())))"

Returns: 5



4)
"((())())"

Returns: 9



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

class Bracket107 {
	public:
    bool isCorrectBracket(string s) {
        int open = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') open++;
            else open--;
            if (open < 0) return false;
        }
        
        if (open == 0) return true;
        else return false;
    }
	int yetanother(string s) {
        long len = s.length();
        int res = 0;
        set<string> seen;
        seen.insert(s);
        for (int i = 0; i < len; i++) {
            string t = s.substr(0, i) + s.substr(i + 1, len - i);
            for (int j = 0; j <= len - 1; j++) {
                string u = t.substr(0, j) + ")" + t.substr(j, len - 1 - j);
                string u2 = t.substr(0, j) + "(" + t.substr(j, len - 1 - j);
//                cerr << u << endl;
//                cerr << u2 << endl;
                if (isCorrectBracket(u)) {
                    if (seen.find(u) == seen.end()) {
                        seen.insert(u);
//                        cerr << u << endl;
                        res++;
                    }
                }
                if (isCorrectBracket(u2)) {
                    if (seen.find(u2) == seen.end()) {
                        seen.insert(u2);
//                        cerr << u2 << endl;
                        res++;
                    }
                }
            }
        }
        return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(())"; int Arg1 = 1; verify_case(0, Arg1, yetanother(Arg0)); }
	void test_case_1() { string Arg0 = "(())()"; int Arg1 = 3; verify_case(1, Arg1, yetanother(Arg0)); }
	void test_case_2() { string Arg0 = "()()()"; int Arg1 = 3; verify_case(2, Arg1, yetanother(Arg0)); }
	void test_case_3() { string Arg0 = "(((())))"; int Arg1 = 5; verify_case(3, Arg1, yetanother(Arg0)); }
	void test_case_4() { string Arg0 = "((())())"; int Arg1 = 9; verify_case(4, Arg1, yetanother(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Bracket107 ___test;
	___test.run_test(-1);
}

// END CUT HERE
