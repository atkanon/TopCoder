// 2 "ApplesAndOrangesEasy.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Garth likes apples and oranges. Recently he bought N fruits, where each fruit was either an apple or an orange. Then he ate all N fruits in some order. You are given an int K. Garth observed that at every point in time, if he made a list of the last K fruits he ate, there were at most K/2 (rounded down) apples in this list.


For each valid i, you know that the info[i]-th fruit Garth ate was an apple. (Fruits Garth ate are numbered starting from 1. For example, info[i]=1 means that the very first fruit Garth ate was an apple.)


Please find and return the maximum number of apples Garth could have eaten.

DEFINITION
Class:ApplesAndOrangesEasy
Method:maximumApples
Parameters:int, int, vector <int>
Returns:int
Method signature:int maximumApples(int N, int K, vector <int> info)


NOTES
-If Garth makes his list at a point in time when he ate fewer than K fruits, his list will have fewer than K fruits but the requirement will still be the same: there have to be at most K/2 apples in the list.


CONSTRAINTS
-N will be between 2 and 2,000, inclusive.
-K will be between 2 and N, inclusive.
-info will contain between 0 and N elements, inclusive.
-Each element of info will be between 1 and N, inclusive.
-The elements of info will be distinct.
-The elements of info will be consistent with Garth's observation.


EXAMPLES

0)
3
2
{}

Returns: 2

Garth ate N=3 fruites. The requirement is that any K=2 consecutive fruits may contain at most K/2 = 1 apple. As info is empty, you have no additional information about the fruits Garth ate.


Garth might have eaten an apple, then an orange, then an apple. This satisfies the conditions:

After eating the 1st fruit, the list is [apple].
After eating the 2nd fruit, the list is [apple, orange].
After eating the 3rd fruit, the list is [orange, apple].

Each list contains at most 1 apple.

1)
10
3
{3, 8}

Returns: 2

All fruits, except for the 3rd and the 8th, must have been oranges.

2)
9
4
{1, 4}

Returns: 5



3)
9
4
{2, 4}

Returns: 4



4)
23
7
{3, 2, 9, 1, 15, 23, 20, 19}

Returns: 10



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

class ApplesAndOrangesEasy {
	public:
	int maximumApples(int N, int K, vector <int> info) {
        vector<int> apple(N * 2, 0);
        for (int i = 0; i < info.size(); i++) apple[info[i] - 1]++;
        
        for (int i = 0; i < N; i++) {
            if (apple[i]) continue;
            
            bool canApple = true;
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (j == i || apple[j]) cnt++;
                int lost = j - K;
                if (lost >= 0 && (apple[lost] || lost == i)) cnt--;
                
                if (cnt > K / 2) canApple = false;
            }
            
            if (canApple) apple[i] = true;
        }
        
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (apple[i]) cnt++;
            
//            if (apple[i]) cerr << i << ": o" << endl;
//            else cerr << i << ": " << endl;
        }
        return cnt;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {3, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {1, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(2, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {2, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 23; int Arg1 = 7; int Arr2[] = {3, 2, 9, 1, 15, 23, 20, 19}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(4, Arg3, maximumApples(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	ApplesAndOrangesEasy ___test;
	___test.run_test(-1);
}

// END CUT HERE
