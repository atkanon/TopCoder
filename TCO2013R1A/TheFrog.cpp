// BEGIN CUT HERE
/*
��TCO2013R1A medium

����蕶
�W�����v���D���Ȑl������
�Ƃ������W�����v�����o���Ȃ��l������
�������܂������ɂ����i�߂Ȃ��A�����ē������ł����W�����v�ł��Ȃ�
���Ɍ����J���Ă��āA���ɗ����Ȃ��悤�ɓ���i�ݐ؂肽��
���̍��[�ƉE�[���^������̂ŁA���ɗ����Ȃ��悤�ȃW�����v���̍ŏ��l�����߂�
���[�ƉE�[�ɂ͌��ɗ����Ȃ��悤�ɗ����Ƃ��ł���

�����
���z���܂΂�Ȃ̂�2���T���͂ł��Ȃ�����
�ŏ��lmax(R[i]-L[i])���瓹��n���悤�ɂ�����Ƃ����₵�Ă���
�𒼂�1�񂸂W�����v�����TLE���Ă��܂���
L[i]�̒��O�Ŏ~�߂āA1��W�����v�������ƂɌ��ɗ��������ǂ���������
������double�Ȃ̂�EPS�ɒ���
�덷�Ō��ɗ�����Ɖ����傫���Ȃ��Ă��܂��̂ŁA������ƌ��ɗ����ĂĂ���ڂɌ���悤��EPS������

CONSTRAINTS
-D will be between 1 and 30,000, inclusive.
-L will contain between 1 and 50 elements, inclusive.
-Each element of L will be between 0 and D-1, inclusive.
-R will contain the same number of elements as L.
-The i-th element of R will be between L[i]+1 and D, inclusive.
-The intervals given by (L[i], R[i]) will not intersect.
*/
// END CUT HERE
//#line 87 "TheFrog.cpp"
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

class TheFrog {
	public:
	double getMinimum(int D, vector <int> L, vector <int> R) {
		int len = L.size();
		double res = 0;
		for (int i = 0; i < len; i++)  res = res > R[i] - L[i] ? res : R[i] - L[i];
		while (1) {
			bool flg = 1;
			for (int i = 0; i < len; i++) {
				int tmp = (int)(L[i] / res) + 1;
				if (L[i] + EPS < tmp * res && tmp * res + EPS < R[i]) {
					double rem = R[i] - tmp * res;
					res += rem / tmp;
					flg = 0;
				}
			}
			if (flg) break;
		}
		return res;
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 7.0; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 25; int Arr1[] = {11, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {21, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 10.5; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 100.0; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arr1[] = {0, 50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 50.0; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 30000; int Arr1[] = {17, 25281, 5775, 2825, 14040}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {55, 26000, 5791, 3150, 14092}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 787.8787878787879; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TheFrog ___test;
  ___test.run_test(-1);
}
// END CUT HERE
