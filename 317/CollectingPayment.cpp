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

using namespace std;
class CollectingPayment {
public:
  double maximumProfit(vector <int> earning, vector <int> moment, int fee, int rate){
    int N = earning.size();
    vector<int> e(N + 1, 0);
    vector<double> dp(N + 1, 0.0);
    for(int i = 1; i <= N; i++) e[i] = e[i - 1] + earning[i - 1];

    for(int i = 0; i < N + 1; i++){
      for(int j = 0; j < i; j++){
	dp[i] = max(dp[i], dp[j]);
	int money = e[i] - e[j] - fee;
	if(money < 0) continue;
	dp[i] = max(dp[i], dp[j] + money * pow(1.0 + rate / 1000.0, (365 - moment[i - 1]) / 7 + 1));
      }
    }
    return dp[N];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {300,290,320,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {120,124,200,202}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; int Arg3 = 10; double Arg4 = 1325.1174146859212; verify_case(0, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {300,290,320,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,122,243,365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 40; int Arg3 = 10; double Arg4 = 1240.733092976253; verify_case(1, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {300,290,320,150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,122,243,365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; int Arg3 = 10; double Arg4 = 868.6; verify_case(2, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; int Arg3 = 100; double Arg4 = 110.0; verify_case(3, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1000,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {155,365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 100; double Arg4 = 17274.90824619758; verify_case(4, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {1,346,7,346,345,3,453,5,346,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,7,34,74,163,200,250,352,360}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; double Arg4 = 1855.0; verify_case(5, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {1,346,7,346,345,3,453,5,346,354,25,23,354,235,235}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,7,34,74,98,154,163,178,200,210,250,279,325,352,360}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; int Arg3 = 10; double Arg4 = 3693.6800093457805; verify_case(6, Arg4, maximumProfit(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CollectingPayment ___test;
___test.run_test(-1);
}
// END CUT HERE 
