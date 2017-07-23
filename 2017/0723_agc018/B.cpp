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
int A[310][310];
queue<int> Q[310];
set<int> S;

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < M; ++j) {
      cin >> A[i][j];
      A[i][j]--;
      Q[i].push(A[i][j]);
    }
  }
  int ans = N;
  while (true) {
    bool cont = true;
    for (auto i = 0; i < N; ++i) {
      if (Q[i].empty()) {
        cont = false;
        break;
      }
    }
    if (!cont) break;
    int cnt[310];
    fill(cnt, cnt+M, 0);
    for (auto i = 0; i < N; ++i) {
      cnt[Q[i].front()]++;
    }
    /*
    for (auto i = 0; i < M; ++i) {
      cerr << cnt[i] << " ";
    }
    cerr << endl;
    */
    int t = 0;
    int max_ind = 100000;
    for (auto i = 0; i < M; ++i) {
      if (t < cnt[i]) {
        t = cnt[i];
        max_ind = i;
      }
    }
    assert(max_ind < 100000);
    ans = min(ans, t);
    S.insert(max_ind);
    for (auto i = 0; i < N; ++i) {
      if (S.find(Q[i].front()) != S.end()) {
        Q[i].pop();
      }
    }
  }
  cout << ans << endl;
}
