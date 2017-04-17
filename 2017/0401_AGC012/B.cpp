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

int N, M;
vector<int> V[100010];
int q;
int v[100010];
int d[100010];
int c[100010];
int ans[100010];
vector<int> res[100010];
int max_paint_d[100010];
int max_paint_i[100010];

typedef tuple<int, int, int> state; // vert, dist, ind;
stack<state> S;

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  cin >> q;
  for (auto i = 0; i < q; ++i) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
    S.push(state(v[i], d[i], i));
  }
  fill(ans, ans+N, 0);
  fill(max_paint_d, max_paint_d+N, 0);
  while (!S.empty()) {
    int src = get<0>(S.top());
    int dist = get<1>(S.top());
    int ind = get<2>(S.top());
    S.pop();
    if (ans[src] == 0) {
      ans[src] = c[ind];
    }
    if (max_paint_d[src] < dist) {
      max_paint_d[src] = dist;
      max_paint_i[src] = ind;
      if (dist >= 1) {
        for (auto dst : V[src]) {
          S.push(state(dst, dist-1, ind));
        }
      }
    }
  }
  for (auto i = 0; i < N; ++i) {
    cout << ans[i] << endl;
  }
}
