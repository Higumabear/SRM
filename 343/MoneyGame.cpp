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

int dp[11][11][11][11][11][11];
bool used[11][11][11][11][11][11];

vector<int> val;
int A, B, C;

class MoneyGame {
public:
  int rec(int a, int b, int c, int d, int e, int f){
    
    int &ret = dp[a][b][c][d][e][f];
    if(used[a][b][c][d][e][f]) return ret;
       used[a][b][c][d][e][f] = true;

    if(a == 0 && b == 0 && c == 0)
      return ret = -(val[0] * d + val[1] * e + val[2] * f);
    
    ret = -INF;
    for(int ii = 0;  ii < 3; ii++){
      int v[3] = {a, b, c};
      if(ii == 0 && a > 0) v[0]--;
      else if(ii == 1 && b > 0) v[1]--;
      else if(ii == 2 && c > 0) v[2]--;
      else continue;

      for(int i = 0; i <= A - d - v[0]; i++)
	for(int j = 0; j <= B - e - v[1]; j++)
	  for(int k = 0; k <= C - f - v[2]; k++){
	    if(i * val[0] + j * val[1] + k * val[2] >= val[ii]) continue;
	    int r = rec(d, e, f, v[0] + i, v[1] + j, v[2] + k);
	    ret = max(ret, -r);
	  }
    }
    return ret;
  }
  int play(vector <int> lennysCoins, vector <int> fredsCoins, vector <int> values){
    val = values;
    memset(used, false, sizeof(used));
    A = lennysCoins[0] + fredsCoins[0];
    B = lennysCoins[1] + fredsCoins[1];
    C = lennysCoins[2] + fredsCoins[2];
    return rec(lennysCoins[0]	, lennysCoins[1], lennysCoins[2],
	       fredsCoins[0]	, fredsCoins[1], fredsCoins[2]);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,10,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -2; verify_case(0, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,10,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,5,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,753,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 600; verify_case(3, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000,1000,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -15000; verify_case(4, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,8,14}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 42; verify_case(5, Arg3, play(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
MoneyGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
