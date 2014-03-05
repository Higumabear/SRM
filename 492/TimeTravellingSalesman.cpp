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
#include <numeric>
using namespace std;
static const double EPS = 1e-8;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
static const ll INF= 1LL << 40;

int s2i(string s){
  stringstream ss;
  ss << s;
  int a;
  ss >> a;
  return a;
}

ll prim(vector<vector<ll> > dist){
  int N = dist.size();
  vector<bool> used(N, false);
  ll ret = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > Q;
  Q.push(make_pair(0, 0));
  while(!Q.empty()){
    ll cost = Q.top().first;
    ll to = Q.top().second;
    Q.pop();
    if(used[to]) continue;
    used[to] = true;
    ret += cost;
    for(int i = 0; i < N; i++) Q.push(make_pair(dist[to][i], i));
  }
  return ret;
}

class TimeTravellingSalesman {
public:
  long long determineCost(int N, vector <string> roads) {
    string str = accumulate(ALL(roads), string(""));
    vector<vector<ll> > d(N, vector<ll>(N, INF));
    for(int i = 0; i < (int)str.length(); i++) if(str[i] == ',') str[i] = ' ';
    
    stringstream ss; ss << str;
    string s1, s2, s3;
    while(ss >> s1 >> s2 >> s3)
      d[s2i(s1)][s2i(s2)] = d[s2i(s2)][s2i(s1)] = s2i(s3);
    
    ll result = prim(d);
    return result >= INF ? -1 : result;
  }
  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
