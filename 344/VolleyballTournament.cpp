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
class VolleyballTournament {
public:
  string reconstructResults(int wonMatches, int lostMatches, int wonSets, int lostSets){
    wonSets -= 3 * wonMatches;
    lostSets -= 3 * lostMatches;

    string ans;
    if(wonSets == 0){
      for(int i = 0; i < lostMatches; i++) ans += "0-3,";
    }else if(wonSets == 2 * lostMatches){
      for(int i = 0; i < lostMatches; i++) ans += "2-3,";
    }else if(wonSets == 2 * lostMatches - 1){
      ans += "1-3,";
      for(int i = 0; i < lostMatches - 1; i++) ans += "2-3,";
    }else if(wonSets == 1){
      for(int i = 0; i < lostMatches - 1; i++) ans += "0-3,";
      ans += "1-3,";
    }else return "AMBIGUITY";

    if(lostSets == 0){
      for(int i = 0; i < wonMatches; i++) ans += "3-0,";
    }else if(lostSets == 2 * wonMatches){
      for(int i = 0; i < wonMatches; i++) ans += "3-2,";
    }else if(lostSets == 2 * wonMatches - 1){
      ans += "3-1,";
      for(int i = 0; i < wonMatches - 1; i++) ans += "3-2,";
    }else if(lostSets == 1){
      for(int i = 0; i < wonMatches - 1; i++) ans += "3-0,";
      ans += "3-1,";
    }else return "AMBIGUITY";
    return ans.substr(0, ans.length() - 1);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 9; int Arg3 = 9; string Arg4 = "0-3,0-3,0-3,3-0,3-0,3-0"; verify_case(0, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 3; int Arg2 = 6; int Arg3 = 9; string Arg4 = "2-3,2-3,2-3"; verify_case(1, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 9; int Arg3 = 3; string Arg4 = "AMBIGUITY"; verify_case(2, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 4; int Arg3 = 4; string Arg4 = "1-3,3-1"; verify_case(3, Arg4, reconstructResults(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
VolleyballTournament ___test;
___test.run_test(-1);
}
// END CUT HERE 
