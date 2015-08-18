// 2 "LuckyCycle.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
This problem is about trees.
A tree consists of some special points (called nodes), and some lines (called edges) that connect those points.
Each edge connects exactly two nodes.
If there are N nodes in a tree, there are exactly N-1 edges.
The edges of a tree must connect the nodes in such a way that the tree is connected: 
it must be possible to get from any node to any other node by traversing some sequence of edges.
Note that this implies that a tree never contains a cycle:
for each pair of nodes there is exactly one way to reach one from the other without using the same edge twice.



Dog has a tree.
The edges in Dog's tree have weights.
As Dog likes the numbers 4 and 7, the weight of each edge is either 4 or 7.



Cat loves modifying trees.
Cat is now going to modify Dog's tree by adding one new edge.
The new edge will also have a weight that is either 4 or 7.
The new edge will connect two nodes that don't already have an edge between them.
Note that adding any such edge will create exactly one cycle somewhere in the tree.
(A cycle is a sequence of consecutive edges that starts and ends in the same node.)



A cycle is balanced if the number of edges on the cycle is even, and among them the number of edges with weight 4 is the same as the number of edges with weight 7.
Cat would like to add the new edge in such a way that the cycle it creates will be balanced.



You are given the description of Dog's current tree in vector <int>s edge1, edge2, and weight.
Each of these vector <int>s will have exactly n-1 elements, where n is the number of nodes in Dog's tree.
The nodes in Dog's tree are labeled 1 through n.
For each valid i, Dog's tree contains an edge that connects the nodes edge1[i] and edge2[i], and the weight of this edge is weight[i].



Return a vector <int> with exactly three elements: {P,Q,W}.
Here, P and Q should be the nodes connected by the new edge, and W should be the weight of the new edge.
(Note that P and Q must be between 1 and N, inclusive, and W must be either 4 or 7.)
If there are multiple solutions, return any of them.
If there are no solutions, return an empty vector <int> instead.


DEFINITION
Class:LuckyCycle
Method:getEdge
Parameters:vector <int>, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight)


CONSTRAINTS
-N will be between 2 and 100, inclusive.
-edge1, edge2, and weight will each contain exactly N-1 elements.
-Each element of weight will be either 4 or 7
-Each element of edge1 and edge2 will be between 1 and N, inclusive.
-The input will define a tree.


EXAMPLES

0)
{1}
{2}
{4}

Returns: { }

We cannot add any edge because the only two nodes are already connected by an edge.

1)
{1, 3, 2, 4}
{2, 2, 4, 5}
{4, 7, 4, 7}

Returns: {1, 5, 7 }

The input describes a tree with 5 nodes.
The tree contains the following edges: 1-2 (weight 4), 3-2 (weight 7), 2-4 (weight 4), and 4-5 (weight 7).
The example return value describes a new edge that connects nodes 1 and 5, and has weight 7.

Adding the new edge creates a cycle that goes through the nodes 1, 2, 4, and 5, in this order.
This cycle is balanced: two of its four edges have weight 4 and the other two have weight 7.

2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
{4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7}

Returns: {1, 12, 7 }



3)
{1, 2, 3, 5, 6}
{2, 3, 4, 3, 5}
{4, 7, 7, 7, 7}

Returns: {1, 4, 4 }



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>

#define INF 1<<28

using namespace std;

typedef long long LL;

class LuckyCycle {
	public:
	vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
        int sz = edge1.size();
        int n = sz + 1;
        vector<int> ans;
        int W[101][101][2] = {0};
        
        for (int i = 0; i < sz; i++) {
            edge1[i]--;
            edge2[i]--;
        }
        
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                W[i][j][0] = W[i][j][1] = INF;
            }
        }
        
        for (int i = 0; i < sz; i++) {
            if (weight[i] == 4) {
                W[edge1[i]][edge2[i]][0] = 1;
                W[edge2[i]][edge1[i]][0] = 1;
                W[edge1[i]][edge2[i]][1] = 0;
                W[edge2[i]][edge1[i]][1] = 0;
            } else {
                // 7
                W[edge1[i]][edge2[i]][1] = 1;
                W[edge2[i]][edge1[i]][1] = 1;
                W[edge1[i]][edge2[i]][0] = 0;
                W[edge2[i]][edge1[i]][0] = 0;
            }
        }
        

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    W[i][j][0] = min(W[i][j][0], W[i][k][0] + W[k][j][0]);
                    W[j][i][0] = W[i][j][0];
                    W[i][j][1] = min(W[i][j][1], W[i][k][1] + W[k][j][1]);
                    W[j][i][1] = W[i][j][1];
//                        printf("i:%d k:%d j%d, 4(%d %d %d), 7(%d %d %d)\n", i, k, j, W[i][k][0], W[i][j][0], W[k][j][0], W[i][k][1], W[i][j][1], W[k][k][1]);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int c4 = W[i][j][0];
                int c7 = W[i][j][1];
//                cerr << i << " " << j << " " << W[i][j][0] << " " << W[i][j][1] << endl;
                if (c4 >= 1 && c7 >= 1) {
                    if (c4 - c7 == 1) {
                        ans.push_back(i+1);
                        ans.push_back(j+1);
                        ans.push_back(7);
                        return ans;
                    } else if (c7 - c4 == 1) {
                        ans.push_back(i+1);
                        ans.push_back(j+1);
                        ans.push_back(4);
                        return ans;
                    }
                }
            }
        }
        
        return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getEdge(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 3, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 7, 4, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 5, 7 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getEdge(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 12, 7 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getEdge(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 4, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 7, 7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 4, 4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getEdge(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	LuckyCycle ___test;
	___test.run_test(-1);
}

// END CUT HERE
