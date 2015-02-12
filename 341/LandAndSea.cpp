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

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;
class LandAndSea {
public:
  vector <int> howManyIslands(vector <string> seaMap){
    int N = seaMap.size(), M = seaMap[0].length();
    vector<vector<int>> vis(N, vector<int>(M, 0));
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(seaMap[i][j] == '.' || vis[i][j] > 0) continue;
	cnt++;
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));
	vis[i][j] = cnt;
	while(!Q.empty()){
	  int y = Q.front().first, x = Q.front().second;
	  Q.pop();
	  for(int k = 0; k < 8; k++){
	    int ny = y + dy[k], nx = x + dx[k];
	    if(0 <= nx && nx < M && 0 <= ny && ny < N && 
	       seaMap[ny][nx] == 'x' && vis[ny][nx] == 0){
	      Q.push(make_pair(ny, nx));
	      vis[ny][nx] = cnt;
	    }
	  }
	}
      }
    }
    vector<bool> f(cnt + 1, false);
    vector<int> g[cnt];
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(vis[i][j] == 0 || f[vis[i][j]]) continue;
	int label = vis[i][j];
	f[label] = true;
	queue<pair<int, int>> Q;
	Q.push(make_pair(i, j));
	int parent = -1;
	while(!Q.empty()){
	  int y = Q.front().first, x = Q.front().second;
	  Q.pop();
	  for(int k = 0; k < 8; k += 2){
	    int ny = y + dy[k], nx = x + dx[k];
	    if(!(0 <= nx && nx < M && 0 <= ny && ny < N)) goto L1;
	    if(vis[i][j] == 0 || vis[i][j] == label) 
	      Q.push(make_pair(ny, nx));
	    else
	      parent = vis[i][j];
	  }
	}

      L1:;
      }
    }

    return vector<int>();
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"x"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, howManyIslands(Arg0)); }
	void test_case_1() { string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, howManyIslands(Arg0)); }
	void test_case_2() { string Arr0[] = {
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx",
"xxxxx",
"x...x",
"x.x.x",
"x...x",
"xxxxx"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, howManyIslands(Arg0)); }
	void test_case_3() { string Arr0[] = {
"..",
".."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, howManyIslands(Arg0)); }
	void test_case_4() { string Arr0[] = {
"............",
".......xxxx.",
"..xxx.x...x.",
"..x..x..x.x.",
"..x.x.x...x.",
"..xx...xxx.."
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, howManyIslands(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LandAndSea ___test;
___test.run_test(-1);
}
// END CUT HERE 
