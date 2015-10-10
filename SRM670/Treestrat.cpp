// 2 "Treestrat.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Two players are playing a game with some tokens on a tree.
Player A has one or more red tokens.
Player B has one or more blue tokens.
Initially, each vertex of the tree is either empty or contains exactly one token (either a red one or a blue one, not both).
During the game there can be arbitrarily many tokens of each color in each vertex.

You are given the description of the initial state of the game.
More precisely, you are given the vector <int>s tree, A, and B.
The length of tree is n-1, where n is the number of vertices in the tree.
The vertices in the tree are numbered 0 through n-1.
For each i between 1 and n-1, inclusive, there is an edge between the vertices i and tree[i-1].
The elements of A are the numbers of vertices that initially contain player A's tokens.
The elements of B are the vertices with player B's tokens.

The game is played in rounds.
Each round consists of two phases.
In the first phase player A may move some of his tokens, and in the second phase player B may move some of her tokens.
More precisely, the current player always examines all of their tokens, and for each of them the player either decides to keep it in its current vertex, or decides to move it to one of the adjacent vertices.

Player B wins if after some round there is a vertex that contains both a red and a blue token.
(There can even be multiple red or blue tokens in that vertex.)
Player B wants to win in as few rounds as possible.
Player A wants the game to go for as many rounds as possible.
Assume that both players play the game optimally.
Compute and return the number of rounds the game will take.

Note that it can be shown that the answer is always finite: player B always has a winning strategy.
Also note that you are supposed to return the number of rounds, not the total number of phases.

DEFINITION
Class:Treestrat
Method:roundcnt
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int roundcnt(vector <int> tree, vector <int> A, vector <int> B)


CONSTRAINTS
-tree will contain n - 1 element.
-n will be between 2 and 50, inclusive.
-i-th elements in tree will be between 0 and i, inclusive.
-A will contain between 1 and 50 elements, inclusive.
-B will contain between 1 and 50 elements, inclusive.
-Each element in A and B will be between 0 and n - 1, inclusive.
-No element will occur more than once in the concatenation of A and B.


EXAMPLES

0)
{0}
{0}
{1}

Returns: 1

This is a tree with a single edge 0-1.
Initially there is a red token in vertex 0 and a blue token in vertex 1.
Regardless of where player A moves the red token, player B can move the blue token to the same vertex and win.

1)
{0,1}
{1}
{2}

Returns: 2

This tree is a line that consists of two edges: 0-1 and 1-2.
We start with a red token on vertex 1 and a blue token on vertex 2.
Player A's optimal strategy is to start by moving his token into vertex 0.
Player B will then move her token into vertex 1.
In the second round player B will then win the game in the same way as in Example 0.

2)
{0,0,0,3,4}
{2}
{1}

Returns: 2



3)
{0,0,0,3,4,2}
{1}
{6}

Returns: 5



4)
{0,0,0,3,4,2}
{1}
{6,5}

Returns: 3



5)
{0,0,0,3,4,2}
{4,1}
{3,6}

Returns: 2



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

class Treestrat {
	public:
	int roundcnt(vector <int> tree, vector <int> A, vector <int> B) {
        int a[50][50] = {0};
        int b[50] = {0};
        for (int i = 0; i < 50; i++) {
            b[i] = INF;
            for (int j = 0; j < 50; j++) {
                a[i][j] = INF;
            }
            a[i][i] = 0;
        }
        for (int i = 0; i < tree.size(); i++) {
            a[i+1][tree[i]] = a[tree[i]][i+1] = 1;
        }
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                for (int k = 0; k < 50; k++) {
                    a[j][k] = a[k][j] = min(a[j][k], a[j][i] + a[i][k]);
                }
            }
        }
        
/*        for (int i = 0; i <= tree.size(); i++) {
            for (int j = 0; j <= tree.size(); j++) {
                cerr << i << " " << j << ": " << a[i][j] << endl;
            }
        }*/
        
        for (int i = 0; i < 50; i++) {
            int dist = INF;
            for (int j = 0; j < B.size(); j++) {
                dist = min(dist, a[B[j]][i]);
            }
            b[i] = dist;
        }
        
/*        for (int i = 0; i <= tree.size(); i++) {
            cerr << i << ": " << b[i] << endl;
        }*/
        
        int res = INF;
        for (int i = 0; i < A.size(); i++) {
            int t = -1;
            for (int j = 0; j < 50; j++) {
                if (a[A[i]][j] >= INF) continue;
                if (b[j] > a[A[i]][j] && b[j] > t) {
                    t = b[j];
                }
            }
            res = min(res, t);
        }
        
        return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(3, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, roundcnt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Treestrat ___test;
	___test.run_test(-1);
}

// END CUT HERE
