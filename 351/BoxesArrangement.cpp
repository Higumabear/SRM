#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

int dp[51][51][51][3][3];

class BoxesArrangement {
public:
  int L;
  string s;
  int rec(char last1, char last2, int pos, int A, int B, int C){
    if(pos == L) return (A == 0 && B == 0 && C == 0) ? 0 : -INF;

    int &ret = dp[pos][A][B][last1 - 'A'][last2 - 'A'];
    if(ret != -1) return ret;

    ret = -INF;
    if(!(last1 == last2 && last1 == s[pos]))
      ret = max(ret, 1 + rec(last2, s[pos], pos + 1, A, B, C));

    if(s[pos] == 'A') A++;
    if(s[pos] == 'B') B++;
    if(s[pos] == 'C') C++;

    if(!(last1 == last2 && last1 == 'A'))
      ret = max(ret, rec(last2, 'A', pos + 1, A - 1, B, C));
    if(!(last1 == last2 && last1 == 'B'))
      ret = max(ret, rec(last2, 'B', pos + 1, A, B - 1, C));
    if(!(last1 == last2 && last1 == 'C'))
      ret = max(ret, rec(last2, 'C', pos + 1, A, B, C - 1));

    return ret;
  }
  int maxUntouched(string boxes) {
    L = boxes.size();
    s = boxes;
    memset(dp, -1, sizeof(dp));
    int ret = rec('D', 'D', 0, 0, 0, 0);
    return ret < 0 ? -1 : ret;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAABBBCCC"; int Arg1 = 6; verify_case(0, Arg1, maxUntouched(Arg0)); }
	void test_case_1() { string Arg0 = "AAAAAAAACBB"; int Arg1 = 7; verify_case(1, Arg1, maxUntouched(Arg0)); }
	void test_case_2() { string Arg0 = "CCCCCB"; int Arg1 = -1; verify_case(2, Arg1, maxUntouched(Arg0)); }
	void test_case_3() { string Arg0 = "BAACAABAACAAA"; int Arg1 = 5; verify_case(3, Arg1, maxUntouched(Arg0)); }
	void test_case_4() { string Arg0 = "CBBABA"; int Arg1 = 6; verify_case(4, Arg1, maxUntouched(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BoxesArrangement ___test;
    ___test.run_test(-1);
}
// END CUT HERE
