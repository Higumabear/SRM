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
class ImprovingStatistics {
public:
  
  int howManyGames(int played, int won){
    double p = played, w = won;
    int A = (int)(floor(100.0 * w / p));
    if(played == won) return -1;
    if(A == 99) return -1;
    
    int x = 1.0 * (A * p + p - 100 * w) / (99 - A);
    cout << A << " " << x << endl;
    int P = (int)(floor(100.0 * (w + x - 1) / (p + x - 1)));
    int C = (int)(floor(100.0 * (w + x) / (p + x)));
    int N = (int)(floor(100.0 * (w + x + 1) / (p + x + 1)));
    if(P >= A + 1) return x - 1;
    if(C >= A + 1) return x;
    if(N >= A + 1) return x + 1;
    return -1;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 1; verify_case(0, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 80; int Arg2 = 6; verify_case(1, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 47; int Arg2 = -1; verify_case(2, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 99000; int Arg1 = 0; int Arg2 = 1000; verify_case(3, Arg2, howManyGames(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 470000000; int Arg2 = 19230770; verify_case(4, Arg2, howManyGames(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ImprovingStatistics ___test;
___test.run_test(-1);
}
// END CUT HERE 
