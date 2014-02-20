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

class RectangleAvoidingColoringEasy {
public:
  vector <string> fi;
  int N, M;
  int ans;
  bool check(int y, int x){
    for(int i = 0; i < y; i++)
      for(int j = 0; j < x; j++)
	if(fi[i][j] == fi[y][x] && fi[i][x] == fi[y][x] && 
	   fi[y][j] == fi[y][x]) return false;
    return true;
  }
  void dfs(int y, int x){
    if(y == N){ ans++; return; }
    
    int x2 = x + 1, y2 = y;
    if(x2 == M){ x2 = 0; y2++; }

    if(fi[y][x] == '?'){
      fi[y][x] = 'B';
      if(check(y, x)) dfs(y2, x2);
      fi[y][x] = 'W';
      if(check(y, x)) dfs(y2, x2);
      fi[y][x] = '?';
    }else{
      if(check(y, x)) dfs(y2, x2);
    }
    return;
  }
  int count(vector <string> board) {
    ans = 0;
    fi = board;
    N = board.size(); M = board[0].length();
    dfs(0, 0);
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "?B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"WW",
 "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"??B??",
 "W???W",
 "??B??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  RectangleAvoidingColoringEasy ___test;
  ___test.run_test(-1);
}
// END CUT HERE
