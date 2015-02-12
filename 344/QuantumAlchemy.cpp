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

struct alc{
  int d, cur;
  map<int, int> num;
};

class QuantumAlchemy {
public:
  int ans = 0;
  bool re[26][26];
  map<int, int> num;
 
  void rec(int cur){
    if(num.count(cur) && num[cur] >= 1) {
      num[cur]--;
      return;
    }
    if(ans > 100){
      ans = INF;
      return;
    }

    ans++;
    bool found = false;
    for(int i = 0; i < 26; i++){
      if(re[cur][i]){
	found = true;
	rec(i);
      }
    }

    if(!found) ans = INF;
    return;
  }
  int minSteps(string initial, vector <string> reactions){
    if(count(ALL(initial), 'X')) return 0;

    memset(re, false, sizeof(re));
    num.clear();
    int N = reactions.size();

    for(int i = 0; i < N; i++){
      int c = reactions[i][reactions[i].length() - 1] - 'A';
      string ing = reactions[i].substr(0, reactions[i].length() - 3);
      for(int j = 0; j < (int)ing.length(); j++) re[c][ing[j] - 'A'] = true;
    }
    for(int i = 0; i < (int)initial.length(); i++) num[initial[i] - 'A']++;

    ans = 0;
    rec('X' - 'A');
    return ans >= INF / 2 ? -1 : ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDE"; string Arr1[] = {"ABC->F", "FE->X"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AABBB"; string Arr1[] = {"BZ->Y", "ZY->X", "AB->Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAABB"; string Arr1[] = {"BZ->Y", "ZY->X", "AB->Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAXB"; string Arr1[] = {"BZ->Y", "ZY->X", "AB->Z"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, minSteps(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWYZABCDEFGHIJKLMNOPQRSTUVWYZ"; string Arr1[] = {"ABCE->Z", "RTYUIO->P", "QWER->T", "MN->B"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, minSteps(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
QuantumAlchemy ___test;
___test.run_test(-1);
}
// END CUT HERE 
