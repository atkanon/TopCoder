/**
 * srm572 div1 medium
 */

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
#include <stdio.h>
using namespace std;
static const double EPS = 1e-9;
typedef long long LL;

class EllysBulls {
	public:
	int pow(int a, int b) {
		int res = a;
		while (--b) res *= a;
		return res;
	}

	string getNumber(vector <string> guesses, vector <int> bulls)  {
		int sz = guesses.size(), len = guesses[0].length();
		vector<pair<LL, int> > vpii;
		int llen = len / 2, rlen = len - llen;
		char c[100];
		
		for (int i = 0; i < pow(10, llen); i++) {
			sprintf(c, "%0*d", llen, i);
			LL match = 0;
			for (int j = 0; j < sz; j++) {
				int cnt_bull = 0;
				for (int k = 0; k < llen; k++) {
					if (c[k] == guesses[j][k]) cnt_bull++;
				}
				match = match * 10 + cnt_bull;
			}
			vpii.push_back(make_pair(match, i));
		}
		
		sort(vpii.begin(), vpii.end());
		vector<LL> vi;
		for (int i = 0; i < vpii.size(); i++) vi.push_back(vpii[i].first);
		
		LL bulls_int = 0;
		for (int i = 0; i < sz; i++) bulls_int = bulls_int * 10 + bulls[i];

		int cnt = 0;
		char res[100] = "Liar";
		for (int i = 0; i < pow(10, rlen); i++) {
			sprintf(c, "%0*d", rlen, i);
			LL match = 0;
			for (int j = 0; j < sz; j++) {
				int cnt_bull = 0;
				for (int k = 0; k < rlen; k++) {
					if (c[k] == guesses[j][k + llen]) cnt_bull++;
				}
				match = match * 10 + cnt_bull;
			}

			LL sch = bulls_int - match;

			int find = upper_bound(vi.begin(), vi.end(), sch)
						- lower_bound(vi.begin(), vi.end(), sch);
			if (find) {
				vector<LL>::iterator ite = lower_bound(vi.begin(), vi.end(), sch);
				sprintf(res, "%0*d%0*s", llen, vpii[ite - vi.begin()].second, rlen, c);
				printf("%s %d\n", res, find); 
				cnt += find;
				if (cnt > 1) return "Ambiguity";
			}
		}
		return string(res);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1337"; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0000", "1111", "2222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Liar"; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"666666", "666677", "777777", "999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Ambiguity"; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "987", "654", "321", "100", "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 0, 0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "007"; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "54"; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "4266642"; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"000000000", "555555555", "100000001", "920000000", "083000000", "007400000", "000606000", "000004700", "000000380", "000000029", "000404000", "000004080", "007000009", "000000309", "003000001", "000006001", "000000720", "007000080", "003000300", "900000080", "100000001", "100000001", "000006020", "007006000", "000006020", "000600009", "080006000", "020000001", "027000000", "000006300", "083000000", "000004009", "027000000", "000600080", "020004000", "020000300", "080006000", "080000700", "180000000", "007006000", "100004000", "020000300", "100000300", "900000080", "007400000", "000004700", "000000081", "000000309", "007000009", "111666999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	int Arr1[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "123456789"; verify_case(6, Arg2, getNumber(Arg0, Arg1)); }
 
// END CUT HERE

};
// BEGIN CUT HERE 
int main()  {
	EllysBulls ___test;
	___test.run_test(-1);
}
// END CUT HERE
