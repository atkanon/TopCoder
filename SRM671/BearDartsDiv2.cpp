// 2 "BearDartsDiv2.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is an old brown bear who likes to play darts.

Limak just picked up an empty scorecard.
He then threw a sequence of darts into a dartboard and for each dart he recorded the point value of the area it hit.
You are given a vector <int> w containing the contents of Limak's scorecard: a sequence of point values.

Today there is a special jackpot.
In order to win the jackpot, the player must present a scorecard with exactly four scores: (a, b, c, d).
Additionally, these scores must be such that a*b*c = d.
Note that order matters: the scores a, b, c, d must have been obtained in this particular order.

Limak wants to erase all but four scores from his scorecard in such a way that he will win the jackpot.
Compute and return the number of different ways in which he can do that.

DEFINITION
Class:BearDartsDiv2
Method:count
Parameters:vector <int>
Returns:long long
Method signature:long long count(vector <int> w)


NOTES
-Pay attention to the unusual time limit.


CONSTRAINTS
-w will contain between 4 and 500 elements, inclusive.
-Each element in w will be between 1 and 10^6, inclusive.


EXAMPLES

0)
{10,2,2,7,40,160}

Returns: 2

Limak must erase two of the six scores on his scorecard.
There are two ways to do that and win the jackpot:

Erase the elements on 0-based indices 3 and 5. You are left with (a,b,c,d) = (10,2,2,40), and 10*2*2 = 40.
Erase the elements on 0-based indices 0 and 3. You are left with (a,b,c,d) = (2,2,40,160), and 2*2*40 = 160.


1)
{128,64,32,16,8,4,2,1}

Returns: 0

Regardless of which four scores Limak erases, the remaining four will always have a > b > c > d and therefore it cannot be the case that a*b*c = d.

2)
{2,3,4,5,6,8,12,16,20,24,40,24,20,16,12,8,6,5,4,3,2}

Returns: 3



3)
{100,100,100,1000000,1000000,1000000,1000000,1000000}

Returns: 5



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 2573031125



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

class BearDartsDiv2 {
	public:
	long long count(vector <int> w) {
        long sz = w.size();
        map<LL, LL> count[501];
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (w[j] % w[i] == 0) {
                    int v = w[j] / w[i];
                    if (count[i].find(v) != count[i].end()) {
                        count[i][v]++;
                    } else {
                        count[i][v] = 1;
                    }
                }
            }
        }
        
        map<LL, LL>::iterator ite;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                for (ite = count[i].begin(); ite != count[i].end(); ite++) {
                    LL v = ite->first;
                    if (count[j].find(v) != count[j].end()) {
                        count[j][v] += ite->second;
                    } else {
                        count[j][v] = ite->second;
                    }
                }
            }
        }
        
/*        for (int i = 0; i < sz; i++) {
            for (ite = count[i].begin(); ite != count[i].end(); ite++) {
                cerr << i << " " << ite->first << " " << ite->second << endl;
            }
        }*/
        
        LL res = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                LL v = w[i] * w[j];
                if (count[j+1].find(v) != count[j+1].end()) {
                    res += count[j+1][v];
                }
            }
        }
        
        return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,2,2,7,40,160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {128,64,32,16,8,4,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {2,3,4,5,6,8,12,16,20,24,40,24,20,16,12,8,6,5,4,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {100,100,100,1000000,1000000,1000000,1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2573031125LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	BearDartsDiv2 ___test;
	___test.run_test(-1);
}

// END CUT HERE
