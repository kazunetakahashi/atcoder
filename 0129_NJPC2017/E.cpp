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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const ll M = 1000000007;

typedef tuple<int, int, bool> pass;
typedef tuple<int, int> state;

int N, D;
vector<pass> V[100020];

int main () {
  cin >> N >> D;
  for (auto i = 0; i < N; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    A--; B--;
    V[A].push_back(pass(B, C, true));
    V[B].push_back(pass(A, C, false));
  }
  int dist[100010];
  fill(dist, dist+N, -1);
  stack<state> S;
  S.push(state(0, 0));
  while (!S.empty()) {
    int src = get<0>(S.top());
    int d = get<0>(S.top());
    S.pop();
    if (dist[src] == -1) {
      dist[src] = d;
      for (auto x : V[src]) {
        int dst = get<0>(x);
        int cost = get<1>(x);
        if (dist[dst] == -1) {
          S.push(state(dst, d + cost));
        }
      }
    }
  }
  int ind_left = 0;
  int maxi = 0;
  for (auto i = 0; i < N; i++) {
    if (maxi < dist[i]) {
      maxi = dist[i];
      ind_left = i;
    }
  }
  int dist2[100010];
  fill(dist2, dist2+N, -1);
  stack<state> SS;
  SS.push(state(ind_left, 0));
  while (!S.empty()) {
    int src = get<0>(SS.top());
    int d = get<0>(SS.top());
    SS.pop();
    if (dist[src] == -1) {
      dist[src] = d;
      for (auto x : V[src]) {
        int dst = get<0>(x);
        int cost = get<1>(x);
        if (dist[dst] == -1) {
          SS.push(state(dst, d + cost));
        }
      }
    }
  }
  int ind_right = 0;
  maxi = 0;
  for (auto i = 0; i < N; i++) {
    if (maxi < dist2[i]) {
      maxi = dist2[i];
      ind_right = i;
    }
  }
  
}
