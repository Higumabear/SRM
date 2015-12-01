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

int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int V; // 頂点数
const int MAX_V = 2000;
vector<int> G[MAX_V]; // グラフのリンクリスト表現
int match[MAX_V]; // マッチングのペア
bool used[MAX_V]; // DFSですでに調べたかのフラグ

 // uとvをつなぐ
void add_edge(int u, int v){
  G[u].push_back(v);
  //G[v].push_back(u);
}

// 増加パスをDFSで探す
bool dfs(int v){
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    int u = G[v][i], w =  match[u];
    if(w < 0 || !used[w] && dfs(w)){
      match[v] = u;
      match[u] = v;
      return true;
    }
  }
  return false;
}

// 二部グラフの最大マッチングを求める
int bipartite_matching(){
  int res = 0;
  memset(match, -1, sizeof(match));
  for(int v = 0; v < V; v++){
    if(match[v] < 0){
      memset(used, 0, sizeof(used));
      if(dfs(v)){
        res++;
      }
    }
  }
  return res;
}
class Knights {
public:
  int s2i(string s){
    stringstream ss(s);
    int x; ss >> x; return x;
  }
  int makeFriendly(int N, vector <string> pos){
    vector<vector<bool>> f(N, vector<bool>(N, false));
    V = N * N;
    for(int i = 0; i < MAX_V; i++) G[i].clear();

    for(int i = 0; i < (int)pos.size(); i++){
      stringstream ss(pos[i]);
      string t;
      while(ss >> t){
	int x = s2i(t.substr(1)) - 1;
	int y = t[0] - 'A';
	f[y][x] = true;
      }
    }
    for(int y = 0; y < N; y++){
      for(int x = 0; x < N; x++){
	if(!f[y][x]) continue;
	for(int j = 0; j < 8; j++){
	  int ny = y + dy[j], nx = x + dx[j];
	  if(0 <= ny && ny < N && 0 <= nx && nx < N && f[ny][nx])
	    add_edge(y * N + x, ny * N + nx);
	}
      }
    }
    return bipartite_matching();
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"A2 A4", "B1 B5", "D1 D5 E2 E4 C3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"A1 A2 B1 B2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"A1 A5 B3 C1 C5 D2 D4 E6 F5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = {"A2 A4 A5 A6 B2 B5 B6 B7 B8",
 "C3 C8 D1 D2 D3 D4 D5 D6 D8",
 "E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; string Arr1[] = {"A3 A4 A5 A7 A8 B6 B8 C3 C6",
 "C7 C9 D4 D5 D8 D9 E1 E3 E7",
 "F2 G2 G6 G7 H2 H9 I2 I4 I5",
 "I6 I7 I8 I9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(4, Arg2, makeFriendly(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Knights ___test;
___test.run_test(-1);
}
// END CUT HERE 
