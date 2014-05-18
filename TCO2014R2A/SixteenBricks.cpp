#line 2 "SixteenBricks.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

class SixteenBricks {
	public:
	int calc(vector<int> height) {
		int res = 0;
		res += 4*4;
		res += height[0] + height[4] + height[8] + height[12];
		res += height[3] + height[7] + height[11] + height[15];
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 4; j++) {
				int a = i*4 + j, b = i*4 + j - 1;
				res += max(0, height[a]-height[b]);
				res += max(0, height[b]-height[a]);
			}
		}

		res += height[0] + height[1] + height[2] + height[3];
		res += height[12] + height[13] + height[14] + height[15];
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 4; j++) {
				int a = j*4 + i, b = j*4 + i - 4;
				res += max(0, height[a]-height[b]);
				res += max(0, height[b]-height[a]);
			}
		}

		return res;
	}

	int maximumSurface(vector <int> height) {
		sort(height.begin(), height.end());
		int res = 16;
		for (int i = 0; i < 8; i++) res += 4 * height[16 - 1 - i];
		for (int i = 0; i < 4; i++) res -= 2 * height[16 - 8 - 2 - 1 - i];
		for (int i = 0; i < 2; i++) res -= 4 * height[16 - 8 - 2 - 4 - 1 - i];
		return res;

		vector<int> vi = height, vig, vis;
		sort(height.rbegin(), height.rend());
		vi[5] = height[0];
		for (int i = 1; i < 8; i++) vig.push_back(height[i]);
		sort(height.begin(), height.end());
		vi[6] = height[0];
		for (int i = 1; i < 8; i++) vis.push_back(height[i]);

//		int res = 0;
		do {
			vi[0] = vig[0];
			vi[2] = vig[1];
//			vi[5] = vig[2];
			vi[7] = vig[2];
			vi[8] = vig[3];
			vi[10] = vig[4];
			vi[13] = vig[5];
			vi[15] = vig[6];
			do {
				vi[1] = vis[0];
				vi[3] = vis[1];
				vi[4] = vis[2];
//				vi[6] = vis[3];
				vi[9] = vis[3];
				vi[11] = vis[4];
				vi[12] = vis[5];
				vi[14] = vis[6];
				res = max(res, calc(vi));
			} while (next_permutation(vis.begin(), vis.end()));
		} while (next_permutation(vig.begin(), vig.end()));
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, maximumSurface(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, maximumSurface(Arg0)); }
	void test_case_2() { int Arr0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1798; verify_case(2, Arg1, maximumSurface(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	SixteenBricks ___test;
	___test.run_test(-1);
}

// END CUT HERE
