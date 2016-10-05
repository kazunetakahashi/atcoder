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

int main() {
  int N, M;
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
  int have = 0;
  int t = 0;
  auto it = X[get<1>(V[0])].begin();
  visited[get<1>(V[0])] = true;
  while (t < N && it != X[get<1>(V[0])].end()) {
    if (t == *it) {
      t++;
      it++;
    } else if (t < *it) {
      if (!visited[t]) {
        cout << get<1>(V[0])+1 << " " << t+1 << endl;
        visited[t] = true;
        have++;
        if (have == N-1) return 0;
      }
      t++;
    } else {
      it++;
    }
  }
  while (t < N) {
    if (!visited[t]) {
      cout << get<1>(V[0])+1 << " " << t+1 << endl;
      visited[t] = true;
      have++;
      if (have == N-1) return 0;
    }
    t++;
  }
  for (auto i = 1; i < N; i++) {
    if (visited[get<1>(V[i])]) continue;
    int t = 0;
    auto it = X[get<1>(V[i])].begin();
    while (t < N && it != X[get<1>(V[i])].end()) {
      if (t == *it) {
        t++;
        it++;
      } else if (t < *it) {
        if (visited[t]) {
          cout << get<1>(V[i])+1 << " " << t+1 << endl;
          visited[get<1>(V[i])] = true;
          have++;
          if (have == N-1) return 0;
          break;
        }
        t++;
      } else {
        it++;
      }
    }
    while (t < N) {
      if (!visited[t]) {
        cout << get<1>(V[i])+1 << " " << t+1 << endl;
        visited[get<1>(V[i])] = true;
        have++;
        if (have == N-1) return 0;
        break;
      }
      t++;
    } 
  }
}
