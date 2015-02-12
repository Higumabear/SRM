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

const int NUM = 4000000;
int p[10];
int memo[NUM];
int used[NUM];

using namespace std;
class ExtendedHappyNumbers {
public:
  int KK;
  int S(int a){
    int ret = 0;
    while(a){
      ret += p[a % 10];
      a /= 10;
    }
    return ret;
  }

  int rec(int a){
    if(used[a] == 2){
      if(memo[a] == -1) return memo[a] = a;
      else return memo[a];
    }
    used[a]++;
    return memo[a] = min(a, rec(S(a)));
  }

  long long calcTheSum(int A, int B, int K){
    fill(memo, memo + NUM, -1);
    fill(used, used + NUM, 0);
    for(int i = 0; i < 10; i++){
      p[i] = 1;
      for(int j = 0; j < K; j++)
	p[i] *= i;
    }

    ll ans = 0;    
    for(int i = A; i <= B; i++) ans += rec(i);
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 13; int Arg2 = 2; long long Arg3 = 1LL; verify_case(0, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 2; long long Arg3 = 14LL; verify_case(1, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 99; int Arg2 = 1; long long Arg3 = 450LL; verify_case(2, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 535; int Arg1 = 538; int Arg2 = 3; long long Arg3 = 820LL; verify_case(3, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 400000; int Arg2 = 6; long long Arg3 = 5169721292LL; verify_case(4, Arg3, calcTheSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ExtendedHappyNumbers ___test;
___test.run_test(-1);
}
// END CUT HERE 
