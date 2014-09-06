// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;
class Pathfinding {
public:
  int getDirections(int x, int y){
    if(x >= 0 && y >= 0){
      if(x % 2 == 0 || y % 2 == 0) return x + y;
      else return x + y + 2;
    }
    if(x > 0 && y <= 0){
      if(x % 2 == 1 || abs(y) % 2 == 0) return abs(x) + abs(y);
      else return abs(x) + abs(y) + 2;
    }
    if(x <= 0 && y > 0){
      if(abs(x) % 2 == 0 || y % 2 == 1) return abs(x) + abs(y);
      return abs(x) + abs(y) + 2;
    }
    if(x <= 0 && y <= 0){
      if(abs(x) % 2 == 1 || abs(y) % 2 == 1) return abs(x) + abs(y) + 2;
      else return abs(x) + abs(y) + 4;
    }
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = -4; int Arg2 = 8; verify_case(0, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = -4; int Arg2 = 9; verify_case(1, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 9; verify_case(2, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -1; int Arg1 = -4; int Arg2 = 7; verify_case(3, Arg2, getDirections(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; verify_case(4, Arg2, getDirections(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Pathfinding ___test;
___test.run_test(-1);
}
// END CUT HERE 
