// 2 "ValueOfString.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given a string s consisting of lower case letters.
We assign the letters 'a' to 'z' values of 1 to 26, respectively.
We will denote the value assigned to the letter X by val[X].
For example, val['a'] = 1 and val['e'] = 5.



We define the value of the string s as follows.
For each letter s[i], let k[i] be the number of letters in s that are less than or equal to s[i], including s[i] itself.
Then, the value of s is defined to be the sum of k[i] * val[s[i]] for all valid i.



Given the string, compute and return the value of the string.


DEFINITION
Class:ValueOfString
Method:findValue
Parameters:string
Returns:int
Method signature:int findValue(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-s will consist of lowercase letters ('a'-'z').


EXAMPLES

0)
"babca"

Returns: 35


The value of this string is 2*4 + 1*2 + 2*4 + 3*5 + 1*2 = 35.



We can get the value as follows. The first character is a 'b' which has value 2, and has 4 characters that are less than or equal to it in the string (i.e. the first, second, third and fifth character of the string). Thus, this first character contributes 2*4 to the sum. We can derive a similar expression for each of the other characters. 


1)
"zz"

Returns: 104



2)
"y"

Returns: 25



3)
"aaabbc"

Returns: 47



4)
"topcoder"

Returns: 558



5)
"thequickbrownfoxjumpsoverthelazydog"

Returns: 11187



6)
"zyxwvutsrqponmlkjihgfedcba"

Returns: 6201



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

class ValueOfString {
	public:
	int findValue(string s) {
		int length = s.length();
		int sum = 0;
		for (int i = 0; i < length; i++) {
			int count = 0;
			for (int j = 0; j < length; j++) {
				if (s[i] >= s[j]) count++;
			}
			sum += (s[i] - 'a' + 1) * count;
		}
		return sum;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "babca"; int Arg1 = 35; verify_case(0, Arg1, findValue(Arg0)); }
	void test_case_1() { string Arg0 = "zz"; int Arg1 = 104; verify_case(1, Arg1, findValue(Arg0)); }
	void test_case_2() { string Arg0 = "y"; int Arg1 = 25; verify_case(2, Arg1, findValue(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbc"; int Arg1 = 47; verify_case(3, Arg1, findValue(Arg0)); }
	void test_case_4() { string Arg0 = "topcoder"; int Arg1 = 558; verify_case(4, Arg1, findValue(Arg0)); }
	void test_case_5() { string Arg0 = "thequickbrownfoxjumpsoverthelazydog"; int Arg1 = 11187; verify_case(5, Arg1, findValue(Arg0)); }
	void test_case_6() { string Arg0 = "zyxwvutsrqponmlkjihgfedcba"; int Arg1 = 6201; verify_case(6, Arg1, findValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ValueOfString ___test;
	___test.run_test(-1);
}

// END CUT HERE
