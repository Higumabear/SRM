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
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

double dp[1001][60][20];

class TestBettingStrategy {
public:
  double winProbability(int initSum, int goalSum, int rounds, int prob){
    memset(dp, 0.0, sizeof(dp));
    dp[initSum][0][0] = 1.0;
    for(int i = 0; i <= 1000; i++){
      for(int j = 0; j < rounds; j++){
	for(int k = 0; k <= min(10, j); k++){
	  if(dp[i][j][k] < -EPS) continue;
	  dp[min(i + (1 << k), 1000)][j + 1][k + 1] = dp[i][j][k] * (100 - prob) * 0.01;
	  dp[i][j + 1][0] = dp[i][j][k] * prob * 0.01;
	}
      }
    }
    double ans = 0.0;
    for(int i = 0; i < 60; i++)
      for(int j = 0; j < 20; j++) ans += dp[1000][i][j];
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 11; int Arg2 = 4; int Arg3 = 50; double Arg4 = 0.875; verify_case(0, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 20; int Arg3 = 50; double Arg4 = 0.3441343307495117; verify_case(1, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 10; int Arg3 = 90; double Arg4 = 0.34867844010000015; verify_case(2, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 24; int Arg1 = 38; int Arg2 = 24; int Arg3 = 60; double Arg4 = 0.5940784635646947; verify_case(3, Arg4, winProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TestBettingStrategy ___test;
___test.run_test(-1);
}
// END CUT HERE 
