// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// An encryption algorithm is applied on a piece of original text containing only lowercase letters ('a'-'z') and spaces. The original text contains no leading or trailing spaces, and no consecutive spaces.  A word is defined as a maximal consecutive sequence of letters. Each word in the original text is between 2 and 8 characters long, inclusive, and contains at least one vowel ('a', 'e', 'i', 'o' or 'u').

The encryption algorithm works as follows. Spaces and lowercase letters all have corresponding numeric values. The number 0 corresponds to a space, and the numbers 1 through 26 correspond to the letters 'a' through 'z', respectively.

First, a password is chosen. The password is a non-empty sequence of lowercase letters ('a'-'z'). Take the first character of the original text and the first character of the password, and add their numeric values together. This sum, modulo 27, corresponds to the first character of the encrypted text.  For example, if the first character of the text is 'x', and the first character of the password is 'd', then the first character of the encrypted text will be 'a' ('x' + 'd' = 24 + 4 = 28, 28 mod 27 = 1 = 'a').

Perform the same transformation using the second character of the original text and the second character of the password, and so on. When you run out of letters in the password, cycle back to the first letter of the password.

For example, let's encrypt the text "hello world" with the password "pun":
hello world
punpunpunpu
-----------
xzzainlieay

The encrypted text is "xzzainlieay".

Given the encrypted text as a String cipherText, you must determine the original text without knowing the password. Thanks to frequency analysis, you know that the password contains exactly 3 letters. Return the original text that satisfies the requirements given above. It is guaranteed that a single unique solution exists. All quotes in the problem statement are for clarity only.

DEFINITION
Class:SimpleRotationDecoder
Method:decode
Parameters:string
Returns:string
Method signature:string decode(string cipherText)


NOTES
-The password does not contain spaces.
-The password is not required to contain vowels.


CONSTRAINTS
-cipherText will contain between 3 and 50 characters, inclusive.
-cipherText will contain only spaces (' ') and lowercase letters ('a'-'z').
-There will be exactly one correct solution.


EXAMPLES

0)
"mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg"

Returns: "the quick brown fox jumps over the lazy dog again"

This text was encrypted with the password "tex".

1)
"ntgntgntgntofwlfwlfwlnookookook"

Returns: "he he he heh he he heh he he he"



2)
"f sgnzslhzquq ydyuinmqiwfyrtdvn"

Returns: "abkbprnn usmlbqz mdpelkoa jofni"

3)
"shxnaaeqjlofhhsuurbhpdgt z"

Returns: "naeiui jrghnca pnzxaxz avs"

*/
// END CUT HERE
//#line 70 "SimpleRotationDecoder.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
static const double EPS = 1e-8;
typedef long long LL;

class SimpleRotationDecoder {
	public:
	string decode(string cipherText) {
		string res = "111";
		string s = cipherText;
		int len = s.length();
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < 26; j++){
				for(int k = 0; k < 26; k++){
					res[0] = i+'a'; res[1] = j+'a'; res[2] = k+'a';
					string t = s;
					for(int L = 0; L < len; L++){
						int temp1 = (s[L] == ' ' ? 0 : s[L]-'a'+1);
						int temp2 = res[L%3]-'a'+1;
						int n = (temp1 >= temp2 ? temp1-temp2 : temp1-temp2+27);
						if(n == 0) t[L] = ' ';
						else t[L] = 'a'+n-1;
					}
					stringstream ss; ss << t;
					vector<string> vs;
					while(!ss.eof()){
						string _s; ss >> _s;
						vs.push_back(_s);
					}
					int flg = 0;
					if(t[0] == ' ' || t[t.length()-1] == ' ') flg++;
					for(int L = 0; L < t.length()-1; L++){
						if(t[L] == ' ' && t[L+1] == ' ') flg++;
					}
					for(int L = 0; L < vs.size(); L++){
						int flg2 = 0;
//						cout << vs[L] << endl;
						if(vs[L].length() < 2 || vs[L].length() > 8) flg++;
						for(int m = 0; m < vs[L].length(); m++){
							int c = vs[L][m];
							if(c == 'a'
								|| c == 'i'
								|| c == 'u'
								|| c == 'e'
								|| c == 'o')
							{
								flg2++;
							}
						}
						if(!flg2) flg++;
					}
					if(!flg){
						cout << res << endl;
						return t;
					}
				}
			}
		}
		return s;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg"; string Arg1 = "the quick brown fox jumps over the lazy dog again"; verify_case(0, Arg1, decode(Arg0)); }
	void test_case_1() { string Arg0 = "ntgntgntgntofwlfwlfwlnookookook"; string Arg1 = "he he he heh he he heh he he he"; verify_case(1, Arg1, decode(Arg0)); }
	void test_case_2() { string Arg0 = "f sgnzslhzquq ydyuinmqiwfyrtdvn"; string Arg1 = "abkbprnn usmlbqz mdpelkoa jofni"; verify_case(2, Arg1, decode(Arg0)); }
	void test_case_3() { string Arg0 = "shxnaaeqjlofhhsuurbhpdgt z"; string Arg1 = "naeiui jrghnca pnzxaxz avs"; verify_case(3, Arg1, decode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SimpleRotationDecoder ___test;
  ___test.run_test(-1);
}
// END CUT HERE
