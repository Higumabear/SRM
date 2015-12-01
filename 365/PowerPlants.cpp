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

int dp[1 << 16];

class PowerPlants {
public:
  int N;
  int np;
  
  vector<vector<int>> C;
  int cost(char s){
    if(s <= '9') return s - '0';
    else return (int)(s - 'A') + 10;
  }

  int rec(int S){
    if(__builtin_popcount(S) >= np) return 0;
    if(dp[S] != -1) return dp[S];

    int ret = INF;
    for(int i = 0; i < N; i++){
      if(S >> i & 1) continue;
      int tmp = INF;
      for(int j = 0; j < N; j++) if(S >> j & 1) tmp = min(tmp, C[j][i]);
      ret = min(ret, rec(S | 1 << i) + tmp);
    }
    return dp[S] = ret;
  }
  
  int minCost(vector <string> connectionCost, string plantList, int numPlants) {
    N = connectionCost.size();
    np = numPlants;
    C.resize(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	C[i][j] = cost(connectionCost[i][j]);

    int st = 0;
    for(int i = 0; i < N; i++)
      if(plantList[i] == 'Y') st |= 1 << i;
    memset(dp, -1, sizeof(dp));
    return rec(st);
  }
   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"024",
 "203",
 "430"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNN"; int Arg2 = 3; int Arg3 = 5; verify_case(0, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0AB",
 "A0C",
 "CD0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNN"; int Arg2 = 3; int Arg3 = 21; verify_case(1, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1ABCD",
 "35HF8",
 "FDM31",
 "AME93",
 "01390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NYNNN"; int Arg2 = 5; int Arg3 = 14; verify_case(2, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"012",
 "123",
 "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NNY"; int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"1309328",
 "DS2389U",
 "92EJFAN",
 "928FJNS",
 "FJS0DJF",
 "9FWJW0E",
 "23JFNFS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YYNYYNY"; int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, minCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"01","20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YN"; int Arg2 = 2; int Arg3 = 1; verify_case(5, Arg3, minCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PowerPlants ___test;
    ___test.run_test(-1);
}
// END CUT HERE
