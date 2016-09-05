#include <bits/stdc++.h>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ABS(a) ((a) < 0 ? - (a) : (a))
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

const int MAX = 220001;
int nxt[MAX];
int dp[MAX];
bool checked[MAX], visited[MAX];

class RoundAboutCircle {  
public:
  int rec(int cur){
    if(visited[cur]) return 0;
    if(dp[cur] != INF) return dp[cur];
    checked[cur] = true;
    visited[cur] = true;
    
    int ret = 0;
    ret = 1 + rec(nxt[cur]);
    return ret;
  }
  int maxScore(int N) {
    for(int i = 1; i <= N; i++){
      int tmp = i;
      int s = 0;
      while(tmp){
	s += tmp % 10;
	tmp /= 10;
      }
      nxt[i] = (i + s) % N == 0 ? N : (i + s) % N;
    }
    
    fill(checked, checked + MAX, false);
    fill(dp, dp + MAX, INF);

    int ans = 0;
    for(int i = 1; i <= N; i++){
      if(!checked[i]){
	fill(visited, visited + MAX, false);
	int path = rec(i);
	ans = max(ans, path);
      }
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 4; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { int Arg0 = 17; int Arg1 = 11; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { int Arg0 = 566; int Arg1 = 176; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  RoundAboutCircle ___test;
  ___test.run_test(-1); 
}
// END CUT HERE
