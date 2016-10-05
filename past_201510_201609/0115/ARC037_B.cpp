#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V[110];

int main() {
  int N, M;
  cin >> N >> M;
  int u, v;
  for (auto i = 0; i < M; i++) {
    cin >> u >> v;
    u--; v--;
    V[u].push_back(v);
    V[v].push_back(u);
  }
  bool visited[110];
  fill(visited, visited+110, false);
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (visited[i]) continue;
    bool istree = true;
    stack<int> S;
    // int vert = 0;
    S.push(i);
    while (!S.empty()) {
      int now = S.top();
      S.pop();
      if (!visited[now]) {
        visited[now] = true;
        // vert++;
        int pass = 0;
        for (auto x : V[now]) {
          if (!visited[x]) {
            S.push(x);
          } else {
            pass++;
          }
        }
        if (pass >= 2) istree = false;
      }
    }
    if (istree) ans++;
  }
  cout << ans << endl;
}
