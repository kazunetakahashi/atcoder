#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int a[100010];
vector<int> V[100010];
int ans[100010];

void writeans(int i, int x) {
  if (ans[i] == -1) {
    ans[i] = x;
  } else {
    if (abs(a[i] - x) < abs(a[i] - ans[i])) {
      ans[i] = x;
    } else if (abs(a[i] - x) == abs(a[i] - ans[i]) && x < ans[i]) {
      ans[i] = x;
    }
  }
}

int N;
int root;
set<int> M;

void findans() {
  M.clear();
  stack<int> S;
  S.push(root);
  bool visited[100010];
  fill(visited, visited+N, false);
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    if (!visited[now]) {
      visited[now] = true;
      S.push(now);
      for (auto x : V[now]) {
        S.push(x);
      }
      // cerr << "visiting : " << now << endl;
      auto it = M.lower_bound(a[now]);
      if (it != M.end()) {
        // cerr << *it << endl;
        writeans(now, *it);
      }
      if (it != M.begin()) {
        it--;
        // cerr << *it << endl;
        writeans(now, *it);
      }
    } else {
      M.insert(a[now]);
    }
  }
}

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  bool ischild[100010];
  fill(ischild, ischild+N, false);
  for (auto i = 0; i < N-1; i++) {
    int s, t;
    cin >> s >> t;
    V[s].push_back(t);
    ischild[t] = true;
  }
  fill(ans, ans+N, -1);
  for (auto i = 0; i < N; i++) {
    if (!ischild[i]) {
      root = i;
      break;
    }
  }
  findans();
  for (auto i = 0; i < N; i++) {
    reverse(V[i].begin(), V[i].end());
  }
  findans();
  for (auto i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
}
