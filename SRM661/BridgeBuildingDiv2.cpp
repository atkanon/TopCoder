// 2 "BridgeBuildingDiv2.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have two rows of nodes.
Each row contains N nodes, numbered 0 through N-1 from the left to the right.



Within each row, adjacent nodes are already connected by edges.
You are given the lengths of these edges as vector <int>s a and b, each containing N-1 elements.
For each valid i, a[i] is the length of the edge between nodes i and (i+1) in the top row, and b[i] is the length of the edge between nodes i and (i+1) in the bottom row.



You want to add exactly K new edges to this graph.
Each of the new edges must be vertical -- i.e., it must connect some vertex i in the top row to the vertex i in the bottom row.
All new edges will have length 0.



By adding the K new edges we will produce a connected graph.
The diameter of this graph is the maximum of all shortest distances among pairs of its nodes.
In other words, the diameter is the smallest number D such that it is possible to travel from any node to any other node using a path of length D or less.



Given a, b, and the int K, compute and return the smallest possible diameter of the resulting graph.


DEFINITION
Class:BridgeBuildingDiv2
Method:minDiameter
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int minDiameter(vector <int> a, vector <int> b, int K)


CONSTRAINTS
-N will be between 2 and 11, inclusive.
-a,b will contain exactly N-1 elements each.
-K will be between 1 and N, inclusive.
-Each element of a,b will be between 1 and 50, inclusive.


EXAMPLES

0)
{2,1,1,1,2}
{1,9,1,9,1}
4

Returns: 6


One example of an optimal solution is to draw the bridges as follows:




1)
{1,50,1,50,1,50,1,50}
{50,1,50,1,50,1,50,1}
9

Returns: 8



2)
{50,10,15,31,20,23,7,48,5,50}
{2,5,1,8,3,2,16,11,9,1}
3

Returns: 124



3)
{2,4,10,2,2,22,30,7,28}
{5,26,1,2,6,2,16,3,15}
5

Returns: 54



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>

#define INF 1000000000

using namespace std;

typedef long long LL;

class BridgeBuildingDiv2 {
	public:
	int minDiameter(vector <int> a, vector <int> b, int K) {
        long sz = a.size() + 1;
        int res = INF;
        for (int i = 0; i < 1 << sz; i++) {
            int exist[12] = {0};
            int cnt = 0;
            for (int j = 0; j < sz; j++) {
                if ((i>>j) & 1) {
                    exist[j]++;
                    cnt++;
                }
            }
            
            if (cnt != K) continue;
            
/*            for (int j = 0; j < sz; j++) {
                cerr << exist[j] << " ";
            }
            cerr << endl;*/
            
            int dist[30][30] = {0};
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 30; j++) {
                    dist[i][j] = INF;
                }
                dist[i][i] = 0;
             }
            for (int i = 0; i < sz - 1; i++) {
                dist[i][i+1] = dist[i+1][i] = a[i];
                dist[i+sz][i+sz+1] = dist[i+sz+1][i+sz] = b[i];
            }
            for (int i = 0; i < sz; i++) {
                if (exist[i]) {
                    dist[i][i+sz] = 0;
                }
            }
            
            for (int i = 0; i < sz * 2; i++) {
                for (int j = 0; j < sz * 2; j++) {
                    for (int k = 0; k < sz * 2; k++) {
                        dist[j][k] = dist[k][j] = min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }
            
            int maxDist = -1;
            for (int i = 0; i < sz * 2; i++) {
                for (int j = 0; j < sz * 2; j++) {
                    maxDist = max(maxDist, dist[i][j]);
//                    cerr << i << " " << j << " " << dist[i][j] << endl;
                }
            }

            res = min(res, maxDist);
        }
        
        return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,9,1,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,50,1,50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,1,50,1,50,1,50,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 8; verify_case(1, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50,10,15,31,20,23,7,48,5,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,8,3,2,16,11,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 124; verify_case(2, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2,4,10,2,2,22,30,7,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,26,1,2,6,2,16,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 54; verify_case(3, Arg3, minDiameter(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	BridgeBuildingDiv2 ___test;
	___test.run_test(-1);
}

// END CUT HERE
