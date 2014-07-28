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
class ExtraordinarilyLarge {
public:
  string compare(string x, string y){
    int N = min(count(ALL(x), '!'), count(ALL(y), '!'));
    stringstream a(x), b(y);
    int aa, bb; a >> aa; b >> bb;
    if(aa <= 1 && bb <= 1 && N) return "x=y";
    x = x.substr(0, x.length() - N); y = y.substr(0, y.length() - N);

    bool sw = count(ALL(y), '!') > 0;
    if(sw) swap(x, y);

    stringstream ss(x);
    stringstream sss(y);
    cout << x << " " << y << endl;
    ll d; ss >> d;
    ll e; sss >> e;

    ll p = d;
    bool great = p > e;
    if(d == 0 && count(ALL(x), '!')){
      p = 1; great = p > e; goto L1;
    }

    for(int i = 0; i < count(ALL(x), '!'); i++){
      ll tmp = 1;
      for(ll t = p; t > 0; t--){
	tmp *= t;
	if(tmp > e){
	  great = true;
	  goto L1;
	}
	p = tmp;
      }
    }
  L1:;
    dump(great); dump(sw);
    dump(p); dump(e);
    if(p == e && !great) return "x=y";
    if(great && sw){
      return "x<y";
    }
    if(!great && sw){
      return "x>y";
    }

    if(great && !sw){
      return "x>y";
    }

    if(!great && !sw){
      return "x<y";
    }
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0!"; string Arg1 = "1"; string Arg2 = "x=y"; verify_case(0, Arg2, compare(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "9!"; string Arg1 = "999999999"; string Arg2 = "x<y"; verify_case(1, Arg2, compare(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "9!!"; string Arg1 = "999999999"; string Arg2 = "x>y"; verify_case(2, Arg2, compare(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "456!!!"; string Arg1 = "123!!!!!!"; string Arg2 = "x<y"; verify_case(3, Arg2, compare(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "5!"; string Arg1 = "120"; string Arg2 = "x=y"; verify_case(4, Arg2, compare(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ExtraordinarilyLarge ___test;
___test.run_test(-1);
}
// END CUT HERE 
