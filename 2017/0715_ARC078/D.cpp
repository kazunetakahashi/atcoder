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
int parents[100010];

typedef tuple<int, int, int> state; // now, d, from

int main () {
  int N;
  cin >> N;
  for (auto i = 0; i < N-1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  stack<state> S;
  S.push(state(0, 0, -1));
  int cut;
  int D;
  fill(visited, visited+N, false);
  while (!S.empty()) {
    int now = get<0>(S.top());
    int d = get<1>(S.top());
    int from = get<2>(S.top());
    S.pop();
    if (!visited[now]) {
      // cerr << "now = " << now << ", d = " << d << endl;
      visited[now] = true;
      parents[now] = from;
      if (now == N-1) {
        D = d;
        break;
      }
      for (auto x : V[now]) {
        if (!visited[x]) {
          S.push(state(x, d+1, now));
        }
      }
    }
  }
  stack<state> SS;
  SS.push(state(N-1, 0, parents[N-1]));
  int cnt = 0;
  cut = N-1;
  for (auto i = 0; i < (D-1)/2; ++i) {
    cut = parents[cut];
  }
  fill(visited, visited+N, false);
  while (!SS.empty()) {
    int now = get<0>(SS.top());
    int d = get<1>(SS.top());
    SS.pop();
    if (!visited[now]) {
      visited[now] = true;
      cnt++;
      for (auto x : V[now]) {
        if (!visited[x] && x != parents[cut]) {
          SS.push(state(x, d+1, now));
        }
      }
    }    
  }
  int su = cnt - 1;
  int fa = N - 2 - su;
  cerr << "D = " << D << endl;
  cerr << "cut = " << cut << endl;
  cerr << "cnt = " << cnt << endl;
  cerr << "su = " << su << ", fa = " << fa << endl;
  if (fa > su) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}
