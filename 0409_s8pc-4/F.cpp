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

int H, W, N;
ll f;
int sx, sy, gx, gy;
int a[70010];
int b[70010];
char c[70010];
int d[70010];
ll e[70010];

typedef tuple<ll, int> pass;
vector<pass> V[100010];

int main () {
  cin >> H >> W >> N >> f;
  cin >> sx >> sy >> gx >> gy;
  sx--; sy--; gx--; gy--;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    a[i]--; b[i]--;
    if (c[i] == 'E') d[i] = -1 * d[i];
  }
  assert(H == 1);
  for (auto i = 0; i < W-1; ++i) {
    V[i].push_back(pass(f, i+1));
    V[i+1].push_back(pass(f, i));
  }
  for (auto i = 0; i < N; ++i) {
    V[a[i]].push_back(pass(0, b[i]+d[i]));
    int gyaku = a[i]-d[i];
    if (0 <= gyaku && gyaku < W) { 
      V[a[i]].push_back(pass(e[i], gyaku));
    }
  }
  priority_queue<pass, vector<pass>, greater<pass> > Q;
  Q.push(pass(0, sy));
  int visited[100010];
  fill(visited, visited+100010, -1);
  while (!Q.empty()) {
    ll cost = get<0>(Q.top());
    int now = get<1>(Q.top());
    Q.pop();
    if (visited[now] == -1) {
      visited[now] = cost;
      if (now == gy) {
        cout << cost << endl;
        return 0;
      }
      for (auto x : V[now]) {
        ll newcost = cost + get<0>(x);
        int dst = get<1>(x);
        if (visited[dst] == -1) {
          Q.push(pass(newcost, dst));
        }
      }
    }
  }
}
