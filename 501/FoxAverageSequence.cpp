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

int MOD = 1000000007;
int dp[42][1610][42][2];

class FoxAverageSequence {
public:
  int theCount(vector <int> seq) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    int N = seq.size();
    for(int i = 1; i <= N; i++){
      for(int j = 0; j <= 1600; j++){
	for(int k = 0; k <= 40; k++){
	  if(j - k < k * (i - 1)) continue;
	  if(seq[i - 1] != -1 && seq[i - 1] != k) continue;
	  for(int prek = 0; prek <= 40; prek++){
	    if(prek > k){
	      dp[i][j][k][0] += dp[i - 1][j - k][prek][1];
	      dp[i][j][k][0] %= MOD;
	    }else{
	      dp[i][j][k][1] += (dp[i - 1][j - k][prek][0] 
				 + dp[i - 1][j - k][prek][1]) % MOD;
	      dp[i][j][k][1] %= MOD;
	    }
	  }
	}
      }
    }
    int ans = 0;
    for(int j = 0; j <= 1600; j++){
      for(int k = 0; k <= 40; k++){
	ans += (dp[N][j][k][0] + dp[N][j][k][1]) % MOD;
	ans %= MOD;
      }
    }
    return ans % MOD;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 3, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, 0, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 579347890; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {-1, 12, 25, 0, 18, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  FoxAverageSequence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
