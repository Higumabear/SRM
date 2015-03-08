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

ll dp[60][60], take[60][60];

using namespace std;
class KMonotonic {
public:
  ll calc(vector<ll> a){
    int N = a.size();
    vector<vector<ll>> b(N, vector<ll>(N, 0));
    vector<vector<ll>> c(N, vector<ll>(N, 0));
    vector<vector<ll>> dp(N, vector<ll>(N, 0));

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++) b[i][j] = a[j] - j + i;
      sort(ALL(b[i]));
      for(int j = 0; j < N; j++) c[i][j] = abs(b[i][j] - a[i]);
    }
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	dp[i][j] = (i == 0) ? c[i][j] : LLINF;
    for(int i = 1; i < N; i++){
      ll tmp = LLINF;
      int j = 0;
      for(int k = 0; k < N; k++){
	while(j < N && b[i - 1][j] < b[i][k]){
	  tmp = min(tmp, dp[i - 1][j]);
	  j++;
	}
	dp[i][k] = tmp + c[i][k];
      }
    }
    ll ans = LLINF;
    for(int i = 0; i < N; i++) ans = min(ans, dp[N - 1][i]);
    return ans;
  }
  int transform(vector <int> sequence, int K){
    int N = sequence.size();
    for(int i = 0; i < N; i++){
      for(int j = i; j < N; j++){
	take[i][j] = LLINF;
	vector<ll> tmp1(sequence.begin() + i, sequence.begin() + j + 1);
	vector<ll> tmp2(sequence.begin() + i, sequence.begin() + j + 1);
	reverse(ALL(tmp2));
	take[i][j] = min(take[i][j], calc(tmp1));
	take[i][j] = min(take[i][j], calc(tmp2));
	
	//cout << i << " " << j << " " << take[i][j] << endl;
      }
    }
    
    cout << take[0][N - 1] << endl;
    for(int i = 0; i < 60; i++) for(int j = 0; j < 60; j++) dp[i][j] = LLINF;
    for(int i = 0; i < N; i++) dp[i][1] = take[0][i];
    for(int i = 0; i < N; i++){
      for(int j = 0; j + 1 <= i; j++){
	for(int k = 2; k <= K; k++)
	  dp[i][k] = min(dp[i][k], dp[j][k - 1] + take[j + 1][i]);
      }
    }
    return dp[N - 1][K];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 9; verify_case(3, Arg2, transform(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,3,2,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(4, Arg2, transform(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,10,4,2,5,1,3,2,4,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 11; verify_case(5, Arg2, transform(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {-913,-4158,-146,-2625,-2926,3071,297,4049,-4566,3581,-2070,-1794,1953,4434,4351,-710,-3124,2148,1192,1802,644}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 611; verify_case(6, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
KMonotonic ___test;
___test.run_test(-1);
}
// END CUT HERE 
