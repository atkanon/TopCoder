// 2 "SingingEasy.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Alice and Bob are going to sing a song together.
For simplicity, we will assign the numbers 1 through 1,000,000 to the pitches that occur in the song (from the lowest to the highest).
Both Alice and Bob are able to sing all of these pitches.
You are given a vector <int> pitch containing the pitches of all notes in the song, in order.
Each note of the song will be sung by exactly one of our singers.



Changing the pitch of one's voice is exhausting.
Given a sequence of pitches to sing, the difficulty for the singer can be computed by summing up the differences between consecutive pitches.
For example, the difficulty of the sequence 8, 8, 13, 12 is abs(8-8) + abs(13-8) + abs(12-13) = 0+5+1 = 6.



The total difficulty of singing the song can be computed as the difficulty for Alice plus the difficulty for Bob.
Return the smallest possible total difficulty of singing the given song.


DEFINITION
Class:SingingEasy
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> pitch)


CONSTRAINTS
-The number of elements in pitches will be between 1 and 2,000, inclusive.
-all elements in pitch will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1,3,8,12,13}

Returns: 7

One optimal solution is to let Alice sing the first two notes and Bob the remaining three.
Then, Alice will sing the sequence of pitches {1,3} and Bob will sing {8,12,13}.
The difficulty for Alice is abs(3-1) = 2.
The difficulty for Bob is abs(12-8) + abs(13-12) = 5.
Thus, the total difficulty is 2+5 = 7.

1)
{1,5,6,2,1}

Returns: 3

One optimal solution is to let our singers sing in the order Alice-Bob-Bob-Alice-Alice.
In this case Alice sings the sequence of pitches {1,2,1} and Bob sings {5,6}.
Hence the difficulty for Alice is 2 and the difficulty for Bob is 1.

2)
{5,5,5,5,4,4,4,4}

Returns: 0



3)
{1000000}

Returns: 0



4)
{24,13,2,4,54,23,12,53,12,23,42,13,53,12,24,12,11,24,42,52,12,32,42}

Returns: 188



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

class SingingEasy {
	public:
	int solve(vector <int> pitch) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,8,12,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,5,6,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {5,5,5,5,4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {24,13,2,4,54,23,12,53,12,23,42,13,53,12,24,12,11,24,42,52,12,32,42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 188; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	SingingEasy ___test;
	___test.run_test(-1);
}

// END CUT HERE
