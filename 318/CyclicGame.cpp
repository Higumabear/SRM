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
#define EPS 1e-10
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

double dp[1000][15];
vector<int> a;

class CyclicGame {
public:
  double rec(int idx, int cur){
    if(idx >= 1000) return 0.0;
    if(dp[idx][cur] >= 0.0) return dp[idx][cur];

    double ret = 0.0;
    for(int i = 1; i <= 6; i++){
      int next = (cur + i) % a.size();
      int val = a[next];
      ret += val * pow(6, -idx) + rec(idx + 1, next);
    }
    if(ret < 0.0) ret = 0.0;
    return dp[idx][cur] = ret;
  }

  double estimateBank(vector <int> cells){
    int N = cells.size();
    a = cells;
    memset(dp, -1, sizeof(dp));
    return rec(1, 0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-10, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.3611111111111112; verify_case(0, Arg1, estimateBank(Arg0)); }
	void test_case_1() { int Arr0[] = {-10, 7, -5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.30434782608695654; verify_case(1, Arg1, estimateBank(Arg0)); }
	void test_case_2() { int Arr0[] = {-1, -2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, estimateBank(Arg0)); }
	void test_case_3() { int Arr0[] = {-40, 9, 9, 9, 9, 9, -44, 9, 9, 9, 9, 9, -40, 15, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.5653612433724144; verify_case(3, Arg1, estimateBank(Arg0)); }
	void test_case_4() { int Arr0[] = {-36, 95, -77, -95, 49, -52, 42, -34, -1, 98, -20, 96, -96, 23, -52}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 12.395613307567126; verify_case(4, Arg1, estimateBank(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CyclicGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
