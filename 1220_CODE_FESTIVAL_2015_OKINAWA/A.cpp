#include <iostream>
#include <algorithm>
using namespace std;

char M[110][110];

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  fill(&M[0][0], &M[0][0]+110*110, '.');
  int ans = 0;
  for (auto i = 0; i < H; i++) {
    if (i%2 == 1) continue;
    for (auto j = 0; j < W; j++) {
      if (j%2 == 1) continue;
      M[i][j] = '#';
      ans++;
      if (ans == K) goto EXIT;
    }
  }
 EXIT:
  if (ans == K) {
    for (auto i = 0; i < H; i++) {
      for (auto j = 0; j < W; j++) {
        cout << M[i][j];
      }
      cout << endl;
    }
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
