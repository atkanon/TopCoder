// 2 "OddEvenTree.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In a tree, the distance between two nodes is the number of edges on the (only) simple path that connects them.


You are given a vector <string> x with N elements, each containing N characters.
Draw a tree with N nodes, numbered 0 through N-1.
The tree must have the following properties:
For each i and j, if x[i][j] is 'E' the distance between i and j must be even, and if it is 'O' (uppercase o) this distance must be odd.


If there is no tree with these properties, return {-1}.
Otherwise, return a vector <int> with 2N-2 elements: the list of edges in one such tree.
For example, if N=3 and your tree contains the edges 0-2 and 1-2, return {0,2,1,2}.
If there are multiple correct outputs you may output any of them.

DEFINITION
Class:OddEvenTree
Method:getTree
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getTree(vector <string> x)


NOTES
-If you use plugins to test your solution, be careful. Plugins cannot tell you whether your solution is correct -- they'll just tell you whether it matches the example output exactly.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-x will contain exactly n elements.
-Each element in x will have exactly n characters.
-Each character in x will be 'O' or 'E'.


EXAMPLES

0)
{"EOE",
 "OEO",
 "EOE"}

Returns: {0, 1, 2, 1 }

The tree: 0-1-2 is a valid answer.

1)
{"EO",
 "OE"}

Returns: {0, 1 }



2)
{"OO",
 "OE"}

Returns: {-1 }

dist[0][0] must be 0, and it should be an even number, so it is impossible.

3)
{"EO",
 "EE"}

Returns: {-1 }

dist[0][1] should be same with dist[1][0].

4)
{"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"}

Returns: {0, 1, 0, 3, 2, 1 }



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

class OddEvenTree {
	public:
	vector <int> getTree(vector <string> x) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"EOE",
 "OEO",
 "EOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTree(Arg0)); }
	void test_case_1() { string Arr0[] = {"EO",
 "OE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getTree(Arg0)); }
	void test_case_2() { string Arr0[] = {"OO",
 "OE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getTree(Arg0)); }
	void test_case_3() { string Arr0[] = {"EO",
 "EE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getTree(Arg0)); }
	void test_case_4() { string Arr0[] = {"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getTree(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	OddEvenTree ___test;
	___test.run_test(-1);
}

// END CUT HERE
