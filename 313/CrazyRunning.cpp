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



class CrazyRunning {
public:
  double expectedTime(vector <int> corridors){
    int N = corridors.size();
    double L = accumulate(ALL(corridors), 0);
    double ans = corridors[0] + (L - corridors[0]) / (N - 1.0);
    for(int i = 1; i < N - 1; i++) ans += 2.0 * L / N * (N - 1) / i;
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 30.0; verify_case(0, Arg1, expectedTime(Arg0)); }
	void test_case_1() { int Arr0[] = {150,150,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 900.0; verify_case(1, Arg1, expectedTime(Arg0)); }
	void test_case_2() { int Arr0[] = {100,150,200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 875.0; verify_case(2, Arg1, expectedTime(Arg0)); }
	void test_case_3() { int Arr0[] = {1000,1000,900,1000,555,1000,2562}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 33550.32857142857; verify_case(3, Arg1, expectedTime(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CrazyRunning ___test;
___test.run_test(-1);
}
// END CUT HERE 
