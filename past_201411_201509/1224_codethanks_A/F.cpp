#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> V[60];

int main() {
  int N, M;
  cin >> N >> M;
  for (auto i=0; i<M; i++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    V[B].push_back(A);
  }
  stack<int> S;
  S.push(0);
  bool visited[60];
  fill(visited, visited+60, false);
  int ans = 0;
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      ans++;
      for (auto i=0; i<V[now].size(); i++) {
        int dst = V[now][i];
        if (!visited[dst]) {
          S.push(dst);
        }
      }
    }
  }
  cout << ans << endl;
}
