#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int H, W;
string c[510];
int visited[510][510];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

struct point {
  int x, y;
};

struct state {
  point p;
  int b = 0;
};

int valid(point p) {
  if (!(0 <= p.x && p.x < H && 0 <= p.y && p.y < W)) {
    return -1;
  } else if (c[p.x][p.y] == '#') {
    return 1;
  } else {
    return 0;
  }
}

bool visit(state s) {
  return (visited[s.p.x][s.p.y] > s.b);
}

int main() {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    cin >> c[i];
  }
  point start, goal;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (c[i][j] == 's') {
        start.x = i;
        start.y = j;
      } else if (c[i][j] == 'g') {
        goal.x = i;
        goal.y = j;
      }
    }
  }
  stack<state> S;
  state s;
  s.p = start;
  s.b = 0;
  S.push(s);
  fill(&visited[0][0], &visited[0][0]+510*510, 3);
  while (!S.empty()) {
    state now = S.top();
    S.pop();
    if (visit(now)) {
      visited[now.p.x][now.p.y] = now.b;
      if (now.p.x == goal.x && now.p.y == goal.y) {
        cout << "YES" << endl;
        return 0;
      }
      for (auto i = 0; i < 4; i++) {
        state next;
        next.p.x = now.p.x + dx[i];
        next.p.y = now.p.y + dy[i];
        int hei = valid(next.p);
        if (hei == -1) {
          continue;
        } else {
          next.b = now.b + hei;
          if (visit(next)) {
            S.push(next);
          }
        }
      }
    }
  }
  cout << "NO" << endl;
}
