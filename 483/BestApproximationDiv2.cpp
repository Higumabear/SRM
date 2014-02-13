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
using namespace std;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

class BestApproximationDiv2 {
public:
  double stoi(string s){
    stringstream ss;
    ss << s;
    double a;
    ss >> a;
    return a;
  }

  /* int to string */
  string itos(int a){
    stringstream ss;
    ss << a;
    return ss.str();
  }

  char strA[60];

  void divStr(ll a, ll b, int n){
    int i;
    for(i = 0; i < n ; i++){
      strA[i] = '0' + a / b;
      a %= b;
      a *= 10;
    }
    strA[i] = '\0';
    return;
  }
  string findFraction(int maxDen, string number) {
    string result;
    double C = stoi(number);
    string num;
    for(int i = 0; i < (int)number.length(); i++) 
      if(number[i] != '.') num += number[i];
    
    int coins = 0;
    for(ll B = 1; B <= maxDen; B++){
      ll tmp = B * C;
      for(ll candA = max(0LL, tmp - 2); candA <= tmp + 2 && candA < B; candA++){
	int cnt = 0;
	divStr(candA, B, 50);
	for(; cnt < (int)num.length() && strA[cnt] != '\0' && num[cnt] == strA[cnt]; cnt++);
	
	if(coins < cnt){
	  coins = cnt;
	  result = itos(candA) + "/" + itos(B) + " has " + itos(cnt) 
	    + " exact digits";
	}
      }
    }
    return result;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 42; string Arg1 = "0.141592658"; string Arg2 = "1/7 has 3 exact digits"; verify_case(0, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; string Arg1 = "0.1337"; string Arg2 = "0/1 has 1 exact digits"; verify_case(1, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 80000; string Arg1 = "0.1234567891011121314151617181920"; string Arg2 = "10/81 has 8 exact digits"; verify_case(2, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; string Arg1 = "0.42"; string Arg2 = "3/7 has 3 exact digits"; verify_case(3, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; string Arg1 = "0.420"; string Arg2 = "21/50 has 4 exact digits"; verify_case(4, Arg2, findFraction(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 115; string Arg1 = "0.141592658"; string Arg2 = "16/113 has 7 exact digits"; verify_case(5, Arg2, findFraction(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  BestApproximationDiv2 ___test;
  ___test.run_test(-1);
  //___test.run_test(0);
}
// END CUT HERE
