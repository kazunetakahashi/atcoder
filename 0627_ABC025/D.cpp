#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int> point;

int main() {
  int x[5][5];
  bool y[5][5];
  bool used[25];
  int cnt = 25;
  fill(used, used+25, false);
  for (auto i=0; i<5; i++) {
    for (auto j=0; j<5; j++) {
      cin >> x[i][j];
      x[i][j]--;
      y[i][j] = (x[i][j] == -1);
      if (!(y[i][j])) {
        used[x[i][j]] = true;
        cnt--;
      }
    }
  }
  if (cnt > 10) return 0; // 部分点
  int X[25];
  int* pt = X;
  for (auto i=0; i<25; i++) {
    if (!(used[i])) {
      *pt = i;
      pt++;
    }
  }
  point Y[25];
  point* pty = Y;
  for (auto i=0; i<5; i++) {
    for (auto j=0; j<5; j++) {
      if (y[i][j]) {
        *pty = make_tuple(i, j);
        pty++;
      }
    }
  }
  for (auto i=0; i<cnt; i++) {
    // cerr << X[i] << " ";
  }
  // cerr << endl;
  for (auto i=0; i<cnt; i++) {
    // cerr << "(" << get<0>(Y[i]) << "," << get<1>(Y[i]) << ") ";
  }
  // cerr << endl;

  sort(X, X+cnt);
  int ans = 0;
  do {
    for (auto i=0; i<cnt; i++) {
      int tx = get<0>(Y[i]);
      int ty = get<1>(Y[i]);
      x[tx][ty] = X[i];
    }
    bool ok = true;
    for (auto i=0; (ok && (i<5)); i++) {
      for (auto j=0; j<3; j++) {
        if ((x[i][j] < x[i][j+1] && x[i][j+1] < x[i][j+2])
            || (x[i][j] > x[i][j+1] && x[i][j+1] > x[i][j+2])) {
          ok = false;
          break;
        }
      }
    }
    for (auto j=0; (ok && (j<5)); j++) {
      for (auto i=0; i<3; i++) {
        if ((x[i][j] < x[i+1][j] && x[i+1][j] < x[i+2][j])
            || (x[i][j] > x[i+1][j] && x[i+1][j] > x[i+2][j])) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      ans++;
      // cerr << "ok table" << endl;
      for (auto i=0; i<5; i++) {
        for (auto j=0; j<5; j++) {
          // cerr << x[i][j] << " ";
        }
        // cerr << endl;
      }
    }
  } while (next_permutation(X, X+cnt));
  cout << ans << endl;
}
