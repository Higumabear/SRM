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



class QuadraticEquations {
public:
  ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
  }
  long long howMany(int x, int y, int d, int z, int k){
    ll ans = 0;
    int sd = sqrt(d) + EPS;
    if(sd * sd != d && y != 0){
      
    }else{
      ll p = (x + 1LL * y * sd);
      ll q = z;
      ll g = gcd(p, q);
      p /= g; q /= g;
      if(q < 0) p *= -1, q *= -1;
      
    }
    return ;
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
