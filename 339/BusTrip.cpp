// BEGIN CUT HERE
// END CUT HERE
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <iterator>
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

#define maxt 1003
#define maxn 101

int ne[maxt][maxn];

using namespace std;
class BusTrip {
public:
  void add(int t0, int t, int a, int b){
    while(t0 < maxt){
      if(ne[t0][a] == -1) ne[t0][a] = b;
      t0 += t;
    }
  }
  int returnTime(int N, vector <string> buses){
    int i, j, t, sumt, f;
    memset(ne, -1, sizeof(ne));
    for(i = 0; i < (int)buses.size(); i++){
      stringstream ss(buses[i]);
      sumt = t = 0;
      vector<int> a;
      while(ss >> j) a.push_back(j);
      a.push_back(a[0]);
      for(j = 0; j < (int)a.size(); j++) if(j) sumt += abs(a[j] - a[j - 1]);
      for(j = 0; j < (int)a.size(); j++) 
	if(j) add(t, sumt, a[j - 1], a[j]), t += abs(a[j] - a[j - 1]);
    }
    i = t = f = 0;
    while(1){
      if(t > 1001) return -1;
      else if(f && !i) return t - 1;
      else if(ne[t][i] == -1) t++;
      else j = ne[t][i], t += abs(j - i) + 1, i = j, f = 1;
    }
    return 0;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0 1 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 51; string Arr1[] = {"0 5 10 15 20 25 30 35 40 50"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; verify_case(1, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0 1 2", "2 1 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; string Arr1[] = {"0 1 2 3 4", "3 1 2 0", "4 1 2 3 0", "1 2 0 3 4", "4 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 25; string Arr1[] = {"24 14 9 7 2", "21 4 18 24 7 1 2 11 8 9 14 16 5 17 13 23 19 15 22", "12 22 24 9 1 5 10 8 7 18 16 19 4 13 17", 
 "14 5 17 9 23 7 16 22 10 4 6", "19 8 1 9 24 3 5 22 16 7 6 4 10 23 17 0 13 15", 
 "2 16 10 13 14 1 11 20 0 24 22 23 19 4 18", "19 15 18 0", "15 9 22 5 20 8 23 14 24 18 21 6 13 19", 
 "2 6 19 3 21 10 20 22 24 13 16 15 8 18 17 14 5", "19 10 1 7 5 11 21 8 14 0 17 23 12 2 3 16"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 157; verify_case(4, Arg2, returnTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; string Arr1[] = {"0 10 30 45 60 46 39 31 20", "9 20 0 86"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, returnTime(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BusTrip ___test;
___test.run_test(-1);
}
// END CUT HERE 
