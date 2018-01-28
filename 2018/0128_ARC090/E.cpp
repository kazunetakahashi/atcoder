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
  stack<int> X;
  X.push(S);
  while (!X.empty()) {
    int now = X.top();
    X.pop();
    if (!visited[now]) {
      visited[now] = true;
      for (auto x : V[now]) {
        ll d = get<0>(x);
        ll dst = get<1>(x);
        if (D[dst] == D[now] + d) {
          cnt[dst] += cnt[now];
          cnt[dst] %= MOD;
          X.push(dst);
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
  fill(revcnt, revcnt+100010, 0);
  fill(visited, visited+100010, false);
  revcnt[T] = 1;
  stack<int> Y;
  Y.push(T);
  while (!Y.empty()) {
    int now = Y.top();
    Y.pop();
    if (!visited[now]) {
      visited[now] = true;
      for (auto x : V[now]) {
        ll d = get<0>(x);
        ll dst = get<1>(x);
        if (revD[dst] == revD[now] + d) {
          revcnt[dst] += revcnt[now];
          revcnt[dst] %= MOD;
          Y.push(dst);
        }
      }      
    }
  }
#if DEBUG == 1
  for (auto i = 0; i < N; ++i) {
    cerr << "revcnt[" << i << "] = " << revcnt[i] << endl;
  }
#endif
  ll L = D[T];
  if (L % 2 == 0) {
    for (auto i = 0; i < N; ++i) {
      if (D[i] == L/2) {
        ll t = (cnt[i] * revcnt[i])%MOD;
        W.push_back(t);
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    for (auto x : V[i]) {
      int j = get<1>(x);
      if (2 * D[i] < L && L < 2 * D[j]) {
        ll t = (cnt[i] * revcnt[j])%MOD;
        W.push_back(t);
      }
    }
  }
  ll sum = 0;
  for (auto x : W) {
    sum += x;
    sum %= MOD;
  }
  ll ans = 0;
  for (auto x : W) {
    ans += (x * (sum + MOD - x))%MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}
