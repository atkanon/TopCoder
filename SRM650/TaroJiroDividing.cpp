// 2 "TaroJiroDividing.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The dividing game is played as follows:
You start by taking a clean sheet of paper and writing down some positive integer.
Then you repeat the following process:
Let X be the last integer you wrote.
If X is odd, the game ends.
Otherwise, divide X by 2 and write down the result.




For example, if you start the game by writing 12 you will then write 12/2 = 6, followed by 6/2 = 3, and as 3 is odd, the game ends there.
Your paper now contains the numbers 12, 6, and 3.




Cat Taro has just played the game starting with the integer A.
Jiro has also played the game but he started with the integer B.
You are given the ints A and B.
Return the number of integers that were written both by Taro and by Jiro.


DEFINITION
Class:TaroJiroDividing
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int A, int B)


CONSTRAINTS
-A and B will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
8
4

Returns: 3

Taro will write the integers {8,4,2,1}. Jiro will write {4,2,1}. The three integers written by both of them are 4, 2, and 1.

1)
4
7

Returns: 0



2)
12
12

Returns: 3



3)
24
96

Returns: 4



4)
1000000000
999999999

Returns: 0



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <map>

using namespace std;

typedef long long LL;

class TaroJiroDividing {
	public:
	int getNumber(int A, int B) {
		map<int, int> written;
		written[A]++;
		while (A % 2 == 0) {
			A /= 2;
			written[A]++;
		}
		written[B]++;
		while (B % 2 == 0) {
			B /= 2;
			written[B]++;
		}
		map<int, int>::iterator ite;
		int count = 0;
		for (ite = written.begin(); ite != written.end(); ite++) {
			if (ite->second == 2) count++;
		}
		return count;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 3; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 0; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 12; int Arg1 = 12; int Arg2 = 3; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 24; int Arg1 = 96; int Arg2 = 4; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 999999999; int Arg2 = 0; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	TaroJiroDividing ___test;
	___test.run_test(-1);
}

// END CUT HERE
