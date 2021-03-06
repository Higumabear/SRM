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



class Survived {
public:
  double minTime(int x, int y, int V, int U){
    int A = U * U - V * V, B = -2 * U * x, C = x * x + y * y;
    cout << A << " " << B << " " << C << endl;
    if(A < 0) A *= -1, B *= -1, C *= -1;
    if(A == 0){
      if(B == 0) return C == 0 ? 0 : -1;
      else return (B * C <= 0) ? -C * 1.0 / B : -1;
    }else{
      int D = B * B - 4 * A * C;
      if(D < 0) return -1;
      
      double t1 = (-B + sqrt(D)) * 0.5 / A;
      double t2 = (-B - sqrt(D)) * 0.5 / A;
      if(t2 >= 0.0) return t2;
      if(t1 >= 0.0) return t1;
      return -1;
    }
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = -1; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; double Arg4 = 1.4142135623730951; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; double Arg4 = 2.0593413823019864; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; double Arg4 = 0.0; verify_case(4, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 12; int Arg2 = 24; int Arg3 = 26; double Arg4 = 1.3; verify_case(5, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Survived ___test;
___test.run_test(-1);
}
// END CUT HERE 
