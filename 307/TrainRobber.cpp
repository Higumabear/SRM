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
#include <deque>
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

priority_queue<pair<ll, ll> > Q;

ll ne(){
  pair<ll, ll> p = Q.top(); Q.pop();
  Q.push(make_pair(p.first - p.second, p.second));
  return -p.first;
}

class TrainRobber {
public:
  double finalPosition(int length, int nCarriages, vector <string> offset, vector <string> period, int trainSpeed, int robberSpeed, int nBridges){
    priority_queue<pair<ll, ll> > em; swap(em, Q);
    vector<int> x, y;
    ll now = 0;
    for(int i = 0; i < (int)offset.size(); i++){
      stringstream ss(offset[i]);
      int t; while(ss >> t) x.push_back(t);
    }
    for(int i = 0; i < (int)period.size(); i++){
      stringstream ss(period[i]);
      int t; while(ss >> t) y.push_back(t);
    }
    for(int i = 0; i < (int)x.size(); i++) Q.push(make_pair(-x[i], y[i]));
    for(int i = 0; i < nBridges; i++){
      ll next = ne(); ll t = ((next - now) * robberSpeed) / ((ll)length * (robberSpeed + trainSpeed));

      if(t >= nCarriages) return 1.0 * length * (robberSpeed + trainSpeed) / robberSpeed * nCarriages + now;
      nCarriages -= t;
      now = next;
    }

    return now;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 4; string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4", "2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; int Arg5 = 1; int Arg6 = 100; double Arg7 = 14.0; verify_case(0, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 4; string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"4 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; double Arg7 = 3.0; verify_case(1, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 10; string Arr2[] = {"8 23"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"15 13"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 10; int Arg6 = 10; double Arg7 = 75.0; verify_case(2, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; string Arr2[] = {"1 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"1 1"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; int Arg5 = 100; int Arg6 = 100; double Arg7 = 50.0; verify_case(3, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1000000; string Arr2[] = {"10", "15 63"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"23 42 11"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; int Arg5 = 1000; int Arg6 = 1000; double Arg7 = 6355.0; verify_case(4, Arg7, finalPosition(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
TrainRobber ___test;
___test.run_test(-1);
}
// END CUT HERE 
