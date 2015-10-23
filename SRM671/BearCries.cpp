// 2 "BearCries.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a polar bear who often chats online with his friends.
Nowadays, bears often use emoticons to express their feelings.
In this problem we consider one particular emoticon: the crying emoticon.

A crying emoticon consists of an arbitrary positive number of underscores between two semicolons.
Hence, the shortest possible crying emoticon is ";_;" (quotes for clarity).
The strings ";__;" and ";_____________;" are also valid crying emoticons.

Today Limak is sad, so he sent his friend a sequence of crying emoticons.
However, due to a network malfunction all those emoticons got mixed together into a single string.

You are given a string message containing the message Limak's friend received.
You guess that the message can be divided into one or more crying emoticons.
Each emoticon must be a subsequence of the message, and each character of the message must belong to exactly one emoticon.
Note that the subsequences are not required to be contiguous.

Let X be the number of ways in which one can divide the given message into emoticons.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:BearCries
Method:count
Parameters:string
Returns:int
Method signature:int count(string message)


CONSTRAINTS
-message will contain between 1 and 200 characters, inclusive.
-Each character in message will be either semicolon or underscore.


EXAMPLES

0)
";_;;_____;"

Returns: 2

There are two ways to divide this string into two crying emoticons.
One looks as follows:

 ;_;
    ;_____;

and the other looks like this:

 ;_ ;
   ; _____;


1)
";;;___;;;"

Returns: 36

This message consists of 3 semicolons, 3 underscores and 3 semicolons again.
Clearly, we have to divide this message into exactly three crying emoticons, each with a single underscore.
There are 36 different ways to do so.

2)
"_;__;"

Returns: 0

As this message begins with an underscore, it clearly cannot be divided into one or more crying emoticons: each crying emoticon starts with a semicolon.

3)
";_____________________________________;"

Returns: 1



4)
";__;____;"

Returns: 0



5)
";_;;__;_;;"

Returns: 52



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

#define MOD 1000000007
using namespace std;

typedef long long LL;

static int dp[201][201][201] = {0};
class BearCries {
	public:
	int count(string message) {
        memset(dp, 0, sizeof(dp));
        if (message[0] == ';') {
            dp[0][1][0] = 1;
        }
        
        for (int i = 1; i < message.length(); i++) {
            for (int j = 0; j < 200; j++) {
                for (int k = 0; k < 200; k++) {
                    LL cnt = dp[i-1][j][k];
                    if (cnt) {
                        if (message[i] == ';') {
                            dp[i][j+1][k] = (cnt + dp[i][j+1][k]) % MOD;
                            dp[i][j][k-1] = (cnt * k + dp[i][j][k-1]) % MOD;
                        } else {
                            dp[i][j][k] = (cnt * k + dp[i][j][k]) % MOD;
                            dp[i][j-1][k+1] = (cnt * j + dp[i][j-1][k+1]) % MOD;
                        }
                    }
                }
            }
        }
        
        return dp[message.length()-1][0][0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ";_;;_____;"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = ";;;___;;;"; int Arg1 = 36; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "_;__;"; int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = ";_____________________________________;"; int Arg1 = 1; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = ";__;____;"; int Arg1 = 0; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arg0 = ";_;;__;_;;"; int Arg1 = 52; verify_case(5, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	BearCries ___test;
	___test.run_test(-1);
}

// END CUT HERE
