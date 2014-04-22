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

const int MAX = 18;
ll dp[180][20];

class FoxAndSorting {
public:
  ll rec(int s, int x){
    if(dp[s][x] == -1){
      ll res = 0;
      if(s == 0) res++;
      for(int d = 0; d <= 9 && s - d >= 0 ; d++)
	if((x != 0) && ((d != 0) || (x != MAX)))
	  res += rec(s - d, x - 1);
      dp[s][x] = res;
    }
    return dp[s][x];
  }
  long long get(long long idx) {
    memset(dp, -1, sizeof(dp));
    int s = 0;
    while(idx > rec(s, MAX)){
      idx -= rec(s, MAX);
      s++;
    }
    ll num = 0;
    for(int x = 18; x >= 1; x--){
      if(s == 0){
	if(idx == 1) break;
	else idx--;
      }
      for(int d = 0; d <= 9 && s - d >= 0; d++){
	if(d != 0 || x != MAX){
	  if(idx <= rec(s - d, x - 1)){
	    num = num * 10 + d;
	    s -= d;
	    break;
	  }else
	    idx -= rec(s - d, x - 1);
	}
      }
    }
    return num;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 100000000LL; verify_case(0, Arg1, get(Arg0)); }
	void test_case_1() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 999999999999999999LL; verify_case(1, Arg1, get(Arg0)); }
	void test_case_2() { long long Arg0 = 58LL; long long Arg1 = 100000000100LL; verify_case(2, Arg1, get(Arg0)); }
	void test_case_3() { long long Arg0 = 314159265358979LL; long long Arg1 = 646003042230121105LL; verify_case(3, Arg1, get(Arg0)); }
	void test_case_4() { long long Arg0 = 271828182845904523LL; long long Arg1 = 132558071125756493LL; verify_case(4, Arg1, get(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  FoxAndSorting ___test;
  ___test.run_test(-1);
}
// END CUT HERE
