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

class NSegmentDisplay {
public:
  string brokenSegments(vector <string> symbols, vector <string> patterns) {
    int N = symbols.size(), M = symbols[0].size();

    vector<vector<int>> need(M, vector<int>(2, 0));
    for(int i = 0; i < patterns.size(); i++)
      for(int j = 0; j < M; j++)
	if(patterns[i][j] == '1')
	  need[j][1] = true;

    vector<vector<int>> matches(patterns.size());
    for(int i = 0; i < patterns.size(); i++){
      for(int j = 0; j < N; j++){
	bool good = true;
	for(int k = 0; k < M; k++){
	  if(need[k][1] && symbols[j][k] != patterns[i][k])
	    good = false;
	}
	if(good) matches[i].push_back(j);
      }
    }

    for(int i = 0; i < patterns.size(); i++){
      if(!matches[i].size()) return "INCONSISTENT";

      vector<int> used(M, 1);
      for(int j = 0; j < matches[i].size(); j++){
	int index = matches[i][j];
	for(int k = 0; k < M; k++)
	  if(symbols[index][k] == '0') used[k] = 0;
      }
      for(int j = 0; j < M; j++){
	if(!need[j][1] && used[j]) need[j][0] = true;
      }
    }
    string ans;
    for(int i = 0; i < M; i++){
      if(need[i][1]) ans += 'Y';
      else if(need[i][0]) ans += 'N';
      else ans += '?';
    }
    return ans;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1011111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Y?YYYYY"; verify_case(0, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0111111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NYYYYYY"; verify_case(1, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1000000","0010000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INCONSISTENT"; verify_case(2, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0010110","0010010","0010000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NNYNYYN"; verify_case(3, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"110000111001","100000101000","000001010000"
,"101100010011","111111111101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"010000000000","010000000000","000000000000"
,"000000000000","000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "NY????NNN??N"; verify_case(4, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"00000000001000000010","01010000001011101110"
,"01010101110110011010","00111001111001000100"
,"10010111010110110000","11011011001000110001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00011000010000000000","10010110010000100000"
,"00010100010000001000","00010100010000001000"
,"00010000000000101000","00000000000000000000"
,"00010100010000001000","00011000010000000000"
,"00011000010000000000","00000000000000000000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "YNNYYYYNNYNNNNYNYNN?"; verify_case(5, Arg2, brokenSegments(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"001000111101000","000001111011001"
,"010010100100010","111000100010011"
,"011011011010001","010011111101000"
,"000101011110011","010000011111000"
,"000001100100011","000000111110000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"001000110001000","000101110000011"
,"000101010000011","001000110101000"
,"010001100000111"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INCONSISTENT"; verify_case(6, Arg2, brokenSegments(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    NSegmentDisplay ___test;
    ___test.run_test(-1);
}
// END CUT HERE
