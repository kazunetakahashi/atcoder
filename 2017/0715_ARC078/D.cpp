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

vector<int> V[100010];
bool visited[100010];

typedef tuple<int, int> state;

int main () {
  int N;
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    int a, b;
    a--;
    b--;
    cin >> a >> b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  stack<state> S;
  S.push(state(0, 0));
  int parent;
  int D;
  fill(visited, visited+N, false);
  while (!S.empty()) {
    int now = get<0>(S.top());
    int d = get<1>(S.top());
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      if (now == N-1) {
        D = d;
        parent = now;
        break;
      }
      for (auto x : V[now]) {
        if (!visited[x]) {
          S.push(state(x, d+1));
        }
      }
    }
  }
  stack<state> SS;
  SS.push(state(N-1, 0));
  int cnt = 0;
  fill(visited, visited+N, false);
  while (!SS.empty()) {
    int now = get<0>(SS.top());
    int d = get<1>(SS.top());
    SS.pop();
    if (!visited[now]) {
      visited[now] = true;
      cnt++;
      for (auto x : V[now]) {
        if (!visited[x] && x != parent) {
          SS.push(state(x, d+1));
        }
      }
    }    
  }
  int su = (D-1)/2 + cnt - 1;
  int fa = N - 2 - fa;
  if (fa > su) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}
