// 2 "Hexspeak.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// If you compile a Java program and open the .class file in a text editor, you will find that the first four bytes spell "CAFEBABE" in hexadecimal.
Using hexadecimal numbers to spell words is called Hexspeak.


Hexadecimal numbers are integers written in base 16.
The letters 'A' through 'F' represent the digits with values 10 through 15.
For example, the integer 202 written in hexadecimal is "CA".
This is because 202 = 12*16 + 10, and the digits 12 and 10 are written as 'C' and 'A', respectively.


In this problem we will use eight different letters: in addition to the letters 'A' through 'F' we will also interpret the digit 0 as the letter 'O' and the digit 1 as the letter 'I'.
Hence, any word that only consists of the letters ABCDEFIO can be interpreted as a hexadecimal number.
Such words are called valid hexspeak words.


Fox Ciel has a long long ciphertext containing a positive integer.
Convert this number to hexadecimal.
If you get the representation of a valid hexspeak word, return that word.
Otherwise, return the string "Error!" (quotes for clarity).
In other words, you should return "Error!" if the hexadecimal representation of ciphertext contains some occurrence of a digit between 2 and 9, inclusive.

DEFINITION
Class:Hexspeak
Method:decode
Parameters:long long
Returns:string
Method signature:string decode(long long ciphertext)


NOTES
-The correct hexadecimal representation of ciphertext does not contain any leading zeros.
-The return value is case-sensitive.


CONSTRAINTS
-ciphertext will be between 1 and 1,000,000,000,000,000,000, inclusive.


EXAMPLES

0)
257

Returns: "IOI"

The number 257 in decimal is written as 101 in hexadecimal.
The digits 1 and 0 represent the characters 'I' and 'O', thus we should return "IOI".

1)
258

Returns: "Error!"

The number 258 in decimal is written as 102 in hexadecimal.
The digit 2 does not represent a letter, so we return "Error!".

2)
3405691582

Returns: "CAFEBABE"



3)
2882400001

Returns: "ABCDEFOI"



4)
999994830345994239

Returns: "DEOBIFFFFFFFFFF"



5)
1000000000000000000

Returns: "Error!"



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

class Hexspeak {
	public:
	string decode(long long ciphertext) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 257LL; string Arg1 = "IOI"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { long long Arg0 = 258LL; string Arg1 = "Error!"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { long long Arg0 = 3405691582LL; string Arg1 = "CAFEBABE"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { long long Arg0 = 2882400001LL; string Arg1 = "ABCDEFOI"; verify_case(3, Arg1, decode(Arg0)); }
	void test_case_4() { long long Arg0 = 999994830345994239LL; string Arg1 = "DEOBIFFFFFFFFFF"; verify_case(4, Arg1, decode(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000000000000LL; string Arg1 = "Error!"; verify_case(5, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Hexspeak ___test;
	___test.run_test(-1);
}

// END CUT HERE
