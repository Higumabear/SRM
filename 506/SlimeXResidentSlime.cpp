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
#include <cstring>
using namespace std;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

class SlimeXResidentSlime {
public:
  int N, M;
  bool inside(int y, int x){return 0 <= y && y < N && 0 <= x && x < M;};
  int exterminate(vector <string> field) {
    map<pair<int, int>, int> num;
    int revive[11]; fill(revive, revive + 11, INF);
    int d[10][10]; 
    for(int i = 0; i < 10; i++) fill(d[i], d[i] + 10, INF);
    N = field.size(), M = field[0].length();

    //スライムが何匹以上いるか調べる
    int cnt = 0;
    for(int i = 0; i < N; i++) 
      for(int j = 0; j < M; j++)
	if(field[i][j] == '$' || isdigit(field[i][j])) cnt++;
    if(cnt > 10) return -1;

    cnt = 0;
    
    //各スライムに順番付けしていく
    for(int i = 0; i < N; i++) 
      for(int j = 0; j < M; j++) 
	if(isdigit(field[i][j])){
	  revive[cnt] = field[i][j] - '0';
	  num[make_pair(i, j)] = cnt++;
	}
    for(int i = 0; i < N; i++) 
      for(int j = 0; j < M; j++)
	if(field[i][j] == '$'){
	  revive[cnt] = INF;
	  num[make_pair(i, j)] = cnt++;
	}

    //各ゴール、スライム間の道のりを幅優先探索で求める
    map<pair<int, int>, int>::iterator it, idx;
    for(it = num.begin(); it != num.end(); it++){
      vector<vector<int> > dist(N, vector<int>(M, INF));
      dist[(it->first).first][(it->first).second] = 0;
      queue<pair<int, int> > Q;
      Q.push(it->first);
      while(!Q.empty()){
	int y = Q.front().first;
	int x = Q.front().second;
	Q.pop();
	for(int i = 0; i < 4; i++){
	  int ny = y + dy[i];
	  int nx = x + dx[i];
	  if(inside(ny, nx) && field[ny][nx] != '#' && dist[ny][nx] == INF){
	    dist[ny][nx] = dist[y][x] + 1;
	    Q.push(make_pair(ny, nx));
	  }
	}
      }
      for(idx = num.begin(); idx != num.end(); idx++)
	d[it->second][idx->second] = d[idx->second][it->second] 
	  = dist[(idx->first).first][(idx->first).second];
    }

    //各順列についてそのような訪れ方が可能か調べ、可能ならターン数の最小値を求める
    int result = INF;
    int turn[11]; for(int i = 0; i < 11; i++) turn[i] = i;
    do{
      bool ok = true;
      int path[11] = {0};
      for(int i = 1; i < cnt; i++){//訪れる順番を逆順に調べていく
	path[i] = path[i - 1] + d[turn[i]][turn[i - 1]];
	if(path[i] >= revive[turn[i]]) ok = false;
      }
      if(ok) result = min(result, path[cnt - 1]);
    }while(next_permutation(turn, turn + cnt - 1));
    return result >= INF ? -1 : result;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = 
{
"#1$",
".2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, exterminate(Arg0)); }
	void test_case_1() { string Arr0[] = {
"$",
"1",
"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, exterminate(Arg0)); }
	void test_case_2() { string Arr0[] = {
"$124"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, exterminate(Arg0)); }
	void test_case_3() { string Arr0[] = {"$.#2"
,"#..1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, exterminate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  SlimeXResidentSlime ___test;
  ___test.run_test(-1);
}
// END CUT HERE
