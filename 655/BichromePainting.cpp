// BEGIN CUT HERE
// END CUT HERE
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
using namespace std;

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;



class BichromePainting {
public:
  string isThatPossible(vector <string> board, int k){
    int N = board.size();
    int a, b;
    for(int t = 0; t < N * N; t++){
      for(int i = 0; i <= N - k; i++){
	for(int j = 0; j <= N - k; j++){
	  a = 0, b = 0;
	  for(int u = 0; u < k; u++)
	    for(int v = 0; v < k; v++)
	      if(board[u + i][v + j] == 'W') a++; 
	      else if(board[u + i][v + j] == 'B')b++;
	  
	  if(a == 0 || b == 0)
	    for(int u = 0; u < k; u++)
	      for(int v = 0; v < k; v++)
		board[u + i][v + j] = 'Q';
	}
      }	  
    }
    a = 0, b = 0;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
	if(board[i][j] == 'W') a++; 
	else if(board[i][j] == 'B') b++;

    return a == 0 && b == 0 ? "Possible" : "Impossible";
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BW",
 "WB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(1, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(2, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(3, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"BB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(5, Arg2, isThatPossible(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main() {
BichromePainting ___test;
___test.run_test(-1);
}
// END CUT HERE 
