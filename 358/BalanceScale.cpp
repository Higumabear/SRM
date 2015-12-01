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

class BalanceScale {
public:
  int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }

  int N;
  vector<int> W;
  map<int, int> mem;
  int rec(int a){
    if(a == 1) return 0;
    if(mem.count(a)) return mem[a];

    int res = INF;
    for(int i = 0; i < N; i++){
      int ta = gcd(a, W[i]);
      if(ta == a) continue;
      res = min(res, 1 + rec(ta));
    }
    return mem[a] = res;
  }
  int takeWeights(vector <int> weight) {
    N = weight.size();
    int g = weight[0];
    W = weight;
    for(int i = 0; i < N; i++) g = gcd(g, weight[i]);
    for(int i = 0; i < N; i++) W[i] /= g;

    mem.clear();
    int ans = INF;
    for(int i = 0; i < N; i++) ans = min(ans, 1 + rec(W[i]));
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 5, 4, 1, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, takeWeights(Arg0)); }
	void test_case_1() { int Arr0[] = { 2, 3, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, takeWeights(Arg0)); }
	void test_case_2() { int Arr0[] = { 60, 105, 490, 42 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, takeWeights(Arg0)); }
	void test_case_3() { int Arr0[] = { 15, 25, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, takeWeights(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BalanceScale ___test;
    ___test.run_test(-1);
}
// END CUT HERE
