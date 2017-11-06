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

int N;
ll x[2][100010];
typedef tuple<int, int> point;
typedef tuple<ll, int, int> edge;

int main () {
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> x[0][i] >> x[1][i];
  }
  vector<edge> V;
  for (auto k = 0; k < 2; ++k) {
    vector<point> W;
    for (auto i = 0; i < N; ++i) {
      W.push_back(point(x[k][i], i));
    }
    sort(W.begin(), W.end());
    for (auto i = 0; i < N-1; ++i) {
      int d0 = get<0>(W[i]);
      int p0 = get<1>(W[i+1]);
      int d1 = get<0>(W[i]);
      int p1 = get<1>(W[i+1]);
      V.push_back(edge(abs(d0 - d1), p0, p1));
    }
  }
  sort(V.begin(), V.end());
  int used = 0;
  ll ans = 0;
  bool visited[100010];
  fill(visited, visited+100010, false);
  auto it = V.begin();
  while (used < N) {
    ll cost = get<0>(*it);
    int p0 = get<1>(*it);
    int p1 = get<2>(*it);
    ++it;
    if (visited[p0] && visited[p1]) continue;
    if (!visited[p0]) {
      visited[p0] = true;
      ++used;
    }
    if (!visited[p1]) {
      visited[p1] = true;
      ++used;
    }
    ans += cost;
  }
  cout << ans << endl;
}
