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

ll d[30];

using namespace std;
class IntegerPalindrome {
public:
  string s2i(ll a){
    stringstream ss; ss << a;
    string r; ss >> r; return r;
  }
  ll i2s(string a){
    stringstream ss(a); ll x;
    ss >> x; return x;
  }
  ll concat(ll a, int keta){
    string f = s2i(a);
    string s = f;
    reverse(ALL(s));
    f += (keta % 2) ? s.substr(1) : s;
    return i2s(f);
  }
  long long findByIndex(int K){
    fill(d, d + 20, 1LL);
    ll sum = 0LL;
    int i;
    for(i = 1; i <= 20; i++){
      int half = (i + 1) / 2;
      for(int j = 0; j < half; j++) d[i] *= (j == half - 1) ? 9LL : 10LL;
      sum += d[i];
    }

    sum = 0LL, i = 1;
    while(sum <= K) sum += d[i++];
    sum -= d[--i];

    ll kth = K - sum;
    ll t = 1;
    for(int j = 0; j < (i + 1) / 2 - 1; j++) t *= 10LL;
    kth += t;

    return concat(kth, i);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; long long Arg1 = 9LL; verify_case(0, Arg1, findByIndex(Arg0)); }
	void test_case_1() { int Arg0 = 9; long long Arg1 = 11LL; verify_case(1, Arg1, findByIndex(Arg0)); }
	void test_case_2() { int Arg0 = 19; long long Arg1 = 111LL; verify_case(2, Arg1, findByIndex(Arg0)); }
	void test_case_3() { int Arg0 = 235; long long Arg1 = 13731LL; verify_case(3, Arg1, findByIndex(Arg0)); }
	void test_case_4() { int Arg0 = 23746; long long Arg1 = 137484731LL; verify_case(4, Arg1, findByIndex(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
IntegerPalindrome ___test;
___test.run_test(-1);
}
// END CUT HERE 
