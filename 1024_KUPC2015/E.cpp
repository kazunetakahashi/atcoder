#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

double H, W;
const double epsilon = 0.0000001;

void solve() {
  if (H < W) swap(H, W);
  double lb = W;
  double ub = 2 * sqrt(H*H + W*W);
  while (ub - lb > epsilon) {
    double t = (ub+lb)/2;
    bool ok = true;
    double x, y, X, Y;
    if (t < W) {
      ok = true;
      goto EXIT;
    }
    y = sqrt(t*t - W*W);
    if (t < H) {
      x = 0;
    } else {
      x = sqrt(t*t - H*H);
    }
    X = W-x;
    Y = H-y;
    ok = (sqrt(X*X+Y*Y) > t);
  EXIT:
    if (ok) {
      lb = t;
    } else {
      ub = t;
    }
  }
  cout << fixed << setprecision(10) << lb << endl;
}

int main() {
  int T;
  cin >> T;
  for (auto i=0; i<T; i++) {
    cin >> H >> W;
    solve();
  }
}
