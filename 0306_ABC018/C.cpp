#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int R, C, K;
bool table[600][600];
int ud[600][600];

bool valid(int i, int j) {
  return (0 <= i && i < R && 0 <= j && j < C && table[i][j]);
}

void ud_fill(int i, int j) {
  int t = 0;
  while (valid(i + t, j) && valid(i - t, j)) {
    t++;
  }
  ud[i][j] = t;
}

bool ok(int i, int j) {
  for (auto t = -K+1; t<=K-1; t++) {
    // cerr << t << endl;
    if ((!valid(i, j+t)) || ud[i][j+t] < K-abs(t)) return false;      
  }
  return true;
}

int main() {
  cin >> R >> C >> K;
  string S;
  for (auto i=0; i<R; i++) {
    cin >> S;
    for (auto j=0; j<C; j++) {
      table[i][j] = (S[j] == 'o');
    }
  }
  for (auto i=0; i<R; i++) {
    for (auto j=0; j<C; j++) {
      ud_fill(i, j);
      // cerr << ud[i][j];
    }
    // cerr << endl;
  }
  int ans = 0;
  for (auto i=0; i<R; i++) {
    for (auto j=0; j<C; j++) {
      if (ok(i, j)) ans++;
    }
  }
  cout << ans << endl;
}
