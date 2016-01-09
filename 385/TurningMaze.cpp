#include <bits/stdc++.h>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ABS(a) ((a) < 0 ? - (a) : (a))
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

int dp[1 << 7][1 << 7][7][7];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

struct state{
  int H, W, y, x;
};

class TurningMaze {  
public:
  int N, M;
  vector<string> f;
  bool pass(int H, int W, int y, int x, int ny, int nx){
    bool flip_now = (H >> y) ^ (W >> x);
    bool flip_next = (H >> ny) ^ (W >> nx);
    char door_now, door_next;
    if(f[y][x] == 'C' && flip_now) door_now = 'D';
    else if(f[y][x] == 'D' && flip_now) door_now = 'C';
    else door_now = f[y][x];
    if(f[ny][nx] == 'C' && flip_next) door_next = 'D';
    else if(f[ny][nx] == 'D' && flip_next) door_next = 'C';
    else door_next = f[ny][nx];

    if(door_now == 'A'){
      if(door_next == 'A') return true;
      if(door_next == 'C' && x == nx) return true;
      if(door_next == 'D' && y == ny) return true;
    }
    else if(door_now == 'C'){
      if(door_next == 'A' && x == nx) return true;
      if(door_next == 'C' && x == nx) return true;
    }
    else if(door_now == 'D'){
      if(door_next == 'A' && y == ny) return true;
      if(door_next == 'D' && y == ny) return true;
    }
    else{
    } 

    return false;
  }

  int rec(int H, int W, int y, int x){
    if(y == N - 1 && x == M - 1) return 0;
    
    int &ans = dp[H][W][y][x];
    if(ans >= 0) return ans;

    ans = INF;

    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(!(0 <= nx && nx < M && 0 <= ny && ny < N)) continue;
      if(pass(H, W, y, x, ny, nx)) ans = min(ans, 1 + rec(H, W, ny, nx));
    }
    ans = min(ans, 1 + rec(H ^ (1 << y), W ^ (1 << x), y, x));
    return ans;
  }
  int minTime(vector <string> maze) {
    memset(dp, -1, sizeof(dp));
    N = maze.size(), M = maze[0].size();
    f = maze;
    
    queue<state> Q;
    state init; init.H = 0, init.W = 0, init.y = 0, init.x = 0;
    dp[0][0][0][0] = 0;
    Q.push(init);
    while(!Q.empty()){
      int y = Q.front().y, x = Q.front().x;
      int H = Q.front().H, W = Q.front().W;
      Q.pop();
      if(y == N - 1 && x == M - 1) return dp[H][W][y][x];

      state tmp;
      for(int i = 0; i < 4; i++){
    	int ny = y + dy[i], nx = x + dx[i];
    	if(!(0 <= nx && nx < M && 0 <= ny && ny < N)) continue;
    	if(pass(H, W, y, x, ny, nx) && dp[H][W][ny][nx] == -1){
    	  dp[H][W][ny][nx] = dp[H][W][y][x] + 1;
	  tmp.H = H, tmp.W = W, tmp.y = ny, tmp.x = nx;
    	  Q.push(tmp);
    	}
      }
      if(dp[H ^ (1 << y)][W ^ (1 << x)][y][x] == -1){
    	dp[H ^ (1 << y)][W ^ (1 << x)][y][x] = dp[H][W][y][x] + 1;
	tmp.H = (H ^ (1 << y)), tmp.W = (W ^ (1 << x)), tmp.y = y, tmp.x = x;
    	Q.push(tmp);
      }
    }
    return -1;
    // int ans = rec(0, 0, 0, 0);
    // return ans == INF ? -1 : ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAA", "BBA", "AAA", "ABB", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAACAAA", "BBBBBBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"ACDCDCA", "BBBBBBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"CA", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minTime(Arg0)); }
	void test_case_5() { string Arr0[] = {"AAAAAAA","ADCAAAD","CDDCDCC","ADAAAAD","BADCDDA","AADAAAB","AADCACA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, minTime(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  TurningMaze ___test;
  ___test.run_test(-1); 
}
// END CUT HERE
