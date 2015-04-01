#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;

typedef long long LL;

class SquareScoresDiv2 {
    public:
    int getscore(string s) {
        int len = (int)s.length();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            string t = "";
            for (int j = i; j < len; j++) {
                t += s[j];

                int tlen = (int)t.length();
                if (tlen == 1) {
                    cnt++;
                } else {
                    char c = t[0];
                    for (int k = 1; k < tlen; k++) {
                        if (c != t[k]) break;
                        if (k == tlen - 1) {
                            cnt++;
                        }
                    }
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
	void test_case_0() { string Arg0 = "aaaba"; int Arg1 = 8; verify_case(0, Arg1, getscore(Arg0)); }
	void test_case_1() { string Arg0 = "zzzxxzz"; int Arg1 = 12; verify_case(1, Arg1, getscore(Arg0)); }
	void test_case_2() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; int Arg1 = 26; verify_case(2, Arg1, getscore(Arg0)); }
	void test_case_3() { string Arg0 = "p"; int Arg1 = 1; verify_case(3, Arg1, getscore(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 5050; verify_case(4, Arg1, getscore(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
  SquareScoresDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
