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

double dp[1 << 20];

using namespace std;
class GrasslandFencer {
public:
  int N;
  vector<int> f;
  double rec(int S){
    if((S + 1) >> N & 1) return 0.0;
    if(dp[S] >= 0.0) return dp[S];
    
    double tmp = 0.0;
    for(int i = 0; i < N; i++)
      for(int j = i + 1; j < N; j++)
	for(int k = j + 1; k < N; k++)
	  if(!(S >> i & 1) && !(S >> j & 1) && !(S >> k & 1))
	    tmp = max(tmp, 
		      area(f[i], f[j], f[k]) + rec(S | 1 << i | 1 << j | 1 << k));
    return dp[S] = max(dp[S], tmp);
  }
  double area(double a, double b, double c){
    if(a + b + c <= 2. * max(a, max(b, c))) return 0.0;
    double s = 0.5 * (a + b + c);
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }
  double maximalFencedArea(vector <int> fences){
    N = fences.size();
    fill(dp, dp + (1 << 20), -1.0);
    f = fences;
    return rec(0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 36.754383146489694; verify_case(0, Arg1, maximalFencedArea(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, maximalFencedArea(Arg0)); }
	void test_case_2() { int Arr0[] = {7,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 6.928203230275509; verify_case(2, Arg1, maximalFencedArea(Arg0)); }
	void test_case_3() { int Arr0[] = {21,72,15,55,16,44,54,63,69,35,75,69,76,70,50,81}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7512.322360676162; verify_case(3, Arg1, maximalFencedArea(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
GrasslandFencer ___test;
___test.run_test(-1);
}
// END CUT HERE 
