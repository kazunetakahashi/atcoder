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
const ll MOD = 1000000007;

typedef tuple<ll, int> edge;
typedef tuple<ll, int> state;

int N, M;
int S, T;
vector<edge> V[100010];
ll D[100010];
ll cnt[100010];
ll revD[100010];
ll revcnt[100010];
bool visited[100010];
vector<ll> W;

int main () {
  cin >> N >> M;
  cin >> S >> T;
  S--;
  T--;
  for (auto i = 0; i < M; ++i) {
    int u, v;
    ll d;
    cin >> u >> v >> d;
    u--;
    v--;
    V[u].push_back(edge(d, v));
    V[v].push_back(edge(d, u));
  }
  fill(D, D+100010, -1);
  priority_queue<state, vector<state>, greater<state> > Q;
  Q.push(state(0, S));
  while (!Q.empty()) {
    ll dist = get<0>(Q.top());
    int now = get<1>(Q.top());
    Q.pop();
    if (D[now] == -1) {
      D[now] = dist;
      for (auto x : V[now]) {
        ll d = get<0>(x);
        ll dst = get<1>(x);
        if (D[dst] == -1) {
          Q.push(state(D[now] + d, dst));
        }
      }
    }
  }
  fill(cnt, cnt+100010, 0);
  fill(visited, visited+100010, false);
  cnt[S] = 1;
  vector<state> X;
  for (auto i = 0; i < N; ++i) {
    X.push_back(state(D[i], i));
  }
  sort(X.begin(), X.end());
  for (auto y : X) {
    int now = get<1>(y);
    if (!visited[now]) {
      visited[now] = true;
      for (auto x : V[now]) {
        ll d = get<0>(x);
        ll dst = get<1>(x);
        if (D[dst] == D[now] + d) {
          cnt[dst] += cnt[now];
          cnt[dst] %= MOD;
        }
      }      
    }
  }
#if DEBUG == 1
  for (auto i = 0; i < N; ++i) {
    cerr << "cnt[" << i << "] = " << cnt[i] << endl;
  }
#endif
  for (auto i = 0; i < N; ++i) {
    revD[i] = D[T] - D[i];
  }
  X.clear();
  for (auto i = 0; i < N; ++i) {
    if (revD[i] >= 0) {
      X.push_back(state(revD[i], i));      
    }
  }
  sort(X.begin(), X.end());
  fill(revcnt, revcnt+100010, 0);
  fill(visited, visited+100010, false);
  revcnt[T] = 1;
  for (auto y : X) {
    int now = get<1>(y);
    if (!visited[now]) {
      visited[now] = true;
      for (auto x : V[now]) {
        ll d = get<0>(x);
        ll dst = get<1>(x);
        if (revD[dst] == revD[now] + d) {
          revcnt[dst] += revcnt[now];
          revcnt[dst] %= MOD;
        }
      }      
    }
  }
#if DEBUG == 1
  for (auto i = 0; i < N; ++i) {
    cerr << "revcnt[" << i << "] = " << revcnt[i] << endl;
  }
#endif
  ll ans = (cnt[T] * cnt[T])%MOD;
  ll L = D[T];
  if (L % 2 == 0) {
    for (auto i = 0; i < N; ++i) {
      if (D[i] == L/2) {
        ll t = (cnt[i] * revcnt[i])%MOD;
        ans += MOD - (t * t)%MOD;
        ans %= MOD;
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    for (auto x : V[i]) {
      ll c = get<0>(x);
      int j = get<1>(x);
      if (2 * D[i] < L && L < 2 * D[j] && D[j] - D[i] == c) {
        ll t = (cnt[i] * revcnt[j])%MOD;
        ans += MOD - (t * t)%MOD;
        ans %= MOD;
      }
    }
  }  
  cout << ans << endl;
}
