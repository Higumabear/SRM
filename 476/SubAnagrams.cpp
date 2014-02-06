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

int dp[510][510];

class SubAnagrams {
public:
  int maximumParts(vector <string> suppliedWord) {
    string s;
    for(int i = 0; i < (int)suppliedWord.size(); i++) s += suppliedWord[i];
    
    memset(dp, 0, sizeof(dp));
    fill(dp[0], dp[0] + 510, 1);
    int L = s.length();
    for(int i = 0; i < L; i++){
      for(int j = i; j < L; j++){
	int t;
	int a[30] = {0};
	int b[30] = {0};
	for(int k = i; k <= j; k++) a[s[k] - 'A']++;
	for(t = i - 1; t >= 0; t--)
	  if(a[s[t] - 'A'] < ++b[s[t] - 'A']) break;
	t++;

	for(int k = t; k < i; k++)
	  if(dp[k][i - 1] > 0)
	    dp[i][j] = max(dp[i][j], dp[k][i - 1] + 1);
      }
    }
	  
    int ans = 0;
    for(int i = 0; i < L; i++) ans = max(ans, dp[i][L - 1]);
    return ans;
  }
	
    // BEGIN CUT HERE
  public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
  private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"ABABAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximumParts(Arg0)); }
    void test_case_1() { string Arr0[] = {"AAXAAAABX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maximumParts(Arg0)); }
    void test_case_2() { string Arr0[] = {"ABCDEFGHIJKL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maximumParts(Arg0)); }
    void test_case_3() { string Arr0[] = {"ABBAB","B","BBX","Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, maximumParts(Arg0)); }
    
    // END CUT HERE
    
  };
  
  // BEGIN CUT HERE 
  int main() {
    SubAnagrams ___test;
    ___test.run_test(-1);
  }
  // END CUT HERE
  
