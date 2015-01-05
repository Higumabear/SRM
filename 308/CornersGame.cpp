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
#define INF 1 << 27
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

map<ll, int> memo;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class CornersGame {
public:
  int countMoves(vector <string> board){
    memo.clear();
    queue<ll> Q;
    Q.push(1LL << 28 | 1LL << 29 | 1LL << 34 | 1LL << 35);
    while(!Q.empty()){
      ll v = Q.front(); Q.pop();
      if(v == (1LL << 0 | 1LL << 1 | 1LL << 6 | 1LL << 7)) return memo[v];

      vector<string> b = board;
      for(int i = 0; i < 36; i++) if(v & (1LL << i)) b[i/6][i%6] = 'b';
      for(int i = 0; i < 6; i++){
	for(int j = 0; j < 6; j++){
	  if(b[i][j] != 'b') continue;
	  for(int k = 0; k < 4; k++){
	    int i1 = i + dy[k];
	    int j1 = j + dx[k];
	    int i2 = i + dy[k] * 2;
	    int j2 = j + dx[k] * 2;
	    if(0 <= i1 && i1 < 6 && 0 <= j1 && j1 < 6 && b[i1][j1] == '.'){
	      ll v2 = (v ^ (1LL << (i * 6 + j))) | (1LL << (i1 * 6 + j1));
	      if(memo.find(v2) == memo.end()){
		memo[v2] = memo[v] + 1;
		Q.push(v2);
	      }
	    }

	    if(0 <= i1 && i1 < 6 && 0 <= j1 && j1 < 6 && 
	       0 <= i2 && i2 < 6 && 0 <= j2 && j2 < 6 && 
	       b[i2][j2] == '.' && (b[i1][j1] == 's' || b[i1][j1] == 'b')){
	      ll v2 = (v ^ (1LL << (i * 6 + j))) | (1LL << (i2 * 6 + j2));
	      if(memo.find(v2) == memo.end()){
		memo[v2] = memo[v] + 1;
		Q.push(v2);
	      }
	    }
	  }
	}
      }
    }
    return -1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"......", 
 "......",
 "......",
 "......",
 "......",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, countMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {".....s",
 "..s.r.",
 "r.....",
 ".srs..",
 "..r...",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, countMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"......",
 "......",
 "....ss",
 "....ss",
 "...r..",
 "...r.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, countMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"...s.r",
 "..r.s.",
 "rr.s..",
 "..s.rr",
 "s.rr..",
 ".s.s.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(3, Arg1, countMoves(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
CornersGame ___test;
___test.run_test(-1);
}
// END CUT HERE 
