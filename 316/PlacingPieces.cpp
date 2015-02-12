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

bool dp[1001][50][50];

using namespace std;
class PlacingPieces {
public:
  int len;
  int N;
  vector<int> p;
  int calc(int idx, int cnt, int sum){
    dp[sum][idx][cnt] = true;
    for(int i = idx; i < N; i++){
      for(int j = cnt; j < N; j++){
	for(int l = 0; l <= len; l++){
	  if(!dp[l][i][j]) continue;
	  if(l + p[i] <= len)
	    dp[l + p[i]][i + 1][j + 1] = true;
	  dp[l][i + 1][j] = true;
	}
      }
    }
    return 0;
  }
  int optimalPlacement(int L, vector <int> pieces){
    sort(ALL(pieces));
    N = pieces.size();
    p = pieces;
    len = L;

    int ans = N;
    for(int i = 0; i <= N; i++){
      int sum = 0;
      for(int j = 0; j < i; j++) sum += pieces[j];
      if(sum > L) continue;

      memset(dp, false, sizeof(dp));
      calc(i, i, sum);
      for(int l = 0; l <= 1000; l++)
	for(int k = 0; k <= N; k++)
	  if(dp[l][N][k] && L - l >= 0 && 
	     1.0 * (L - l) / (k + 1) < pieces[i]) ans = min(ans, k);

    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arr1[] = {1, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 36; int Arr1[] = {1, 1, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37; int Arr1[] = {1, 1, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 18; int Arr1[] = {2, 2, 2, 9, 9, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arr1[] = {2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, optimalPlacement(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 703; int Arr1[] = {73, 76, 90, 42, 84, 13, 57, 88, 80, 45, 80, 1, 78, 41, 73, 40, 97, 42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(5, Arg2, optimalPlacement(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
PlacingPieces ___test;
___test.run_test(-1);
}
// END CUT HERE 
