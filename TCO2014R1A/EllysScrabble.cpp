#line 2 "EllysScrabble.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

typedef long long LL;

const int mx = 60;
bool used[mx];
bool jumped[mx];
char ans[mx];

class EllysScrabble {
	public:


	string getMin(string letters, int maxDistance) {
		int len = letters.length();
		int used[51] = {0};
		string ans = "";
		for (int i = 0; i < len; i++) {
			int target = -1;
			char c = char('Z' + 1);
			for (int j = 0; j < len; j++) {
//				cout << j << endl;
				if (used[j] == 0 && i - j == maxDistance) {
					ans += letters[j];
					used[j] = 1;
					break;
				}
				if (used[j] == 0 && abs(i - j) <= maxDistance && letters[j] < c) {
//					cout << letters[j] << " " << c << endl;
					c = letters[j];
					target = j;
				}
				if (j == len-1) {
					ans += letters[target];
					used[target] = 1;
					break;
				}
			}
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TOPCODER"; int Arg1 = 3; string Arg2 = "CODTEPOR"; verify_case(0, Arg2, getMin(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ESPRIT"; int Arg1 = 3; string Arg2 = "EIPRST"; verify_case(1, Arg2, getMin(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BAZINGA"; int Arg1 = 8; string Arg2 = "AABGINZ"; verify_case(2, Arg2, getMin(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg1 = 9; string Arg2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; verify_case(3, Arg2, getMin(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "GOODLUCKANDHAVEFUN"; int Arg1 = 7; string Arg2 = "CADDGAHEOOFLUKNNUV"; verify_case(4, Arg2, getMin(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"; int Arg1 = 6; string Arg2 = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"; verify_case(5, Arg2, getMin(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABRACADABRA"; int Arg1 = 2; string Arg2 = "AABARACBDAR"; verify_case(6, Arg2, getMin(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	EllysScrabble ___test;
	___test.run_test(-1);
}

// END CUT HERE
