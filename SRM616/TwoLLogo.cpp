#line 2 "TwoLLogo.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

typedef long long LL;

class TwoLLogo {
	public:
	long long countWays(vector <string> grid) {
		int sz = grid.size(), len = grid[0].length();
		LL ans = 0;
		for (int i = 1; i < sz; i++) {
			for (int j = 0; j < len-1; j++) {
				// L is found.
				if (grid[i][j] == '.' && grid[i-1][j] == '.' && grid[i][j+1] == '.') {
					cout << i << " " << j << endl;
//				}
//				if (0) {
					grid[i][j] = 'L';
					// vertical
					for (int ii = i-1; ii >= 0; ii--) {
						if (grid[ii][j] == '.') {
							grid[ii][j] = 'L';
							// horizontal
							for (int jj = j+1; jj < len; jj++) {
								if (grid[i][jj] == '.') {
									grid[i][jj] = 'L';
									for (int i2 = 1; i2 < sz; i2++) {
										for (int j2 = 0; j2 < len-1; j2++) {
											// L2 is found
											if (grid[i2][j2] == '.' && grid[i2-1][j2] == '.' && grid[i2][j2+1] == '.') {
												//vertical
												LL v = 1;
												for (int ii2 = i2-2; ii2 >= 0; ii2--) {
													if (grid[ii2][j2] == '.') v++;
													else break;
												}
												// horizontal
												LL h = 1;
												for (int jj2 = j2+2; jj2 < len; jj2++) {
													if (grid[i2][jj2] == '.') h++;
													else break;
												}
												cout << "L2 " << i2 << " " << j2 << " " << v << " " << h << endl;
												ans += v*h;
											}
										}
									}
									if (jj == len-1) {
										for (int jjj = jj; jjj >= j+1; jjj--) grid[i][jjj] = '.';
									}
								} else {
									for (int jjj = jj-1; jjj >= j+1; jjj--) grid[i][jjj] = '.';
									break;
								}
							}
							if (ii == 0) {
								for (int iii = ii; iii <= i-1; iii--) grid[iii][j] = '.';
							}
						} else {
							for (int iii = ii+1; iii <= i-1; iii--) grid[iii][j] = '.';
							break;
						}
					}
				}
			}
		}

		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {".##..",
 "...#.",
 ".#.#.",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
 "#.#.",
 "....",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {".#.#",
 "....",
 ".#.#",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 34LL; verify_case(4, Arg1, countWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1350LL; verify_case(5, Arg1, countWays(Arg0)); }
	void test_case_6() { string Arr0[] = {"#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2386LL; verify_case(6, Arg1, countWays(Arg0)); }
	void test_case_7() { string Arr0[] = {"...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5020791386LL; verify_case(7, Arg1, countWays(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	TwoLLogo ___test;
	___test.run_test(0);
	___test.run_test(1);
}

// END CUT HERE
