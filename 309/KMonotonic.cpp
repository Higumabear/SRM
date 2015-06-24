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
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

ll dp1[60][60], dp2[60][60];

class KMonotonic {
public:
  int N;
  vector<int> s;
  void func(vector<int> a){
    for(int i = 0; i < N; i++){
      s = a;
      for(int j = i + 1; j < N; j++) 
	if(s[j - 1] >= a[j]) s[j] = s[j - 1] + 1;
      for(int j = i - 1; j >= 0; j--) 
	if(s[j + 1] <= a[j]) s[j] = s[j + 1] - 1;

      for(int p = 0; p < N; p++){
	ll sum = 0;
	for(int q = p; q < N; q++){
	  sum += abs(s[q] - a[q]);
	  dp1[p][q] = min(dp1[p][q], sum);
	}
      }
      // for(int j = i + 1; j < N; j++) 
      // 	dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + abs(s[j] - a[j]));
      // for(int j = i - 1; j >= 0; j--) 
      // 	dp1[j][i] = min(dp1[j][i], dp1[j + 1][i] + abs(s[j] - a[j]));
      // cout << i << " ";
      // for(int j = 0; j < N; j++) cout << s[j] << " ";
      // cout << endl;
    }
  }
  int transform(vector <int> sequence, int K){
    N = sequence.size();
    for(int i = 0; i < 60; i++){
      for(int j = 0; j < 60; j++){
	dp1[i][j] = i == j ? 0 : LLINF;
	dp2[i][j] = LLINF;
      }
      //dp2[i][1] = 0;
    }

    func(sequence);
    reverse(ALL(sequence));
    func(sequence);

    for(int i = 0; i < N; i++) dp2[i][1] = dp1[0][i];
    for(int i = 0; i < N; i++) 
      for(int j = 0; j + 1 <= i; j++)
	for(int k = 2; k <= K; k++)
	  dp2[i][k] = min(dp2[i][k], dp2[j][k - 1] + dp1[j + 1][i]);
    
    return dp2[N - 1][K];
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
