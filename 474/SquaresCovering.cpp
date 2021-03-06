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
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
static const ll INF= 1LL << 50;

ll dp[1 << 16];

class SquaresCovering {
public:
  int minCost(vector <int> x, vector <int> y, vector <int> cost, vector <int> sides) {
    int result;
    fill(dp, dp + (1 << 16), INF);
    dp[0] = 0;
    int N = cost.size();
    int M = x.size();
    for(int S = 0; S < 1 << M; S++){
      ll minx = INF, maxx = -1, miny = INF, maxy = -1;
      for(int j = 0; j < M; j++){
	if(S >> j & 1){
	  minx = min(minx, (ll)x[j]);
	  maxx = max(maxx, (ll)x[j]);
	  miny = min(miny, (ll)y[j]);
	  maxy = max(maxy, (ll)y[j]);
	}
      }
      for(int i = 0; i < N; i++)
	if(sides[i] >= maxx - minx && sides[i] >= maxy - miny)
	  dp[S] = min(dp[S], (ll)cost[i]);
    }

    for(int i = 0; i < 1 << M; i++){
      for(int j = i; j > 0; --j &= i){
	dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
      }
    }
    return dp[(1 << M) - 1];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,100,201,300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,100,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,100,99}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 22; verify_case(2, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {41,6334,19169,11478,26962,5705,23281,41}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18467,26500,15724,29358,24464,28145,16827,18467}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {292,11943,5437,14605,154,12383,18717,19896,21727,11539,19913,26300,9895,23812,30334,4665,7712,6869,27645,32758}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9962,2996,4828,32392,33,293,17422,19719,5448,14772,1870,25668,17036,28704,31323,17674,15142,28254,25548,32663}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 738; verify_case(3, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {41,6334,9169,1478,6962,5705,3281}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8467,6500,5724,9358,4464,8145,6827}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {92,43,37,15,54,83,17,96,27,39,13,100,95,12,34,65,12,69,45,58}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {962,996,828,392,903,293,422,719,448,772,870,668,36,704,323,674,142,254,548,663}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 84; verify_case(4, Arg4, minCost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  SquaresCovering ___test;
  ___test.run_test(-1);
}
// END CUT HERE
