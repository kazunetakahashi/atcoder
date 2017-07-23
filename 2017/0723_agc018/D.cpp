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
const ll infty = 100000000000007;

typedef tuple<int, int> edge; // vert, dist
typedef tuple<int, int> state; // vert, 

int N;
vector<edge> V[100010];
int parent[100010];
int c_size[100010];
ll dist[100010];

void dfs(int v, int p, ll d) {
  // cerr << v << " " << p << " " << d << endl;
  parent[v] = p;
  dist[v] = d;
  for (auto x : V[v]) {
    if (get<0>(x) != p) {
      dfs(get<0>(x), v, dist[v] + get<1>(x));
    }
  }
}

int child_size(int v) {
  // cerr << "v = " << v << endl;
  if (c_size[v] != -1) return c_size[v];
  int ans = 1;
  for (auto x : V[v]) {
    if (get<0>(x) != parent[v]) {
      // cerr << v << " " << get<0>(x) << endl;
      ans += child_size(get<0>(x));
    }
  }
  return c_size[v] = ans;
}

int centroid = 0;

int main () {
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a;
    --b;
    V[a].push_back(edge(b, c));
    V[b].push_back(edge(a, c));
  }
  dfs(0, -1, 0);
  fill(c_size, c_size+100010, -1);
  child_size(0);
  bool cont = true;
  while (cont) {
    cont = false;
    for (auto x : V[centroid]) {
      if (get<0>(x) != parent[centroid]) {
        if (child_size(get<0>(x)) > N/2) {
          centroid = get<0>(x);
          cont = true;
          break;
        }
      }
    }
  }
  dfs(centroid, -1, 0);
  fill(c_size, c_size+100010, -1);
  child_size(centroid);
  ll mini = infty;
  if (N % 2 == 0) {
    for (auto x : V[centroid]) {
      if (child_size(get<0>(x)) == N/2) {
        mini = get<1>(x);
        break;
      }
    }
  }
  if (mini == infty) {
    for (auto x : V[centroid]) {
      if (get<1>(x) < mini) {
        mini = get<1>(x);
      }
    }
  }
  ll ans = -mini;
  for (auto i = 0; i < N; ++i) {
    ans += 2 * dist[i];
  }
  cout << ans << endl;
}
