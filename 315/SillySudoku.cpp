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
class SillySudoku {
public:
  int ans;
  vector<vector<int>> f;
  void rec(vector<vector<int>> a, int idx){
    if(idx == 4){
      if(check(a[0][0], a[0][1], a[1][0], a[1][1]) && 
	 check(a[0][2], a[0][3], a[1][2], a[1][3]) && 
	 check(a[2][0], a[2][1], a[3][0], a[3][1]) && 
	 check(a[2][2], a[2][3], a[3][2], a[3][3]) && 
	 check(a[0][0], a[1][0], a[2][0], a[3][0]) && 
	 check(a[0][1], a[1][1], a[2][1], a[3][1]) && 
	 check(a[0][2], a[1][2], a[2][2], a[3][2]) && 
	 check(a[0][3], a[1][3], a[2][3], a[3][3])) ans++;
      return;
    }

    int num[4] = {1, 2, 3, 4};
    do{
      vector<vector<int>> t = a;
      bool good = true;
      for(int i = 0; i < 4; i++){
	if(t[idx][i] == 0 || t[idx][i] == num[i]) t[idx][i] = num[i];
	else good = false;
      }
      if(good) rec(t, idx + 1);
    }while(next_permutation(num, num + 4));

    return;
  }

  bool check(int a, int b, int c, int d){
    int s[4] = {a, b, c, d};
    sort(s, s + 4);
    return s[0] == 1 && s[1] == 2 && s[2] == 3 && s[3] == 4;
  }

  int countWays(vector <string> board){
    ans = 0;
    int N = board.size();
    f.clear();
    f.resize(N);
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	f[i].push_back(board[i][j] == '-' ? 0 : board[i][j]- '0');

    rec(f, 0);
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"--21", 
 "--34", 
 "2143", 
 "3412"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"--1-", 
 "--1-", 
 "----", 
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"1---", 
 "-42-", 
 "-3--", 
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"1---", 
 "--1-", 
 "-1--", 
 "---1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"1---", 
 "----", 
 "----", 
 "----"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; verify_case(4, Arg1, countWays(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
SillySudoku ___test;
___test.run_test(-1);
}
// END CUT HERE 
