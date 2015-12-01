#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

int d[1000001];

class ReverseDistance {
public:
  ll rev(ll t){
    ll v = 0;
    while(t){
      v = 10 * v + t % 10;
      t /= 10;
    }
    return v;
  }
  int len(int t){
    int r = 0;
    while(t){
      t /= 10; r++;
    }
    return r;
  }
  string find(int difference) {
    ll p[15] = {};
    p[0] = 1;
    for(int i = 1; i < 15; i++) p[i] = p[i - 1] * 10;

    for(int i = 0; i <= 1000000; i++){
      int l = len(i);
      int r = rev(i);

      ll rem = (difference + r) % p[l];
      ll c = i * p[l] + rem;
      if(c - rev(c) == difference) return i2s(c);

      rem = (difference + r) % p[l - 1];
      c = i * p[l - 1] + rem;
      if(c - rev(c) == difference) return i2s(c);
    }
    return "NONE";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 18; string Arg1 = "20"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 15; string Arg1 = "NONE"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 4275; string Arg1 = "5080"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 900; string Arg1 = "101001"; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { int Arg0 = 1989; string Arg1 = "100990"; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { int Arg0 = 857232; string Arg1 = "860300"; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { int Arg0 = 45; string Arg1 = "50"; verify_case(6, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ReverseDistance ___test;
    ___test.run_test(-1);
}
// END CUT HERE
