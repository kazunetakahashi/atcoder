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

typedef tuple<int, double> pass;

int N;
vector<pass> V[150010];

double solve(int root, int from) {
  int cnt = 0;
  for (auto x : V[root]) {
    if (get<0>(x) != from) ++cnt;
  }
  if (cnt == 0) return 0;
  double ans = 0;
  for (auto x : V[root]) {
    if (get<0>(x) == from) continue;
    if (get<1>(x) < 0) {
      get<1>(x) = solve(get<0>(x), root) + 1;
    }
    ans += get<1>(x);
  }
  ans /= cnt;
  return ans;
}

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    V[u].push_back(pass(v, -1));
    V[v].push_back(pass(u, -1));
  }
  for (auto i = 0; i < N; ++i) {
    cout << fixed << setprecision(12) << solve(i, -1) << endl;
  }
}
