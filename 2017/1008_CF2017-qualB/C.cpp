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

typedef tuple<int, int> state; // now, from
typedef tuple<int, int> cond; // now, depth

int N;
int M;
vector<int> V[100010];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  for (auto i = 0; i < N; ++i) {
    random_shuffle(V[i].begin(), V[i].end());
  }
  bool visited[100010];
  fill(visited, visited+100010, false);
  bool is_loop[100010];
  fill(is_loop, is_loop+100010, false);
  int parent[100010];
  stack<state> S;
  S.push(state(0, -1));
  while (!S.empty()) {
    int now = get<0>(S.top());
    int from = get<1>(S.top());
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      parent[now] = from;
      for (auto x : V[now]) {
        if (x != parent[now]) {
          S.push(state(x, now));
        }
      }
    } else {
      is_loop[from] = true;
      is_loop[now] = true;
      int back = parent[from];
      while (true) {
        is_loop[back] = true;
        back = parent[back];
        cerr << "back = " << back << endl;
        if (back == now) break;
      }
    }
  }
  for (auto i = 0; i < 100010; ++i) {
    visited[i] = is_loop[i];
  }
  ll ans = 0;
  for (auto i = 0; i < N; ++i) {
    if (visited[i]) continue;
    stack<cond> SS;
    SS.push(cond(i, 0));
    ll cnt[2] = {0, 0};
    while (!SS.empty()) {
      int now = get<0>(SS.top());
      int depth = get<1>(SS.top());
      SS.pop();
      if (!visited[now]) {
        visited[now] = true;
        cnt[depth%2]++;
        for (auto x : V[now]) {
          if (!visited[x]) {
            SS.push(cond(x, depth+1));
          }
        }
      }
    }
    ans += cnt[0] * cnt[1];
  }
  ll L = 0;
  for (auto i = 0; i < N; ++i) {
    if (is_loop[i]) L++;
  }
  cerr << "L = " << L << endl;
  ans += L * (L-1) / 2 + L * (N-L) - M;
  cout << ans << endl;
}
