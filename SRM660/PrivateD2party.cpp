// 2 "PrivateD2party.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Hero is inviting his friends to the party.
He has n friends, numbered 0 through n-1.
For each of his friends there is at most one other person the friend dislikes.
You are given this information as a vector <int> a with n elements.
For each i, a[i] is either the number of the person disliked by friend i, we have a[i]=i if friend i likes everybody else.

Hero is inviting his friends one at a time.
Whenever he invites friend i, they will accept if and only if the friend a[i] didn't accept an earlier invitation.
(That includes two cases: either Hero didn't invite friend a[i] yet, or he did but the friend rejected the invitation.)

Hero noticed that the order in which he invites his friends matters: different orders may produce different numbers of accepted invitations.

Find an order that will produce the most accepted invitations, and return their number.


DEFINITION
Class:PrivateD2party
Method:getsz
Parameters:vector <int>
Returns:int
Method signature:int getsz(vector <int> a)


CONSTRAINTS
-a will contain exactly n elements.
-n will be between 1 and 50, inclusive.
-Each element of a will be between 0 and n - 1, inclusive.


EXAMPLES

0)
{0,1}

Returns: 2

Each of the friends likes the other. Regardless of the order in which Hero asks them, they will both accept the invitation.

1)
{1,0}

Returns: 1

Friend 0 dislikes friend 1 and vice versa. The first friend Hero asks will accept the invitation but then the other friend will certainly reject it.

2)
{1,0,3,2}

Returns: 2



3)
{5,2,2,4,5,0}

Returns: 5

Here is what would happen if Hero invited the friends in the order (0,1,2,3,4,5):

Friend 5 didn't accept yet, so friend 0 would accept.
Friend 2 didn't accept yet, so friend 1 would accept.
Friend 2 likes everybody and therefore they would accept.
Friend 4 didn't accept yet, so friend 3 would accept.
Friend 5 didn't accept yet, so friend 4 would accept.
Friend 0 did already accept, therefore friend 5 would reject.

It turns out that this solution happens to be optimal: there is no order such that all six friends would accept the invitations.

4)
{3,2,1,0,5,4}

Returns: 3



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

class PrivateD2party {
	public:
	int getsz(vector <int> a) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getsz(Arg0)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getsz(Arg0)); }
	void test_case_2() { int Arr0[] = {1,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getsz(Arg0)); }
	void test_case_3() { int Arr0[] = {5,2,2,4,5,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, getsz(Arg0)); }
	void test_case_4() { int Arr0[] = {3,2,1,0,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, getsz(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	PrivateD2party ___test;
	___test.run_test(-1);
}

// END CUT HERE
