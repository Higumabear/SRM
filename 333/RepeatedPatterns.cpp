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
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;



class RepeatedPatterns {
public:
  ll z;

  ll s2i(string s){
    stringstream ss(s);
    ll x; ss >> x; return x;
  }
  bool in(ll idx){
    return idx + z <= 1e16;
  }
  long long findZeroSegment(string P1, string P2, string zeroCount){
    int N = P1.length(), M = P2.length();
    ll h1 = 0, t1 = 0, h2 = 0, t2 = 0;
    while(h1 < N && P1[h1] == '0') h1++;
    while(h2 < M && P2[h2] == '0') h2++;
    while(t1 < N && P1[N - 1 - t1] == '0') t1++;
    while(t2 < M && P2[M - 1 - t2] == '0') t2++;
    
    z = s2i(zeroCount);
    ll ans = LLINF;
    //Å‰‚©‚çŒ»‚ê‚é
    if(z <= h1) return ans = min(ans, 0LL);
    //P1“à‚ÉŒ»‚ê‚é
    if(N >= z){
      int idx = P1.find(string(z, '0'), 0);
      if(string::npos != idx) ans = min(ans, (ll)idx);
    }

    //P2“à‚ÉŒ»‚ê‚é
    if(M >= z){
      int idx = P2.find(string(z, '0'), 0);
      if(string::npos != idx) ans = min(ans, 1000000LL * N + idx);
    }

    //P1‚ÆP1‚Ì‹«–Ú
    if(t1 + h1 >= z && in(N - t1)) 
      ans = min(ans, N - t1);
    
    //P1‚ÆP2‚Ì‹«–Ú
    if(t1 + h2 >= z && in(1000000LL * N - t1))
      ans = min(ans, 1000000LL * N - t1);
   
    //P2‚ÆP1‚Ì‹«–Ú
    if(t2 + h1 >= z && in(N * 1000000LL + M - t2)) 
      ans = min(ans, N * 1000000LL + M - t2);

    //P2‚ÆP2‚Ì‹«–Ú
    if(t2 + h2 >= z && in(2LL * (1000000LL * N + M) - t2)) 
      ans = min(ans, 2LL * (1000000LL * N + M) - t2);

    //P1‚ª‚·‚×‚Ä0‚Ì‚Æ‚«
    if(h1 == N){
      if(t2 + 1000000LL * N + h2 >= z && in(1000000LL * N + M - t2))
	ans = min(ans, 1000000LL * N + M - t2);
      if(1000000LL * N + h2 >= z && in(0))
	ans = min(ans, 0LL);
    }

    //P2‚ª‚·‚×‚Ä0‚Ì‚Æ‚«
    if(h2 == M){
      if(zeroCount.length() / P2.length() * P1.length() < 17){
	ll p = ((z - t1 - h1) % M == 0) ? 
	  (z - t1 - h1) / M : (z - t1 - h1) / M + 1;
	ll q = 1000000LL * N * p + p * (p - 1) / 2 * M - t1;
	if(q < 0) q = 0;
	if(in(q)) ans = min(ans, q);
      }
    }

    //P1,P2‚·‚×‚Ä0‚Ì‚Æ‚«
    if(t1 == N && t2 == M && in(0)) ans = 0;
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
