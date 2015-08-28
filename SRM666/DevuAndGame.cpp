// 2 "DevuAndGame.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Devu loves to play games.
This problem is about a game he recently played.
In the game there are n locations, numbered 0 through n-1.
Each location has one entrance and one exit.
You are given a vector <int> nextLevel with n elements.
For each i, nextLevel[i] describes the exit from location i.
If nextLevel[i] is a number between 0 and n-1, inclusive, it means that the exit from location i leads to the entrance of location nextLevel[i].
Otherwise, nextLevel[i] will be -1 and it means that if the player reaches this exit, they win the game.





Devu started the game by entering location 0.
Return "Win" (quotes for clarity) if he can win the game.
Otherwise, return "Lose".
Note that the return value is case-sensitive.


DEFINITION
Class:DevuAndGame
Method:canWin
Parameters:vector <int>
Returns:string
Method signature:string canWin(vector <int> nextLevel)


CONSTRAINTS
-nextLevel will have between 1 and 50 elements, inclusive.
-Each element in nextLevel will be either -1 or will be between 0 and n - 1, inclusive.


EXAMPLES

0)
{1, -1}

Returns: "Win"

Devu will start in location 0. The exit from this location will bring him to location 1, and when he reaches the exit from location 1 he wins the game.

1)
{1, 0, -1}

Returns: "Lose"

Devu will go back and forth between locations 0 and 1. He is unable to reach the exit from location 2.

2)
{0, 1, 2}

Returns: "Lose"

The exit from location 0 leads back to location 0. Devu is unable to reach the other locations.

3)
{29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27}

Returns: "Win"

There can be multiple x such that nextLevel[x] is -1.
In order to win the game, Devu has to reach any single location with this property.

4)
{17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29}

Returns: "Win"



5)
{3, 1, 1, 2, -1, 4}

Returns: "Lose"

In this game, Devu will go from location 0 to location 3, from there to location 2, and from there to location 1. There he will get stuck, as the exit from location 1 leads back to location 1.

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

class DevuAndGame {
	public:
	string canWin(vector <int> nextLevel) {
        int begin = 0;
        int cnt = 0;
        while (true) {
            int next = nextLevel[begin];
            if (next == -1) return "Win";
            
            begin = next;
            cnt++;
            if (cnt > 100) return "Lose";
        }
        return "Unko";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Win"; verify_case(0, Arg1, canWin(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 0, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Lose"; verify_case(1, Arg1, canWin(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Lose"; verify_case(2, Arg1, canWin(Arg0)); }
	void test_case_3() { int Arr0[] = {29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Win"; verify_case(3, Arg1, canWin(Arg0)); }
	void test_case_4() { int Arr0[] = {17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Win"; verify_case(4, Arg1, canWin(Arg0)); }
	void test_case_5() { int Arr0[] = {3, 1, 1, 2, -1, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Lose"; verify_case(5, Arg1, canWin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	DevuAndGame ___test;
	___test.run_test(-1);
}

// END CUT HERE
