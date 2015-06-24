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



class LikelyWord {
public:
  int likely(vector <string> dictionary, int k){
    int N = dictionary.size();
    vector<ll> num;
    for(int i = 0; i <= N; i++){
      string cur, next;
      if(i == 0) cur = string(k, 'a');
      else{
	cur = dictionary[i - 1];
	if(cur.length() > k) cur.resize(k);
	else cur += string(k - cur.length(), 'a');
      }
      
      if(i == N) next = string(k, 'z');
      else{
	next = dictionary[i];
	if(next.length() > k) next.resize(k);
	else next += string(k - next.length(), 'a');	
      }

      ll cnt = 0, base = 1;
      for(int j = k - 1; j >= 0; j--){
	cnt += base * (next[j] - cur[j]);
	base *= 26LL;
      }
      cnt++;
      if(i > 0 && cur <= dictionary[i - 1]) cnt--;
      if(i < N && next >= dictionary[i]) cnt--;
      if(cnt < 0) cnt = 0;
      num.push_back(cnt);
    }
    if(count(ALL(num), *max_element(ALL(num))) >= 2) return -1;
    return max_element(ALL(num)) - num.begin();
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"time","zoology"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, likely(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"az","ma","xz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, likely(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"az","ma","xz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, likely(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a","m","y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(3, Arg2, likely(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
LikelyWord ___test;
___test.run_test(-1);
}
// END CUT HERE 
