// 2 "Cdgame.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Two players are playing a cooperative game.
At the beginning of the game each player has some cards.
There is a positive integer written on each card.
The game is played as follows:

Each player chooses one of their cards.
At the same time, each player gives the chosen card to the other player.
Each player computes the sum of the numbers on the cards they now have.
The final outcome of the game is the product of the two sums the players computed in the previous step.


You are given the vector <int>s a and b.
The elements of a are the numbers on the first player's cards at the beginning of the game.
The elements of b are the numbers on the second player's cards.
Compute and return the number of different outcomes the game may have.


DEFINITION
Class:Cdgame
Method:rescount
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int rescount(vector <int> a, vector <int> b)


CONSTRAINTS
-A and B will contain between 1 and 50 elements, inclusive.
-A and B will contain the same number of elements.
-Each element in A and B will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,2}
{3,4}

Returns: 2

This game can be played in four possible ways.
One of them looks as follows:

The first player chooses the card with the number 1. At the same time, the second player chooses the card with the number 3.
Each player gives the chosen card to the other player. After the exchange the first player has the cards with numbers 2 and 3, and the second player has the cards with numbers 1 and 4.
The first player computes that his sum is 2+3 = 5. The second player computes that her sum is 1+4 = 5.
The final outcome is the value 5*5 = 25.

The other three ways correspond to the following outcomes: (2+4)*(1+3) = 6*4 = 24, (1+3)*(2+4) = 4*6 = 24, and (1+4)*(2+3) = 5*5 = 25.
Hence, only two different outcomes are possible: 24 and 25.
Thus, the correct return value is 2.


1)
{1,2,4}
{8,16,32}

Returns: 9

With three cards in each player's hand there are 9 ways to play the game.
In this case each of those ways leads to a different outcome.


2)
{1,1,1}
{1,1,1}

Returns: 1

Again, there are 9 ways to play the game, but obviously in this case the outcome will always be the same.


3)
{1,2,3}
{5,5,5}

Returns: 3



4)
{3,3,4,1}
{2,2,2,100}

Returns: 4



5)
{31,34,55,56,57}
{1,2,3,4,5}

Returns: 15



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

class Cdgame {
	public:
	int rescount(vector <int> a, vector <int> b) {
        long sz = a.size();
        
        long aSum = 0, bSum = 0;
        for (int i = 0; i < sz; i++) {
            aSum += a[i];
            bSum += b[i];
        }
        
        set<long> s;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                long aSum2 = aSum - a[i] + b[j];
                long bSum2 = bSum - b[j] + a[i];
                s.insert(aSum2 * bSum2);
            }
        }
        
        return s.size();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, rescount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,16,32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(1, Arg2, rescount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, rescount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, rescount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,3,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(4, Arg2, rescount(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {31,34,55,56,57}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(5, Arg2, rescount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	Cdgame ___test;
	___test.run_test(-1);
}

// END CUT HERE
