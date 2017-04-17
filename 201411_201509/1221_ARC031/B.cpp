#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

typedef pair<int, int> point;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool field[10][10];
int cnt = 0;

bool isvalid(int x, int y) {
  return (0 <= x && x < 10 && 0 <= y && y < 10 && field[x][y]);
}

bool isconnected(int x, int y) {
  stack<point> S;
  S.push(make_pair(x, y));
  bool visited[10][10];
  fill(&visited[0][0], &visited[0][0]+10*10, false);
  int c = (field[x][y] ? 0 : -1);
  while (!S.empty()) {
    int nx = S.top().first;
    int ny = S.top().second;
    S.pop();
    if (!visited[nx][ny]) {
      cerr << "visiting " << nx << " " << ny << endl;
      visited[nx][ny] = true;
      c++;
      for (auto i=0; i<4; i++) {
        int sx = nx + dx[i];
        int sy = ny + dy[i];
        if (isvalid(sx, sy) && !visited[sx][sy]) {
          S.push(make_pair(sx, sy));
        }
      }
    }
  }
  return (c == cnt);
}

int main() {
  fill(&field[0][0], &field[0][0]+10*10, false);
  for (auto i=0; i<10; i++) {
    string S;
    cin >> S;
    for (auto j=0; j<10; j++) {
      if (S[j] == 'o') {
        field[i][j] = true;
        cnt++;
      }
    }
  }
  for (auto i=0; i<10; i++) {
    for (auto j=0; j<10; j++) {
      if (isconnected(i, j)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
