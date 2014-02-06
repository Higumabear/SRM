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
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
static const ll INF= 1LL << 50;

ll dist[110][110];

class RabbitJumping {
public:
  int getMinimum(vector <int> holes, int largeJump) {
    if(largeJump % 2 == 0) return -1; 
    for(int i = 0; i < 110; i++) fill(dist[i], dist[i] + 110, INF);
    int N = holes.size() / 2;
    vector<pair<ll, ll> > seg;
    for(int i = 0; i <= N; i++){
      if(i == 0) seg.push_back(make_pair(-INF, holes[0] - 1));
      else if(i == N) seg.push_back(make_pair(holes[2 * (N - 1) + 1] + 1, INF));
      else{
	if(holes[2 * (i - 1) + 1] + 1 <= holes[2 * i] - 1)
	  seg.push_back(make_pair(holes[2 * (i - 1) + 1] + 1, holes[2 * i] - 1));      
      }
    }
    N = seg.size();
    //2 * i, 2 * i + 1
    //largeJump ‚É‚æ‚éŠï‹ö‚Ì•Ï‰»
    for(int i = 0; i < N; i++){
      for(int j = i; j < N; j++){
	ll mind = seg[j].first - seg[i].second;
	ll maxd = seg[j].second - seg[i].first;
	if(mind < largeJump && largeJump < maxd){
	  dist[2 * i][2 * j + 1] = dist[2 * j + 1][2 * i] = 1;
	  dist[2 * i + 1][2 * j] = dist[2 * j][2 * i + 1] = 1;
	}
	if(largeJump == mind){
	  dist[2 * i + (seg[i].second) % 2][2 * j + (seg[i].second + 1) % 2] = 1;
	  dist[2 * j + (seg[i].second + 1) % 2][2 * i + (seg[i].second) % 2] = 1;
	}
	if(largeJump == maxd){
	  dist[2 * i + (seg[i].first) % 2][2 * j + (seg[i].first + 1) % 2] = 1;
	  dist[2 * j + (seg[i].first + 1) % 2][2 * i + (seg[i].first) % 2] = 1;
	}
      }
    }

    //smallJump ‚É‚æ‚éŠï‹ö‚ÌˆÚ“®
    for(int i = 0; i < N; i++){
      ll width = seg[i].second - seg[i].first;
      if(width == 2){
	dist[2 * i + (seg[i].first) % 2][2 * i + (seg[i].first) % 2] = 0;
      }
      if(width > 2){
	dist[2 * i][2 * i] = 0;
	dist[2 * i + 1][2 * i + 1] = 0;
      }
    }

    cout << dist[0][0] << " " << dist[0][1] << " " << dist[0][2] << " " << dist[0][3] << endl;

    for(int k = 0; k < 2 * N; k++)
    for(int i = 0; i < 2 * N; i++)
    for(int j = 0; j < 2 * N; j++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist[0][2 * (N - 1) + 1] >= INF ? -1 : dist[0][2 * (N - 1) + 1];
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = { 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = -1; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = { 2, 3 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = { 2, 17, 21, 36, 40, 55, 59, 74 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arg2 = 5; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = { 187640193, 187640493, 187640738, 187640845, 564588641, 564588679, 
  564588696, 564588907, 605671187, 605671278, 605671288, 605671386, 
  755723729, 755723774, 755723880, 755723920, 795077469, 795077625, 
  795077851, 795078039, 945654724, 945654815, 945655107, 945655323 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 475; int Arg2 = 9; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  RabbitJumping ___test;
  ___test.run_test(-1);
}
// END CUT HERE
