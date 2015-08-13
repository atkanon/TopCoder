// 2 "BearPlays.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a little bear who loves to play.
Today he is playing by moving some stones between two piles of stones.
Initially, one of the piles has A and the other has B stones in it.

Limak has decided to perform a sequence of K operations.
In each operation he will double the size of the currently smaller pile.
Formally, if the current pile sizes are labeled X and Y in such a way that X <= Y, he will move X stones from the second pile to the first one.
After this move the new pile sizes will be X+X and Y-X.

You are given the ints A, B, and K.
Determine the pile sizes after Limak finishes all his operations.
Return the size of the smaller of those piles.

Formally, suppose that the final pile sizes are labeled P and Q in such a way that P <= Q.
Return P.

DEFINITION
Class:BearPlays
Method:pileSize
Parameters:int, int, int
Returns:int
Method signature:int pileSize(int A, int B, int K)


NOTES
-Pay attention to the unusual time limit.


CONSTRAINTS
-A and B will be between 1 and 1,000,000,000, inclusive. 
-K will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
4
7
2

Returns: 5

The process will look as follows:

Initially, the pile sizes are 4 and 7.
First operation: Limak doubles the pile of size 4 by moving 4 stones from the other pile to this pile. The new pile sizes are 8 and 3.
Second operation: Limak doubles the pile of size 3. The final pile sizes are 5 and 6.
As 5 <= 6, the correct return value is 5.


1)
5
5
3

Returns: 0

The initial pile sizes are 5 and 5.
In the first operation Limak will double one of them, so after the operation the new pile sizes will be 10 and 0.
The second and third operation do nothing: in each of them Limak doubles the size of an empty pile.

As 0 ≤ 10, the correct return value is 0.

2)
2
6
1

Returns: 4

After the only operation the pile sizes will be 4 and 4, hence the correct return value is 4.

3)
2
8
2000000000

Returns: 2



4)
900000000
350000000
3

Returns: 300000000



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

class BearPlays {
	public:
	int pileSize(int A, int B, int K) {
		LL S = A + B;
		LL c = 1;
		LL t = 2;
		while (K) {
			if (K%2) c = c * t % S;
			t = (t * t) % S;
			K /= 2;
		}

		LL a = (A * c) % S;
		if (a <= S/2) return a;
		else return S - a;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 1; int Arg3 = 4; verify_case(2, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 8; int Arg2 = 2000000000; int Arg3 = 2; verify_case(3, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 900000000; int Arg1 = 350000000; int Arg2 = 3; int Arg3 = 300000000; verify_case(4, Arg3, pileSize(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	BearPlays ___test;
	___test.run_test(-1);
}

// END CUT HERE
