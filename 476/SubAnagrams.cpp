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

int dp[510];

class SubAnagrams {
public:
  bool subana(string s, string t){
    set<char> moji;
    for(int j = 0; j < (int)t.length(); j++)
      moji.insert(t[j]);
    for(int i = 0; i < (int)s.length(); i++)
      if(moji.insert(s[i]).second) return false;
    return true;
  }
  int maximumParts(vector <string> suppliedWord) {
    memset(dp, 0, sizeof(dp));
    string s;
    for(int i = 0; i < (int)suppliedWord.size(); i++)
      s += suppliedWord[i];

    int L = s.length();
    for(int i = 0; i < L; i++){
      for(int j = 0; j < i; j++){
	dp[i] = max(dp[i], );
      }
    }
    return result;
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
