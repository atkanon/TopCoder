// 2 "ShadowSculpture.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// A shadow sculpture is a 3D object that seems amorphous but casts a beautiful shadow.



You want to create a simple shadow sculpture that will consist of unit cubes.
More precisely, imagine an n*n*n cube that is aligned with the coordinate axes and divided into unit cubes.
Your sculpture will consist of some of those unit cubes (possibly none or all of them).
The unit cubes have coordinates (x,y,z) where 0 <= x,y,z < n.



You have already determined three shadows your sculpture should cast: its orthogonal projections onto the XY, YZ, and ZX plane.
You are given their description in three vector <string>s: XY, YZ, and ZX.



Their meaning is as follows:
For each i and j, the character XY[i][j] is either 'Y' or 'N'.
The character 'Y' means that the unit square (i,j) of the projection is dark.
In other words, if XY[i][j] is 'Y', at least one of the cubes with coordinates (i,j,k) has to be a part of your sculpture.
On the other hand, if XY[i][j] is 'N', none of the cubes with coordinates (i,j,k) may belong into your sculpture.
YZ and ZX describe the other two projections in the same way.
E.g., if ZX[i][j] is 'Y', you have to use at least one of the cubes (j,k,i).



Finally, there is one last constraint:
Your entire sculpture has to be 6-connected.
(Formally: Your sculpture must form one connected component, given that two cubes are adjacent iff they share a common face.)



Return "Possible" if it is possible to construct a sculpture that matches all the given constraints.
Otherwise, return "Impossible".

DEFINITION
Class:ShadowSculpture
Method:possible
Parameters:vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-XY, YZ and ZX will contain exactly n elements.
-Each element of XY, YZ and ZX will contain exactly n characters.
-Each element of XY, YZ and ZX will contain only 'Y' and 'N'.


EXAMPLES

0)
{"YN","NN"}
{"YN","NN"}
{"YN","NN"}

Returns: "Possible"

It is possible: we only have one solid cell at (0, 0, 0).

1)
{"YN","NY"}
{"YN","NY"}
{"YN","NY"}

Returns: "Impossible"

Here it is impossible to make a valid sculpture.
Note that you can make all three projections look right by using exactly two cubes: (0,0,0) and (1,1,1).
However, this sculpture is not 6-connected.

2)
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}

Returns: "Possible"



3)
{"YYY","YNY","YYY"}
{"NYY","YNY","YYY"}
{"YYY","YNY","YYN"}

Returns: "Impossible"



4)
{"N"}
{"N"}
{"N"}

Returns: "Possible"

A sculpture that consists of no cubes is connected.

*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

typedef long long LL;

class ShadowSculpture {
	public:

	vector <string> XY;
	vector <string> YZ;
	vector <string> ZX;
	string possible(vector <string> _XY, vector <string> _YZ, vector <string> _ZX) {
		XY = _XY;
		YZ = _YZ;
		ZX = _ZX;
		int scul[11][11][11] = {0};
		int sz = XY.size();
		string imp = "Impossible";
		string po = "Possible";
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					scul[i][j][k] = 1;
				}
			}
		}

		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					if (XY[i][j] == 'N') scul[i][j][k] = 0;
					if (YZ[j][k] == 'N') scul[i][j][k] = 0;
					if (ZX[k][i] == 'N') scul[i][j][k] = 0;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					if (scul[i][j][k]) cnt++;
				}
			}
		}
		
		if (!check_scul(scul, sz)) return imp;

		// check 6 connected
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < sz; k++)
					bfs_scul[i][j][k] = scul[i][j][k];

		int union_cnt = 0;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					init_copy_scul(sz);
					if (bfs(sz, i, j, k)) {
						union_cnt++;
						if (check_scul(copy_scul, sz)) return po;
					}
				}
			}
		}

		if (union_cnt) return imp;
		else return po;
	}

	int check_scul(int scul[11][11][11], int sz) {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				bool unit = false;
				for (int k = 0; k < sz; k++) {
					if (scul[i][j][k]) unit = true;
				}
				if (unit ^ (XY[i][j] == 'Y')) return 0;
			}
		}	
		for (int j = 0; j < sz; j++) {
			for (int k = 0; k < sz; k++) {
				bool unit = false;
				for (int i = 0; i < sz; i++) {
					if (scul[i][j][k]) unit = true;
				}
				if (unit ^ (YZ[j][k] == 'Y')) return 0;
			}
		}	
		for (int k = 0; k < sz; k++) {
			for (int i = 0; i < sz; i++) {
				bool unit = false;
				for (int j = 0; j < sz; j++) {
					if (scul[i][j][k]) unit = true;
				}
				if (unit ^ (ZX[k][i] == 'Y')) return 0;
			}
		}	
		return 1;
	}

	int bfs_scul[11][11][11];
	int copy_scul[11][11][11];
	void init_copy_scul(int sz) {
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < sz; k++)
					copy_scul[i][j][k] = 0;
	}
	int bfs(int sz, int ti, int tj, int tk) {
		if (!bfs_scul[ti][tj][tk]) return 0;
		bfs_scul[ti][tj][tk] = 0;
		copy_scul[ti][tj][tk] = 1;
		if (ti > 0 && bfs_scul[ti-1][tj][tk]) bfs(sz, ti-1, tj, tk);
		if (tj > 0 && bfs_scul[ti][tj-1][tk]) bfs(sz, ti, tj-1, tk);
		if (tk > 0 && bfs_scul[ti][tj][tk-1]) bfs(sz, ti, tj, tk-1);
		if (ti < sz-1 && bfs_scul[ti+1][tj][tk]) bfs(sz, ti+1, tj, tk);
		if (tj < sz-1 && bfs_scul[ti][tj+1][tk]) bfs(sz, ti, tj+1, tk);
		if (tk < sz-1 && bfs_scul[ti][tj][tk+1]) bfs(sz, ti, tj, tk+1);
		return 1;
	}

	// for debug
	void printXY(int scul[11][11][11], int sz) {
		for (int i = 0; i < sz; i++) {
			string s = "";
			for (int j = 0; j < sz; j++) {
				bool unit = false;
				for (int k = 0; k < sz; k++) {
					if (scul[i][j][k]) unit = true;
				}
				if (unit) s += "Y";
				else s += "N";
			}
			cerr << s << endl;
		}
	}
	void printYZ(int scul[11][11][11], int sz) {
		for (int j = 0; j < sz; j++) {
			string s = "";
			for (int k = 0; k < sz; k++) {
				bool unit = false;
				for (int i = 0; i < sz; i++) {
					if (scul[i][j][k]) unit = true;
				}
				if (unit) s += "Y";
				else s += "N";
			}
			cerr << s << endl;
		}
	}
	void printZX(int scul[11][11][11], int sz) {
		for (int k = 0; k < sz; k++) {
			string s = "";
			for (int i = 0; i < sz; i++) {
				bool unit = false;
				for (int j = 0; j < sz; j++) {
					if (scul[i][j][k]) unit = true;
				}
				if (unit) s += "Y";
				else s += "N";
			}
			cerr << s << endl;
		}
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(5, Arg3, possible(Arg0, Arg1, Arg2)); }



// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ShadowSculpture ___test;
	___test.run_test(-1);
}

// END CUT HERE
