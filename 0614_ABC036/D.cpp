#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;

int N;
vector<int> V[100010];
const ll M = 1e9+7;
ll memo[2][100010];
int parent[100010];

ll calc(bool b, int v) {
  if (memo[b][v] != -1) return memo[b][v];
  ll ret = 1;
  for (auto x : V[v]) {
    if (x == parent[v]) continue;
    if (b) {
      ret *= calc(false, x);
    } else {
      ret *= (calc(true, x) + calc(false, x))%M;
    }
    ret %= M;
  }
  return memo[b][v] = ret;
}

int main() {
  cin >> N;
  for (auto i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  fill(&memo[0][0], &memo[0][0]+2*100010, -1);
  stack<int> S;
  S.push(0);
  parent[0] = -1;
  while(!S.empty()) {
    int now = S.top();
    S.pop();
    for (auto x : V[now]) {
      if (x == parent[now]) continue;
      S.push(x);
      parent[x] = now;
    }
  }
  cout << (calc(true, 0) + calc(false, 0))%M << endl;
}
