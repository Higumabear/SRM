#include <bits/stdc++.h>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ABS(a) ((a) < 0 ? - (a) : (a))
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

const int MAX = 55;

int memo[2 * MAX][MAX];

class TheHomework {  
public:
  int N, M;
  int lcs(vector<int> a, vector<int> b){
    int dp[51][51] = {};
    for(int i = 0; i < (int)a.size(); i++)
      for(int j = 0; j < (int)b.size(); j++){
	if(a[i] == b[j])
	  dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
	else{
	  dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
	}
      }

    return dp[a.size()][b.size()];
  }
  int rec(int num, int match){
    if(num >= 2 * MAX) return INF;
    if(num == M && match == M) return 0;

    int &ans = memo[num][match];
    if(ans >= 0) return ans;

    ans = INF;
    for(int i = 1; i <= num; i++)
      ans = min(ans, rec(num + i, min(match + i, M)) + 1);
    for(int i = 1; i * 2 <= num; i++)
      ans = min(ans, rec(num - i, min(match, num - i)) + 1);
    for(int i = 1; i * 2 <= num; i++)
      ans = min(ans, rec(num, min(match + i, M)) + 1);

    return ans;
  }
  int transform(vector <int> first, vector <int> second) {
    int ans = 0;
    sort(ALL(first));
    sort(ALL(second));

    int LCS = lcs(first, second);
    N = first.size(), M = second.size();
    memset(memo, -1, sizeof(memo));
    dump(LCS);
    return rec(N, LCS);
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,2,7,999,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,7,2,999,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {12,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(3, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  TheHomework ___test;
  ___test.run_test(-1); 
}
// END CUT HERE
