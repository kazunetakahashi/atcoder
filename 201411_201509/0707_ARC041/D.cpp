#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, bool> > V[2010]; // V[src] -> (dst, edge_id, color)
  int a, b;
  char ch;
  int tc;
  for (auto i=0; i<M; i++) {
    cin >> a >> b >> ch;
    a--; b--;
    tc = (ch == 'r');
    V[a].push_back(make_tuple(b, i, tc));
    V[b].push_back(make_tuple(a, i, tc));
  }
  for (auto i=0; i<N; i++) {
    for (auto j=0; j<2; j++) {
      queue<tuple<int, bool> > Q; // vert, color
      Q.push(make_tuple(i, (j == 0)));
      bool visited[2010]; // edge
      fill(visited, visited+M, false);
      int ve = 0;
      int dep[2010]; // vert
      fill(dep, dep+N, -1);
      while (!Q.empty()) {
        int src = get<0>(Q.front());
        bool c = get<1>(Q.front());
        Q.pop();
        if (dep[src] == -1) {
          dep[src] = (c ? 0 : 1);
          for (auto e:V[src]) {
            int dst = get<0>(e);
            int id = get<1>(e);
            bool nc = get<2>(e);
            if (nc == c && (!visited[id])) {
              visited[id] = true;
              ve++;
              Q.push(make_tuple(dst, !c));
              if (ve == M) {
                cout << "Yes" << endl;
                return 0;
              }
            }
          }
        } else if (dep[src] != (c ? 0 : 1)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
