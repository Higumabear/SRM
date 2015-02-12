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

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
const int MAX = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;

class ExpensiveTravel {
public:
  int minTime(vector <string> m, int startRow, int startCol, int endRow, int endCol){
    int N = m.size(), M = m[0].length();
    int A[60][60], visited[60][60];
    pair<int, int> memo[60][60];
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++){
	A[i][j] = MAX / (m[i][j] - '0');
	memo[i][j] = make_pair(INF, 0);
      }
    }
    int y = startRow - 1, x = startCol - 1;
    memo[y][x] = make_pair(0, A[y][x]);
    memset(visited, 0, sizeof(visited));
    
    while(1){
      y = -1, x = -1;

      int i, j;
      for(i = 0; i < N; i++) 
	for(j = 0; j < M; j++)
	  if(visited[i][j] == 0 && (y == -1 || memo[y][x] > memo[i][j])) y = i, x = j;
      
      if(y == -1 || memo[i][j].first == INF) break;

      visited[y][x] = 1;
      for(int i = 0; i < 4; i++){
	int ny = y + dy[i];
	int nx = x + dx[i];
	if(!(0 <= ny && ny < N && 0 <= nx && nx < M)) continue;
	if(memo[y][x].second + A[ny][nx] <= MAX)
	  memo[ny][nx] = min(memo[ny][nx], make_pair(memo[y][x].first, 
						     memo[y][x].second + A[ny][nx]));
	if(A[y][x] + A[ny][nx] <= MAX)
	  memo[ny][nx] = min(memo[ny][nx], make_pair(memo[y][x].first + 1, 
						     A[y][x] + A[ny][nx]));
      }
    }
    if(memo[endRow - 1][endCol - 1].first == INF) return -1;
    return memo[endRow - 1][endCol - 1].first + 1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"22334"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 5; int Arg5 = 3; verify_case(0, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"55",
 "52",
 "55"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; int Arg4 = 2; int Arg5 = 1; verify_case(1, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"251",
 "212",
 "122"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; int Arg4 = 3; int Arg5 = -1; verify_case(2, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"452232",
 "287979",
 "219872",
 "928234",
 "767676"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; int Arg3 = 3; int Arg4 = 1; int Arg5 = 3; verify_case(3, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; int Arg5 = -1; verify_case(4, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"123456789987654321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 1; int Arg4 = 16; int Arg5 = 5; verify_case(5, Arg5, minTime(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ExpensiveTravel ___test;
___test.run_test(-1);
}
// END CUT HERE 
