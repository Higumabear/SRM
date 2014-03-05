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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
static const int INF = 1 << 29;
static const ll LINF = 1LL << 55;

class AlternatingLane {  
public:
  double sum(int j, int l, int h){
    if(h <= j) return (j - (l + h) / 2.0) * (h - l + 1);
    if(j <= l) return ((l + h) / 2.0 - j) * (h - l + 1);
    return (h - j) / 2.0 * (h - j + 1) + (j - l) / 2.0 * (j - l + 1);
  }
  double expectedBeauty(vector <int> low, vector <int> high) {
    double res = 0;
    for(int i = 1; i < (int)low.size(); i++){
      double t = 0;
      for(int h = low[i - 1]; h <= high[i - 1]; h++) 
	t += sum(h, low[i], high[i]);
      t /= (high[i] - low[i] + 1); 
      t /= (high[i - 1] - low[i - 1] + 1);
      res += t;
    }
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 3, 5, 7, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 4, 6, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(2, Arg2, expectedBeauty(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4, 3, 3, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.171428571428572; verify_case(3, Arg2, expectedBeauty(Arg0, Arg1)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  AlternatingLane ___test; 
  ___test.run_test(-1);
}
// END CUT HERE
