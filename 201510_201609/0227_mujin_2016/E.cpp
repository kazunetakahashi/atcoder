#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <complex>
using namespace std;

// 問題を勘違いしていた。

typedef complex<double> point;

double inner(point a, point b) {
  return (conj(a) * b).real();
}

point x[6];
point y[3];

int main() {
  double tx, ty;
  for (auto i = 0; i < 6; i++) {
    cin >> tx >> ty;
    x[i] = point(tx, ty);
  }
  double ans = 4000000000;
  for (auto i = 0; i < 2; i++) {
    point p = x[0+i] + x[2+i] - x[1+i];
    if (p == (x[2+i] + x[4+i] - x[3+i])
        && p == (x[4+i] + x[0+i] - x[(5+i)%6])) {
      cerr << p.real() << " " << p.imag() << endl;
      y[0] = x[i+0] - p;
      y[1] = x[i+2] - p;
      y[2] = x[i+4] - p;
      //cerr << y[0].real() << " " << y[0].imag() << endl;
      double r0r1 = -1 * inner(y[0], y[1]);
      cerr << r0r1 << endl;
      double r1r2 = -1 * inner(y[1], y[2]);
      double r2r0 = -1 * inner(y[0], y[1]);
      double r0sq = r0r1 * r2r0 / r1r2;
      double r1sq = r1r2 * r0r1 / r2r0;
      double r2sq = r2r0 * r1r2 / r0r1;
      if (r0sq > 0 && r1sq > 0 && r2sq > 0) {
        double tans = (inner(y[0], y[0]) + r0sq)
          * (inner(y[1], y[1]) + r1sq)
          * (inner(y[2], y[2]) + r2sq);
        ans = min(ans, sqrt(tans));
      }
    } else {
      continue;
    }
  }
  if (ans > 3900000000) {
    cout << "-1" << endl;
  } else {
    cout << fixed << setprecision(10) << ans << endl;
  }
}
