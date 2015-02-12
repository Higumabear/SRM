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

int N;
int p[100];
ll dp[100];

using namespace std;
class PrefixFreeSubsets {
public:
  ll rec(int idx){
    if(idx == N) return 1;
    if(dp[idx] != -1) return dp[idx];
    return dp[idx] = rec(idx + 1) + rec(p[idx]);
  }
  long long cantPrefFreeSubsets(vector <string> words){
    sort(ALL(words));
    N = words.size();
    for(int i = 0; i < N; i++){
      int j;
      for(j = i + 1; j < N; j++)
	if(words[j].length() < words[i].length() || 
	   words[j].substr(0, words[i].length()) != words[i]) break;
      p[i] = j;
    }
    memset(dp, -1, sizeof(dp));
    return rec(0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"hello","hell","hi"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(0, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","b","c","d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(1, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_2() { string Arr0[] = {"a","ab","abc","abcd","abcde","abcdef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(2, Arg1, cantPrefFreeSubsets(Arg0)); }
	void test_case_3() { string Arr0[] = {"a","b","aa","ab","ba","bb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 25LL; verify_case(3, Arg1, cantPrefFreeSubsets(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PrefixFreeSubsets ___test;
___test.run_test(-1);
}
// END CUT HERE 
