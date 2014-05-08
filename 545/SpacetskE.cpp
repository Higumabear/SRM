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

const int MAX_COMB = 210;
const ll MOD = 1000000007;
bool used[210][210];

class SpacetskE {
public:
  int result;
  int comb[MAX_COMB + 1][MAX_COMB + 1];
  void combination(){
    comb[0][0] = 1;
    for(int i = 1; i < MAX_COMB + 1; i++){
      comb[i][0] = 1;
      for(int j = 1; j < MAX_COMB + 1; j++){
	comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
      }
    }
  }

  int countsets(int L, int H, int K) {
    memset(comb, 0, sizeof(comb));
    combination();

    if(K == 1) return (L + 1) * (H + 1);

    ll ans = 0;
    for(int i = 0; i <= L; i++){
      memset(used, false, sizeof(used));
      for(int y = 1; y <= H; y++){
	for(int x = 0; x <= L; x++){
	  if(used[y][x]) continue;
	  int dx = x - i;
	  int dy = y;
	  int cnt = 0;
	  for(int px = i, py = 0; 
	      0 <= px && px <= L && 0 <= py && py <= H;
	      px += dx, py += dy){
	    used[py][px] = true;
	    cnt++;
	  }
	  ans = (ans + comb[cnt][K]) % MOD;
	}
      }
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; verify_case(1, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 9; verify_case(2, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 23; verify_case(3, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 202; verify_case(4, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 70; int Arg1 = 52; int Arg2 = 18; int Arg3 = 296314116; verify_case(5, Arg3, countsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  SpacetskE ___test;
  ___test.run_test(-1);
}
// END CUT HERE
