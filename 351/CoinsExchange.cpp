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
class CoinsExchange {
public:
  int countExchanges(int G1, int S1, int B1, int G2, int S2, int B2){
    int ans = 0;
    while(G1 < G2){
      S1 -= 11; G1++; ans++;
    }
    while(B1 < B2){
      S1--; B1 += 9; ans++;
    }
    while(S1 < S2 && G1 > G2){
      G1--; S1 += 9; ans++;
    }
    while(S1 < S2 && B1 - 11 >= B2){
      B1 -= 11; S1++; ans++;
    }
    return S1 >= S2 ? ans : -1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 81; int Arg6 = 10; verify_case(0, Arg6, countExchanges(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 12; int Arg3 = 5; int Arg4 = 53; int Arg5 = 33; int Arg6 = 7; verify_case(1, Arg6, countExchanges(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 100; int Arg2 = 12; int Arg3 = 5; int Arg4 = 63; int Arg5 = 33; int Arg6 = -1; verify_case(2, Arg6, countExchanges(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 12; int Arg3 = 3; int Arg4 = 7; int Arg5 = 9; int Arg6 = 0; verify_case(3, Arg6, countExchanges(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CoinsExchange ___test;
___test.run_test(-1);
}
// END CUT HERE 
