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
int a[100];
int b[100];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  int ans = 0;
  for (auto k = 0; k < M; ++k) {
    vector<int> V[100];
    for (auto i = 0; i < M; ++i) {
      if (i == k) continue;
      V[a[i]].push_back(b[i]);
      V[b[i]].push_back(a[i]);
    }
    bool visited[100];
    fill(visited, visited+N, false);
    stack<int> S;
    S.push(0);
    int cnt = 0;
    while (!S.empty()) {
      int now = S.top();
      S.pop();
      if (!visited[now]) {
        ++cnt;
        visited[now] = true;
        for (auto x : V[now]) {
          if (!visited[x]) {
            S.push(x);
          }
        }
      }
    }
    if (cnt < N) {
      ans++;
    }
  }
  cout << ans << endl;
}
