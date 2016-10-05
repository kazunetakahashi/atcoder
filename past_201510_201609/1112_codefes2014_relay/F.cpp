#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pass;

vector<int> V[100010];

int main() {
  int n;
  cin >> n;
  for (auto i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  stack<pass> S;
  int dist[100010];
  fill(dist, dist+100010, -1);
  S.push(make_pair(0, 0));
  while (!S.empty()) {
    int now = S.top().first;
    int d = S.top().second;
    S.pop();
    if (dist[now] == -1) {
      dist[now] = d;
      for (auto e : V[now]) {
        if (dist[e] == -1) {
          S.push(make_pair(e, d+1));
        } else if (dist[now] - dist[e] > 1) {
          cout << dist[now] - dist[e] + 1 << endl;
          return 0;
        }
      }
    }
  }
}
