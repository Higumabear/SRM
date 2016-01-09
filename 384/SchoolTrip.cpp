#include <bits/stdc++.h>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define DOBINF 1e100
#define EPS 1e-6
#define ABS(a) ((a) < 0 ? - (a) : (a))
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

const int MAX = 2000;

double dp[1 << 6][6][MAX];
vector<double> p;

class SchoolTrip {  
public:
  int N;
  int nextturn(int state, int idx){
    for(int i = idx + 1; i < N; i++) if(state >> i & 1) return i;
    for(int i = 0; i < idx; i++) if(state >> i & 1) return i;
  }
  double rec(int S, int idx, int depth){
    //cout << S << " " << idx << " " << depth << endl;
    if(__builtin_popcount(S) <= 1) return 0.0;
    if(depth >= MAX) return 1.00;

    double &ans = dp[S][idx][depth];
    if(ans > 0.0) return ans;
    
    ans = 1e100;
    vector<int> m;
    for(int i = 0; i < N; i++) 
      if(S >> i & 1) m.push_back(i);
    int L = m.size();

    for(int i = 0; i < L; i++) if(m[i] != idx){
	int nextstate;
	//hit
	nextstate = S ^ (1 << m[i]);
	double hit = rec(nextstate, nextturn(nextstate, idx), depth + 1) * p[idx];
	//miss
	nextstate = S;
	double miss = rec(nextstate, nextturn(nextstate, idx), depth + 1) * (1.0 - p[idx]);
	ans = min(ans, 1.0 + hit + miss);
    }
    return ans;
  }
  double duration(vector <int> probability) {
    double ans;
    p.clear();
    N = probability.size();
    for(int i = 0; i < N; i++) p.push_back(probability[i] * 0.01);
    memset(dp, -1, sizeof(dp));
    
    return rec((1 << N) - 1, 0, 0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, duration(Arg0)); }
	void test_case_1() { int Arr0[] = {50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.0; verify_case(1, Arg1, duration(Arg0)); }
	void test_case_2() { int Arr0[] = {25,50,75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.892383478590375; verify_case(2, Arg1, duration(Arg0)); }
	void test_case_3() { int Arr0[] = {100,100,100,42,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(3, Arg1, duration(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  SchoolTrip ___test;
  ___test.run_test(-1); 
}
// END CUT HERE
