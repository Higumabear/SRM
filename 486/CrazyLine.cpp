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

int dp[50][50];

class CrazyLine {
public:
  int maxCrazyness(vector <int> heights) {
    int N = heights.size();
    sort(ALL(heights));
//     for(int i = 0; i < N / 2; i++)
//       ans += ((i == N / 2 - 1) ? 1 : 2) * (heights[N - i - 1] - heights[i]);
//     if(N % 2 == 1 && N >= 3) ans += max(heights[N / 2] - heights[N / 2 - 1], heights[N / 2 + 1] - heights[N / 2]);
//     return ans;
//     if(N % 2 == 0){
      
//     }else{

    int result = 0;
    for(int i = 1; i < N - 1; i++){
      int mid = i;
      int ans = 0;
      for(int j = 0; j < N; j++) ans += 2 * abs(heights[j] - heights[mid]);
      ans -= (abs(heights[mid - 1] - heights[mid]) + abs(heights[mid + 1] - heights[mid]));
      result = max(result, ans);
    }
    return result;
      //}
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,10,25,40,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(0, Arg1, maxCrazyness(Arg0)); }
	void test_case_1() { int Arr0[] = {2,3,5,7,11,13,17,19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 82; verify_case(1, Arg1, maxCrazyness(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,501}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; verify_case(2, Arg1, maxCrazyness(Arg0)); }
	void test_case_3() { int Arr0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, maxCrazyness(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  CrazyLine ___test;
  ___test.run_test(-1);
}
// END CUT HERE
