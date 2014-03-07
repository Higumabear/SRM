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


class KingdomXCitiesandVillagesAnother {
public:
  double prim(vector<vector<double> > dist){
    int N = dist.size();
    vector<bool> used(N, false);
    double ret = 0;
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > Q;
    Q.push(make_pair(0, 0));
    while(!Q.empty()){
      double cost = Q.top().first;
      int to = Q.top().second;
      Q.pop();
      if(used[to]) continue;
      used[to] = true;
      ret += cost;
      for(int i = 0; i < N; i++) Q.push(make_pair(dist[to][i], i));
    }
    return ret;
  }

  double euc(ll a, ll b){
    ll dx = (ll)a * a + b * b;
    return sqrt((double)dx); 
  }
  double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
    int N = cityX.size();
    int M = villageX.size();
    vector<vector<double> > d(N + M, vector<double>(N + M, 0));
    for(int i = 0; i < N; i++) 
      for(int j = 0; j < N; j++)
	d[i][j] = d[j][i] = 0.0;
    for(int i = 0; i < N; i++) 
      for(int j = 0; j < M; j++)
	d[i][j + N] = d[j + N][i] = euc(cityX[i] - villageX[j], cityY[i] - villageY[j]);
    for(int i = 0; i < M; i++) 
      for(int j = 0; j < M; j++)
	d[i + N][j + N] = d[j + N][i + N] = euc(villageX[i] - villageX[j], villageY[i] - villageY[j]);
    return prim(d);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.8284271247461903; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  KingdomXCitiesandVillagesAnother ___test;
  ___test.run_test(-1);
}
// END CUT HERE
