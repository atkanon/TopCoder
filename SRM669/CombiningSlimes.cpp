// 2 "CombiningSlimes.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The idols Ami and Mami like playing games.
Today they bought a new game.
At the beginning of the game a group of slimes appears on the screen.
In each turn of the game the player can select any two of the slimes and merge them together.
The game ends when there is only one slime left.

Each slime has a positive integer size.
Whenever the player merges two slimes, the size of the merged slime is x+y, where x and y are the sizes of the two merged slimes.
Additionally, the player is awarded x*y mascots for performing this merge.

Ami and Mami have just started a new game.
You are given a vector <int> a containing the initial sizes of all slimes.
Ami and Mami really like mascots.
Find and return the maximum total number of mascots they can obtain during the game.


DEFINITION
Class:CombiningSlimes
Method:maxMascots
Parameters:vector <int>
Returns:int
Method signature:int maxMascots(vector <int> a)


CONSTRAINTS
-a will contain between 2 and 100 elements, inclusive.
-Each element of a will be between 1 and 100, inclusive.


EXAMPLES

0)
{3,4}

Returns: 12

There are two slimes, their sizes are 3 and 4.
There is only one possible move: we merge them into a single slime of size 7.
Doing so gives us 3*4 = 12 mascots.

1)
{2,2,2}

Returns: 12

In the first turn we will merge any two slimes.
The size of the new slime will be 2+2 = 4, and we will gain 2*2 = 4 mascots.
In the second turn we will merge the two remaining slimes.
The size of the final slime will be 4+2 = 6.
The second merge will give us 4*2 = 8 mascots.
Hence, the total number of mascots we will obtain is 4 + 8 = 12.

2)
{1,2,3}

Returns: 11

One optimal solution looks as follows:
First, merge slimes of sizes 1 and 3.
This produces a slime of size 4, and we get 3 mascots.
Then, merge slimes of sizes 4 and 2.
This produces a slime of size 6, and we get 8 mascots.

3)
{3,1,2}

Returns: 11

The set of slimes is the same as in Example 2, therefore the correct answer is also the same.
As we can merge any two slimes, their order in a does not matter.

4)
{7,6,5,3,4,6}

Returns: 395



*/
// END CUT HERE

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

class CombiningSlimes {
	public:
	int maxMascots(vector <int> a) {
        sort(a.begin(), a.end());
        int score = 0;
        while (a.size() > 1) {
            score += a[0] * a[1];
            int newSlime = a[0] + a[1];
            a.erase(a.begin());
            a[0] = newSlime;
        }
        return score;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, maxMascots(Arg0)); }
	void test_case_1() { int Arr0[] = {2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, maxMascots(Arg0)); }
	void test_case_2() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(2, Arg1, maxMascots(Arg0)); }
	void test_case_3() { int Arr0[] = {3,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, maxMascots(Arg0)); }
	void test_case_4() { int Arr0[] = {7,6,5,3,4,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 395; verify_case(4, Arg1, maxMascots(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	CombiningSlimes ___test;
	___test.run_test(-1);
}

// END CUT HERE
