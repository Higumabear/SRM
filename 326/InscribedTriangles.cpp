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
#define PI 3.141592653589793

using namespace std;
class InscribedTriangles {
public:
  double area(int a, int b, int c){
    double x1 = 5 * cos(a * PI / 180000.0);
    double y1 = 5 * sin(a * PI / 180000.0);
    double x2 = 5 * cos(b * PI / 180000.0);
    double y2 = 5 * sin(b * PI / 180000.0);    
    double x3 = 5 * cos(c * PI / 180000.0);
    double y3 = 5 * sin(c * PI / 180000.0);
    return fabs(x1 * y2 - y1 * x2 + x2 * y3 - y2 * x3 + x3 * y1 - y3 * x1) * 0.5;
  }

  bool check1(int x, vector<int> a, vector<int> b){
    x %= 360000;
    for(int i = 0; i < (int)a.size(); i++)
      if(a[i] <= x && x <= b[i]) return true;
    return false;
  }
  bool check2(int x, vector<int> a, vector<int> b){
    x %= 720000;
    for(int i = 0; i < (int)a.size(); i++)
      if(2 * a[i] <= x && x <= 2 * b[i]) return true;
    return false;
  }
  double solve(int x, int y, vector<int> a, vector<int> b){
    double best = 0;
    if(check2(x + y, a, b)) best = max(best, area(x, y, 0.5 * (x + y)));
    if(check2(x + y + 360000, a, b)) best = max(best, area(x, y, 0.5 * (x + y + 360000)));
    return best;
  }
  double get(int x, vector<int> a, vector<int> b){
    if(check1(x + 120000, a, b) && check1(x + 240000, a, b))
      return area(x, x + 120000, x + 240000);
    return 0.0;
  }
  double findLargest(vector <int> angleFrom, vector <int> angleTo){
    double ans = 0.;
    int N = angleFrom.size();
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	for(int k = 0; k < N; k++){
	  ans = max(ans, area(angleFrom[i], angleFrom[j], angleFrom[k]));
	  ans = max(ans, area(angleFrom[i], angleFrom[j], angleTo[k]));
	  ans = max(ans, area(angleFrom[i], angleTo[j], angleFrom[k]));
	  ans = max(ans, area(angleFrom[i], angleTo[j], angleTo[k]));
	  ans = max(ans, area(angleTo[i], angleFrom[j], angleFrom[k]));
	  ans = max(ans, area(angleTo[i], angleFrom[j], angleTo[k]));
	  ans = max(ans, area(angleTo[i], angleTo[j], angleFrom[k]));
	  ans = max(ans, area(angleTo[i], angleTo[j], angleTo[k]));
	}
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++){
	ans = max(ans, solve(angleFrom[i], angleFrom[j], angleFrom, angleTo));
	ans = max(ans, solve(angleFrom[i], angleTo[j], angleFrom, angleTo));
	ans = max(ans, solve(angleTo[i], angleFrom[j], angleFrom, angleTo));
	ans = max(ans, solve(angleTo[i], angleTo[j], angleFrom, angleTo));
      }

    for(int i = 0; i < N; i++){
      ans = max(ans, get(angleFrom[i], angleFrom, angleTo));
      ans = max(ans, get(angleTo[i], angleFrom, angleTo));
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {360000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 32.47595264191645; verify_case(0, Arg2, findLargest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {15000,25000,100000,265000,330000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15000,25000,100000,265000,330000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 27.433829549752186; verify_case(1, Arg2, findLargest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {245900,246500,249900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {245915,246611,252901}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.002789909594714814; verify_case(2, Arg2, findLargest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(3, Arg2, findLargest(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
InscribedTriangles ___test;
___test.run_test(-1);
}
// END CUT HERE 
