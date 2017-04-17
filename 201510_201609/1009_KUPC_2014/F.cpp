#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;
typedef complex<double> point;
typedef long long ll;

ll DP[1010][3000];
vector< pair<int, ll> > T[1010];

int N;
point X[1010];
int d[1010];
int c[1010];
bool visited[1010];

void call(int p) {
  visited[p] = true;
  for (auto e:T[p]) {
    int child = e.first;
    if (visited[child]) continue;
    call(child);
  }
  for (auto i=2999; i>=0; i--) {
    if (i < 2999) {
      DP[p][i] = DP[p][i+1];
    } else {
      DP[p][i] = ((ll)1 << 60);
    }
    ll ans = c[p] * i;
    for (auto e:T[p]) {
      int child = e.first;
      int cost = e.second;
      ans += DP[child][max(cost-i, 0)];
    }
    DP[p][i] = min(DP[p][i], ans);
  }
}

int main() {
  fill(visited, visited+1010, false);
  cin >> N;
  double x, y;
  for (auto i=0; i<N; i++) {
    cin >> x >> y;
    X[i] = point(x, y);
  }
  for (auto i=0; i<N; i++) {
    cin >> d[i] >> c[i];
  }
  int u, v, n;
  for (auto i=0; i<N-1; i++) {
    cin >> u >> v;
    u--; v--;
    n = max(0, (int)ceil(abs(X[u]-X[v]) - d[u] - d[v]));
    T[u].push_back(make_pair(v, n));
    T[v].push_back(make_pair(u, n));
  }
  call(0);
  cout << DP[0][0] << endl;
}
