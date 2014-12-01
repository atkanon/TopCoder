#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class AliceGame {
	public:

	long long score(long long n) {
		return n*2-1;
	}

	long long findMinimumValue(long long x, long long y) {
		LL n = -1;
		for (LL i = 0; i <= 2000000; i++) {
			if (i*i == x+y) {
				n = i;
			}
		}
		cerr << n << endl;
		if (n == -1) return -1;
		if (x == 2 || y == 2) return -1;
		if (x == 0) return 0;

		LL sum = 0;
		int cnt = 0;
		for (LL i = n; i >= 1; i--) {
			if (sum + score(i) <= x && x - (sum + score(i)) != 2) {
				sum += score(i);
				cnt++;
			}
		}

		return cnt;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 8LL; long long Arg1 = 17LL; long long Arg2 = 2LL; verify_case(0, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 17LL; long long Arg1 = 8LL; long long Arg2 = 3LL; verify_case(1, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 0LL; verify_case(2, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 9LL; long long Arg1 = 9LL; long long Arg2 = -1LL; verify_case(3, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1959000000000LL; long long Arg1 = 1000000000LL; long long Arg2 = 1000000000000LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 2000001LL; long long Arg1 = 999997999999LL; long long Arg2 = 3LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
	void test_case_6() { long long Arg0 = 1000000000000LL; long long Arg1 = 999998409369LL; long long Arg2 = 414214LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
//	void test_case_4() { long long Arg0 = 1959 000 00 00 00LL; long long Arg1 = 1 000 00 00 00LL; long long Arg2 = 1000000000000LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
//	void test_case_4() { long long Arg0 = 1960000000000LL; long long Arg1 = 0LL; long long Arg2 = 1000000000000LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }
//	void test_case_4() { long long Arg0 = 500000LL; long long Arg1 = 500000LL; long long Arg2 = 294LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
