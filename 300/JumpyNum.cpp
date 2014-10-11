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

ll d[11] = {1, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 
	    10000000LL, 100000000LL, 1000000000LL, 10000000000LL};

using namespace std;
class JumpyNum {
public:
  map<ll, int> memo;

  int dfs(ll num, int head){
    if(num == 0 || head > num) return 0;
    ll h = num * 10LL + head;
    if(memo.count(h)) return memo[h];
    
    int res = (head != 0);
    int num2 = (num - head) / 10;

    cout << h << " ";

    for(int i = 0; i < 10; i++) 
      if(abs(i - head) >= 2LL)
	res += dfs(num2, i);
    return memo[h] = res;
  }
  int cal(int n){
    int res = 0;
    for(int i = 0; i < 10; i++) res += dfs(n, i);
    return res;
  }
  int howMany(int low, int high){
    return cal(high) - cal(low - 1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 9; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 23; int Arg2 = 9; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2000000000; int Arg1 = 2000000000; int Arg2 = 0; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8000; int Arg1 = 20934; int Arg2 = 3766; verify_case(3, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
JumpyNum ___test;
___test.run_test(-1);
___test.run_test(3);
}
// END CUT HERE 
