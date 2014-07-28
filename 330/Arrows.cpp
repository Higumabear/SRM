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
class Arrows {
public:
  string con(char c, int n){
    string ret;
    for(int i = 0; i < n; i++) ret += c;
    return ret;
  }
  int longestArrow(string s){
    int L = s.length();
    int ans = -1;
    for(int i = 1; i <= L; i++){
      string a = "<" + con('-', i - 1);
      string b = "<" + con('=', i - 1);
      string c = con('-', i - 1) + ">";
      string d = con('=', i - 1) + ">";
      if(s.find(a, 0) != string::npos) ans = max(ans, (int)a.length());
      if(s.find(b, 0) != string::npos) ans = max(ans, (int)b.length());
      if(s.find(c, 0) != string::npos) ans = max(ans, (int)c.length());
      if(s.find(d, 0) != string::npos) ans = max(ans, (int)d.length());
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "<--->--==>"; int Arg1 = 4; verify_case(0, Arg1, longestArrow(Arg0)); }
	void test_case_1() { string Arg0 = "<<<<<<<<<<"; int Arg1 = 1; verify_case(1, Arg1, longestArrow(Arg0)); }
	void test_case_2() { string Arg0 = "----==-"; int Arg1 = -1; verify_case(2, Arg1, longestArrow(Arg0)); }
	void test_case_3() { string Arg0 = "<----=====>"; int Arg1 = 6; verify_case(3, Arg1, longestArrow(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Arrows ___test;
___test.run_test(-1);
}
// END CUT HERE 
