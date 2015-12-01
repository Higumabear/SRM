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
#define ABS(a) ((a) < 0 ? - (a) : (a))
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

using namespace std;

struct seg{
  int x1, y1, x2, y2;
};

class PolylineUnion {  
public:
  int s2i(string s){
    stringstream ss(s);
    int x; ss >> x; return x;
  }
  seg s2seg(string s, string t){
    seg a;
    int pos1 = s.find(",", 0);
    int pos2 = t.find(",", 0);
    a.x1 = s2i(s.substr(0, pos1));
    a.y1 = s2i(s.substr(pos1 + 1));
    a.x2 = s2i(t.substr(0, pos2));
    a.y2 = s2i(t.substr(pos2 + 1));
    return a;
  }
 
  int crs(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
  }
	
  bool intersects(seg a, seg b) {
    ll x1 = a.x1, y1 = a.y1, x2 = a.x2, y2 = a.y2;
    ll x3 = b.x1, y3 = b.y1, x4 = b.x2, y4 = b.y2;
    int c1 = crs(x1, y1, x2, y2, x3, y3);
    int c2 = crs(x1, y1, x2, y2, x4, y4);
    int c3 = crs(x3, y3, x4, y4, x1, y1);
    int c4 = crs(x3, y3, x4, y4, x2, y2);
    if(c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0)
      return (min(x3, x4) <= x1 && x1 <= max(x3, x4) && min(y3, y4) <= y1 && y1 <= max(y3, y4)) ||
	(min(x3, x4) <= x2 && x2 <= max(x3, x4) && min(y3, y4) <= y2 && y2 <= max(y3, y4)) ||
	(min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2)) ||
	(min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y1, y2) <= y4 && y4 <= max(y1, y2));
    return min(c1, c2) <= 0 && 0 <= max(c1, c2) && min(c3, c4) <= 0 && 0 <= max(c3, c4);
  }

  void paint(int idx, vector<vector<bool>> e, vector<bool> &vis){
    vis[idx] = true;
    for(int i = 0; i < e.size(); i++)
      if(e[idx][i] && !vis[i])
	paint(i, e, vis);
    return;
  }

  int countComponents(vector <string> polylines) {
    int ans;
    vector<seg> line;
    stringstream ss(accumulate(ALL(polylines), string()));
    string tmp;
    while(ss >> tmp){
      int space = 0;
      for(int i = 0; i < (int)tmp.length(); i++) 
	if(tmp[i] == '-') tmp[i] = ' ', space++;
      
      stringstream sss(tmp);
      vector<string> p;
      string u;
      while(sss >> u) p.push_back(u);
      
      if(space == 0) line.push_back(s2seg(p[0], p[0]));
      else{
	for(int i = 1; i < p.size(); i++)
	  line.push_back(s2seg(p[i - 1], p[i]));
      }
    }

    int N = line.size();
    vector<vector<bool>> e(N, vector<bool>(N, false));
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	if(intersects(line[i], line[j])) 
	  e[i][j] = e[j][i] = true;
    
    for(int k = 0; k < N; k++)
      for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	  if(e[i][k] && e[k][j]) e[i][j] = true;
    
    ans = 0;
    vector<bool> vis(N, false);
    for(int i = 0; i < N; i++){
      if(!vis[i]){
	paint(i, e, vis);
	ans++;
      }
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0,0-10,10 0,10-10,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countComponents(Arg0)); }
	void test_case_1() { string Arr0[] = {"0,0-10,5 5,0-15,5-10,10-5,5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countComponents(Arg0)); }
	void test_case_2() { string Arr0[] = {"1","3,0-5,5 4,0-4,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, countComponents(Arg0)); }
	void test_case_3() { string Arr0[] = {"10,0-10,1-9,2-9,3-8,4 ","8,2-9,2-10,3 ","12,2-11,2-9,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, countComponents(Arg0)); }
	void test_case_4() { string Arr0[] = {"0,0-10,0-0,0 20,0-8,0-20,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, countComponents(Arg0)); }
	void test_case_5() { string Arr0[] = {"1,1 2,2 3,3 4,4 3,3-4,4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, countComponents(Arg0)); }
	void test_case_6() { string Arr0[] = {"10,10-20,10 20,10-15,18 15,18-10,10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, countComponents(Arg0)); }
	void test_case_7() { string Arr0[] = {"1,1 1,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(7, Arg1, countComponents(Arg0)); }

// END CUT HERE
  
};

// BEGIN CUT HERE 
int main() {
  PolylineUnion ___test;
  ___test.run_test(-1); 
}
// END CUT HERE
