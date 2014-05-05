#line 2 "MyLongCake.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <set>
#include <sstream>

using namespace std;

typedef long long LL;

int a[100002], b[100002];
int an, bn;

class MyLongCake {
	public:

	int N;

	void form_next(int *a, int *b, int &an, int &bn, int target) {
		bn = 0;
		int i = 0;
		while (i < an) {
			int cur = target;
			while (i < an && cur > 0) {
				if (a[i] <= cur) {
					b[bn++] = a[i];
					cur -= a[i];
					a[i] = 0;
					i++;
				} else {
					b[bn++] = cur;
					a[i] -= cur;
					cur = 0;
				}
			}
		}
	}

	int cut(int n) {
		an = 1;
		a[0] = n;
		N = n;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				form_next(a, b, an, bn, n / i);
				memcpy(a, b, sizeof(a[0]) * bn);
				an = bn;
			}
		}
		return an;
	}

	int cut2(int n) {
		vector<int> vi;
		for (int i = 2; i < n; i++) {
			if (n%i == 0) vi.push_back(i);
		}

		int sz = vi.size();
		set<int> si;
		for (int i = 0; i < sz; i++) {
			for (int j = 1; j < n/vi[i]; j++) {
//				cout << j*vi[i] << " ";
				si.insert(j*vi[i]);
			}
//			cout << endl;
		}
		cout << endl;

		set<int>::iterator it = si.begin();
		while( it != si.end() ) {
//			cout << *it << " ";
			++it;
		}
//		cout << endl;



		return si.size() + 1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//	publi:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, cut2(Arg0), cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, cut2(Arg0), cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, cut2(Arg0), cut(Arg0)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_4() { int Arg0 = 9950; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_5() { int Arg0 = 10235; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_6() { int Arg0 = 16600; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_7() { int Arg0 = 99876; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_8() { int Arg0 = 5509; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_9() { int Arg0 = 4434; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_10() { int Arg0 = 14; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }
	void test_case_11() { int Arg0 = 0; int Arg1 = 60000; verify_case(3, cut(Arg0), cut(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	MyLongCake ___test;
	___test.test_case_0();
	___test.test_case_1();
	___test.test_case_2();
	___test.test_case_3();
	___test.test_case_4();
	___test.test_case_5();
	___test.test_case_6();
	___test.test_case_7();
	___test.test_case_8();
	___test.test_case_9();
	___test.test_case_10();
	___test.test_case_11();
	___test.run_test(-1);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(0);
}

// END CUT HERE
