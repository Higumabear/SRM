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
using namespace std;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
const ll MOD = 1234567898765;

class GeometricProgressions {
public:
  /* ‘fˆö”•ª‰ð */
  map<ll, ll> prime_factor(int n){
    map<ll, ll> ret;
    for(int i = 2; i * i <= n; i++){
      while(n % i == 0){
	ret[i]++;
	n /= i;
      }
    }
    if(n != 1) ret[n] = 1;
    return ret;
  }

  int count(int b1, int q1, int n1, int b2, int q2, int n2) {
    int result;
    map<ll, ll> a1, p1, a2, p2;
    a1 = prime_factor(b1);
    p1 = prime_factor(q1);
    a2 = prime_factor(b2);
    p2 = prime_factor(q2);

    int cnt = 0;
    for(int i = 1; i <= n2; i++){
      map<ll, ll> tmp = p2;
      map<ll, ll>::iterator it;
      for(it = tmp.begin(); it != tmp.end(); it++) (it->second) *= i;
      for(it = a2.begin(); it != a2.end(); it++) tmp[(it->first)] += it->second;
      for(it = a1.begin(); it != a1.end(); it++) tmp[(it->first)] -= it->second;
      
      vector<ll> t;
      for(it = p1.begin(); it != p1.end(); it++){
	if(tmp[it->first] % (it->second) == 0)
	  t.push_back(tmp[it->first] / (it->second));
	else 
	  t.push_back(INF);
      }
      t.erase(unique(ALL(t)), t.end());
      if(t.size() == 1){
	if(t[0] == INF || t[0] == 0 || t[0] > n1) continue;
	cnt++;
	cout << i << " " << t[0] << " ";
      }
    }
    return n1 + n2 - cnt;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 6; int Arg4 = 2; int Arg5 = 5; int Arg6 = 6; verify_case(0, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; int Arg4 = 3; int Arg5 = 5; int Arg6 = 9; verify_case(1, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 2; verify_case(2, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 100500; int Arg3 = 48; int Arg4 = 1024; int Arg5 = 1000; int Arg6 = 100500; verify_case(3, Arg6, count(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  GeometricProgressions ___test;
  ___test.run_test(-1);
}
// END CUT HERE
