#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
const int MOD = 1e9 + 7;
inline int s2i(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

class SumOfPowers {
public:
  typedef vector<ll> vec;
  typedef vector<vec> mat;

  mat mat_mul(const mat &A, const mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
      for(int k = 0; k < B.size(); k++){
	for(int j = 0; j < B[0].size(); j++){
	  C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	}
      }
    }
    return C;
  }

  mat mat_pow(mat &A, ll n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++){
      B[i][i] = 1;
    }
    while(n > 0){
      if(n & 1) B = mat_mul(B, A);
      A = mat_mul(A, A);
      n >>= 1;
    }
    return B;
  }
  int value(int n, int k) {
    mat a(1, vec(k + 2, 0)); a[0][0] = 1;
    mat p(k + 2, vec(k + 2, 0));
    p[0][0] = 1;
    for(int j = 1; j <= k; j++){
      p[0][j] = 1;
      for(int i = 1; i <= j; i++)
	p[i][j] = (p[i - 1][j - 1] + p[i][j - 1]) % MOD;
    }
    for(int i = 0; i <= k; i++) p[i][k + 1] = p[i][k];
    p[k + 1][k + 1] = 1;
    return mat_mul(a, mat_pow(p, n)).front().back();
  }
  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
