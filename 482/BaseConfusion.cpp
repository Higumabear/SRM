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

class BaseConfusion {
public:
  ll func2(ll N, int B){
    if(N == 0) return 0;
    return func2(N / B, B) * (B + 1) + N % B;
  }
  ll func(ll N, int B){
    if(N == 0) return 0;
    ll ans = func(N / B, B) * B * (B + 1) + N / B * (B * (B - 1) / 2);
    for(ll x = N / B * B; x < N; x++) ans += func2(x, B);
    return ans;
  }
  long long sum(int M, int N, int B) {
    return func(N + 1, B) - func(M, B);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; int Arg1 = 18; int Arg2 = 3; long long Arg3 = 129LL; verify_case(0, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 16; long long Arg3 = 55LL; verify_case(1, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 10; long long Arg3 = 121LL; verify_case(2, Arg3, sum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 209881; int Arg1 = 210565; int Arg2 = 3; long long Arg3 = 3141592653LL; verify_case(3, Arg3, sum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  BaseConfusion ___test;
  ___test.run_test(-1);
}
// END CUT HERE
