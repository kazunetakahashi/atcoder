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

int N, K, X;
vector<int> S;
set<int> SS;

typedef tuple<int, int> pass;

int main () {
  cin >> N >> K >> X;
  for (auto i = 0; i < K; ++i) {
    int s;
    cin >> s;
    S.push_back(s);
    SS.insert(s);
  }
  int ans = 0;
  for (auto i = 0; i < (1 << (N+1)); ++i) {
    vector<int> T;
    bool ok = true;
    for (auto j = 0; j <= N; ++j) {
      bool x = (SS.find(j) != SS.end());
      bool y = (((i >> j) & 1) == 1);
      if (x && !y) {
        ok = false;
        break;
      }
      if (y) {
        T.push_back(j);
      }      
    }
    if (!ok) continue;
    vector<int> V[17];
    for (auto i = 0; i < N; ++i) {
      V[i].push_back(i+1);
      V[i+1].push_back(i);
    }
    for (auto it = S.begin(); it+1 != S.end(); ++it) {
      V[*it].push_back(*(it+1));
      V[*(it+1)].push_back(*it);
    }
    for (auto it = T.begin(); it+1 != T.end(); ++it) {
      V[*it].push_back(*(it+1));
      V[*(it+1)].push_back(*it);
    }
    priority_queue<pass, vector<pass>, greater<pass> > Q;
    Q.push(pass(0, 0));
    int visited[17];
    fill(visited, visited+17, -1);
    while (!Q.empty()) {
      int cost = get<0>(Q.top());
      int now = get<1>(Q.top());
      Q.pop();
      if (visited[now] == -1) {
        visited[now] = cost;
        for (auto x : V[now]) {
          if (visited[x] == -1) {
            Q.push(pass(cost+1, x));
          }
        }
      }
    }
    int maxi = 0;
    for (auto i = 0; i < N; ++i) {
      maxi = max(maxi, visited[i]);
    }
    if (maxi <= X) {
      ans++;
    }
  }
  cout << ans << endl;
}
