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

class PlatformJumper {
public:
  int N, _v, _g;
  int d[50][50];
  vector<pair<int, pair<int, int>>> p;
  bool reach(int x1, int y1, int x2, int y2){
    if(y2 >= y1) return false;
    ll dy = abs(y2 - y1);
    ll dx2 = (x1 - x2) * (x1 - x2);
    return (dx2 * _g <= 2 * dy * _v * _v);
  }
  int maxCoins(vector <string> platforms, int v, int g) {
    N = platforms.size();
    _v = v;
    _g = g;
    p.clear();
    for(int i = 0; i < N; i++){
      stringstream ss(platforms[i]);
      int x, y, c; ss >> x >> y >> c;
      p.push_back(make_pair(x, make_pair(y, c)));
    }

    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	d[i][j] = 10000000;
    for(int i = 0; i < N; i++) d[i][i] = 0;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	if(reach(p[i].first, p[i].second.first,
		 p[j].first, p[j].second.first)){
	  cout << p[i].first << " " << p[i].second.first << "\t"
	       << p[j].first << " " << p[j].second.first << endl;
	   d[i][j] = -p[j].second.second;
	}
    for(int k = 0; k < N; k++)
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	  d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

    int ans = 0;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	ans = min(ans, d[i][j] - p[i].second.second);
    return -ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 10 7", "5 15 7", "8 9 12" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 10; int Arg3 = 14; verify_case(0, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 0 1", "2 4 1", "4 0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, maxCoins(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 0 1", "5000 5000 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 87; int Arg3 = 10; verify_case(2, Arg3, maxCoins(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PlatformJumper ___test;
    ___test.run_test(-1);
}
// END CUT HERE
