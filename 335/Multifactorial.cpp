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
class Multifactorial {
public:
  string adds(string a, string b){
    a = string(1000 - a.length(), '0') + a;
    b = string(1000 - b.length(), '0') + b;
    reverse(ALL(a)); reverse(ALL(b));
    string c(1001, '0');
    
    int co = 0;
    int i;
    for(i = 0; i < 1000; i++){
      int aa = a[i] - '0', bb = b[i] - '0';
      c[i] = (char)(((aa + bb + co) % 10) + '0');
      co = (aa + bb) / 10;
    }
    c[i] = (char)('0' + co);
    return c;
  }
  string muls(string a, string b){
    a = string(1000 - a.length(), '0') + a;
    b = string(1000 - b.length(), '0') + b;

    int A = a.size(), B = b.size();
    reverse(ALL(a)); reverse(ALL(b));

    string ret;
    for(int j = 0; j < B; j++){
      int co = 0;
      string d(1000, '0');
      int i;
      for(i = 0; i < A; i++){
	int aa = a[i] - '0', bb = b[j] - '0';
	d[i] = (char)((aa * bb + co) % 10 + '0');
	co =  aa * bb / 10;
      }
      d[i] = (char)('0' + co);
      //cout << d << endl;
      ret = adds(ret, d);
    }
    return ret;
  }
  string calcMultiFact(int n, int k){
    ll N = n, K = k;
    
    ll tmp = 1;
    for(ll i = 0; N - i * K > 0; i++){
      if(tmp > 1000000000000000000LL / (N - i * K)) return "overflow";
      tmp = (tmp * (N - i * K));
    }
    stringstream ss; ss << tmp; string ans; ss >> ans;
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 14; int Arg1 = 3; string Arg2 = "12320"; verify_case(0, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "5"; verify_case(1, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 2; string Arg2 = "overflow"; verify_case(2, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2000000000; int Arg1 = 1900000000; string Arg2 = "200000000000000000"; verify_case(3, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 256; string Arg2 = "84232704000"; verify_case(4, Arg2, calcMultiFact(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2000000000; int Arg1 = 1; string Arg2 = "overflow"; verify_case(5, Arg2, calcMultiFact(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Multifactorial ___test;
___test.run_test(-1);
}
// END CUT HERE 
