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

int N, M;
vector<edge> V[100010];
stack<int> S;
int visited[100010];
bool loop = false;
int d[100010];

void visit(int n) {
  if (visited[n] == 1) {
    loop = true;
  } else if (visited[n] == 0) {
    visited[n] = 1;
    for (auto x : V[n]) {
      int m = get<0>(x);
      visit(m);
    }
    visited[n] = 2;
    S.push(n);
  }
}

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int L, R, D;
    cin >> L >> R >> D;
    L--;
    R--;
    V[L].push_back(edge(R, D));
  }
  for (auto i = 0; i < N; ++i) {
    visit(i);
  }
  if (loop) {
#if DEBUG == 1
    cerr << "loop" << endl;
#endif
    cout << "No" << endl;
    return 0;
  }
  fill(d, d+100010, -1);
  d[S.top()] = 0;
  while (!S.empty()) {
    int now = S.top();
    // cerr << "now = " << now << endl;
    S.pop();
    for (auto x : V[now]) {
      int dst = get<0>(x);
      int dist = get<1>(x);
      if (d[dst] == -1) {
        d[dst] = dist + d[now];
      } else {
        if (d[dst] == dist + d[now]) {
          //
        } else {
#if DEBUG == 1
          cerr << "d[" << dst << "] = " << d[dst] << endl;
          cerr << "dist = " << dist
               << ", d[" << now << "] = " << d[now] << endl;
#endif
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}
