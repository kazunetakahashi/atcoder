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

typedef tuple<int, ll> path;

int N;
vector<path> V[100010];
int Q, K;
path parent[100010];
ll memo[100010];
int x[100010];
int y[100010];

ll dist(int n) {
  if (memo[n] != -1) return memo[n];
  if (n == K) return memo[n] = 0;
  int p = get<0>(parent[n]);
  return memo[n] = dist(p) + get<1>(parent[n]);
}

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    V[a].push_back(path(b, c));
    V[b].push_back(path(a, c));
  }
  cin >> Q >> K;
  K--;
  for (auto i = 0; i < Q; ++i) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  stack<int> S;
  S.push(K);
  parent[K] = path(-1, 0);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    for (auto x : V[now]) {
      int next = get<0>(x);
      ll d = get<1>(x);
      if (next != get<0>(parent[now])) {
        parent[next] = path(now, d);
        S.push(next);
      }
    }
  }
  for (auto i = 0; i < Q; ++i) {
    cout << dist(x[i]) + dist(y[i]) << endl;
  }
}
