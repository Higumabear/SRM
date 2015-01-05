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
class SumThemAll {
public:
  ll sum(ll n){
    if(n < 10) return n;
    return sum(n / 10) + sum(n % 10);
  }
  ll cnt(ll n){
    if(n < 10) return n * (n + 1) / 2;
    if(n % 10 == 9) return cnt(n / 10) * 10 + (n / 10 + 1) * 45;
    return cnt(n + 1) - sum(n + 1);
  }
  long long getSum(int lowerBound, int upperBound){
    if(lowerBound == 0) lowerBound++;
    return cnt(upperBound) - cnt(lowerBound - 1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 3; long long Arg2 = 6LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 14; long long Arg2 = 15LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 53; long long Arg2 = 296LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 24660; int Arg1 = 308357171; long long Arg2 = 11379854844LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SumThemAll ___test;
___test.run_test(-1);
}
// END CUT HERE 
