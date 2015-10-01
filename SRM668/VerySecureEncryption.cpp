// 2 "VerySecureEncryption.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are going to send a message to your friend.
The message is given as the string message.
To confuse potential eavesdroppers, you are going to scramble the message.


Scrambling of a message is performed using the vector <int> key.
If a letter is at the (0-based) position i in the original message, it will appear at the position key[i] in the scrambled message.
(The constraints given below guarantee that this process will produce a valid scrambled message.)


To make the encryption even more confusing, you are going to repeat the above process K times in a row.
Given message, key, and the int K, find and return the final encrypted message.

DEFINITION
Class:VerySecureEncryption
Method:encrypt
Parameters:string, vector <int>, int
Returns:string
Method signature:string encrypt(string message, vector <int> key, int K)


CONSTRAINTS
-N will be between 1 and 10, inclusive.
-message will contain N characters.
-Each character of message will be a lowercase English letter.
-key will contain N elements.
-Each element of key will be between 0 and N-1, inclusive.
-The elements of key will be distinct.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
"abc"
{1,2,0}
1

Returns: "cab"


The character 'a' will go from position 0 to position key[0]=1.
The character 'b' will go from position 1 to position key[1]=2.
The character 'c' will go from position 2 to position key[2]=0.


1)
"abcde"
{4, 3, 2, 1, 0}
1

Returns: "edcba"



2)
"abcde"
{4, 3, 2, 1, 0}
2

Returns: "abcde"

This is the same message and the same key as in example 1, but now K=2, so we scramble the message twice.
For this particular key we see that each scrambling reverses the order of letters, which means that the final message is the same as the original we started with.

3)
"uogcodlk"
{4, 3, 6, 2, 5, 1, 0, 7}
44

Returns: "goodluck"



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

class VerySecureEncryption {
	public:
	string encrypt(string message, vector <int> key, int K) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abc"; int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "cab"; verify_case(0, Arg3, encrypt(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "abcde"; int Arr1[] = {4, 3, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; string Arg3 = "edcba"; verify_case(1, Arg3, encrypt(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "abcde"; int Arr1[] = {4, 3, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "abcde"; verify_case(2, Arg3, encrypt(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "uogcodlk"; int Arr1[] = {4, 3, 6, 2, 5, 1, 0, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 44; string Arg3 = "goodluck"; verify_case(3, Arg3, encrypt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	VerySecureEncryption ___test;
	___test.run_test(-1);
}

// END CUT HERE
