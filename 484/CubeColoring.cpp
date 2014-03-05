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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
static const int INF = 1 << 29;
static const ll LINF = 1LL << 55;

class CubeColoring {
public:
  long long theCount(vector <string> colors) {
    long long result = 0;
    int N = colors[0].length();
    for(int c1 = 0; c1 < N; c1++){
      if(colors[1][c1] == 'N') continue;
      for(int c4 = 0; c4 < N; c4++){
	if(colors[4][c4] == 'N') continue;
	for(int c6 = 0; c6 < N; c6++){
	  if(colors[6][c6] == 'N') continue;

	  ll num5 = 0;
	  for(int c5 = 0; c5 < N; c5++) 
	    if(colors[5][c5] == 'Y' && c5 != c1 && c5 != c4 && c5 != c6) num5++;
	  
	  for(int c3 = 0; c3 < N; c3++){
	    if(colors[3][c3] == 'N') continue;
	    
	    ll num0 = 0, num2 = 0, num7 = 0;
	    for(int c0 = 0; c0 < N; c0++)
	      if(colors[0][c0] == 'Y' && c0 != c1 && c0 != c4 && c0 != c3)
		num0++;
	    for(int c2 = 0; c2 < N; c2++)
	      if(colors[2][c2] == 'Y' && c2 != c1 && c2 != c3 && c2 != c6)
		num2++;
	    for(int c7 = 0; c7 < N; c7++)
	      if(colors[7][c7] == 'Y' && c7 != c3 && c7 != c4 && c7 != c6)
		num7++;

	    result += num0 * num2 * num5 * num7;
	  }
	}
      }
    }
    return result;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"YNNNNNNN", "NYNNNNNN", "NNYNNNNN", "NNNYNNNN", "NNNNYNNN", "NNNNNYNN", "NNNNNNYN", "NNNNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"YNNYN", "YYYYY", "NYYNY", "YNYYN", "YNNYY", "YNNYY", "NNNYY", "NYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 250LL; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"YNNYN", "YYYYY", "NNNNN", "YNYYN", "YNNYY", "YNNYY", "NNNYY", "NYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { string Arr0[] = {"YNNYNYYYYYNN", "NNNYNYYNYNNY", "YYNNYYNNNYYN", "YYYYYNNYYYNN", "NNNYYYNNYNYN", "YYYNYYYYNYNN", "NNNNNNYYNYYN", "NNYNYYNNYNYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 611480LL; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  CubeColoring ___test;
  ___test.run_test(-1);
}
// END CUT HERE
