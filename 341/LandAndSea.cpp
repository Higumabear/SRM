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
#define ABS(a) ((a) < 0 ? - (a) : (a))
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int label[60][60];

class LandAndSea {
public:
  int N, M;
  int num;
  vector <string> f;
  vector<int> G[1000];

  void dfs(int y, int x, char c, int num){
    label[y][x] = num;
    for(int i = 0; i < ((c == 'x') ? 8 : 4); i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(0 <= ny && ny < N && 0 <= nx && nx < M && 
	 label[ny][nx] == -1 && f[ny][nx] == c) dfs(ny, nx, c, num);
    }
  }
  void cca(){
    num = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(label[i][j] != -1) continue;
	dfs(i, j, f[i][j], num++);
      }
    }
  }
  vector <int> howManyIslands(vector <string> seaMap) {
    f.clear();
    N = seaMap.size() + 2, M = seaMap[0].length() + 2;
    for(int i = 0; i < N; i++){
      if(i == 0 || i == N - 1) f.push_back(string(M, '.'));
      else f.push_back("." + seaMap[i - 1] + ".");
    }
    memset(label, -1, sizeof(label));
    cca();
    
    map<int, int> ant;
    for(int i = 0; i < num; i++) ant[i] = INF;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	for(int k = 0; k < 4; k++){
	  int ny = i + dy[k], nx = j + dx[k];
	  if(0 <= ny && ny < N && 0 <= nx && nx < M)
	    ant[label[i][j]] = min(ant[label[i][j]], label[ny][nx]);
	}
	cout << label[i][j];
      }
      cout << endl;
    }

    for(int i = 0; i < num; i++)
      if(i != ant[i]) G[ant[i]].push_back(i);
    for(int i = 0; i < num; i++){
      cout << i << " : ";
      for(int j = 0; j < (int)G[i].size(); j++) cout << G[i][j] << " ";
      cout << endl;
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
