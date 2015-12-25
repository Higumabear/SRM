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

int dp[11][1 << 10];

class FloorBoards {
public:
  int H, W;
  int addline(int prev, int now, int field){
    int res = 0;
    bool flag = false;
    for(int i = 0; i < W; i++){
      if(now >> i & 1){
	if(!(prev >> i & 1)) res++;
	flag = false;
      }else{
	if(field >> i & 1) flag = false;
	else{
	  if(!flag) res++;
	  flag = true;
	}
      }
    }
    return res;
  }
  int layout(vector <string> room) {
    H = room.size(), W = room[0].size();
    for(int i = 0; i < 1 << 10; i++)
      for(int j = 0; j < 11; j++) dp[j][i] = INF;
    dp[0][0] = 0;
    
    for(int i = 0; i < H; i++){
      int row = 0;
      for(int j = 0; j < W; j++) if(room[i][j] == '#') row += (1 << j);
      for(int j = 0; j < 1 << W; j++){
	if(dp[i][j] == INF) continue;
	for(int k = 0; k < 1 << W; k++){
	  if((row & k) != 0) continue;
	  dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + addline(j, k, row));
	}
      }
    }
    int res = INF;
    for(int k = 0; k < 1 << W; k++) res = min(res, dp[H][k]);
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....."
,"....."
,"....."
,"....."
,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, layout(Arg0)); }
	void test_case_1() { string Arr0[] = {"......."
,".#..##."
,".#....."
,".#####."
,".##..#."
,"....###"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, layout(Arg0)); }
	void test_case_2() { string Arr0[] = {"####"
,"####"
,"####"
,"####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, layout(Arg0)); }
	void test_case_3() { string Arr0[] = {"...#.."
,"##...."
,"#.#..."
,".#...."
,"..#..."
,"..#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, layout(Arg0)); }
	void test_case_4() { string Arr0[] = {".#...."
,"..#..."
,".....#"
,"..##.."
,"......"
,".#..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, layout(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FloorBoards ___test;
    ___test.run_test(-1);
}
// END CUT HERE
