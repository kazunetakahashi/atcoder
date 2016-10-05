#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int> pass; // cost, dst

int S[100010];
int L[100010];
vector<pass> V[100010];

int main() {
  int N, M;
  cin >> N >> M;
  for (auto i=0; i<N; i++) {
    cin >> S[i] >> L[i];
  }
  for (auto i=0; i<N; i++) {
    V[S[i]].push_back(make_tuple(L[i], S[i]+L[i]));
  }
  for (auto i=0; i<M; i++) {
    V[i].push_back(make_tuple(2, i+1));
    V[i+1].push_back(make_tuple(0, i));
  }
  priority_queue<pass, vector<pass>, greater<pass> > Q;
  Q.push(make_tuple(0, 0));
  int visited[100010];
  fill(visited, visited+100010, -1);
  while (!Q.empty()) {
    int cost = get<0>(Q.top());
    int src = get<1>(Q.top());
    Q.pop();
    if (visited[src] == -1) {
      visited[src] = cost;
      if (src == M) {
        cout << 2 * M - cost << endl;
        return 0;
      }
      for (auto x : V[src]) {
        int ncost = get<0>(x);
        int dst = get<1>(x);
        if (visited[dst] == -1) {
          Q.push(make_tuple(cost+ncost, dst));
        }       
      }
    }
  }
}
