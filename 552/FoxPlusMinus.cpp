#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>
 
using namespace std;
 
#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORN(i,a,b) for (int i = (a); i < (b); i++)
#define DOWN(i,a,b) for (int i = (a); i > (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FREOPEN freopen("a.in", "r", stdin); freopen("a.out", "w", stdout)
 
class FoxPlusMinus{
public:
  vector<int> call(vector <LL> C, vector <int> first) {
    int K = first.size();
    int used[100];
    vector <int> res;
    
    //all position is unused
    SET (used, 0);
    FOR (i, 0, K - 1) res.PB(0);
    
    sort(first.begin(), first.end());
    
    FOR (i, 0, K - 1) {
      int pos = -1;
      FOR (j, 0, K - 1) 
	if (used[j] == 0 && (pos == -1 || C[j] < C[pos])) pos = j;
      res[pos] = first[i];
      used[pos] = 1;
    }
    
    return res;
  }
  
  vector<int> maximize(vector <int> first, int N) {
    int K = first.size();
    
    if (K % 2) {
      //in this case A[i] = A[i - k - 1]
      vector <LL> CC;
      if ((N % (K + 1)) == K) {
	//A[N] = A[K] = F[0] - F[1] + ... + F[K - 1];
	FOR (i, 0, K - 1)
	  if (i % 2) CC.PB(-1);
	  else CC.PB(1);
      }
      else {
	//A[N] = F[N % (K + 1)];
	FOR (i, 0, K - 1) CC.PB(0);
	CC[N % (K + 1)] = 1;
      }
      
      return call(CC, first);
    }
    
    //if N < K, C array is easy to prepare
    if (N < K) {
      vector <LL> C;
      FOR (i, 1, K) C.PB(0);
      C[N] = 1;
      return call(C, first);
    }
    
    if (N < 2 * K) {
      //build the suitable partern of C for each value of N
      vector <LL> C;
      FOR (i, 1, N - K + 1) C.PB(i);
      FOR (i, 1, K - (N - K + 1)) C.PB(N - K + 1);
      
      if (N % 2) {
	FOR (i, 0, K - 1) 
	  if ((i % 2) == 0) C[i] = - C[i];
      } else {
	FOR (i, 0, K - 1) 
	  if (i % 2) C[i] = - C[i];
      }
      
      return call(C, first);
    }
    
    //build the any C array which have |C[0]| < |C[1]| < ... <|C[K - 1]|
    //and if N is even (0 indexed), all elements of C in the odd position will be negative and other elements will be positive. 
    //And vice versa, if N is odd all elements of C in the odd position will be positive and other elements will be negative.
    
    vector <LL> CC;
    FOR (i, 0, K - 1) CC.PB(i + 1);
    if ((N % 2) == 0) {
      FOR (i, 0, K - 1) if (i % 2) CC[i] = -CC[i];
    }
    else FOR (i, 0, K - 1) if ((i % 2) == 0) CC[i] = -CC[i];
    
    return call(CC, first);
  }
};
