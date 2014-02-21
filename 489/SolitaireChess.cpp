#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-8;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

typedef pair<int, int> P;
const int MAX_V = 1000;
const int INF = 10000000;

struct edge{ int to, cap, cost, rev; };

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

int min(int a, int b){
  return (a > b) ? b : a;
}

void add_edge(int from, int to, int cost, int cap){
  G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
  G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f){
  int res = 0;
  fill(h, h + V, 0);
  while(f > 0){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      int v = p.second;
      if(dist[v] < p.first) continue;
      for(int i = 0; i < (int)G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if(dist[t] == INF){
      return -1; // もうこれ以上流せない
    }
    for(int v = 0; v < V; v++) h[v] += dist[v];
    //s-t最短路にそって目一杯流す
    int d = f;
    for(int v = t; v != s; v = prevv[v]){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -=d;
    res += d * h[t];
    for(int v = t; v != s; v = prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

int d[100][100];
int N, M;

bool inside(int y, int x){return 0 <= y && y < N && 0 <= x && x < M;}

class SolitaireChess {
public:

  int transform(vector <string> board1, vector <string> board2) {
    N = board1.size(); M = board1[0].length();

    //ナイトのポーンの数を数えて盤面1と2で食い違えば-1
    int nN1 = 0, nP1 = 0;
    int nN2 = 0, nP2 = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(board1[i][j] == 'N') nN1++;
	if(board1[i][j] == 'P') nP1++;
	if(board2[i][j] == 'N') nN2++;
	if(board2[i][j] == 'P') nP2++;
      }
    }
    if(nN1 + nP1 != nN2 + nP2 || nP1 < nP2) return -1;

    //ナイトの盤面内移動について最小回数をwarshall-floydでもとめる
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int i = 0; i < 100; i++) fill(d[i], d[i] + 100, INF);
    for(int i = 0; i < N; i++){ 
      for(int j = 0; j < M; j++){
	d[i * M + j][i * M + j] = 0;
	for(int k = 0; k < 8; k++)
	  if(inside(i + dy[k], j + dx[k])) d[i * M + j][(i + dy[k]) * M + j + dx[k]] = 1; 
      }
    }
    for(int k = 0; k < N * M; k++)
      for(int i = 0; i < N * M; i++) 
	for(int j = 0; j < N * M; j++)
	  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    

    //盤面1の各コマから盤面2の各コマについて辺を張る
    V = 1000;
    for(int i = 0; i < V; i++) G[i].clear();
    int from = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++){
	if(board1[i][j] == '.') continue;
	int to = 200;
	for(int k = 0; k < N; k++){
	  for(int l = 0; l < M; l++){
	    if(board2[k][l] == '.') continue;
	    if(board1[i][j] == 'P' && board2[k][l] == 'P') add_edge(from, to, (j == l && k <= i) ? i - k : INF, 1);
	    else if(board1[i][j] == 'N' && board2[k][l] == 'N') add_edge(from, to, d[i * M + j][k * M + l], 1);
	    else if(board1[i][j] == 'N' && board2[k][l] == 'P') add_edge(from, to, INF, 1);
	    else if(board1[i][j] == 'P' && board2[k][l] == 'N') add_edge(from, to, d[j][k * M + l] + i, 1);
	    
	    to++;
	  }
	}
	from++;
      }
    }


    //始点から盤面1の各コマへ、盤面2の各コマから終点に辺を張る
    int s = 500, t = 501;
    int cnt1 = 0;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	if(board1[i][j] != '.') add_edge(s, cnt1++, 0, 1);
    
    int cnt2 = 200;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	if(board2[i][j] != '.') add_edge(cnt2++, t, 0, 1);

    int ans = min_cost_flow(s, t, cnt1);
    return ans >= INF ? -1 : ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...N....",
 "........",
 "........",
 "........",
 "........",
 "........",
 "...P....",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"...N....",
 ".....N..",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"........",
 "........",
 "...P....",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "...P...."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 ".N...P.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 ".....P..",
 ".......N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"N.......",
 "........",
 "N.......",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"........",
 "..N.....",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, transform(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"..N.N...",
 "PPP....N",
 "..N..N..",
 "N...N...",
 "...NNNNN",
 "N.......",
 "...NN...",
 "..N...N."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..N....N",
 "P....N..",
 "..N..N..",
 "N..NNN.N",
 "N.....N.",
 "N.N.....",
 "...NNN..",
 ".....N.N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; verify_case(4, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  SolitaireChess ___test;
  ___test.run_test(-1);
}
// END CUT HERE
