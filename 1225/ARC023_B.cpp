#include <iostream>
using namespace std;

int T[1010][1010];

int main() {
  int R, C, D;
  cin >> R >> C >> D;
  for (auto i = 0; i < R; i++) {
    for (auto j = 0; j < C; j++) {
      cin >> T[i][j];
    }
  }
  int maxi = -1;
  int mod = D%2;
  for (auto i = 0; i < R; i++) {
    for (auto j = 0; j < C; j++) {
      if (i + j <= D && (i+j)%2 == mod) {
        maxi = max(maxi, T[i][j]);
      }
    }
  }
  cout << maxi << endl;
}
