#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;

typedef tuple<int, int, int> state;

int N, K;
vector<int> V[2010];

int sakujo(int cent) {
  int visited[2010];
  fill(visited, visited+N, -1);
  queue<state> Q;
  int grand[2010];
  fill(grand, grand+N, -1);
  grand[cent] = cent;
  for (auto x : V[cent]) {
    grand[x] = x;
  }
  Q.push(make_tuple(cent, 0, 0));
  while (!Q.empty()) {
    state s = Q.front();
    int src = get<0>(s);
    int cnt = get<1>(s);
    int gra = get<2>(s);
    Q.pop();
    if (visited[src] == -1) {
      visited[src] = cnt;
      if (grand[src] == -1) {
        grand[src] = gra;
      }
      for (auto dst : V[src]) {
        if (visited[dst] == -1) {
          Q.push(make_tuple(dst, cnt+1, grand[src]));
        }
      }
    }
  }
  int cnt = 0;
  if (K%2 == 0) {
    for (auto i = 0; i < N; i++) {
      if (visited[i] <= K/2) cnt++;
    }
    return N - cnt;
  } else {
    map<int, int> M;
    for (auto i = 0; i < N; i++) {
      if (visited[i] <= K/2) {
        cnt++;
      } else if (visited[i] == K/2 + 1) {
        if (M.find(grand[i]) == M.end()) {
          M[grand[i]] = 1;
        } else {
          M[grand[i]]++;
        }
      }
    }
    int maxi = 0;
    for (auto x : M) {
      maxi = max(maxi, x.second);
    }
    cnt += maxi;      
    return N - cnt;
  }
}

int main() {
  cin >> N >> K;
  for (auto i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int mini = N;
  for (auto i = 0; i < N; i++) {
    mini = min(mini, sakujo(i));
  }
  cout << mini << endl;
}
