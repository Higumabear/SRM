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
static const ll INF= 1LL << 55;

class BottlesOnShelf {
public:
  ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
  ll lcm(ll a, ll b){return a * b / gcd(a, b);}
  int getNumBroken(int N, vector <int> left, vector <int> right, vector <int> damage) {
    ll result = 0;
    int M = left.size();
    
    for(int S = 1; S < 1 << M; S++){
      ll LCM = 1;
      ll l = 0, r = INF;
      for(int i = 0; i < M; i++) if(S >> i & 1) {
	LCM = lcm(LCM, damage[i]);
	l = max(l, (ll)left[i]);
	r = min(r, (ll)right[i]);
      }
      
      ll a = (l <= r) ? r / LCM - (l - 1) / LCM : 0;
      result += (__builtin_popcount(S) % 2 == 1) ? a : -a;
    }
    return (int)result;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, getNumBroken(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 7; int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, getNumBroken(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,3,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, getNumBroken(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {1,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 6; verify_case(3, Arg4, getNumBroken(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(4, Arg4, getNumBroken(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000000000; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000000000; verify_case(5, Arg4, getNumBroken(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  BottlesOnShelf ___test;
  ___test.run_test(-1);
}
// END CUT HERE
