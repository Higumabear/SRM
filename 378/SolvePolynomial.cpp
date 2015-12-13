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

class SolvePolynomial {
public:
  int N, start;
  int a[10005];
  vector<int> ans;
  int abs(int a){ return a > 0 ? a : -a; }
  void check(int x){
    ll y = 0;
    for(int i = start; i <= N; i++){
      y -= a[i];
      if(y % x != 0) return;
      y /= x;
    }
    if(y != 0) return;
    ans.push_back(x);
  }
  vector <int> integerRoots(vector <int> X, vector <int> Y, int n) {
    ans.clear();
    int IX = X.size(), IY = Y.size();
    for(int i = 0; i <= n; i++){
      int p = i % IX;
      int q = (i + Y[i % IY]) % IX;
      a[i] = X[p], X[p] = X[q], X[q] = a[i];
    }

    N = n, start = 0;
    while(a[start] == 0) start++;
    if(start) ans.push_back(0);

    for(int i = 1; i * i <= abs(a[start]); i++)
      if(a[start] % i == 0)
	check(i), check(-i), check(a[start] / i), check(-a[start] / i);

    sort(ALL(ans));
    ans.erase(unique(ALL(ans)), ans.end());
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-4, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = {-2, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-15, -10, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {735134400, 1383, 4121, 18875, 10463, 
 13512, 19603, 28679, 13483, 9509, 1701,
 13383, 24425, 7923, 7978, 21702, 30989,
 20676, 18547, 28130, 10944}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {34,23,6,5,3,5,4,34,37,5,6,21,17,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, integerRoots(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SolvePolynomial ___test;
    ___test.run_test(-1);
}
// END CUT HERE
