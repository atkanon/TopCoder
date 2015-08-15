// 2 "LuckyXor.cpp"
// BEGIN CUT HERE
/*
 // PROBLEM STATEMENT
 //
 A lucky number is a positive integer consisting of only the digits 4 and 7.
 
 
 
 Given an int a, return an int b strictly greater than a, such that a XOR b is a lucky number. (See Notes for the definition of XOR.) The number b should be in the range 1 to 100, inclusive. If such a number does not exist, return -1. If there are multiple such b, you may return any of them.
 
 
 DEFINITION
 Class:LuckyXor
 Method:construct
 Parameters:int
 Returns:int
 Method signature:int construct(int a)
 
 
 NOTES
 -XOR is the bitwise exclusive-or operation. To compute the value of P XOR Q, we first write P and Q in binary. Then, each bit of the result is computed by applying XOR to the corresponding bits of the two numbers, using the rules 0 XOR 0 = 0, 0 XOR 1 = 1, 1 XOR 0 = 1, and 1 XOR 1 = 0.
 -For example, let's compute 21 XOR 6. In binary these two numbers are 10101 and 00110, hence their XOR is 10011 in binary, which is 19 in decimal.
 -You can read more about the XOR operation here: https://en.wikipedia.org/wiki/Exclusive_or
 
 
 CONSTRAINTS
 -a is between 1 and 100, inclusive.
 
 
 EXAMPLES
 
 0)
 4
 
 Returns: 40
 
 4 XOR 40 = 44, 44 is a lucky number.
 
 1)
 19
 
 Returns: 20
 
 19 XOR 20 = 7
 
 2)
 88
 
 Returns: 92
 
 88 XOR 92 = 4
 
 3)
 36
 
 Returns: -1
 
 
 
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

class LuckyXor {
public:
    bool isLucky(int n) {
        stringstream ss;
        ss << n;
        string s = ss.str();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '4' && s[i] != '7') return false;
        }
        return true;
    }
    int construct(int a) {
        for (int i = a + 1; i <= 100; i++) {
            if (isLucky(a^i)) return i;
        }
        return -1;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 4; int Arg1 = 40; verify_case(0, Arg1, construct(Arg0)); }
    void test_case_1() { int Arg0 = 19; int Arg1 = 20; verify_case(1, Arg1, construct(Arg0)); }
    void test_case_2() { int Arg0 = 88; int Arg1 = 92; verify_case(2, Arg1, construct(Arg0)); }
    void test_case_3() { int Arg0 = 36; int Arg1 = -1; verify_case(3, Arg1, construct(Arg0)); }
    
    // END CUT HERE
    
};

// BEGIN CUT HERE

int main() {
    LuckyXor ___test;
    ___test.run_test(-1);
}

// END CUT HERE
