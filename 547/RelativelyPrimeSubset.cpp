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

#define N 15

int prime[N] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int a[55];
int dp[55][1 << N];
int n;

class RelativelyPrimeSubset {
public:
  int findSize(vector <int> S) {
    n = S.size();
    int ans = 0;
    sort(ALL(S));
    for(int i = 0; i < n; i++){
      int tmp = 0;
      vector<int> v;
      v.push_back(S[i]);
      for(int j = 0; j < n; j++){
	if(i == j) continue;
	bool b = true;
	for(int k = 0; k < (int)v.size(); k++){
	  if(__gcd(S[j], v[k]) != 1){
	    b = false;
	    break;
	  }
	}
	if(b) v.push_back(S[j]);
      }
      tmp = v.size();
      ans = max(ans, tmp);
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,7,11,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {4,8,12,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {100,17,81,82}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, findSize(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  RelativelyPrimeSubset ___test;
  ___test.run_test(-1);
}
// END CUT HERE
