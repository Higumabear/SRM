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
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

ll T[250010];

class FloatingMedian {
public:
  long long sumOfMedians(int seed, int mul, int add, int N, int K){
    T[0] = seed;
    for(int i = 1; i < N; i++)
      T[i] = (T[i - 1] * mul + add) % 65536;
    
    set<pair<ll, int>> s;
    for(int i = 0; i < K; i++) s.insert(make_pair(T[i], i));
    auto it = s.begin();
    advance(it, (K - 1) / 2);

    ll ans = it->first;
    for(int i = K; i < N; i++){
      s.insert(make_pair(T[i], i));
      if(make_pair(T[i], i) <= *it) it--;
      if(make_pair(T[i - K], i - K) <= *it) it++;
      s.erase(make_pair(T[i - K], i - K));
      ans += it->first;
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 10; int Arg4 = 3; long long Arg5 = 60LL; verify_case(0, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 13; int Arg3 = 5; int Arg4 = 2; long long Arg5 = 49LL; verify_case(1, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4123; int Arg1 = 2341; int Arg2 = 1231; int Arg3 = 7; int Arg4 = 3; long long Arg5 = 102186LL; verify_case(2, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 5621; int Arg2 = 1; int Arg3 = 125000; int Arg4 = 1700; long long Arg5 = 4040137193LL; verify_case(3, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 32321; int Arg1 = 46543; int Arg2 = 32552; int Arg3 = 17; int Arg4 = 17; long long Arg5 = 25569LL; verify_case(4, Arg5, sumOfMedians(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
FloatingMedian ___test;
___test.run_test(-1);
}
// END CUT HERE 
