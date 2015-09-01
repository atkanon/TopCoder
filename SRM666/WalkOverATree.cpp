// 2 "WalkOverATree.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Given is a tree on n nodes.
The nodes are numbered 0 through n-1.
You are given the description of the tree as a vector <int> parent with n-1 elements.
For each valid i, there is an edge between vertices (i+1) and parent[i].





A person is currently standing in node 0.
In a single step, the person can move from its current node to any adjacent node.
You are given an int L.
The person is allowed to make at most L steps.





Return the maximum number of nodes the person can visit during the walk.
Node 0 (where the walk starts) and the node where the walk ends count as visited.
Each visited node is only counted once, even if it is visited multiple times.


DEFINITION
Class:WalkOverATree
Method:maxNodesVisited
Parameters:vector <int>, int
Returns:int
Method signature:int maxNodesVisited(vector <int> parent, int L)


CONSTRAINTS
-parent will contain between 0 and 49 elements, inclusive.
-For each i, parent[i] will be between 0 and i, inclusive.
-L will be between 1 and 100, inclusive.


EXAMPLES

0)
{0, 0}
2

Returns: 2

The tree consists of edges 1-0 and 2-0.
Our person will start in node 0 and can make at most L=2 steps.
In two steps, the best we can do is visit one of the nodes 1 and 2.

1)
{0, 0}
3

Returns: 3

This is the same tree, only now we have L=3.
In three steps the person can visit all three nodes: for example, by going from node 0 to node 1, back to node 0, and finally to node 2.
Note that even though the person visited node 0 twice, we only count it once.

2)
{0, 1, 2, 3}
2

Returns: 3



3)
{0,0,0,0,2,4,2,3,1}
1

Returns: 2



4)
{0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}
4

Returns: 5



5)
{0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}
26

Returns: 17



6)
{0, 0, 2, 0}

100

Returns: 5

As the tree is very small and L large, the person can easily visit all nodes.

7)
{0, 0, 2}
4

Returns: 4



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

class WalkOverATree {
	public:
	int maxNodesVisited(vector <int> parent, int L) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,2,4,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(4, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; int Arg2 = 17; verify_case(5, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 0, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 5; verify_case(6, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(7, Arg2, maxNodesVisited(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	WalkOverATree ___test;
	___test.run_test(-1);
}

// END CUT HERE
