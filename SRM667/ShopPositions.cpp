// 2 "ShopPositions.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Carol is starting a new taco shop business.
She is going to open some taco shops in a block of buildings.
The blocks consists of n adjacent buildings in a row.
Each building has exactly m floors.
The buildings are numbered 0 through n-1 in order.



Carol can open between 0 and m taco shops in each building (as there can be at most one taco shop per floor in each building).
For each taco shop, the profit P[x][y] will depend on two factors:

the number x of the building that contains this taco shop
the total count y of taco shops in that particular building and in buildings adjacent to that building (including this particular taco store)




You are given the ints n and m.
You are also given the profits as defined above, encoded into a vector <int> c.
For each x between 0 and n-1, and for each y between 1 and 3m, the profit P[x][y] is given in c[x*3*m+y-1].



It is guaranteed that the profits don't increase as y increases. That is, for each valid x and y, P[x][y] will be greater than or equal to P[x][y+1].
Note that the profit is for a single store.
For example, if there are three taco stores in building 7 and no other stores in buildings 6 and 8, each of these three taco stores will bring the profit P[7][3].



Determine and return the maximum total profit that Carol can gain from opening the taco shops.


DEFINITION
Class:ShopPositions
Method:maxProfit
Parameters:int, int, vector <int>
Returns:int
Method signature:int maxProfit(int n, int m, vector <int> c)


CONSTRAINTS
-n will be between 1 and 30, inclusive.
-m will be between 1 and 30, inclusive.
-c will have exactly n*3*m elements.
-Each element of c will be between 1 and 1,000, inclusive.
-For each x between 0 and n-1, the sequence c[3*m*x], c[3*m*x + 1], ..., c[3*m*(x+1) - 1] will be sorted in nonincreasing order


EXAMPLES

0)
1
5
{100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1}

Returns: 300


Carol has 1 building with 5 floors.



Building one shop will get her a profit of 100, while building two shops will get a profit of 90*2.
The optimal strategy in this case is to build 5 taco shops, for a profit of 60*5=300.




1)
1
5
{1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

Returns: 1000



2)
3
1
{
  7,6,1,
  10,4,1,
  7,6,3
}

Returns: 14

The optimal strategy here is to open one taco store in building 0 and one taco store in building 2.

3)
2
2
{
 12,11,10,9,8,7,
 6,5,4,3,2,1
}

Returns: 24



4)
3
3
{
  30,28,25,15,14,10,5,4,2,
  50,40,30,28,17,13,8,6,3,
  45,26,14,14,13,13,2,1,1
}

Returns: 127



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

class ShopPositions {
	public:
	int maxProfit(int n, int m, vector <int> c) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 300; verify_case(0, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; verify_case(1, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arr2[] = {
  7,6,1,
  10,4,1,
  7,6,3
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 14; verify_case(2, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 12,11,10,9,8,7,
 6,5,4,3,2,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 24; verify_case(3, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {
  30,28,25,15,14,10,5,4,2,
  50,40,30,28,17,13,8,6,3,
  45,26,14,14,13,13,2,1,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 127; verify_case(4, Arg3, maxProfit(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ShopPositions ___test;
	___test.run_test(-1);
}

// END CUT HERE
