#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // if (S.find(key) != S.end()) { }
// for (auto i=S.begin(); i != S.end(); i++) { }
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;
typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

const int C = 100010;
int a[C], b[C], c[C];

ll mint(int i, ll t) { // 交差点iに時刻tについた時いつ青になるか
  ll ans = t;
  if (t < c[i]) return c[i];
  t -= c[i];
  t %= (a[i]+b[i]);
  if (t < a[i]) return ans;
  return ans + (a[i]+b[i] - t);
}

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  s--; d--;
  for (auto i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  int x[C], y[C], z[C];
  for (auto i=0; i<m; i++) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }
  vector< tuple<int, int> > V[C]; // node, cost
  for (auto i=0; i<m; i++) {
    V[x[i]].push_back(make_tuple(y[i], z[i]));
    V[y[i]].push_back(make_tuple(x[i], z[i]));
  }
  priority_queue< tuple<ll, int> > Q; // -1 * cost, node
  bool visited[C];
  fill(visited, visited+C, false);
  ll ans[C];
  Q.push(make_tuple(0, s));
  while (!Q.empty()) {
    ll cost = -1 * get<0>(Q.top());
    int node = get<1>(Q.top());
    Q.pop();
    if (node == d) {
      cout << cost << endl;
      return 0;
    }
    if (!visited[node]) {
      visited[node] = true;
      cost = mint(node, cost); // 交差点の待ち時間
      ans[node] = cost;
      for (auto i=0; i<V[node].size(); i++) {
	int dst = get<0>(V[node][i]);
	int tcost = get<1>(V[node][i]);
	if (!visited[dst]) {
	  Q.push(make_tuple(-1*(cost+tcost), dst));
	}
      }
    }
  }
}
