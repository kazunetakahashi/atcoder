#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;

typedef tuple<int, int> pass; // dst dice
typedef tuple<int, int, int, int> state; // -cost, src, dice, from
typedef tuple<int, int> dice_map; // dice, from

int main() {
  int M;
  cin >> M;
  int a[6];
  for (auto i=0; i<6; i++) {
    cin >> a[i];
  }
  int s, g;
  cin >> s >> g;
  s--; g--;
  int N[310];
  for (auto i=0; i<M; i++) {
    cin >> N[i];
  }
  vector<pass> P[310]; // pass
  for (auto i=0; i<M; i++) {
    for (auto j=-6; j<=6; j++) {
      if (j == 0) continue;
      int t = i + j/abs(j) * a[abs(j)-1];
      if (0 <= t && t < M) {
        t += N[t];
        // i から j を出すと t にいける
        P[t].push_back(make_tuple(i, j));
      }
    }
  }
  vector<state> S[310];
  priority_queue<state> Q;
  Q.push(make_tuple(0, g, 0, g));
  bool visited[310];
  dice_map D[310];
  fill(visited, visited+310, false);
  while (!Q.empty()) {
    int cost = -get<0>(Q.top());
    int src = get<1>(Q.top());
    int dice = get<2>(Q.top());
    int from = get<3>(Q.top());
    Q.pop();
    if (!visited[src]) {
      visited[src] = true;
      D[src] = make_tuple(dice, from);
      if (src == s) break;
      for (auto e:P[src]) {
        int dst = get<0>(e);
        int n_dice = get<1>(e);
        if (!visited[dst]) {
          Q.push(make_tuple(-cost-1, dst, n_dice, src));
        }
      }
    }
  }
  int now = s;
  while (true) {
    int need_dice = get<0>(D[now]);
    int need_dst = get<1>(D[now]);
    while (true) {
      int given_dice;
      cin >> given_dice;
      if (given_dice == abs(need_dice)) {
        cout << need_dice/given_dice << endl;
        break;
      } else {
        cout << 0 << endl;
      }
    }
    now = need_dst;
    if (now == g) return 0;
  }
}
