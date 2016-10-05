#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, int> state;

vector<state> V[40010];

int main() {
  int N, M;
  cin >> N >> M;
  N--;
  int a, b;
  ll c, d;
  for (auto i = 0; i < M; i++) {
    cin >> a >> b >> c >> d;
    a--; b--;
    V[a].push_back(make_tuple(d, c, b));
    V[b].push_back(make_tuple(d, c, a));
  }
  priority_queue<state, vector<state>, greater<state> > Q;
  Q.push(make_tuple(0, 1, 0));
  set<tuple<int, ll>> visited;
  while (!Q.empty()) {
    int src = get<2>(Q.top());
    ll cost = get<0>(Q.top());
    ll color = get<1>(Q.top());
    Q.pop();
    if (src == N) {
      cout << cost << endl;
      return 0;
    }
    if (visited.find(make_tuple(src, color)) == visited.end()) {
      //cerr << "src = " << src << ", cost = " << cost
      //     << ", color = " << color << endl;
      visited.insert(make_tuple(src, color));
      for (auto x : V[src]) {
        int dst = get<2>(x);
        ll tcost = get<0>(x);
        ll tcolor = get<1>(x);
        if (visited.find(make_tuple(dst, tcolor)) == visited.end()) {
          Q.push(make_tuple(cost+tcost+abs(color-tcolor), tcolor, dst));
        }
      }
    }
  }
}
