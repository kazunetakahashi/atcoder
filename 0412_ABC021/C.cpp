#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;
typedef tuple<int, int, ll> state; // 距離、頂点、回数

const ll M = 1000000007;
int infty = 100100100;

int main() {
  int N;
  cin >> N;
  int a, b;
  cin >> a >> b;
  a--; b--;
  int m;
  cin >> m;
  int T[110][110];
  fill(&T[0][0], &T[0][0]+110*110, infty);
  for (auto i=0; i<N; i++) {
    T[i][i] = 0;
  }
  vector<int> V[110];
  int x, y;
  for (auto i=0; i<m; i++) {
    cin >> x >> y;
    x--; y--;
    V[x].push_back(y);
    V[y].push_back(x);
    T[x][y] = T[y][x] = 1;
  }
  for (auto k=0; k<N; k++) {
    for (auto i=0; i<N; i++) {
      for (auto j=0; j<N; j++) {
        int x = T[i][k] + T[k][j];
        if (T[i][j] > x) T[i][j] = x;
      }
    }
  }
  int* dist = T[a];
  for (auto i=0; i<N; i++) {
    auto itr = V[i].begin();
    while(itr != V[i].end()) {
      if (dist[*itr] - dist[i] != 1) {
        itr = V[i].erase(itr);
      } else {
        itr++;
      }
    }
  }
  ll route[110];
  fill(route, route+110, 0);
  route[a] = 1;
  queue<int> Q;
  Q.push(a);
  bool visited[110];
  fill(visited, visited+N, false);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    if (!visited[v]) {
      visited[v] = true;
      for (auto i=0; i<(int)V[v].size(); i++) {
        int w = V[v][i];
        route[w] += route[v];
        route[w] %= M;
        if (!visited[w]) {
          Q.push(w);
        }
      }
    }
  }
  cout << route[b] << endl;
}
