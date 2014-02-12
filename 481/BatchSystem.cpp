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
using namespace std;
static const double EPS = 1e-8;
static const int INF= 1 << 29;
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;

struct job{
  string name;
  ll sum;
  vector<int> idx;
  bool operator<(const job &r)const{
    return sum < r.sum;
  }
};

class BatchSystem {
public:
  vector <int> schedule(vector <int> duration, vector <string> user) {
    vector <int> result;
    
    int N = duration.size();
    vector<job> batch;
    for(int i = 0; i < N; i++){
      bool found = false;
      for(int j = 0; j < (int)batch.size(); j++){
	if(batch[j].name == user[i]){
	  batch[j].sum += duration[i];
	  batch[j].idx.push_back(i);
	  found = true;
	}
      }
      if(!found){
	job tmp; tmp.sum = 0;
	tmp.name = user[i];
	tmp.sum += duration[i];
	tmp.idx.push_back(i);
	batch.push_back(tmp);
      }
    }
    stable_sort(ALL(batch));
//     for(int i = 0; i < (int)batch.size(); i++) {
//       cout << batch[i].name << " " << batch[i].sum << endl;
//     }
    for(int i = 0; i < (int)batch.size(); i++) 
      for(int j = 0; j < (int)batch[i].idx.size(); j++)
	result.push_back(batch[i].idx[j]);
    return result;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {400, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 1, 2, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, schedule(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {200, 200, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Gil", "Sarah", "Warrick"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, schedule(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 200, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Horatio Caine", "horatio caine", "YEAAAAAAH"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, schedule(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
  BatchSystem ___test;
  ___test.run_test(-1);
}
// END CUT HERE
