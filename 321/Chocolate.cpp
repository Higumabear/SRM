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
class Chocolate {
public:
  int minSplitNumber(int w, int h, int nTiles){
    ll small = min(w, h);
    ll big = max(w, h);
    ll nt = nTiles;
    int ans = INF;
    for(ll i = 1; i * i <= nt; i++){
      if(nt % i != 0) continue;
      if(small == i && big == nt / i) return 0;
      // if(i < small && nt < big * i) ans = min(ans, 2);
      // if(small == i && nt < big * i) ans = min(ans, 1);
      // if(small < i && big * i == nt) ans = min(ans, 1);
      // if(small * i == nt && i < big) ans = min(ans, 1);
      cout << i << "\t" << nt / i << endl;
      if(i <= small && nt / i <= big){
	if(small == i || big == i || small == nt / i || big == nt / i) ans = min(ans, 1);
	ans = min(ans, 2);
      }
    }
    return ans == INF ? -1 : ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 12; int Arg3 = 1; verify_case(0, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 12; int Arg1 = 10; int Arg2 = 120; int Arg3 = 0; verify_case(1, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; verify_case(2, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 17; int Arg1 = 19; int Arg2 = 111; int Arg3 = -1; verify_case(3, Arg3, minSplitNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Chocolate ___test;
___test.run_test(-1);
}
// END CUT HERE 
