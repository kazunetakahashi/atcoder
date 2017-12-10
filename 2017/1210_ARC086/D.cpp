#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int> state;
vector<state> ans;

int main () {
  int N;
  cin >> N;
  int a[100];
  for (auto i = 0; i < N; ++i) {
    cin >> a[i];
  }
  bool isplus = true;
  int b = 0;
  int ind = 0;
  for (auto i = 0; i < N; ++i) {
    if (b < abs(a[i])) {
      b = abs(a[i]);
      ind = i;
      isplus = (a[i] > 0);
    }
  }
  if (b == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (auto i = 0; i < N; ++i) {
    ans.push_back(state(ind, i));
  }
  if (isplus) {
    for (auto i = 0; i < N-1; ++i) {
      ans.push_back(state(i, i+1));
    }
  } else {
    for (auto i = N-1; i > 0; --i) {
      ans.push_back(state(i, i-1));
    }
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << get<0>(x)+1 << " " << get<1>(x)+1 << endl;
  }
}
