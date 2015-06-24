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



class SumThemAll {
public:
  ll dp[10][11];
  ll f(int x){
    vector<int> d;
    while(x){
      d.push_back(x % 10);
      x /= 10;
    }
    reverse(ALL(d));
    ll b = 1;
    for(int i = 1; i < d.size(); i++) b *= 10LL;

    ll ret = 0;
    int y = 0;
    for(int j = 0; j < d.size(); j++){
      for(int i = 0; i < d[j]; i++) ret += dp[i][d.size() - j] + y * b;
      y += d[j];
      b /= 10;
    }
    return ret;
  }
  long long getSum(int lowerBound, int upperBound){
    memset(dp, 0, sizeof(dp));
    ll k = 1;
    for(int j = 1; j < 11; j++){
      for(int i = 0; i < 10; i++) dp[0][j] += dp[i][j - 1];
      for(int i = 0; i < 10; i++) dp[i][j] = dp[0][j] + k * i;
      k *= 10;
    }
    return f(upperBound + 1) - f(lowerBound);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 3; long long Arg2 = 6LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 14; long long Arg2 = 15LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 53; long long Arg2 = 296LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 24660; int Arg1 = 308357171; long long Arg2 = 11379854844LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SumThemAll ___test;
___test.run_test(-1);
}
// END CUT HERE 
