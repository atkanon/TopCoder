// 2 "GCDLCMEasy.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Your task is to find n positive integers.
We will label them x[0] through x[n-1].



We will give you some information about these integers.
Namely, for some pairs of integers we will tell you both their greatest common divisor (GCD) and their least common multiple (LCM).



You are given the int n and four vector <int>s: A, B, G, and L.
These vector <int>s will all have the same number of elements.
Their meaning is as follows:
For each valid i, the integers x[ A[i] ] and x[ B[i] ] must have the greatest common divisor G[i] and the least common multiple L[i].



Return "Solution exists" (quotes for clarity) if there is at least one way to choose x[0] through x[n-1] so that all requirements are satisfied.
Otherwise, return "Solution does not exist".

DEFINITION
Class:GCDLCMEasy
Method:possible
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L)


NOTES
-The greatest common divisor (GCD) of two positive integers x and y is the largest positive integer z such that z divides x and at the same time z divides y.
-The least common multiple (LCM) of two positive integers x and y is the smallest positive integer z such that x divides z and at the same time y divides z.
-For example, the GCD of 10 and 15 is 5, and the LCM of 10 and 15 is 30.


CONSTRAINTS
-n will be between 1 and 500, inclusive.
-A will contain between 1 and 500 elements, inclusive.
-A and B will contain the same number of elements.
-A and G will contain the same number of elements.
-A and L will contain the same number of elements.
-Each element in A will be between 0 and n-1, inclusive.
-Each element in B will be between 0 and n-1, inclusive.
-For each i, A[i] and B[i] will be different.
-Each element in G will be between 1 and 10,000, inclusive.
-Each element in L will be between 1 and 10,000, inclusive.


EXAMPLES

0)
4
{0,1,2,3}
{1,2,3,0}
{6,6,6,6}
{12,12,12,12}

Returns: "Solution exists"

We have 4 unknown integers: x[0], x[1], x[2], and x[3].
The given A, B, G, and L encode the following information:

The GCD of x[0] and x[1] must be 6 and their LCM must be 12.
The GCD of x[1] and x[2] must be 6 and their LCM must be 12.
The GCD of x[2] and x[3] must be 6 and their LCM must be 12.
The GCD of x[3] and x[0] must be 6 and their LCM must be 12.

There are two valid solutions.
In one of them, x[0] = x[2] = 6 and x[1] = x[3] = 12.

1)
5
{0,1,2,3,4}
{1,2,3,4,0}
{6,6,6,6,6}
{12,12,12,12,12}

Returns: "No solution"



2)
2
{0,0}
{1,1}
{123,123}
{456,789}

Returns: "Solution does not exist"

The LCM of x[0] and x[1] cannot be 456 and 789 at the same time.

3)
2
{0}
{1}
{1234}
{5678}

Returns: "Solution does not exist"

The LCM of x[0] and x[1] must always be a multiple of their GCD.

4)
6
{0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}
{1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}
{2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7}
{30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}


Returns: "Have solution"

There is one solution: {6, 10, 14, 15, 21, 35}.

5)
500
{0}
{1}
{10000}
{10000}

Returns: "Have solution"



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

class GCDLCMEasy {
	public:

	vector<int> calc(int n) {
		vector<int> vi;
		for (int i = 2; i < 101; i++) {
			int v = 1;
			while (a%i == 0 && b%i == 0) {
				a /= i;
				b /= i;
				v *= i;
			}
			if (cnt) {
				vi.push_back(v);
			}
		}

		int sz = vi.size();
		vector<int> res;
		for (int i = 0; i < 1<<sz; i++) {
			int val = 1;
			for (int j = 0; j < sz; j++) {
				if (i&(1<<j)) {
					val *= vi[j];
				}
			}
			res.push_back(val);
		}

		return vi;
	}


/*
	string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector <int> L) {
		int sz = A.size();
		string NO = "Solution does not exist";
		string YES = "Have solution";

		for (int i = 0; i < sz; i++) {
			if (L % G != 0) return NO;
			vector<int> vi = calc(L / G);
		}	
	}
*/

		int arr[10005][500];
	string possible(int n, vector <int> A, vector <int> B, vector <int> G, vector<int> L) {
		memset(arr, 0, sizeof(arr));
		vector<int> primes;
		int aux[10005] = {0};
		for (int i = 2; i < 10005; i++) {
			if (aux[i] == 0) {
				primes.push_back(i);
				aux[i] = 1;
				for (int j = i*i; j < 10005; j += i) {
					aux[j] = 1;
				}
			}
		}

		int N = A.size();
		vector<pair<int, int> > cop;
		for (int i = 0; i < N; i++) {
			if (L[i] % G[i] != 0) return "Solution does not exist";
			int g = G[i];
			if (g == 1) {
				cop.push_back(make_pair(A[i], B[i]));
				continue;
			}
			int k = 0;
			int c;
			while (g > 1 && k < primes.size()) {
				if (g % primes[k] == 0) {
					c = 0;
					while (g % primes[k] == 0) {
						c++;
						g = g / primes[k];
					}
					arr[primes[k]][A[i]] = max(c, arr[primes[k]][A[i]]);
					arr[primes[k]][B[i]] = max(c, arr[primes[k]][B[i]]);
				}
				k++;
			}
		}
		for (int i = 0; i < N; i++) {
			int l = L[i];
			int k = 0;
			int c;
			while (l > 1 && k < primes.size()) {
				if (l % primes[k] == 0) {
					c = 0;
					while( l % primes[k] == 0) {
						c++;
						l = l / primes[k];
					}
					if (arr[primes[k]][A[i]] > c) {
						return "Solution does not exist";
					}
					if (arr[primes[k]][B[i]] > c) {
						return "Solution does not exist";
					}
				}
				k++;
			}
		}
		for (int i = 0; i < cop.size(); i++) {
			for (int j = 0; j < primes.size(); j++) {
				if (arr[cop[i].first][primes[j]] > 0 && arr[copi].second][primes[j]] > 0) {
					return "Solution does not exist";
				}
			}
		}
		for (int i = 0; i < n; i++) {
			bool ok = 0;
			for (int j = 0; j < primes.size(); j++) {
				if (arr[primes[j]][i] > 0) {
					ok = 1;
					break;
				}
			}
			if (!ok) return "Solution odes not exist";
		}
		return "Solution exists";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {12,12,12,12}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution exists"; verify_case(0, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,6,6,6,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {12,12,12,12,12}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "No solution"; verify_case(1, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {123,123}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {456,789}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution does not exist"; verify_case(2, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1234}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5678}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Solution does not exist"; verify_case(3, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2, 3, 3, 1, 2, 5, 1, 5, 1, 7, 7, 3, 5, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {30, 42, 30, 42, 210, 70, 30, 210, 70, 210, 42, 70, 105, 105, 105}
; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Have solution"; verify_case(4, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 500; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {10000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {10000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arg5 = "Have solution"; verify_case(5, Arg5, possible(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	GCDLCMEasy ___test;
	___test.run_test(-1);
}

// END CUT HERE
