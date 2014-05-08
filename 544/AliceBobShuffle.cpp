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

const ll MOD = 1000000007;

ll dp[51][51][51][51];

class AliceBobShuffle {
public:
  vector<int> as, bs, ae, be;
  ll rec(int a, int b, int c, int d){
    if(a == (int)as.size() && b == (int)bs.size() && 
       c == (int)ae.size() && d == (int) be.size())
      return 1;

    if(dp[a][b][c][d] >= 0) return dp[a][b][c][d];

    ll ret = 0;
    if(a < as.size() && c < ae.size() && as[a] == ae[c])
      ret = (ret + rec(a + 1, b, c + 1, d)) % MOD;
    if(a < as.size() && d < be.size() && as[a] == be[d])
      ret = (ret + rec(a + 1, b, c, d + 1)) % MOD;
    if(b < bs.size() && c < ae.size() && bs[b] == ae[c])
      ret = (ret + rec(a, b + 1, c + 1, d)) % MOD;
    if(b < bs.size() && d < be.size() && bs[b] == be[d])
      ret = (ret + rec(a, b + 1, c, d + 1)) % MOD;

    return dp[a][b][c][d] = ret;
  }
  int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd) {
    memset(dp, -1, sizeof(dp));
    as = AliceStart, ae = AliceEnd, bs = BobStart, be = BobEnd;
    return rec(0, 0, 0, 0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(3, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {3, 3, 2, 4, 1, 3, 1, 2, 1, 1, 5, 5, 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 1, 4, 3, 4, 4, 4, 3, 2, 1, 6, 2, 2, 3, 2, 2, 1, 3, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 1, 4, 3, 4, 4, 4, 1, 3, 1, 2, 2, 2, 3, 2, 1, 2, 1, 2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 3, 2, 3, 4, 2, 1, 2, 1, 1, 5, 6, 5, 1, 3, 1, 2, 3, 1, 1, 1, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 314159265; verify_case(4, Arg4, countWays(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  AliceBobShuffle ___test;
  ___test.run_test(-1);
}
// END CUT HERE
