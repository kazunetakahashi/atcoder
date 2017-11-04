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

typedef tuple<int, int> edge;
typedef tuple<int, int, int> uvc;

int N, M;
vector<edge> V[310];

bool subroutine(uvc e) {
  int u0 = get<0>(e);
  edge edge0 = edge(get<1>(e), get<2>(e));
  int u1 = get<1>(e);
  edge edge1 = edge(get<0>(e), -get<2>(e));
  // Make an dfs tree without (u0, edge0) and (u1, edge1).
  stack<edge> S;
  S.push(edge(0, 0));
  int height[310];
  fill(height, height+310, -1);
  uvc parent[310];
  parent[0] = uvc(-1, 0, -1);
  while (!S.empty()) {
    int now = get<0>(S.top());
    int h = get<1>(S.top());
    S.pop();
    if (height[now] == -1) {
      height[now] = h;
      for (auto x : V[now]) {
        if ((now == u0 && x == edge0) || (now == u1 && x == edge1)) {
          continue;
        }
        int dst = get<0>(x);
        int cost = h + get<1>(x);
        if (height[dst] == -1) {
          parent[dst] = uvc(now, dst, cost);
          S.push(edge(dst, cost));
        }
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    for (auto x : V[i]) {
      int j = get<0>(x);
      int cost = get<1>(x);
      if (height[j] - height[i] != cost) {
        return false;
      }
    }
  }
  return true;
}

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    V[a].push_back(edge(b, c));
    V[b].push_back(edge(a, -c));
  }
  // Make an initial dfs tree.
  stack<edge> S;
  S.push(edge(0, 0));
  int height[310];
  fill(height, height+310, -1);
  uvc parent[310];
  parent[0] = uvc(-1, 0, -1);
  while (!S.empty()) {
    int now = get<0>(S.top());
    int h = get<1>(S.top());
    S.pop();
    if (height[now] == -1) {
      height[now] = h;
      for (auto x : V[now]) {
        int dst = get<0>(x);
        int cost = h + get<1>(x);
        if (height[dst] == -1) {
          parent[dst] = uvc(now, dst, cost);
          S.push(edge(dst, cost));
        }
      }
    }
  }
  bool initial_ok = true;
  vector<uvc> forbid;
  for (auto i = 0; i < N; ++i) {
    for (auto x : V[i]) {
      int j = get<0>(x);
      int cost = get<1>(x);
      if (height[j] - height[i] != cost) {
        initial_ok = false;
        int now = i;
        while (now != -1) {
          forbid.push_back(parent[now]);
          now = get<0>(parent[now]);
        }
        now = j;
        while (now != -1) {
          forbid.push_back(parent[now]);
          now = get<0>(parent[now]);
        }
        break;
      }
    }
    if (!initial_ok) break;
  }
  if (initial_ok) {
    cout << "Yes" << endl;
    return 0;
  }
  for (auto e : forbid) {
    if (subroutine(e)) {
      cout << "Yes" << endl;
      return 0;      
    }
  }
  cout << "No" << endl;
  return 0;
}
