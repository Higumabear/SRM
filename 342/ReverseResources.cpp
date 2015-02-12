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

int N;
vector<string> res;
string s;
ll memo[31][31][51][51];
const ll MOD = 1000000007LL;

class ReverseResources {
public:
  ll rec(int lo, int hi, int id, int start){
    ll &ret = memo[lo][hi][id][start];
    if(ret != -1) return ret;
    if(lo > hi) return ret = 0;
    if(id == N){
      ret = 0;
      for(int i = 0; i < N; i++) ret = (ret + rec(lo, hi, i, 0)) % MOD;
      return ret;
    }
    if(res[id][start] == '%'){
      if(start + 2 == (int)res[id].length()) return ret = rec(lo, hi, N, 0);
      ret = 0;
      for(int fin = lo; fin < hi; fin++)
	ret = (ret + rec(lo, fin, N, 0) * 
	       rec(fin + 1, hi, id, start + 2)) % MOD;
      return ret;
    }
    if(s[lo] != res[id][start]) return ret = 0;
    return ret = (lo == hi && start + 1 == res[id].length()) ? 
      1 : rec(lo + 1, hi, id, start + 1);
  }
  int findDecompositions(string str, vector <string> resources){
    s = str;
    res = resources;
    N = resources.size();
    memset(memo, -1, sizeof(memo));
    return rec(0, str.length() - 1, N, 0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "Error in module foo, code 123."; string Arr1[] = {"foo", "123", "Error in module %s.", "%s, code %s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "The fox jumped over the dog."; string Arr1[] = {"The fox %s over the dog.",
 "lazy",
 "brown",
 "jump%s",
 "s",
 "ed",
 "The %s",
 "fox %s",
 "%s over %s",
 "the dog."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "abcde"; string Arr1[] = {"%sc%s", "b", "de", "a%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abcde"; string Arr1[] = {"%se", "a%s", "%sb%s", "%sc%s", "%sd%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arr1[] = {"a","%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; string Arr1[] = {"a","aa","%s%s","%sa","a%s","aaa","aa%s","a%sa",
"a%s%s","%saa","%sa%s","%s%sa","%s%s%s","aaaa",
"aaa%s","aa%sa","aa%s%s","a%saa","a%sa%s","a%s%sa",
"a%s%s%s","%saaa","%saa%s","%sa%sa","%sa%s%s",
"%s%saa","%s%sa%s","%s%s%sa","%s%s%s%s","aaaaa",
"aaaa%s","aaa%sa","aaa%s%s","aa%saa","aa%sa%s",
"aa%s%sa","aa%s%s%s","a%saaa","a%saa%s","a%sa%sa",
"a%sa%s%s","a%s%saa","a%s%sa%s","a%s%s%sa",
"a%s%s%s%s","%saaaa","%saaa%s","%saa%sa","%saa%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 879704799; verify_case(5, Arg2, findDecompositions(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "aa"; string Arr1[] = {"a", "a", "%s%s", "%s%s"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(6, Arg2, findDecompositions(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
ReverseResources ___test;
___test.run_test(-1);
}
// END CUT HERE 
