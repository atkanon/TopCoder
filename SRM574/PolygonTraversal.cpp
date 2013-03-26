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
typedef long long LL;

int n;
LL dp[1<<18][20];
int st;
class PolygonTraversal {
	public:
	void print_binary(int num) {
		for (int i = n-1; i >= 0; i--) {
			if (num>>i&1) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}

	long long dfs(int v, int last) {
		if (dp[v][last] != -1) return dp[v][last];

		int used[20] = {0}, bef[20] = {0}, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v>>i&1) {
				cnt++;
				used[i] = 1;
				if (i < last) bef[i] = -1;
				else if (i > last) bef[i] = 1;
			} 
		}

		if (cnt == n) {
			if (last != (st+1)%n && last != (st-1+n)%n) return dp[v][last] = 1;
			else return dp[v][last] = 0;
		}

		int aft[20] = {0};
		LL res = 0;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;

			for (int j = 0; j < n; j++) {
				if (j < i) aft[j] = -1;
				else if (j > i) aft[j] = 1;
			}

			int flg = 1;
			for (int j = 0; j < n; j++) {
				if (bef[j]*aft[j] < 0) break;
				if (j == n-1) flg = 0;
			}
			for (int j = 0; j < n; j++) {
				if (bef[j]*aft[j] > 0) break;
				if (j == n-1) flg = 0;
			}

			if (flg) res += dfs(v|1<<i, i);
		}
		return dp[v][last] = res;
	}
	long long count(int N, vector <int> points)  {
		n = N; st = points[0]-1;
		memset(dp, -1, sizeof(dp));
		int v = 0, sz = points.size(), last;
		for (int i = 0; i < sz; i++) {
			v |= 1<<(last = points[i]-1);
		}
		return dfs(v, last);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 18; int Arr1[] = {1, 7, 18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4374612736LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main()  {
	PolygonTraversal ___test;
	___test.run_test(-1);
}
// END CUT HERE
