// BEGIN CUT HERE
/*
□SRM570 division1 medium
解説スライド見てね！！

CONSTRAINTS
-N will be between 2 and 36, inclusive.
-a and b will contain exactly N-1 elements.
-Each element of a and b will be between 1 and N, inclusive.
-The network defined by a and b will be a tree (as explained in the problem statement).

*/
// END CUT HERE
//#line 106 "CentaurCompany.cpp"
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

vector<int> G[40];
LL dp[40][2][40][40];
LL dp2[2][40][40];
int sz;

class CentaurCompany {
	public:
	void dfs(int v, int f) {
//		cout << v << " " << f << endl;
		for (int i = 0; i < G[v].size(); i++) {
			if (G[v][i] == f) continue;
			dfs(G[v][i], v);
		}

		dp[v][0][0][0] = 1;
		dp[v][1][1][0] = 1;
		for (int i = 0; i < G[v].size(); i++) {
			memset(dp2, 0, sizeof(dp2));
			if (G[v][i] == f) continue;
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k <= sz; k++) {
					for (int L = 0; L < sz; L++) {
						if (dp[v][j][k][L] == 0) continue;
						for (int m = 0; m < 2; m++) {
							for (int n = 0; n <= sz; n++) {
								for (int p = 0; p < sz; p++) {
									if (dp[G[v][i]][m][n][p] == 0) continue;
									if (j == 1 && m == 1) {
										dp2[j][k+n][L+p+1] += dp[v][j][k][L]*dp[G[v][i]][m][n][p];
									} else {
										dp2[j][k+n][L+p] += dp[v][j][k][L]*dp[G[v][i]][m][n][p];
									}
								}
							}
						}
					}
				}
			}
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k <= sz; k++) {
					for (int L = 0; L < sz; L++) {
						dp[v][j][k][L] = dp2[j][k][L];
					}
				}
			}
		}
	}
	double getvalue(vector <int> a, vector <int> b) {
		sz = a.size();
		memset(G, 0, sizeof(G));
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < sz; i++) {
			G[--a[i]].push_back(--b[i]);
			G[b[i]].push_back(a[i]);
		}
		sz++;
		dfs(0, -1);

		LL cnt = 0, temp = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j <= sz; j++) {
				for (int k = 0; k < sz; k++) {
//					printf("%d %d %d %d\n", i, j, k, dp[0][i][j][k]);
					cnt += dp[0][i][j][k]*max(j-2*k-2, 0);
					temp += dp[0][i][j][k];
				}
			}
		}

		double res = double(cnt)/(1LL<<(sz-1));
		return res;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.125; verify_case(1, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.375; verify_case(2, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.41796875; verify_case(3, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 15.500000001076842; verify_case(4, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.646484375; verify_case(5, Arg2, getvalue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  CentaurCompany ___test;
  ___test.run_test(-1);
}
// END CUT HERE
