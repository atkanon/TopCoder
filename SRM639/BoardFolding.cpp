#line 2 "BoardFolding.cpp"
#include <string>
#include <vector>

using namespace std;

class BoardFolding {
	public:
	int howMany(int N, int M, vector <string> compressedPaper) {
		int xmap[251][251] = {0};
		int ymap[251][251] = {0};
		xmap[0][M] = 1; ymap[0][N] = 1;

		int paper[251][251] = {0};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				paper[i][j] = (int(compressedPaper[i][j / 6]) >> (j % 6)) % 2;
			}
		}

		int x_mirror[251][251] = {0};
		int y_mirror[251][251] = {0};
		for (int i = 0; i < N; i++) {
			for (int d = 1; d < N; d++) {
				bool mirror = true;
				for (int d2 = 1; d2 <= d; d2++) {
					for (int j = 0; j < M; j++) {
						if (i - d2 < 0 || i + d2 >= M) continue;
						if (paper[i-d2][j] != paper[i+d2][j]) {
							mirror = false;
							break;
						}
					}
				}
			}
		}

	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoardFolding ___test;
	___test.run_test(-1);
}
// END CUT HERE
