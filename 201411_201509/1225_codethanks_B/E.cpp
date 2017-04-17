#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

typedef pair<int, int> point;

int main() {
  int R, C;
  cin >> R >> C;
  point start, goal;
  int x, y;
  cin >> x >> y;
  x--; y--;
  start = make_pair(x, y);
  cin >> x >> y;
  x--; y--;
  goal = make_pair(x, y);
  int field[60][60];
  fill(&field[0][0], &field[0][0]+60*60, 0);
  int N;
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> x >> y;
    x--; y--;
    int h, w;
    cin >> h >> w;
    field[x][y]++;
    field[x+h][y]--;
    field[x][y+w]--;
    field[x+h][y+w]++;
  }
  for (auto i=0; i<R; i++) {
    for (auto j=1; j<C; j++) {
      field[i][j] += field[i][j-1];
    }
  }
  for (auto i=1; i<R; i++) {
    for (auto j=0; j<C; j++) {
      field[i][j] += field[i-1][j];
    }
  }
  for (auto i=0; i<R; i++) {
    for (auto j=0; j<C; j++) {
      cerr << field[i][j];
    }
    cerr << endl;
  }
  stack<point> S;
  if (field[start.first][start.second] >= 1) {
    S.push(start);
  }
  bool visited[60][60];
  fill(&visited[0][0], &visited[0][0]+60*60, false);
  while (!S.empty()) {
    int srcx = S.top().first;
    int srcy = S.top().second;
    S.pop();
    // cerr << "visiting (" << srcx << "," << srcy << ")" << endl;
    if (srcx == goal.first && srcy == goal.second) {
      cout << "YES" << endl;
      return 0;
    }
    if (!visited[srcx][srcy]) {
      visited[srcx][srcy] = true;
      for (auto i=0; i<4; i++) {
        int dstx = srcx + dx[i];
        int dsty = srcy + dy[i];
        if (0 <= dstx && dstx < R && 0<= dsty && dsty < C 
            && field[dstx][dsty] >= 1 && !visited[dstx][dsty]) {
          S.push(make_pair(dstx, dsty));
          // cerr << "pushing (" << dstx << "," << dsty << ")" << endl;
        }
      }
    }
  }
  cout << "NO" << endl;
}
