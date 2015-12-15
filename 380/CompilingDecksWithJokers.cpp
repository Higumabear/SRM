#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 58
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

class CompilingDecksWithJokers {
public:
  int N;
  bool check(ll x, vector<int> &cards, ll jokers){
    ll sum = 0;
    for(int i = 0; i < N; i++)
      sum += max(0LL, (ll)(x - cards[i]));

    return sum <= x && sum <= jokers;
  }
  
  int maxCompleteDecks(vector <int> cards, int jokers) {
    sort(ALL(cards));
    N = cards.size();

    ll ub = LLINF, lb = 0LL;
    while(ub - lb > 10){
      ll mid = (ub + lb) / 2LL;
      if(check(mid, cards, jokers)) lb = mid;
      else ub = mid;
    }
    for(ll i = lb; i <= ub; i++)
      if(!check(i, cards, jokers)) return i - 1;
    return -1;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 13; verify_case(0, Arg2, maxCompleteDecks(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(1, Arg2, maxCompleteDecks(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 6; verify_case(2, Arg2, maxCompleteDecks(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(3, Arg2, maxCompleteDecks(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CompilingDecksWithJokers ___test;
    ___test.run_test(-1);
}
// END CUT HERE
