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
class GooseInZooDivOne {
public:
  vector<vector<int> > cocoa(vector<string> field, char c, int dist){
    int N = field.size(), M = field[0].length();
    vector<vector<int> > la(N, vector<int>(M, -1));

    int cnt = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
	if(la[i][j] != -1 || field[i][j] != c) continue;
	queue<pair<int, int> > Q;
	Q.push(make_pair(i, j));
	la[i][j] = cnt;
	while(!Q.empty()){
	  int y = Q.front().first;
	  int x = Q.front().second;
	  Q.pop();
	  for(int dy = -dist; dy <= dist; dy++){
	    for(int dx = -dist; dx <= dist; dx++){
	      if(!(0 <= dy + y && dy + y < N && 0 <= dx + x && dx + x < M)) continue;
	      if(abs(dy) + abs(dx) <= dist && la[dy + y][dx + x] == -1 && field[dy + y][dx + x] == c){
		Q.push(make_pair(dy + y, dx + x));
		la[dy + y][dx + x] = cnt;
	      }
	    }
	  }
	}
	cnt++;
      }
    }
    return la;
  }

  int count(vector <string> field, int dist){
    vector<vector<int> > pond(field.size(), vector<int>(field[0].size(), -1));
    pond = cocoa(field, 'v', dist);

    map<int, int> label;
    for(int i = 0; i < (int)pond.size(); i++)
      for(int j = 0; j < (int)pond[0].size(); j++)
	label[pond[i][j]]++;

    map<int, int>::iterator it = label.begin();

    int num[2] = {0, 0};
    for(;  it != label.end(); it++) 
      if(it->first != -1) num[(it->second) % 2]++;
    
    int ans = 1;
    for(int i = 0; i < num[0]; i++)
      ans = (ans * 2) % 1000000007;
    for(int i = 0; i < num[1] - 1; i++)
      ans = (ans * 2) % 1000000007;
    return ans - 1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 898961330; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
GooseInZooDivOne ___test;
___test.run_test(-1);
}
// END CUT HERE 
