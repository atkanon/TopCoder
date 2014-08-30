#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cctype>
#include <cstring>


using namespace std;

typedef long long LL;

class DivisorsPower {
	public:

	LL calc(vector<pair<LL, LL> > vp, LL N, LL M) {
		LL sz = vp.size();

		LL flg = 1;
		for (LL i = 0; i < sz; i++) {
			if (vp[i].second%N != 0) flg = 0;
		}

		if (flg == 0) return -1;

		for (LL i = 0; i < sz; i++) {
			vp[i].second /= N;
		}

		LL power_number = 1;
		for (LL i = 0; i < sz; i++) {
			power_number *= (vp[i].second + 1);
		}

		LL res = 1;
		for (LL i = 0; i < sz; i++) {
			for (LL j = 0; j < vp[i].second; j++) {
				res *= vp[i].first;
			}
		}

		LL res2 = 1;
		for (LL i = 0; i < power_number; i++) {
			res2 *= res;
		}

		if (res2 == M) return res;
		else return -1;
	}

	LL findArgument(LL n) {
		if (n == 1) return 1;
		double N = n;
		LL fuck = -1;
		for (int i = 2; i <= n; i++) {
			LL x = (LL)(pow(N, 1.0 / i) + 0.00000001);
			if (x == 1) break;
			LL tmp = 1;
			for (int j = 1; j <= i; j++) {
				tmp *= x;
			}

			if (tmp == n) {
				LL top = sqrt(x);
				int cnt = 0;
				for (int k = 1; k <= top; k++) {
					LL a = k;
					LL b = x / a;
					if (x % a == 0) {
						cnt += 2;
						if (a == b) {
							cnt--;
						}
					}
				}
				if (cnt == i) {
					fuck = x;
				}
			}
		}
		return fuck;


		LL m = n;
		LL div_max = 0;
		vector<pair<LL, LL> > vp;
		for (LL i = 2; i <= sqrt(n); i++) {
			if (m == 1) break;
			if (m%i == 0) {
				LL cnt = 0;
				while (m%i == 0) {
					cnt++;
					m /= i;
				}
				div_max = max(div_max, cnt);
				vp.push_back(make_pair(i, cnt));
			}
		}

/*		for (LL i = 0; i < vp.size(); i++) {
			cout << vp[i].first << " " << vp[i].second << endl;
		}*/

//		cout << div_max << endl;

		LL res = -1;
		for (LL i = 2; i <= div_max; i++) {
			LL res2 = calc(vp, i, n);
//			cout << "res2 " << res2 << endl;

			if (res == -1) res = res2;
			else if (res2 != -1) res = min(res, res2);
		}

		return res;
	}	
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivisorsPower ___test;
	___test.run_test(-1);
}
// END CUT HERE
