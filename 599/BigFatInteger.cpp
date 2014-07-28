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
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;
class BigFatInteger {
public:
  map<int, int> prime_factor(int n){
    map<int, int> ret;
    for(int i = 2; i * i <= n; i++){
      while(n % i == 0){
	ret[i]++;
	n /= i;
      }
    }
    if(n != 1) ret[n] = 1;
    return ret;
  }
  int len(ll a){
    for(int i = 0; i < 63; i++) if((1LL << i) >= a) return i;
  }
  int minOperations(int A, int B)
  {
    map<int, int> pf = prime_factor(A);
    map<int, int>::iterator it = pf.begin();
    vector<int> p;
    for(; it != pf.end(); it++) p.push_back(it->second * B);
    sort(ALL(p));
    
    int x0 = pf.size();
    int l = 0;
    for(int i = 0; i < (int)p.size(); i++){
      //res += __builtin_popcount(p[i]);
      l = max(l, len(p[i]));
    }
    // for(int i = 0; i < 100; i++) cout << i << " " << len(i) << endl;
    // return l - 1 + res;
    return l + x0;
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 162; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999983; int Arg1 = 9; int Arg2 = 5; verify_case(2, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 360; int Arg1 = 8; int Arg2 = 8; verify_case(3, Arg2, minOperations(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BigFatInteger ___test;
___test.run_test(-1);
}
// END CUT HERE 
