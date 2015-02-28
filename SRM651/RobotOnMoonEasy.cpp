// 2 "RobotOnMoonEasy.cpp"
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a robot on the moon.
You are given a vector <string> board containing the map of a rectangular area.
The robot is currently located somewhere in that area.
In the map, the character '.' (period) represents an empty square, 'S' represents an empty square that currently contains the robot, and '#' represents an obstacle.


You are also given a string S.
This string represents a sequence of commands we are going to send to the robot.
Each character in S is one of 'U', 'D', 'L', and 'R', representing a step up, down, left, and right, respectively.


Whenever the robot receives a command, one of three things will happen:

If the requested move leads to an empty square, the robot performs the move.
If the requested move leads to a square with an obstacle, the robot ignores the command and remains in place.
If the requested move leads out of the mapped area, the robot leaves the mapped area and dies immediately.



Given the map and the sequence of commands, compute whether the robot will survive.
Return "Alive" (quotes for clarity) if the robot is still somewhere on the map after the last command.
Otherwise, return "Dead".
Note that the return value is case-sensitive.

DEFINITION
Class:RobotOnMoonEasy
Method:isSafeCommand
Parameters:vector <string>, string
Returns:string
Method signature:string isSafeCommand(vector <string> board, string S)


NOTES
-The direction 'U' corresponds to moving from board[i][j] to board[i-1][j]. The direction 'L' corresponds to moving from board[i][j] to board[i][j-1].


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters.
-Each element of board will contain the same number of characters.
-The characters in board will be '.', '#' or 'S'.
-There will be exactly one 'S' in board.
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be one of 'U', 'D', 'L', 'R'.


EXAMPLES

0)
{".....",
 ".###.",
 "..S#.",
 "...#."}
"URURURURUR"

Returns: "Alive"

The robot will never move from its starting location: commands 'U' and 'R' are sending it into obstacles, so the robot ignores them.

1)
{".....",
 ".###.",
 "..S..",
 "...#."}
"URURURURUR"

Returns: "Dead"

This time there is no obstacle on the robot's right side. Its execution of commands will look as follows:

'U' leads into an obstacle. The robot ignores it.
'R' leads into an empty square. The robot makes a step to the right.
'U' leads into an obstacle. The robot ignores it.
'R' leads into an empty square. The robot makes a step to the right.
The next 'U' now leads into an empty square. The robot makes a step up. After this step, the robot is in row 1, column 4. (Both indices are 0-based.)
'R' leads out of the map. The robot steps out of the map and dies. The remaining four commands never get executed - the robot is already dead.


2)
{".....",
 ".###.",
 "..S..",
 "...#."}
"URURU"

Returns: "Alive"



3)
{"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}
"DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"

Returns: "Alive"

There are obstacles all around the map. Regardless of how the robot moves, it is safe - the obstacles will prevent it from leaving the map.

4)
{"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}
"DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"

Returns: "Dead"

After some steps the robot will leave the map from the only empty square in the bottom row of the map.

5)
{"S"}
"R"

Returns: "Dead"



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

class RobotOnMoonEasy {
	public:
	string isSafeCommand(vector <string> board, string S) {
		
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 ".###.",
 "..S#.",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Alive"; verify_case(0, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURURURUR"; string Arg2 = "Dead"; verify_case(1, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "URURU"; string Arg2 = "Alive"; verify_case(2, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Alive"; verify_case(3, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"; string Arg2 = "Dead"; verify_case(4, Arg2, isSafeCommand(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "R"; string Arg2 = "Dead"; verify_case(5, Arg2, isSafeCommand(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
	RobotOnMoonEasy ___test;
	___test.run_test(-1);
}

// END CUT HERE
