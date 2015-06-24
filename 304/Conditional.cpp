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
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-10
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

double dp[51][51 * 51][2];

class Conditional {
public:
  double probability(int nDice, int maxSide, int v, int theSum){
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1.0;
    for(int i = 0; i < nDice; i++){
      for(int k = 0; k <= nDice * maxSide; k++){
	for(int j = 1; j <= maxSide; j++){
	  if(j == v)
	    dp[i + 1][k + v][1] += (dp[i][k][1] + dp[i][k][0]) * 1.0 / maxSide;
	  else{
	    dp[i + 1][k + j][1] += dp[i][k][1] * 1.0 / maxSide;
	    dp[i + 1][k + j][0] += dp[i][k][0] * 1.0 / maxSide;
	  }
	}
      }
    }
    double ans = 0.0, sum = 0.0;
    for(int k = 0; k <= nDice * maxSide; k++){
      sum += dp[nDice][k][1];
      if(k >= theSum)
	ans += dp[nDice][k][1];
    }
    return ans / sum;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 12; double Arg4 = 0.09090909090909091; verify_case(0, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 6; int Arg3 = 6; double Arg4 = 1.0; verify_case(1, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 9; int Arg2 = 3; int Arg3 = 3; double Arg4 = 1.0; verify_case(2, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 2; int Arg3 = 4; double Arg4 = 0.6; verify_case(3, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Conditional ___test;
___test.run_test(-1);
}
// END CUT HERE 
