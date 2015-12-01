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

int dp[60][110];

class ConnectTheCities {
public:
  int abs(int a){
    return a > 0 ? a : -a;
  }
  int minimalRange(int distance, int funds, vector <int> position) {
    sort(ALL(position));

    int N = position.size();
    for(int w = 1; w < distance; w++){
      for(int i = 0; i < 60; i++) for(int j = 0; j < 110; j++) dp[i][j] = INF;
      dp[0][0] = 0;
      for(int i = 0; i < N; i++){
	for(int j = 0; j <= distance; j++){
	  for(int step = 0; step <= w; step++)
	    dp[i + 1][j + step] = min(dp[i + 1][j + step],
				      dp[i][j] + abs(position[i] - j - step));
	}
      }
      int t = INF;
      for(int i = 0; i <= w; i++)
	t = min(t, dp[N][distance - i]);
      if(t <= funds) return w;
    }
    return distance;
    //return ;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = { 3, 7, 9 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 100; int Arr2[] = { 0, 0, 0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, minimalRange(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 63; int Arg1 = 19; int Arr2[] = { 34, 48, 19, 61, 24 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(2, Arg3, minimalRange(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ConnectTheCities ___test;
    ___test.run_test(-1);
}
// END CUT HERE
