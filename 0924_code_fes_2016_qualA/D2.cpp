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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;
typedef pair<int, ll> point;

int R, C;
int N;
int r[100010], c[100010];
ll a[100010];
vector<point> V[100010];
map<int, ll> W[100010];
ll mini[100010];
int ind[100010];

void merge(int p, int q, ll sub) {
  if (W[p].size() > W[q].size()) {
    merge(q, p, -sub);
  } else {
    for (auto x : W[p]) {
      int col = x.first;
      ll val = x.second;
      ind[col] = q;
      W[q][col] = val + sub;
    }
    mini[q] = min(mini[q], mini[p] + sub);
  }
}

bool issame(int p, int q) {
  return (ind[p] == ind[q]);
}

ll calc_sa(int p, int q) {
  return W[ind[q]][q] - W[ind[p]][p];
}

int main() {
  cin >> R >> C;
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> r[i] >> c[i] >> a[i];
    r[i]--; c[i]--;
    V[r[i]].push_back(make_pair(c[i], a[i]));
  }
  for (auto i = 0; i < C; i++) {
    W[i].insert(make_pair(i, 0));
    ind[i] = i;
  }
  fill(mini, mini+N, 0);
  for (auto i = 0; i < R; i++) {
    /*
    cerr << "i = " << i << endl;
    bool visited[100010];
    fill(visited, visited+100010, false);
    for (auto i = 0; i < C; i++) {
      int v = ind[i];
      if (!visited[v]) {
        visited[v] = true;
        cerr << "v = " << v << ", ";
        for (auto x : W[v]) {
          cerr << x.first << ":" << x.second << " ";
        }
        cerr << ", mini = " << mini[v] << endl;
      }
    }
    */
    if (V[i].empty()) continue;
    int col = V[i][0].first;
    ll val = V[i][0].second;    
    for (auto it = V[i].begin()+1; it != V[i].end(); it++) {
      int ncol = (*it).first;
      ll nval = (*it).second;
      if (issame(col, ncol)) {
        if (calc_sa(col, ncol) == nval - val) {
          // nothing
        } else {
          /*
          cerr << "calc_sa(" << col << ", " << ncol << ") = "
               << calc_sa(col, ncol) << endl;
          cerr << "nval - val = " << nval << " - " << val << endl;
          */
          cout << "No" << endl;
          return 0;
        }
      } else {
        ll desired = calc_sa(col, ncol) - (nval - val);
        merge(ind[col], ind[ncol], desired);
      }
    }
  }
  for (auto i = 0; i < R; i++) {
    if (V[i].empty()) continue;
    int col = V[i][0].first;
    ll val = V[i][0].second;
    if (mini[ind[col]] - W[ind[col]][col] + val < 0) {
      // cerr << mini[ind[col]] << " - " << W[ind[col]][col] << endl;
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
