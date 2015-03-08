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

bool vis[51][51][51][51];
int ans, tam1, tam2;
string A, B;

class InterleavePal {
public:
  void dfs(int x1, int y1, int x2, int y2){
    if(vis[x1][y1][x2][y2]) return;
    vis[x1][y1][x2][y2] = true;

    int tam = y1 - x1 + y2 - x2;
    ans = max(ans, tam);
    
    if(x1){
      if(y1 < tam1 && A[x1 - 1] == A[y1]) dfs(x1 - 1, y1 + 1, x2, y2);
      if(y2 < tam2 && A[x1 - 1] == B[y2]) dfs(x1 - 1, y1, x2, y2 + 1);
    }
    if(x2){
      if(y1 < tam1 && B[x2 - 1] == A[y1]) dfs(x1, y1 + 1, x2 - 1, y2);
      if(y2 < tam2 && B[x2 - 1] == B[y2]) dfs(x1, y1, x2 - 1, y2 + 1);
    }
  }
  int longestPal(string s, string t){
    A = s, B = t; tam1 = s.length(); tam2 = t.length();
    ans = 0;
    for(int i = 0; i <= tam1; i++){
      for(int j = 0; j <= tam2; j++){
	dfs(i, i, j, j);
	if(i < tam1) dfs(i, i + 1, j, j);
	if(j < tam2) dfs(i, i, j, j + 1);
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
	void test_case_0() { string Arg0 = "AA"; string Arg1 = "BB"; int Arg2 = 4; verify_case(0, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = ""; string Arg1 = "JAVA"; int Arg2 = 3; verify_case(1, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ""; string Arg1 = ""; int Arg2 = 0; verify_case(2, Arg2, longestPal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ONCEUPONATIMETHEREWASAYOUNGPROGRAMMERWHOLEARNED"; string Arg1 = "TOPROGRAMJOINEDTOPCODERANDEVENTUALLYBECAMERED"; int Arg2 = 9; verify_case(3, Arg2, longestPal(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
InterleavePal ___test;
___test.run_test(-1);
}
// END CUT HERE 
