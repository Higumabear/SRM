#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

class OneDimensionalRobotEasy {
public:
  int finalPosition(string commands, int A, int B) {
    int result;
    int pos  =0;
    int N = commands.size();
    for(int i = 0; i < N; i++){
      if(commands[i] == 'L'){
	if(pos != -A) pos--;
      }else{
	if(pos != B) pos++;
      }
    }
    return pos;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRLRRLLR"; int Arg1 = 10; int Arg2 = 10; int Arg3 = 2; verify_case(0, Arg3, finalPosition(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "RRRRR"; int Arg1 = 3; int Arg2 = 4; int Arg3 = 4; verify_case(1, Arg3, finalPosition(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "LLLLLLLLLLR"; int Arg1 = 2; int Arg2 = 6; int Arg3 = -1; verify_case(2, Arg3, finalPosition(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "RRRRRRRLRRLRRRRRRRRRRRRLRLRRRRRRRRLRRRRRLRRRRRRRRR"; int Arg1 = 5; int Arg2 = 20; int Arg3 = 20; verify_case(3, Arg3, finalPosition(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "RLRLLLLLLLRLLLRLLLLLLLLRLLLLLRLLLRRLLLLLRLLLLLRLLL"; int Arg1 = 34; int Arg2 = 15; int Arg3 = -30; verify_case(4, Arg3, finalPosition(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  OneDimensionalRobotEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
