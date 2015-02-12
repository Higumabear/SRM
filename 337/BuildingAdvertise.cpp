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
class BuildingAdvertise {
public:
  long long getMaxArea(vector <int> h, int n){
    stack<pair<ll, ll>> R;
    int j = 0;

    ll ans = 0;
    for(int i = 0; i <= n; i++){
      if(i == n) h[j] = 0;
      if(R.empty()) R.push(make_pair(h[j], i));
      else{
	if(R.top().first < h[j]) R.push(make_pair(h[j], i));
	else if(R.top().first > h[j]){
	  int p = i;
	  while(!R.empty() && R.top().first > h[j]){
	    ans = max(ans, R.top().first * (i - R.top().second));
	    p = R.top().second;
	    R.pop();
	  }
	  R.push(make_pair(h[j], p));
	}
      }
      h[j] = ((h[j] ^ h[(j + 1) % h.size()]) + 13) % 835454957;
      j = (j + 1) % h.size();
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,6,5,6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 15LL; verify_case(0, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,0,7,0,2,6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; long long Arg2 = 7LL; verify_case(1, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1048589,2097165}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; long long Arg2 = 104858900000LL; verify_case(2, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,7,2,5,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 8LL; verify_case(3, Arg2, getMaxArea(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BuildingAdvertise ___test;
___test.run_test(-1);
}
// END CUT HERE 
