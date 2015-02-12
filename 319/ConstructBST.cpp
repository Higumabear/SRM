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

ll c[50][50];
int s[50];
set<int> M;
ll R;

class ConstructBST {
public:
  int rec(int node){
    if(M.find(node) == M.end()) return 0;
    int l = rec(2 * node);
    int r = rec(2 * node + 1);
    R *= c[l + r][r];
    return l + r + 1;
  }
  long long numInputs(vector <int> tree){
    memset(c, 0, sizeof(c));
    M.clear();
    for(int i = 0; i < 50; i++)
      for(int j = 0; j <= i; j++)
	c[i][j] = (j == 0) ? 1 : c[i - 1][j - 1] + c[i - 1][j];
    for(int i = 0; i < (int)tree.size(); i++) M.insert(tree[i]);
    R = 1;
    rec(1);
    return R;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, numInputs(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, numInputs(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 5, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(2, Arg1, numInputs(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 4, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(3, Arg1, numInputs(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 4, 3, 62, 7, 15, 1, 31, 5, 14, 28, 57, 56, 114}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 96096LL; verify_case(4, Arg1, numInputs(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ConstructBST ___test;
___test.run_test(-1);
}
// END CUT HERE 
