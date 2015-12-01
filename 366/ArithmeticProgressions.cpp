#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 61
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;
inline ll s2i(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string i2s(T x) {ostringstream sout;sout<<x;return sout.str();}
const double PI  = acos(-1.0);

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}

class ArithmeticProgressions {
public:
  vector<ll> num;
  int N;

  double c(pair<ll, ll> a){
    return a.first * 1.0 / a.second;
  }
  vector <string> maxAptitude(vector <string> numbers) {
    num.clear();
    for(int i = 0; i < (int)numbers.size(); i++)
      num.push_back(s2i(numbers[i]));
    sort(ALL(num));

    N = num.size();
    ll p1 = 0, p2 = 1;
    long double v = 0;

    for(int i = 0; i < N; i++){
      for(int j = i + 1; j < N; j++){
	for(int k = j + 1; k < N; k++){
	  ll g = gcd(num[k] - num[j], num[j] - num[i]);
	  ll cnt = 0;
	  ll cnt2 = ((num[N - 1] - num[0]) - (num[i] - num[0]) % g) / g + 1;
	  for(int a = 0; a < N; a++)
	    if((num[a] - num[i]) % g == 0) cnt++;

	  long double tmp = cnt * 1.0 / cnt2;
	  if(v < tmp){
	    v = tmp;
	    ll gg = gcd(cnt, cnt2);
	    p1 = cnt / gg;
	    p2 = cnt2 / gg;
	  }
	}
      }
    }
    vector<string> z;
    z.push_back(i2s(p1));
    z.push_back(i2s(p2));
    return z;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1", "3", "5", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3", "4" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, maxAptitude(Arg0)); }
	void test_case_1() { string Arr0[] = {"1", "3", "5", "7", "9", "11", "13", "15", "17", "19"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, maxAptitude(Arg0)); }
	void test_case_2() { string Arr0[] = {"1", "999999999999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, maxAptitude(Arg0)); }
	void test_case_3() { string Arr0[] = {"1", "7", "13", "3511", "1053", "10", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3", "391" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, maxAptitude(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ArithmeticProgressions ___test;
    ___test.run_test(-1);
}
// END CUT HERE
