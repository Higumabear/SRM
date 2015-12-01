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
const int MAX_V = 220;

struct edge {int to, cap, rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];

int min(int a, int b){
  return (a > b) ? b : a;
}

// コンパイラによってはこのキャストが許されない場合がある
void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size() - 1});
}

// dfsで増加パスを探す
int dfs(int v, int t, int f){
  if(v == t) return f;
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

// sからtへの最大流を求める
int max_flow(int s, int t){
  int flow = 0;
  for(;;){
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, INF);
    if(f == 0) return flow;
    flow += f;
  }
}

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

class PrinceOfPersia {
public:
  int N, M;
  int minObstacles(vector <string> maze) {
    N = maze.size(), M = maze[0].size();
    for(int i = 0; i < MAX_V; i++) G[i].clear();

    int sy, sx, gy, gx;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	if(maze[i][j] == 'P'){
	  sy = i, sx = j, maze[i][j] = '.';
	  goto L1;
	}

  L1:;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	if(maze[i][j] == 'P') gy = i, gx = j, maze[i][j] = '.';

    if(abs(sx - gx) + abs(sy - gy) <= 1) return -1;

    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	add_edge(i * M + j, i * M + j + 100, 1);
    
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){	
	if(maze[i][j] != '#'){
	  for(int k = 0; k < 4; k++){
	    int ny = i + dy[k], nx = j + dx[k];
	    if(0 <= ny && ny < N && 0 <= nx && nx < M && maze[ny][nx] != '#')
	      add_edge(i * M + j + 100, ny * M + nx, 1);
	  }
	}
      }
    }

    return max_flow(sy * M + sx + 100, gy * M + gx);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"P....",
 "...##",
 "##...",
 "....P"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minObstacles(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".P.P.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, minObstacles(Arg0)); }
	void test_case_2() { string Arr0[] = {".#P.",
 ".P#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minObstacles(Arg0)); }
	void test_case_3() { string Arr0[] = {"####",
 "#PP#",
 "####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minObstacles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PrinceOfPersia ___test;
    ___test.run_test(-1);
}
// END CUT HERE
