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

bool f[5000002];

using namespace std;
class SumsOfPerfectPowers {
public:
  ll lpow(ll a, int b){
    if(a == 0) return 0;
    ll ret = 1;
    for(int i = 1; i <= b; i++) ret *= a;
    return ret;
  }
  int howMany(int lowerBound, int upperBound){
    fill(f, f + 5000002, false);
    
    for(int i = 2; i <= 22; i++){
      for(int j = 2; j <= 22; j++){
	for(ll a = 0; a <= 2300; a++){
	  ll s = lpow(a, i);
	  if(s > upperBound) break;
	  for(ll b = 0; b <= 2300; b++){
	    ll t = lpow(b, j);
	    cout << s + t  << endl;
	    if(0 <= s + t && s + t <= upperBound) f[s + t] = true;
	    else break;
	  }
	}
      }
    }
    int ans = 0;
    for(int i = lowerBound; i <= upperBound; i++) if(f[i]) ans++;
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 1; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 25; int Arg1 = 30; int Arg2 = 5; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 103; int Arg1 = 103; int Arg2 = 0; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 100000; int Arg2 = 33604; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SumsOfPerfectPowers ___test;
___test.run_test(-1);
}
// END CUT HERE 
