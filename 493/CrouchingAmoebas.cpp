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
#include <cstring>
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
static const int INF = 1 << 29;
static const ll LINF = 1LL << 55;

class CrouchingAmoebas {  
public:
  vector<int> xx, yy;
  int TT;
  ll labs(ll a){return a > 0 ? a : -a;}
  int mvAmoeba(ll y0, ll x0, ll y1, ll x1){
    vector<ll> d;
    for(int i = 0; i < (int)xx.size(); i++){
      if(x0 <= xx[i] && xx[i] <= x1 && y0 <= yy[i] && yy[i] <= y1) 
	d.push_back(0);
      else{
	if(x0 <= xx[i] && xx[i] <= x1) 
	  d.push_back(min(labs(yy[i] - y0), labs(yy[i] - y1)));
	else if(y0 <= yy[i] && yy[i] <= y1)
	  d.push_back(min(labs(xx[i] - x0), labs(xx[i] - x1)));
	else{
	  ll a[4];
	  a[0] = labs(xx[i] - x0) + labs(yy[i] - y0);
	  a[1] = labs(xx[i] - x0) + labs(yy[i] - y1);
	  a[2] = labs(xx[i] - x1) + labs(yy[i] - y0);
	  a[3] = labs(xx[i] - x1) + labs(yy[i] - y1);
	  d.push_back(*min_element(a, a + 4));
	}
      }
    }
    sort(ALL(d));
    
    ll sum = 0;
    int j;
    for(j = 0; j < (int)d.size(); j++){
      sum += d[j];
      if(sum > TT) break;
    }
    //cout << j << endl;
    return j;
  }
  int count(vector <int> x, vector <int> y, int A, int T) {
    int res = 0;
    int N = x.size();
    xx = x; yy = y;
    TT = T;
    // for(int i = 0; i < N; i++){
    //   int a, b, c, d;
    //   a = mvAmoeba(y[i] - A, x[i] - A, y[i], x[i]);
    //   b = mvAmoeba(y[i] - A, x[i], y[i], x[i] + A);
    //   c = mvAmoeba(y[i], x[i] - A, y[i] + A, x[i]);
    //   d = mvAmoeba(y[i], x[i], y[i] + A, x[i] + A);
    //   res = max(res, max(a, max(b, max(c, d))));
    //   // cout << a << " " << b << " " << c << " " << d << endl;
    //   // for(int Y = -T; Y < T; Y++){
    //   // 	for(int X = -T; X < T; X++){
    //   // 	  res = max(res, mvAmoeba(y[i] + Y, x[i] + X, y[i] + Y + A, x[i] + X + A));
    //   // 	}
    //   // }
    // }
    for ( int a1=0; a1<N; a1++ )
      for ( long long sx=x[a1]-T; sx<=x[a1]+T; sx++ )
	for ( int a2=0; a2<N; a2++ )
	  for ( long long sy=y[a2]-T; sy<=y[a2]+T; sy++ )
	    res = max(res, mvAmoeba(sy, sx, sy + A, sx + A));
    return res;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; int Arg4 = 3; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,0,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,3,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; int Arg4 = 4; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {-1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000000000,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 15; int Arg4 = 1; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  CrouchingAmoebas ___test; 
  ___test.run_test(-1);
}
// END CUT HERE
