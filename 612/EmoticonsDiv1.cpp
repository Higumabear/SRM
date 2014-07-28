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

int dp[2010][2010];

using namespace std;
class EmoticonsDiv1 {
public:
  int printSmiles(int smiles){
    for(int i = 0; i < 2010; i++)
      for(int j = 0; j < 2010; j++)
	dp[i][j] = INF;

    queue<pair<int, int> > Q;
    Q.push(make_pair(1, 0)); dp[1][0] = 0;
    while(!Q.empty()){
      int cur = Q.front().first;
      int clip = Q.front().second;
      Q.pop();
      if(cur == smiles) return dp[cur][clip];

      int d = dp[cur][clip];
      if(d + 1 < dp[cur][cur]){
	dp[cur][cur] = d + 1;
	Q.push(make_pair(cur, cur));
      }
      if(cur + clip < 2010 && d + 1 < dp[cur + clip][clip]){
	dp[cur + clip][clip] = d + 1;
	Q.push(make_pair(cur + clip, clip));
      }
      if(cur - 1 >= 0 && d + 1 < dp[cur - 1][clip]){
	dp[cur - 1][clip] = d + 1;
	Q.push(make_pair(cur - 1, clip));
      }
    }
    //return *min_element(dp[smiles], dp[smiles] + 2010);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 8; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
EmoticonsDiv1 ___test;
___test.run_test(-1);
}
// END CUT HERE 
