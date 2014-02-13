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
  string div50(int a, int b){ /* a / b */
    string ret;
    int t = a;
    for(int i = 0; i < 51; i++){
      if(i == 0) ret += "0.";
      else{
	t *= 10;
	ret += (t / b + '0');
	t %= b; 
      }
    }
    return ret;
  }
  string findFraction(int maxDen, string number) {
    string result;
    int nu, de;
    int l = 0;

    for(int i = 1; i <= maxDen; i++){
      for(int j = 0; j < maxDen; j++){
	int k;
	string d = div50(j, i);
	for(k = 0; k < (int)number.length(); k++)
	  if(number[k] != d[k]) break;
	
	if(l < k){
	  l = k;
	  nu = j; de = i;
	}
      }
    }
    cout << nu << "/" << de << " " << l - 1 << endl;
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
  //___test.run_test(-1);
  ___test.run_test(1);
  ___test.run_test(3);
  ___test.run_test(4);
  ___test.run_test(5);
}
// END CUT HERE
