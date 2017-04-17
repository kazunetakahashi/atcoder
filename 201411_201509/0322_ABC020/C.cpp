#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <tuple>
using namespace std;

const int C = 20;
int H, W, T;
bool table[C][C];
int Sx, Sy, Gx, Gy;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W);
}

void init() {
  cin >> H >> W >> T;
  fill(&table[0][0], &table[0][0]+C*C, false);
  for (auto x=0; x<H; x++) {
    for (auto y=0; y<W; y++) {
      char s;
      cin >> s;
      if (s == 'S') {
        Sx = x;
        Sy = y;
      } else if (s == 'G') {
        Gx = x;
        Gy = y;
      } else if (s == '#') {
        table[x][y] = true;
      }
    }
  }
}

bool dijkstra(int c) {
  priority_queue< tuple<long long, int, int> > Q; // -1 * cost, x, y
  Q.push(make_tuple(0, Sx, Sy));
  bool visited[C][C];
  fill(&visited[0][0], &visited[0][0]+C*C, false);
  while (!Q.empty()) {
    long long cost = -1 * get<0>(Q.top());
    int x = get<1>(Q.top());
    int y = get<2>(Q.top());
    Q.pop();
    if (!visited[x][y]) {
      visited[x][y] = true;
      if (x == Gx && y == Gy) {
        // cerr << "c = " << c << ", cost = " << cost << endl;
        return (cost <= T);
      }
      for (auto i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!valid(nx, ny)) continue;
        long long ncost = cost + (table[nx][ny] ? c : 1);
        if (!visited[nx][ny]) {
          Q.push(make_tuple(-1 * ncost, nx, ny));
        }
      }
    }
  }
  assert(false);
  return false;
}

int main() {
  init();
  int ub = 1000000010;
  int lb = 1;
  while (ub - lb > 1) {
    int n = (ub + lb)/2;
    if (dijkstra(n)) {
      lb = n;
    } else {
      ub = n;
    }
  }
  cout << lb << endl;
}
