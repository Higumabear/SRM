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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class FixImage {
public:
  int N, M;
  vector<string> ret;
  bool in(int y, int x){ return 0 <= y && y < N && 0 <= x && x < M; }

  void func(int y, int x, int l, vector<vector<int> > &label){
    label[y][x] = l;
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i], nx = x + dx[i];
      if(in(ny, nx) && ret[ny][nx] == '#' && label[ny][nx] == 0)
	func(ny, nx, l, label);
    }
  }
  void cca(vector<vector<int> > &label){
    int l = 1;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < M; j++)
	if(ret[i][j] == '#' && label[i][j] == 0)
	  func(i, j, l++, label);
  }
  
  vector <string> originalImage(vector <string> alteredImage) {
    N = alteredImage.size(), M = alteredImage[0].size();
    ret = alteredImage;
    bool update = true;
    while(update){
      update = false;
      vector<string> tmp = ret;
      vector<vector<int> > la(N, vector<int>(M, 0));
      cca(la);
      for(int i = 0; i < N; i++){
	for(int j = 0; j < M; j++){
	  if(la[i][j] != 0) continue;
	  int wl = 0, el = 0;
	  vector<pair<int, int> > pt;
	  for(int k = j; k >= 0; k--){
	    wl = la[i][k];
	    pt.push_back(make_pair(i, k));
	    if(la[i][k] != 0) break;
	  }
	  for(int k = j + 1; k < M; k++){
	    el = la[i][k];
	    pt.push_back(make_pair(i, k));
	    if(la[i][k] != 0) break;
	  }
	  if(wl == el && wl != 0){
	    update = true;
	    for(int k = 0; k < (int)pt.size(); k++)
	      tmp[pt[k].first][pt[k].second] = '#';
	  }
	  int nl = 0, sl = 0;
	  pt.clear();
	  for(int k = i; k >= 0; k--){
	    nl = la[k][j];
	    pt.push_back(make_pair(k, j));
	    if(la[k][j] != 0) break;
	  }
	  for(int k = i + 1; k < N; k++){
	    sl = la[k][j];
	    pt.push_back(make_pair(k, j));
	    if(la[k][j] != 0) break;
	  }
	  if(nl == sl && nl != 0){
	    update = true;
	    for(int k = 0; k < (int)pt.size(); k++)
	      tmp[pt[k].first][pt[k].second] = '#';
	  }
	}
      }
      ret = tmp;
    }
    return ret;
  }
  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
