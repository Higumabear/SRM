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

class RestoringPolygon {
public:
  int N;
  int restore(vector <int> x1, vector <int> x2, vector <int> y){
    N = x1.size();
    for(int i = 0; i < N; i++) if(x1[i] > x2[i]) swap(x1[i], x2[i]);
    int ans = 0;
    for(int S = 0; S < 1 << N; S++){
      map<int, vector<int>> cor;
      int e = 0;
      for(int i =0; i < N; i++){
	if(S >> i & 1){
	  e++;
	  cor[x1[i]].push_back(y[i]);
	  cor[x2[i]].push_back(y[i]);
	}
      }
      int p = 0;
      for(auto u : cor) p += u.second.size() % 2;
      if(!p){
	int sx, sy, px, py;
	for(auto &u : cor){
	  sort(ALL(u.second));
	  sx = u.first, sy = u.second[0];
	}
	px = sx, py = sy;
	int c = 0;
	while(1){
	  c++;
	  for(int j = 0; j < (int)cor[px].size(); j++){
	    if(py == cor[px][j]){
	      int ny = cor[px][j % 2 ? j - 1 : j + 1];
	      for(int k = 0; k < N; k++)
		if((S >> k & 1) && x1[k] < px && px < x2[k]
		   && min(ny, py) < y[k] && y[k] < max(ny, py)) c -= 1000;
	      py = ny;
	      break;
	    }
	  }
	  for(int j = 0; j < N; j++){
	    if(y[j] == py && (x1[j] == px || x2[j] == px)){
	      px = (x1[j] == px) ? x2[j] : x1[j];
	      break;
	    }
	  }
	  if(sx == px && sy == py) break;
	}
	if(c == e) ans = max(ans, e * 2);
      }
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,4,2,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, restore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,3,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,2,1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, restore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, restore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, restore(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
RestoringPolygon ___test;
___test.run_test(-1);
}
// END CUT HERE 
