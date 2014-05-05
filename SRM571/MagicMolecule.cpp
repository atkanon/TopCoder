// BEGIN CUT HERE
/*
□SRM571 div1 medium

□問題文
連結な無向グラフが与えられる
vertexを好きな様に選んでクリークを探して点数をつける
vertexごとに点数があり、クリークの点数はクリークに属するvertexの点数の和
ただしクリークとして選んだvertexの数mは元のグラフのサイズnに対して
	m*3 >= n*2
を満たしていなければいけない
条件を満たすクリークがなければreturn -1する
クリークの点数の最大値を返す

CONSTRAINTS
-magicPower will contain between 2 and 50 elements, inclusive.
-Each element in magicPower will be between 1 and 100,000, inclusive.
-magicBond and magicPower will contain the same number of elements.
-Each element of magicPower will contain exactly n characters, where n is the number of elements in magicPower.
-Each element of magicPower will only contain the characters 'Y' and 'N'.
-For each valid i, magicPower[i][i] will be 'N'.
-For each valid i and j, magicPower[i][j] will be equal to magicPower[j][i].

*/
// END CUT HERE
//#line 81 "MagicMolecule.cpp"
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

int sz;
int unused[51];
vector<int> mP;
vector<string> mB;

class MagicMolecule {
	public:
	int dfs(int m) {
		int res = -1;
		if (m * 3 < sz * 2) return res;
		for (int i = 0; i < sz; i++) {
			for (int j = i+1; j < sz; j++) {
				if (!unused[i] && !unused[j] && mB[i][j] == 'N') {
					unused[i] = 1;
					res = max(res, dfs(m - 1));
					unused[i] = 0;

					unused[j] = 1;
					res = max(res, dfs(m - 1));
					unused[j] = 0;
					return res;
				}
			}
		}
		int _res = 0;
		for (int i = 0; i < sz; i++) {
			if (!unused[i]) _res += mP[i];
		}
		return max(_res, res);
	}
	int maxMagicPower(vector <int> magicPower, vector <string> magicBond) {
		sz = magicPower.size();
		mP = magicPower;
		mB = magicBond;
		memset(unused, 0, sizeof(unused));
		return dfs(sz);
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNN","YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYY","NNYY","YYNN","YYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {86,15,100,93,53,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 332; verify_case(2, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 57179; verify_case(3, Arg2, maxMagicPower(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MagicMolecule ___test;
  ___test.run_test(-1);
}
// END CUT HERE
