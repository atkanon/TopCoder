#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

typedef long long LL;

class TaroJiroGrid {
	public:

	bool check(vector <string> grid) {
		int size = grid.size();
		int length = grid[0].length();

		for (int i = 0; i < size; i++) {
			char c = grid[0][i];
			int cnt = 1;
			for (int j = 1; j < length; j++) {
				if (c == grid[j][i]) cnt++;
				else {
					c = grid[j][i];
					cnt = 1;
				}
				if (cnt > length / 2) {
					return false;
				}
//				cout << "cnt: " << cnt << endl;
			}
		}
		return true;
	}

	void print(vector <string> grid) {
		int size = grid.size();
		int length = grid[0].length();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}

	int getNumber(vector <string> grid) {
		int size = grid.size();
		int length = grid[0].length();

		/*
		string t[] = {"WB",""};
		cout << sizeof(t) << " " << sizeof(t[0]) << endl;
		vector <string> g(t, t + (sizeof(t) / sizeof(t[0])));

		cout << check(g) << endl;

		return 0;
		*/
		

		if (check(grid)) return 0;

		vector <string> masked_grid;
		for (int i = 0; i < size; i++) {
			for (int c = 0; c < 2; c++) {
				masked_grid = grid;
				for (int j = 0; j < length; j++) {
					masked_grid[i][j] = "WB"[c];
				}
				if (check(masked_grid)) return 1;
			}
		}
		return 2;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) {
		ostringstream os;
		os << "{ ";
		for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter)
			os << '\"' << *iter << "\","; os << " }";
		return os.str();
	}
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() {
		string Arr0[] = {"WB",
 "BB"};
		vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arg1 = 1;
		verify_case(0, Arg1, getNumber(Arg0));
	}
	void test_case_1() { string Arr0[] = {"WB",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"WB",
 "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	TaroJiroGrid ___test;
	___test.run_test(-1);
}

// END CUT HERE
