#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
static const int INF = 1 << 29;
typedef long long ll;
#define ALL(c) (c).begin(), (c).end()
template<class T> string toString(T x){ostringstream out; out << x; return out.str();}

class BigOEasy {
public:
  string isBounded(vector <string> graph) {
    string result;
    int N = graph.size();
    for(int i = 0; i < N; i++){
      map<int, int> visited;
      vector<vector<bool> > used(N, vector<bool>(N, false));
      for(int j = 0; j < N; j++) visited[j] = 0;
      queue<int> pos;
      pos.push(i);
      while(!pos.empty()){
	int p = pos.front();
	pos.pop();
	for(int j = 0; j < N; j++){
	  if(graph[p][j] == 'Y' && !used[p][j]){
	    visited[j]++;
	    pos.push(j);
	    used[p][j] = true;
	  }
	}
      }
      //for(int j = 0; j < N; j++) if(visited[j] >= 2) return "Unbounded";
      if(visited[i] >= 2) return "Unbounded";
    }
    return "Bounded";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(0, Arg1, isBounded(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYYN",
 "NNNY",
 "NNNY",
 "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(1, Arg1, isBounded(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYN",
 "NNY",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(2, Arg1, isBounded(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYN",
 "YNNN",
 "NNNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(3, Arg1, isBounded(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYY",
 "YNN",
 "YNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(4, Arg1, isBounded(Arg0)); }
	void test_case_5() { string Arr0[] = {"NYNYN",
 "NNYNY",
 "YNNNN",
 "NNNNN",
 "YNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(5, Arg1, isBounded(Arg0)); }
	void test_case_6() { string Arr0[] = {"NYYN",
 "NNYN",
 "NNNY",
 "YNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Unbounded"; verify_case(6, Arg1, isBounded(Arg0)); }
	void test_case_7() { string Arr0[] = {"NYYNNNNYNNYNYNNNNYYNNYNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYNYYYYYNYYN",
 "YYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNNNYYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYYYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNYNNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYYYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNYYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYYNNNNNNYYNYNNNN",
 "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYNNYYNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYYNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYYYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNYYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNYNNNNNNNNNNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYYYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYYNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNYNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "YYYNYNNYNNYYYYNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYY",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNYNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYYYYYYYNYYN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNYNN",
 "NYYNNNNYNNYYYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNYNNNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNYNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYNYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNYNNYYNYNNNN",
 "NYYNNNNYNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNYYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYNNNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYYNNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNYNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNYYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYYYYN",
 "NYYNYNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NYYNNNNNNNYNYNNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYNYNYNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYYYNYYN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNYNNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYNN",
 "YYYNYYYYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bounded"; verify_case(7, Arg1, isBounded(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
BigOEasy ___test;
___test.run_test(-1);
}
// END CUT HERE 
