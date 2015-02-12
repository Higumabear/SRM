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
using namespace std;

string itos(int a){
  stringstream ss; ss << a; return ss.str();
}

class LogCutter {
public:
  vector<int> p;
  bool check(int a, int idx, int T){
    int N = p.size();
    int num = 0;
    int cur = p[idx];
    for(int i = idx + 1; i < N; i++){
      if(p[i] - cur <= a){
	if(i + 1 < N && p[i + 1] - cur > a){
	  cur = p[i];
	  num++;
	}
      }else return false;
    }
    return num <= T;
  }
  string bestCut(int L, int A, int K, int C){
    p.clear();
    for(int i = 1; i <= K; i++) 
      p.push_back(((A % (L - 1)) * i) % (L - 1) + 1);
    p.push_back(0);
    p.push_back(L);
    sort(ALL(p));
    p.erase(unique(ALL(p)), p.end());

    int high = INF, lo = 1;
    while(high - lo >= 10){
      int mid = (high + lo) / 2 + 1;
      if(check(mid, 0, C)) high = mid;
      else lo = mid;
    }
    dump(lo);    dump(high);
    int len = 1;
    for(len = lo; len <= high; len++)
      if(check(len, 0, C)) break;
    dump(len);
    for(int i = 1; i < (int)p.size(); i++){
      if(check(len, i, C - 1)){
	return itos(len) + " " + itos(p[i]);
      }
    }
    return "";
  }
  
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 3; int Arg2 = 2; int Arg3 = 1; string Arg4 = "5 4"; verify_case(0, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; int Arg3 = 2; string Arg4 = "3 3"; verify_case(1, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 3; int Arg2 = 5; int Arg3 = 3; string Arg4 = "2 1"; verify_case(2, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10000; int Arg1 = 999983; int Arg2 = 5000; int Arg3 = 1000; string Arg4 = "13 2"; verify_case(3, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 100; int Arg3 = 100; string Arg4 = "1 1"; verify_case(4, Arg4, bestCut(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LogCutter ___test;
___test.run_test(-1);
}
// END CUT HERE 
