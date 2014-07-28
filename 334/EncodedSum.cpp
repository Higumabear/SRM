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
class EncodedSum {
public:
  long long maximumSum(vector <string> numbers){
    vector<int> d;
    for(int i = 0; i < 10; i++) d.push_back(i);
    ll tb[11] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000LL,10000000000LL,100000000000LL};
    vector<ll> a(10, 0);
    vector<bool> b(10, true);
    for(int i = 0; i < (int)numbers.size(); i++){
      b[numbers[i][0] - 'A'] = false;
      for(int j = 0; j < (int)numbers[i].size(); j++)
	a[numbers[i][j] - 'A'] += tb[numbers[i].size() - j - 1];
    }

    ll ret = -1;
    do{
      if(!b[d[0]]) continue;
      ll s = 0;
      for(int i = 0; i < 10; i++) s += a[d[i]] * i;
      ret = max(ret, s);
    }while(next_permutation(ALL(d)));
    return ret;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC",
 "BCA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1875LL; verify_case(0, Arg1, maximumSum(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABCDEFGHIJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9876543210LL; verify_case(1, Arg1, maximumSum(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABCDEFGHIJ", 
 "J"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9876543202LL; verify_case(2, Arg1, maximumSum(Arg0)); }
	void test_case_3() { string Arr0[] = {"A", 
 "BB", 
 "CCC", 
 "DDDD", 
 "EEEEE", 
 "FFFFFF", 
 "GGGGGGG", 
 "HHHHHHHH", 
 "IIIIIIIII", 
 "AJJJJJJJJJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9973936905LL; verify_case(3, Arg1, maximumSum(Arg0)); }
	void test_case_4() { string Arr0[] = {"GHJIDDD",
 "AHHCCCA",
 "IIJCEJ",
 "F",
 "HDBIGFJAAJ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9888114550LL; verify_case(4, Arg1, maximumSum(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
EncodedSum ___test;
___test.run_test(-1);
}
// END CUT HERE 
