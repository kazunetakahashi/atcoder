#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, x;
int h[110];
vector<int> V[110];
vector<int> child[110];
int need[110];

int check(int y) {
  if (need[y] != -1) {
    return need[y];
  }
  if (child[y].empty()) {
    return need[y] = h[y];
  }
  int ans = h[y];
  for (auto z : child[y]) {
    ans += check(z);
  }
  return need[y] = ans;
}

int main() {
  cin >> n >> x;
  x--;
  for (auto i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (auto i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  bool visited[110];
  fill(visited, visited+110, false);
  stack<int> S;
  S.push(x);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      for (auto y : V[now]) {
        if (!visited[y]) {
          S.push(y);
          child[now].push_back(y);
        }
      }
    }
  }
  fill(need, need+110, -1);
  check(x);
  int ans = 0;
  for (auto i = 0; i < n; i++) {
    if (need[i] > 0) ans++; 
  }
  if (ans == 0) {
    cout << 0 << endl;
  } else {
    cout << (ans-1) * 2 << endl;
  }
}
