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
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

const int MAX_V = 100000;

int V; // 頂点数
vector<int> G[MAX_V]; // グラフの隣接リスト
vector<int> rG[MAX_V];// 逆グラフの隣接リスト
vector<int> vs; // 帰りがけの順番の並び
bool used[MAX_V];
int cmp[MAX_V];

void scc_init(){
  for(int i = 0; i < MAX_V; i++){
    G[i].clear();
    rG[i].clear();
    used[i] = false;
    cmp[i] = INF;
  }
  vs.clear();
}

void add_edge(int from, int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    if(!used[G[v][i]]) dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v, int k){
  used[v] = true;
  cmp[v] = k;
  for(int i = 0; i < rG[v].size(); i++){
    if(!used[rG[v][i]]) rdfs(rG[v][i], k);
  }
}


int scc(){
  memset(used, 0, sizeof(used));
  vs.clear();
  for(int v = 0; v < V; v++){
    if(!used[v]) dfs(v);
  }
  
  memset(used, 0, sizeof(used));
  int k = 0;
  for(int i = vs.size() - 1; i >= 0; i--){
    if(!used[vs[i]]) rdfs(vs[i], k++);
  }
  return k;
}

class AntarcticaPolice {
public:
  int N;
  double minAverageCost(vector <int> costs, vector <string> roads){
    V = costs.size();
    for(int i = 0; i < V; i++) G[i].clear(), rG[i].clear();
    for(int i = 0; i < V; i++)
      for(int j = 0; j < V; j++) 
	if(roads[i][j] == 'Y') add_edge(i, j);
    int k = scc(), deg[50] = {};
    bool e[50][50] = {};
    for(int i = 0; i < V; i++)
      for(int j = 0; j < V; j++)
	if(roads[i][j] == 'Y') e[cmp[i]][cmp[j]] = true;
    for(int i = 0; i < k; i++)
      for(int j = 0; j < k; j++)
	if(i != j && e[i][j]) deg[j]++;

    bool use[50] = {};
    int sum = 0, m = 0;
    for(int i = 0; i < k; i++){
      if(deg[i] != 0) continue;
      int mni = -1;
      for(int j = 0; j < V; j++)
	if(cmp[j] == i && (mni < 0 || costs[j] < costs[mni]))
	  mni = j;
      use[mni] = 1;
      sum += costs[mni];
      m++;
    }
    vector<int> v;
    for(int i = 0; i < V; i++) if(!use[i]) v.push_back(costs[i]);
    sort(ALL(v));
    for(int i = 1; i < (int)v.size(); i++) v[i] += v[i - 1];
    double ans = 1.0 * sum / m;
    for(int i = 0; i < (int)v.size(); i++) 
      ans = min(ans, 1.0 * (sum + v[i]) / (m + i + 1));
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","NNYN","NNNY","YNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","NNYN","NNNY","NYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","YNNN","NNNY", "NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(2, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.5; verify_case(3, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {34,22,25,43,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNY","YNNYN","NNNYY","NNNNN","NNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 19.666666666666668; verify_case(4, Arg2, minAverageCost(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
AntarcticaPolice ___test;
___test.run_test(-1);
}
// END CUT HERE 
