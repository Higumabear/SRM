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
class LCMSet {
public:
  ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a % b); }  
  ll lcm(ll a, ll b){ return a * b / gcd(a, b); }
  bool good(vector<int> A, vector<int> B){
    int N = A.size();
    for(int i = 0; i < N; i++){
      int t = 1;
      for(int j = 0; j < (int)B.size(); j++)
	if(A[i] % B[j] == 0) t = lcm(t, B[j]);
      if(t < A[i]) return false;
    }
    return true;
  }
  string equal(vector <int> A, vector <int> B){
    return good(A, B) && good(B, A) ? "Equal" : "Not equal";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,4,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(0, Arg2, equal(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not equal"; verify_case(1, Arg2, equal(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,3,5,7,14,105}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,6,7,30,35}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(2, Arg2, equal(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,5,7,14,105}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,6,7,30,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not equal"; verify_case(3, Arg2, equal(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(4, Arg2, equal(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {999999999,1953125,512,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999999999,1953125,512}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(5, Arg2, equal(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {999999998,999999999,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999999999,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not equal"; verify_case(6, Arg2, equal(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LCMSet ___test;
___test.run_test(-1);
}
// END CUT HERE 
