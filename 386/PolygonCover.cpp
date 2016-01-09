#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-9
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

double dp[1 << 15];

class PolygonCover {
public:
  int N;
  vector<int> X, Y;
  double area(int i, int j, int k){
    double vy = Y[i] - Y[j], vx = X[i] - X[j];
    double uy = Y[i] - Y[k], ux = X[i] - X[k];
    return 0.5 * fabs(vx * uy - vy * ux);
  }
  double rec(int S){
    if(S == (1 << N) - 1) return 0.0;
    if(dp[S] > EPS) return dp[S];

    double ret = 1e100;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	for(int k = 0; k < N; k++){
	  if((S >> i & 1) && (S >> j & 1) && (S >> k & 1)) continue;
	  if(i == j || j == k || k == i) continue;
	  ret = min(ret, area(i, j, k) + rec(S | 1 << i | 1 << j | 1 << k));
	}
      }
    }
    bitset<10> b(S);
    //cout << b << " " << ret << endl;
    return dp[S] = ret;
  }
  double getArea(vector <int> x, vector <int> y) {
    N = x.size();
    memset(dp, -1, sizeof(dp));
    X = x, Y = y;
    return rec(0);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,10,0,-10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,0,10,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 200.0; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,2,-2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,0,2,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,0,-2,-1,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,0,-2,-2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.0; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,0,-4,0,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,0,-4,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PolygonCover ___test;
    ___test.run_test(-1);
}
// END CUT HERE
