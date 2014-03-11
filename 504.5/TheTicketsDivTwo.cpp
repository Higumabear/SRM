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
#include <cstring>
using namespace std;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

class TheTicketsDivTwo {
public:
  double find(int n, int m, int k) {
    double dp[20][20][20];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; i++) dp[1][1][i] = 1.0;
    for(int i = 1; i <= n; i++) dp[i][1][0] = 1.0;
    
    for(int l = 1; l <= k; l++){
      for(int i = 2; i <= n; i++){
	dp[i][1][l] = 1 / 6.0 + dp[i][i][l - 1] / 2.0;
	for(int j = 2; j <= i; j++){
	  dp[i][j][l] = dp[i][j - 1][l - 1] / 2.0 
	    + dp[i - 1][j - 1][l - 1] / 3.0;
	}
      }
    }
    return dp[n][m][k];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.16666666666666666; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.5833333333333334; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 4; double Arg3 = 0.0; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 10; double Arg3 = 0.25264033564814814; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  TheTicketsDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
