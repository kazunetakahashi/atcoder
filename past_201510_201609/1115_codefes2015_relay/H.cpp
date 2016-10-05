#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> pass; // cost, x, y;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int H, W;
string S[510];
vector<pass> V[510][510];

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W);
}

int main() {
  cin >> H >> W;
  for (auto i=0; i<H; i++) {
    cin >> S[i];
  }
  for (auto i=0; i<H; i++) {
    for (auto j=0; j<W; j++) {
      for (auto k=0; k<4; k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if (valid(nx, ny)) {
          V[i][j].push_back(make_tuple((int)(S[i][j] != S[nx][ny]), nx, ny));
        }
      }
    }
  }
  priority_queue<pass, vector<pass>, greater<pass> > Q;
  int visited[510][510];
  fill(&visited[0][0], &visited[0][0]+510*510, -1);
  Q.push(make_tuple(0, 0, 0));
  while (!Q.empty()) {
    int cost = get<0>(Q.top());
    int x = get<1>(Q.top());
    int y = get<2>(Q.top());
    Q.pop();
    if (visited[x][y] == -1) {
      visited[x][y] = cost;
      // cerr << "x = " << x << ", y = " << y << ", cost = " << cost << endl;
      if ((x == H-1) && (y == W-1)) {
        cout << cost << endl;
        return 0;
      }
      for (auto e : V[x][y]) {
        int ncost = get<0>(e);
        int nx = get<1>(e);
        int ny = get<2>(e);
        if (visited[nx][ny] == -1) {
          Q.push(make_tuple(cost+ncost, nx, ny));
        }
      }
    }
  }
}
