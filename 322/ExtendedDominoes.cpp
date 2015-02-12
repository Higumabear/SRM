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
class ExtendedDominoes {
public:
  long long countCycles(vector <string> pieces){
    int N = pieces.size();
    int deg[15] = {0};
    ll ans = 1;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < 2; j++) deg[pieces[i][j] - '0']++;
    for(int i = 0; i < 10; i++){
      if(deg[i] % 2 == 1) return 0;
      for(int j = 1; j < deg[i]; j+= 2) ans *= j;
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12","25","45","24","28","18"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(0, Arg1, countCycles(Arg0)); }
	void test_case_1() { string Arr0[] = {"01","12","23","34","45"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, countCycles(Arg0)); }
	void test_case_2() { string Arr0[] = {"09","12","24","14","57","79","05"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(2, Arg1, countCycles(Arg0)); }
	void test_case_3() { string Arr0[] = {"34","35","36","37","45","46","47","56","57","67"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 243LL; verify_case(3, Arg1, countCycles(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ExtendedDominoes ___test;
___test.run_test(-1);
}
// END CUT HERE 
