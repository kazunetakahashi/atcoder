#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

typedef complex<double> point;

int main() {
  int N;
  cin >> N;
  point star[2][100010];
  point g[2] = {0, 0};
  double m[2] = {-1, -1}; 
  double tx, ty;
  for (auto i=0; i<2; i++) {
    for (auto j=0; j<N; j++) {
      cin >> tx >> ty;
      star[i][j] = point(tx, ty);
      g[i] += star[i][j];
    }
    g[i] /= N;
    for (auto j=0; j<N; j++) {
      m[i] = max(m[i], abs(star[i][j] - g[i]));
    }
  }
  cout << fixed << setprecision(9) << m[1]/m[0] << endl;
}
