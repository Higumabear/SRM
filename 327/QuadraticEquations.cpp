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

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;
class QuadraticEquations {
public:
  ll labs(ll a){return a > 0 ? a : -a;}
  ll divup(ll a, ll b){
    if(a > 0) return (a - 1) / b + 1;
    else return a / b;
  }
  ll divlo(ll a, ll b){
    if(a < 0) return (a + 1) / b - 1;
    else return a / b;
  }
  long long howMany(ll x, ll y, ll d, ll z, ll k){
    ll Y = y * y * d;
    ll sqrtD = (ll)sqrt(d + 1e-9);
    ll sqrtY = (ll)sqrt(Y + 1e-9);

    if(sqrtY * sqrtY != Y){
      ll a = z * z, b = -2LL * z * x, c = x * x - Y;
      ll cm = __gcd(__gcd(a, b), c);
      a /= cm, b /= cm, c /= cm;
      ll num = k / labs(a);
      if(b) num = min(num, k / labs(b));
      if(c) num = min(num, k / labs(c));
      return 2 * num + 1;
    }else{
      cout << "muzu" << endl;
      if(z < 0) x = -x, y = -y, z = -z;

      ll ans = 0;
      ll ue = labs(x + y * sqrtD);
      ll g = __gcd(ue, (ll)z);
      dump(ue); dump(g);
      ue /= g; z /= g;
      ll alim = k / z;
      for(ll ad = -alim; ad <= alim; ad++){
	ll tmp, up1, up2, lo1, lo2;
	lo1 = divup(-k + ad * ue, (ll)z);
	up1 = divlo(k + ad * ue, (ll)z);
	if(ue != 0){
	  lo2 = divup(-k, abs(ue));
	  up2 = divlo(k, abs(ue));
	}else{
	  lo2 = -k;
	  up2 = k;
	}
	tmp = min(up1, up2) - max(lo1, lo2) + 1;
	if(tmp >= 0) ans += tmp;
      }
      return ans;
    }
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 3; int Arg3 = 4; int Arg4 = 30; long long Arg5 = 3LL; verify_case(0, Arg5, howMany(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 3; int Arg3 = 4; int Arg4 = 10; long long Arg5 = 1LL; verify_case(1, Arg5, howMany(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; long long Arg5 = 7LL; verify_case(2, Arg5, howMany(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = -1; int Arg2 = 4; int Arg3 = -1; int Arg4 = 2; long long Arg5 = 7LL; verify_case(3, Arg5, howMany(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = -1; int Arg1 = 3; int Arg2 = 3; int Arg3 = 2; int Arg4 = 1000000; long long Arg5 = 153847LL; verify_case(4, Arg5, howMany(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 0; int Arg2 = 1; int Arg3 = 3; int Arg4 = 5; long long Arg5 = 11LL; verify_case(5, Arg5, howMany(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
QuadraticEquations ___test;
___test.run_test(-1);
}
// END CUT HERE 
