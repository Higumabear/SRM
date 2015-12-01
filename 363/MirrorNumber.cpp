#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline ll s2i(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

int from[] = {0, 1, 8, 2, 5};
int to[] = {0, 1, 8, 5, 2};

class MirrorNumber {
public:
  int dig[20];
  ll ia, ib;
  int cnt, len;
  void rec(int a, int b){
    if(a > b){
      ll base = 1, num = 0;
      for(int i = len; i >= 0; i--){
	num += base * dig[i];
	base *= 10;
      }
      if(num >= ia && num <= ib) cnt++;

      return;
    }
    if(a == b){
      for(int i = 0; i < 3; i++){
	dig[a] = from[i];
	rec(a + 1, b - 1);
      }
      return;
    }
    for(int i = 0; i < 5; i++){
      if(i == 0 && a == 0) continue;
      dig[a] = from[i];
      dig[b] = to[i];
      rec(a + 1, b - 1);
    }
  }
  int count(string A, string B) {
    ia = s2i(A); ib = s2i(B);
    cnt = 0;
    for(len = 0; len < 18; len++) rec(0, len);
    return cnt;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0"; string Arg1 = "10"; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "0"; string Arg1 = "100"; int Arg2 = 7; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "143"; string Arg1 = "23543"; int Arg2 = 54; verify_case(2, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MirrorNumber ___test;
    ___test.run_test(-1);
}
// END CUT HERE
