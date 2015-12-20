#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
using namespace std;

typedef tuple<int, int> vertex;

set<int> S[100010];
set<int> V[100010];
priority_queue<vertex> Q;

int main() {
  int N, M;
  cin >> N >> M;
  for (auto i = 0; i < M; i++) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    S[q].insert(p);
    V[p].insert(q);
  }
  for (auto i = 0; i < N; i++) {
    if (V[i].empty()) {
      Q.push(make_tuple(0, i));
    }
  }
  bool visited[100010];
  fill(visited, visited+100010, false);
  bool ans[100010];
  while (!Q.empty()) {
    int type = get<0>(Q.top());
    int now = get<1>(Q.top());
    Q.pop();
    if (!visited[now]) {
      // cerr << "now = " << now << endl;
      if (type == 0) {
        if (V[now].empty()) {
          ans[now] = false;
          visited[now] = true;
          // cerr << now << " is false" << endl;
          for (auto x : S[now]) {
            Q.push(make_tuple(1, x));
          }
        }
      } else {
        ans[now] = true;
        visited[now] = true;
        // cerr << now << " is true" << endl;
        for (auto x : S[now]) {
          Q.push(make_tuple(0, x));
          V[x].erase(V[x].find(now));
          // cerr << "V[" << x << "].size() = " << V[x].size() << endl;
        }
      }
    }
  }
  if (visited[0]) {
    cout << ((ans[0]) ? "Snuke" : "Sothe") << endl;
  } else {
    cout << "Draw" << endl;
  }
}
