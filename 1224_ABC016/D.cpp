#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<double> point;

double inner_product(point x, point y) {
  return (conj(x) * y).real();
}

double outer_product(point x, point y) {
  return (conj(x) * y).imag();
}

point normalize(point a) {
  return a * (1/abs(a)); // normはabsの2乗、absは本来のノルム。
}

point projection(point a, point b) {
  point e = normalize(b);
  return e * inner_product(a, e);
}

bool opposite(point a1, point a2, point b1, point b2) { // 直線a1a2に対し、b1とb2が反対側か否か。ただし端点は考慮しない。
  return (outer_product(a2-a1, b1-a1) * outer_product(a2-a1, b2-a1) < 0);
}

bool crossed(point a1, point a2, point b1, point b2) { // 線分a1a2と線分b1b2が交点を持つか否か。ただし端点は考慮しない。
  return ( opposite(a1, a2, b1, b2) && opposite(b1, b2, a1, a2) );
}

int main() {
  double Ax, Ay, Bx, By;
  cin >> Ax >> Ay >> Bx >> By;
  point A = point(Ax, Ay);
  point B = point(Bx, By);
  int N;
  cin >> N;
  point X[110];
  for (auto i=0; i<N; i++) {
    double x, y;
    cin >> x >> y;
    X[i] = point(x, y);
  }
  int ans = 0;
  for (auto i=0; i<N; i++) {
    if (crossed(A, B, X[i], X[(i+1)%N])) ans++;
  }
  cout << ans/2 + 1 << endl;
}
