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

typedef tuple<int, int> state; // now, clr

ll N;
ll M;
vector<int> V[100010];

int main () {
  cin >> N >> M;
  for (auto i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int visited[100010];
  fill(visited, visited+100010, 0);
  int color[100010];
  fill(color, color+100010, -1);
  stack<state> S;
  S.push(state(0, 0));
  while (!S.empty()) {
    int now = get<0>(S.top());
    int clr = get<1>(S.top());
    S.pop();
    if (visited[now] == 0) {
      visited[now] = 1;
      color[now] = clr;
      S.push(state(now, clr));
      for (auto x : V[now]) {
        S.push(state(x, 1-clr));
      }
    } else if (visited[now] == 1) {
      if (color[now] != clr) {
        cout << N * (N-1) / 2 - M << endl;
        return 0;
      }      
    }
  }
  ll black = 0;
  for (auto i = 0; i < N; ++i) {
    if (color[i] == 1) black++;
  }
  cout << black * (N - black) - M << endl;
}
