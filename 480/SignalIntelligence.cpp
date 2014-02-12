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

class SignalIntelligence {
public:
  long long encrypt(vector <int> numbers) {
    long long result = 1LL << 62;
    int N = numbers.size();
    for(int i = 0; i < N; i++){
      vector<int> num;
      for(int j = 0; j < N; j++) if(i != j) num.push_back(numbers[j]);
      sort(ALL(num));
      
      int prev = 0;
      int idx = 0;
      for(int j = 0; ; j++){
	if(idx == (int)num.size()) break;
	if((1LL << j) - (1LL << prev) - 1 >= num[idx]){
	  idx++;
	  prev = j;
	}
      }
      result = min(result, (1LL << prev) + numbers[i] - 1);
    }
    return result;
  }
  
// BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(0, Arg1, encrypt(Arg0)); }
  void test_case_1() { int Arr0[] = {4,4,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 19LL; verify_case(1, Arg1, encrypt(Arg0)); }
  void test_case_2() { int Arr0[] = {1000000000,1000000000,1000000000,1000000000,1000000000,
				     1000000000,1000000000,1000000000,1000000000,1000000000,
				     1000000000,1000000000,1000000000,1000000000,1000000000,
				     1000000000,1000000000,1000000000,1000000000,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 281475976710655LL; verify_case(2, Arg1, encrypt(Arg0)); }
  
// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  SignalIntelligence ___test;
  ___test.run_test(-1);
}
// END CUT HERE
