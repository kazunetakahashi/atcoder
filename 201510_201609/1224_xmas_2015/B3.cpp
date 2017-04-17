#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <random>
#include <tuple>
using namespace std;

int choten[200010];
int p[200010];
int q[200010];
set<int> X[200010];
bool visited[200010];

typedef tuple<int, int> vert;
vert V[200010];
int N, M;
int have = 0;

void dfs(int i, int from) {
  if (visited[i]) return;
  if (from >= 0) {
    cout << i+1 << " " << from+1 << endl;
    have++;
  }
  visited[i] = true;
  if (have == N-1) return;
  int t = 0;
  auto it = X[i].begin();
  while (t < N && it != X[i].end()) {
    if (t == *it) {
      t++;
      it++;
    } else if (t < *it) {
      if (!visited[t]) {
        dfs(t, i);
        if (have == N-1) return;
      }
      t++;
    } else {
      it++;
    }
  }
  while (t < N) {
    if (!visited[t]) {
      dfs(t, i);
      if (have == N-1) return;
    }
    t++;
  }
}

int main() {
  cin >> N >> M;
  fill(choten, choten+N, N-1);
  for (auto i = 0; i < M; i++) {
    cin >> p[i] >> q[i];
    p[i]--; q[i]--;
    choten[p[i]]--;
    choten[q[i]]--;
    X[p[i]].insert(q[i]);
    X[q[i]].insert(p[i]);
  }
  for (auto i = 0; i < N; i++) {
    if (choten[i] == 0) {
      cout << "No" << endl;
      return 0;
    }    
  }
  cout << "Yes" << endl;
  for (auto i = 0; i < N; i++) {
    X[i].insert(i);
  }
  fill(visited, visited+N, false);
  for (auto i = 0; i < N; i++) {
    V[i] = make_tuple(choten[i], i);
  }
  sort(V, V+N);
  reverse(V, V+N);
  fill(visited, visited+N, false);
  dfs(get<1>(V[0]), -1);
}
