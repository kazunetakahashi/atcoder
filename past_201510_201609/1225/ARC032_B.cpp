#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> V[100010];
bool visited[100010];

int main() {
  int N, M;
  cin >> N >> M;
  int a, b;
  for (auto i = 0; i < M; i++) {
    cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int ans = -1;
  fill(visited, visited+N, false);
  for (auto i = 0; i < N; i++) {
    if (!visited[i]) {
      ans++;
      stack<int> S;
      S.push(i);
      while (!S.empty()) {
        int now = S.top();
        S.pop();
        if (!visited[now]) {
          visited[now] = true;
          for (auto x : V[now]) {
            if (!visited[x]) {
              S.push(x);
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}
