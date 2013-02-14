// BEGIN CUT HERE
/*
□SRM570 div2 hard

□問題文、解説
同じディレクトリのスライドを見てね！！

CONSTRAINTS
-N will be between 2 and 51, inclusive.
-a and b will contain exactly N-1 elements.
-Each element of a and b will be between 1 and N, inclusive.
-The network defined by a and b will be a tree (as explained in the problem statement).

*/
// END CUT HERE
//#line 87 "CentaurCompanyDiv2.cpp"
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

class CentaurCompanyDiv2 {
	public:
	vector<int> G[52];
	int dp_num[52][2];
	void dfs(int *num, int p, int f) {
		int sz = G[p].size();
//		cout << *num << " " << p << endl;
		for (int i = 0; i < sz; i++) {
			int t = G[p][i];
			if (t != f) {
				dfs(num, t, p);
			}
		}

		dp_num[p][0] = *num;
		dp_num[*num][1] = p;
		(*num)++;
	}
	long long count(vector <int> a, vector <int> b) {
		int sz = a.size(), n = sz+1;
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 2; j++) {
				dp_num[i][j] = 0;
			}
		}
		for (int i = 0; i < sz; i++) {
			int _a = a[i], _b = b[i];
			G[_a].push_back(_b);
			G[_b].push_back(_a);
		}

		int num = 1;
/*		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				cout << G[i][j];
			}
			cout << endl;
		}
*/		dfs(&num, 1, -1);

//		for (int i = 1; i <= n; i++) cout << i << " " << dp_num[i][0] << endl;

		LL dp[52] = {0};
		LL res = 1;
		for (int i = 1; i <= n; i++) {
			int p = dp_num[i][1];
			LL cnt = 1;
			for (int j = 0; j < G[p].size(); j++) {
				int cld = G[p][j];
				if (i > dp_num[cld][0]) cnt *= dp[cld]+1;
			}
			res += (dp[p] = cnt);
		}
//		for (int i = 1; i <= n; i++) cout << i << " " << dp[i] << endl;
		return res;		
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 56LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1125899906842675LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 144LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CentaurCompanyDiv2 ___test;
  ___test.run_test(-1);
}
// END CUT HERE
