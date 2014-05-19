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
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
static const ll MOD = 1234567891LL;
#define ALL(c) (c).begin(), (c).end()

ll dp[5][5][5][5][8][48];

class TheBrickTowerHardDivTwo {
public:
  int find(int C, int K, int H) {
    ll result = 0;
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < C; i++)
    for(int j = 0; j < C; j++)
    for(int k = 0; k < C; k++)
    for(int l = 0; l < C; l++){
      int couple = (i == j) + (j == k) + (k == l) + (l == i);
      if(couple <= K)
	dp[i][j][k][l][couple][1] = 1;
    }

    for(int h = 2; h <= H; h++)
    for(int k = 0; k <= K; k++)
    for(int a0 = 0; a0 < C; a0++)
    for(int a1 = 0; a1 < C; a1++)
    for(int a2 = 0; a2 < C; a2++)      
    for(int a3 = 0; a3 < C; a3++)
    for(int b0 = 0; b0 < C; b0++)
    for(int b1 = 0; b1 < C; b1++)
    for(int b2 = 0; b2 < C; b2++)      
    for(int b3 = 0; b3 < C; b3++){
      int couple = (a0 == b0) + (a1 == b1) + (a2 == b2) + (a3 == b3) + 
	(a0 == a1) + (a1 == a2) + (a2 == a3) + (a3 == a0);
      if(couple + k <= K){
	dp[a0][a1][a2][a3][couple + k][h] += dp[b0][b1][b2][b3][k][h - 1];
	dp[a0][a1][a2][a3][couple + k][h] %= MOD;
      }
    }

    for(int h = 1; h <= H; h++)
    for(int k = 0; k <= K; k++)
    for(int a0 = 0; a0 < C; a0++)
    for(int a1 = 0; a1 < C; a1++)
    for(int a2 = 0; a2 < C; a2++)      
    for(int a3 = 0; a3 < C; a3++)
      result = (result + dp[a0][a1][a2][a3][k][h]) % MOD;
    return result;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; int Arg2 = 19; int Arg3 = 1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 14; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 47; int Arg3 = 1008981254; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  TheBrickTowerHardDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
