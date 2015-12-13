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

typedef vector<long long> vec;
typedef vector<vec> mat;

mat identity(int n){
  mat I(n, vec(n, 0));
  for(int i = 0; i < n; i++) I[i][i] = 1;
  return I;
}

mat mul(const mat &A, const mat &B){
  mat C(A.size(), vec(B[0].size(), 0));
  for(int i = 0; i < A.size(); i++)
    for(int k = 0; k < A[0].size(); k++)
      for(int j = 0; j < B[0].size(); j++)
	C[i][j] = C[i][j] + A[i][k] * B[k][j];
  return C;
}

mat pow(const mat &A, int p){
  if(p == 0) return identity(A.size());
  if(p == 1) return A;
  mat B = pow(mul(A, A), p / 2);
  if(p % 2 == 1) B = mul(B, A);
  return B;
}

class MarbleMachine {
public:
  int H, W, N;

  int id(int y, int x){
    return y * W + x;
  }
  
  long long maxMarbles(vector <string> layout, vector <string> actions, int t) {
    ll ans = 0;
    H = layout.size(), W = layout[0].size();
    N = H * W;
    int P = 60;
    mat mats[100];
    
    for(int i = 0; i < P; i++){
      mat A(N + 1, vec(N + 1));
      A[N][N] = 1;
      
      for(int y = 0; y < H; y++){
	for(int x = 0; x < W; x++){
	  string s = actions[layout[y][x] - '0'];
	  char c = s[i % s.length()];
	  if(isdigit(c)){
	    A[id(y, x)][id(y, x)] = 1;
	    A[id(y, x)][N] = c - '0';
	  }else if(c != 'D'){
	    static const char *nesw = "NESW";
	    static int dy[] = {-1, 0, 1, 0};
	    static int dx[] = {0, 1, 0, -1};
	    int d = strchr(nesw, c) - nesw;
	    int ny = y + dy[d], nx = x + dx[d];
	    if(0 <= ny && ny < H && 0 <= nx && nx < W)
	      A[id(ny, nx)][id(y, x)] = 1;
	  }
	}
      }
      mats[i] = A;
    }
    mat B =  identity(N + 1);
    for(int l = 0; l < P; l++)
      B = mul(mats[l], B);
    B = pow(B, t / P);
    
    for(int l = (t / P) * P; l < t; l++){
      B = mul(mats[l % P], B);
    }

    ll res = 0;
    for(int i = 0; i < N; i++) res = max(res, B[i][N]);
    return res;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"0101",
"1010",
"0101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4","5353"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; long long Arg3 = 21LL; verify_case(0, Arg3, maxMarbles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"011112"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1E","E","0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; long long Arg3 = 498LL; verify_case(1, Arg3, maxMarbles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {
"01",
"32"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1E","SSDSS","W","00000W"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 23; long long Arg3 = 3LL; verify_case(2, Arg3, maxMarbles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MarbleMachine ___test;
    ___test.run_test(-1);
}
// END CUT HERE
