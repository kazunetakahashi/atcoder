#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int H, W;
string S[110];

bool valid(int x, int y) {
  return 0 <= x && x < H && 0 <= y && y < W;
}

bool nuri(int x, int y) {
  for (auto i = -1; i <= 1; i++) {
    for (auto j = -1; j <= 1; j++) {
      if (valid(x+i, y+j) && S[x+i][y+j] != '#') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    cin >> S[i];
  }
  bool T[110][110];
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      T[i][j] = nuri(i, j);
    }
  }
  bool U[110][110];
  fill(&U[0][0], &U[0][0]+110*110, false);
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (T[i][j]) {
        for (auto k = -1; k <= 1; k++) {
          for (auto l = -1; l <= 1; l++) {
            if (valid(i+k, j+l)) {
              U[i+k][j+l] = true;
            }
          }
        }
      }
    }
  }
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if ((S[i][j] == '#') != U[i][j]) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (T[i][j]) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}
