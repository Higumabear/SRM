/*
 * 24.cpp
 *
 * Last update: <09/10/2012 05:30:25>
 */

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
typedef long long ll;

int main(){
  vector<int> v;
  for(int i = 0; i < 10; i++) v.push_back(i);
  for(int i = 1; i < 1000000; i++) next_permutation(v.begin(), v.end());
  for(int i = 0; i < 10; i++) cout << v[i];
  cout << endl;
  return 0;
}
