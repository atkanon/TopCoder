// BEGIN CUT HERE
/*
□SRM370 div1 easy

□問題文
操作：aだけ進んでa回90度回転してを何回か繰り返す
T回操作した後の座標と、初期座標のマンハッタン距離を求める

□解説
4回周期
1回で同じ向きか違う向きか
違う向きなら4回で同じ座標に戻る

CONSTRAINTS
-T will be between 1 and 1,000,000,000, inclusive.
-a will contain between 1 and 50 elements, inclusive.
-Each element of a will be between 1 and 10,000,000, inclusive.

*/
// END CUT HERE
//#line 87 "RobotHerb.cpp"
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

class RobotHerb {
	public:
	long long getdist(int T, vector <int> a) {
		LL x = 0, y = 0, di = 0;
		LL b[4][3] = {0};
		int sz = a.size();
		for(int j = 0; j < 4; j++){
			for(int i = 0; i < sz; i++){
				if(di == 0){
					y += a[i];
				}else if(di == 1){
					x += a[i];
				}else if(di == 2){
					y -= a[i];
				}else{
					x -= a[i];
				}
				di = (di+a[i]%4)%4;
			}
			b[j][0] = x, b[j][1] = y, b[j][2] = di;
		}

		x = b[3][0]*(T/4) + (T%4 == 0 ? 0 : b[T%4-1][0]);
		y = b[3][1]*(T/4) + (T%4 == 0 ? 0 : b[T%4-1][1]);
		return abs(x)+abs(y);
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, getdist(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, getdist(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(2, Arg2, getdist(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000000; int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 100000000000LL; verify_case(3, Arg2, getdist(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 570; int Arr1[] = {2013,2,13,314,271,1414,1732}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4112LL; verify_case(4, Arg2, getdist(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  RobotHerb ___test;
  ___test.run_test(-1);
}
// END CUT HERE
