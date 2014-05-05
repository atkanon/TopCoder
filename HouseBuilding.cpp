// BEGIN CUT HERE
/*
□TCO2013R1A easy

□問題文
２じげんの畑を考える
畑はでこぼこで高かったり低かったりする
高低差を減らしたい
全体の高いところと低いところで差が1以下になるように頑張る

□解説
ふつうにlower決めて全探索すればいいのにはまってしまった。
けしからん
for lower in range(0, 10):
	upper = lower + 1
みたいなかんじでOK

CONSTRAINTS
-area will contain between 1 and 50 elements, inclusive.
-Each element of area will be between 1 and 50 characters long, inclusive.
-All elements of area will be of the same length.
-Each element of area will contain digits ('0'-'9') only.

*/
// END CUT HERE
//#line 69 "HouseBuilding.cpp"
#include <string>
#include <vector>
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
static const double EPS = 1e-9;
const int INF = 987654321;
typedef long long LL;


class HouseBuilding {
	public:
	int getMinimum(vector <string> area) {
		int res = INF;
		for (int i = 0; i <= 50; i++) {
			int cnt = 0;
			for (int j = 0; j < area.size(); j++) {
				for (int k = 0; k < area[0].length(); k++) {
					int t = area[j][k]-'0';
					if (t <= i) {
						cnt += i-t;
					} else {
						cnt += max(t-i-1, 0);
					}
				}
			}
			res = min(res, cnt);
		}
		return res;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "31"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"54454",
 "61551"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"989"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"5781252",
 "2471255",
 "0000291",
 "1212489"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 53; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  HouseBuilding ___test;
  ___test.run_test(-1);
}
// END CUT HERE
