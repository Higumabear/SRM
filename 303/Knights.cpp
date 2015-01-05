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

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

using namespace std;
class Knights {
public:
  pair<int, int> p(string s){
    return make_pair(s[0] - 'A', s[1] - '1');
  }
  int makeFriendly(int N, vector <string> pos){
    vector<pair<int, int>> loc;
    stringstream s(accumulate(ALL(pos), string("")));
    string tmp; while(s >> tmp) loc.push_back(p(tmp));

    vector<int> d(loc.size(), 0);
    vector<pair<int, int>> node(loc.size());
    for(int i = 0; i < (int)loc.size(); i++){
      for(int j = 0; j < 8; j++){
	pair<int, int> t(loc[i].first + dy[j], loc[i].second + dx[j]);
	if(count(ALL(loc), t)){
	  d[i]++;
	  node.push_back(t);
	}
      }
    }
    
    vector<bool> used(d.size(), false);
    for(int i = 0; i < d.size(); i++){
      int idx = -1, mv = 0;
      for()
    }
    return 0;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"A2 A4", "B1 B5", "D1 D5 E2 E4 C3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"A1 A2 B1 B2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arr1[] = {"A1 A5 B3 C1 C5 D2 D4 E6 F5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; string Arr1[] = {"A2 A4 A5 A6 B2 B5 B6 B7 B8",
 "C3 C8 D1 D2 D3 D4 D5 D6 D8",
 "E1 E3 E8 F1 F2 F8 G3 G5 H4 H7 H8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, makeFriendly(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 9; string Arr1[] = {"A3 A4 A5 A7 A8 B6 B8 C3 C6",
 "C7 C9 D4 D5 D8 D9 E1 E3 E7",
 "F2 G2 G6 G7 H2 H9 I2 I4 I5",
 "I6 I7 I8 I9"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(4, Arg2, makeFriendly(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
Knights ___test;
___test.run_test(-1);
}
// END CUT HERE 
