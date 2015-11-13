#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long ll;
typedef tuple<ll, int> pass; // cost, dst

int a[100010];
int b[100010];
int c[100010];
vector<pass> V[100010];

ll wait(int n, ll t) {
  if (t < c[n]) return c[n];
  ll amari = (t-c[n])%(a[n]+b[n]);
  if (amari >= a[n]) {
    return t - amari + a[n] + b[n];
  }
  return t;
}

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  s--; d--;
  for (auto i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (auto i=0; i<m; i++) {
    int x, y;
    ll t;
    cin >> x >> y >> t;
    x--; y--;
    V[x].push_back(make_tuple(t, y));
    V[y].push_back(make_tuple(t, x));
  }
  ll dist[100010];
  fill(dist, dist+100010, -1);
  priority_queue<pass, vector<pass>, greater<pass> > Q;
  Q.push(make_tuple(0, s));
  while (!Q.empty()) {
    int src = get<1>(Q.top());
    ll t = get<0>(Q.top());
    Q.pop();
    if (dist[src] == -1) {
      if (src == d) {
        cout << t << endl;
        return 0;
      }
      dist[src] = t;
      t = wait(src, t);
      for (auto e : V[src]) {
        int dst = get<1>(e);
        ll cost = get<0>(e);
        if (dist[dst] == -1) {
          Q.push(make_pair(t+cost, dst));
        }
      }
    }
  }
}
