#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int, int> rect;

int R, C, M, N;
int X[60][60], Y[60][60];
rect Rect[5010];

int count_south(rect r) {
  for (auto i=0; i<60; i++) {
    for (auto j=0; j<60; j++) {
      Y[i][j] = X[i][j];
    }
  }
  Y[get<0>(r)][get<2>(r)]--;
  Y[get<0>(r)][get<3>(r)]++;
  Y[get<1>(r)][get<2>(r)]++;
  Y[get<1>(r)][get<3>(r)]--;
  for (auto i=0; i<60; i++) {
    for (auto j=1; j<60; j++) {
      Y[i][j] += Y[i][j-1];
    }
  }
  for (auto i=1; i<60; i++) {
    for (auto j=0; j<60; j++) {
      Y[i][j] += Y[i-1][j];
    }
  }
  int ans = 0;
  for (auto i=0; i<R; i++) {
    for (auto j=0; j<C; j++) {
      if (Y[i][j]%4 == 0) ans++;
    }
  }
  return ans;
}

int main() {
  cin >> R >> C >> M >> N;
  fill(&X[0][0], &X[0][0]+60*60, 0);
  for (auto i=0; i<N; i++) {
    int r1, r2, c1, c2;
    cin >> r1 >> r2 >> c1 >> c2;
    r1--; c1--;
    Rect[i] = make_tuple(r1, r2, c1, c2);
    X[r1][c1]++;
    X[r1][c2]--;
    X[r2][c1]--;
    X[r2][c2]++;
  }
  for (auto i=0; i<N; i++) {
    if (M == count_south(Rect[i])) cout << i+1 << endl;
  }
}
