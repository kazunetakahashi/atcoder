#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int H, W;
int a[1010][1010];

const ll M = 1e9+7;

bool valid(int x, int y) {
  return 0 <= x && x < H && 0 <= y && y < W;
}

ll memo[1010][1010];

ll calc(int x, int y) {
  if (memo[x][y] >= 0) return memo[x][y];
  ll ans = 1;
  for (auto i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valid(nx, ny) && a[x][y] < a[nx][ny]) {
      ans += calc(nx, ny);
      ans %= M;
    }
  }
  return memo[x][y] = ans;
}

int main() {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  fill(&memo[0][0], &memo[0][0]+1010*1010, -1);
  ll ans = 0;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      ans += calc(i, j);
      ans %= M;
    }
  }
  cout << ans << endl;
}
