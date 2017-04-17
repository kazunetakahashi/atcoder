#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int memo[110][110];
bool a[110][110];
int row = 0;

int eat(int x, int y) {
  if (memo[x][y] != -1) return memo[x][y];
  if (x == y) {
    return (int)(!a[row][x]);
  }
  return memo[x][y] = max((int)a[row][x] + eat(x+1, y),
                          (int)a[row][y] + eat(x, y-1));
}

int main() {
  cin >> M >> N;
  int temp;
  for (auto i=0; i<M; i++) {
    for (auto j=0; j<N; j++) {
      cin >> temp;
      a[i][j] = (temp == 1);
    }
  }
  for (auto i=0; i<M; i++) {
    a[i][0] = !a[i][0];
    a[i][N-1] = !a[i][N-1];
  }
  for (auto j=0; j<N; j++) {
    a[0][j] = !a[0][j];
  }
  int ans = 0;
  for (row = 0; row<M; row++) {
    fill(&memo[0][0], &memo[0][0]+110*110, -1);
    ans += eat(0, N-1);
  }
  cout << ans << endl;
}
