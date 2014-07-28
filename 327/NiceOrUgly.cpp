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

int dp[110][3][5];

using namespace std;
class NiceOrUgly {
public:
  bool vo(char c){
    return c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O';
  }
  string describe(string s){
    memset(dp, 0, sizeof(dp));
    int N = s.length();

    int ugly = 0, nice = 0;

    dp[0][0][0] = true;
    for(int i = 0; i < N; i++){
      for(int a = 0; a < 3; a++){
	for(int b = 0; b < 5; b++){
	  if(dp[i][a][b]){
	    if(vo(s[i]) || s[i] == '?'){
	      if(a >= 2) ugly = 1;
	      else dp[i + 1][a + 1][0] = 1;
	    }
	    if(!vo(s[i]) || s[i] == '?'){
	      if(b >= 4) ugly = 1;
	      else dp[i + 1][0][b + 1] = 1;
	    }
	  }
	}
      }
    }

    for(int a = 0; a < 3; a++)
      for(int b = 0; b < 5; b++)
	nice |= dp[N][a][b];
    
    if(nice){
      if(ugly) return "42";
      else return "NICE";
    }
    else return "UGLY";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "HELLOWORLD"; string Arg1 = "NICE"; verify_case(0, Arg1, describe(Arg0)); }
	void test_case_1() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg1 = "UGLY"; verify_case(1, Arg1, describe(Arg0)); }
	void test_case_2() { string Arg0 = "HELLOW?RLD"; string Arg1 = "42"; verify_case(2, Arg1, describe(Arg0)); }
	void test_case_3() { string Arg0 = "H??LOWOR??"; string Arg1 = "NICE"; verify_case(3, Arg1, describe(Arg0)); }
	void test_case_4() { string Arg0 = "EE?FFFF"; string Arg1 = "UGLY"; verify_case(4, Arg1, describe(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
NiceOrUgly ___test;
___test.run_test(-1);
}
// END CUT HERE 
