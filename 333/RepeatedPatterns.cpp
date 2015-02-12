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
class RepeatedPatterns {
public:
  ll stoi(string s){
    stringstream ss(s);
    ll ret; ss >> ret; return ret;
  }
  long long findZeroSegment(string P1, string P2, string zeroCount){

    ll ans = LLINF;
    ll pre1 = LLINF, suf1 = LLINF, pre2 = LLINF, suf2 = LLINF; 
    ll L1 = P1.length(), L2 = P2.length(); 
    ll LIM = 10000000000000000LL;
    ll zc = stoi(zeroCount);

    if(L1 >= zc && 
       P1.find(string(zc, '0')) != string::npos){
      return P1.find(string(zc, '0'));
    }

    if(L2 >= zc && 
       P2.find(string(zc, '0')) != string::npos){
      ans = min(ans, 1000000LL * L1 + (ll)P2.find(string(zc, '0')));
    }
      

    for(ll i = 0; i < L1; i++)
      if(P1[i] == '1') pre1 = min(pre1, i);
    for(ll i = L1 - 1; i >= 0; i--)
      if(P1[i] == '1') suf1 = min(suf1, L1 - 1 - i);
    for(ll i = 0; i < L2; i++)
      if(P2[i] == '1') pre2 = min(pre2, i);
    for(ll i = L2 - 1; i >= 0; i--)
      if(P2[i] == '1') suf2 = min(suf2, L2 - 1 - i);
    if(pre1 == LLINF) pre1 = L1;
    if(suf1 == LLINF) suf1 = L1;
    if(pre2 == LLINF) pre2 = L2;
    if(suf2 == LLINF) suf2 = L2;
    cout << pre1 << " " << suf1 << " " << pre2 << " " << suf2 << endl;

    if(pre1 == L1){
      if(pre2 == L2) return 0;
      if(L1 * 1000000LL + pre2 >= zc) return 0;
      if(suf2 + L1 * 1000000LL + pre2 >= zc) ans = min(ans, L1 * 1000000LL + L2 - suf2);
    }
    if(pre2 == L2){
      ll idx = (zc - suf1 - pre1 - 1) / L2;
      dump(idx);
      if(idx <= 1000000000LL){
	ll val = L1 * 1000000LL * (idx + 1) + L2 * idx * (idx + 1LL) / 2LL - suf1;
	if(val + zc <= LIM) ans = min(ans, val);
      }
      //return val >= LIM ? -1 : val;
    }
    
    if(pre1 >= zc) return 0;
    if(pre1 + suf1 >= zc) return L1 - suf1;
    
    if(suf1 + pre2 >= zc) ans = min(ans, 1000000LL * L1 - suf1);
    if(suf2 + pre1 >= zc) ans = min(ans, 1000000LL * L1 + L2 - suf2);
    
    if(suf2 + pre2 >= zc) ans = min(ans, 2LL * 1000000LL * L1 + 2LL * L2 - suf2); 
    
    return ans == LLINF ? -1 : ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111010100001010"; string Arg1 = "010000001000"; string Arg2 = "3"; long long Arg3 = 7LL; verify_case(0, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "3"; long long Arg3 = 9999999LL; verify_case(1, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "1101010010"; string Arg1 = "0001000"; string Arg2 = "5"; long long Arg3 = 20000011LL; verify_case(2, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "10101010"; string Arg1 = "101010101010"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(3, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "11111111111111111111111111"; string Arg1 = "0"; string Arg2 = "9876543219876"; long long Arg3 = -1LL; verify_case(4, Arg3, findZeroSegment(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
RepeatedPatterns ___test;
___test.run_test(-1);
}
// END CUT HERE 
