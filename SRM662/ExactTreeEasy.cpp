// 2 "ExactTreeEasy.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You are given ints n and m.
Construct any tree with exactly n nodes (labeled 0 through n-1) and exactly m leaves.
For the given constraints on n and m a solution will always exist.


The return value should be a vector <int> containing a sequence of 2*(n-1) integers.
If your tree has edges (a[0], b[0]), (a[1], b[1]), etc.,
the correct return value is the sequence {a[0], b[0], a[1], b[1], ...}.
If there are multiple correct return values, you may return any of them.

DEFINITION
Class:ExactTreeEasy
Method:getTree
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> getTree(int n, int m)


NOTES
-A tree is a connected acyclic graph. The leaf of a tree is a node of degree 1, i.e., a node that has exactly one outgoing edge.


CONSTRAINTS
-n will be between 3 and 50, inclusive.
-m will be between 2 and n-1, inclusive.


EXAMPLES

0)
4
2

Returns: {0, 1, 1, 2, 2, 3 }

We are supposed to construct a tree with 4 nodes and 2 leaves. One such tree is a simple path consisting of the edges 0-1, 1-2, and 2-3.

1)
4
3

Returns: {0, 1, 1, 2, 1, 3 }

Now we have to construct a tree with 4 nodes and 3 leaves. The tree returned by our solution contains the edges 1-0, 1-2, and 1-3. The leaves are the nodes 0, 2, and 3.

2)
3
2

Returns: {0, 1, 1, 2 }



3)
5
3

Returns: {0, 1, 1, 2, 1, 3, 3, 4 }



4)
10
9

Returns: {0, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9 }



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

class ExactTreeEasy {
	public:
	vector <int> getTree(int n, int m) {
        vector<int> edges;
        
        int begin = 0;
        for (int i = 1; i < n; i++) {
            if (n - m + 2 <= i) {
                edges.push_back(1);
                edges.push_back(i);
            } else {
                edges.push_back(begin);
                edges.push_back(i);
                begin = i;
            }
        }
        
        return edges;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getTree(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arr2[] = {0, 1, 1, 2, 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getTree(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {0, 1, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getTree(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {0, 1, 1, 2, 1, 3, 3, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getTree(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 9; int Arr2[] = {0, 1, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getTree(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ExactTreeEasy ___test;
	___test.run_test(-1);
}

// END CUT HERE
