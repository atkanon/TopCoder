// 2 "ColorfulLineGraphs.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Bob is going to create a graph with N nodes.
The graph will be constructed in two steps.
First, Bob will take N isolated vertices, label them 1 through N and color each of them using one of K colors.
Then, Bob will add some directed edges to the graph.
For each i between 2 and N, inclusive, Bob may choose a single value j < i such that the nodes i and j have different colors. If he does, he will add the edge from i to j to his graph.
Note that Bob may choose not to add any edge from node i, even if there are some valid choices of j.



Two graphs are considered the same if they have the same node colors and the same set of edges.



You are given the long longs N and K.
You are also given an int M.
Compute and return the number of different graphs Bob may construct, modulo M.


DEFINITION
Class:ColorfulLineGraphs
Method:countWays
Parameters:long long, long long, int
Returns:int
Method signature:int countWays(long long N, long long K, int M)


CONSTRAINTS
-N will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-K will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-M will be between 2 and 1,000,000 (10^6), inclusive. 


EXAMPLES

0)
3
2
100000

Returns: 24


The 24 different graphs are shown below. In each picture, the vertices have labels 1, 2, 3 from the left to the right.




1)
15
3
1000000

Returns: 510625



2)
100000
100000
999999

Returns: 185185



3)
1000000000000
6
1000000

Returns: 109376



4)
5000
1000000000000
314159

Returns: 202996



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

using namespace std;

typedef long long LL;

class ColorfulLineGraphs {
	public:
	int countWays(long long N, long long K, int M) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 2LL; int Arg2 = 100000; int Arg3 = 24; verify_case(0, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 15LL; long long Arg1 = 3LL; int Arg2 = 1000000; int Arg3 = 510625; verify_case(1, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 100000LL; long long Arg1 = 100000LL; int Arg2 = 999999; int Arg3 = 185185; verify_case(2, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 6LL; int Arg2 = 1000000; int Arg3 = 109376; verify_case(3, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 5000LL; long long Arg1 = 1000000000000LL; int Arg2 = 314159; int Arg3 = 202996; verify_case(4, Arg3, countWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ColorfulLineGraphs ___test;
	___test.run_test(-1);
}

// END CUT HERE
