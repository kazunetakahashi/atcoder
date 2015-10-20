#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

typedef tuple<int, int> pass;

int main() {
  int N, X;
  cin >> N >> X;
  int x, y, c;
  vector<pass> V[100010];
  for (auto i=0; i<N-1; i++) {
    cin >> x >> y >> c;
    x--; y--;
    V[x].push_back(make_tuple(y, c));
    V[y].push_back(make_tuple(x, c));
  }
  map<int, long long> M;
  stack<int> S;
  S.push(0);
  int res[100010];
  bool visited[100010];
  fill(visited, visited+100010, false);
  res[0] = 0;
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      for (auto x : V[now]) {
        int next = get<0>(x);
        int cost = get<1>(x);
        if (!visited[next]) {
          res[next] = res[now] ^ cost;
          S.push(next);
        }
      }
    }
  }
  for (auto i=0; i<N; i++) {
    if (M.find(res[i]) == M.end()) {
      M[res[i]] = 1;
    } else {
      M[res[i]]++;
    }
  }
  long long ans = 0;
  for (auto x : M) {
    int r = x.first ^ X;
    if (M.find(r) != M.end()) {
      ans += M[r] * x.second;
    }
  }
  if (X == 0) {
    ans -= N;
  }
  ans /= 2;
  cout << ans << endl;
}
