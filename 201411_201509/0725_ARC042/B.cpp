#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
using namespace std;

typedef complex<double> point;

double area(point a, point b, point c) {
  point x = a - c;
  point y = b - c;
  return abs((conj(x) * y).imag()/2);
}

double suisen(point a, point b, point c) {
  return area(a, b, c) * 2 / (abs(a-b));
} 

int main() {
  double x, y;
  cin >> x >> y;
  point p = point(x, y);
  int N;
  cin >> N;
  double X[100], Y[100];
  point P[100];
  for (auto i=0; i<N; i++) {
    cin >> X[i] >> Y[i];
    P[i] = point(X[i], Y[i]);
  }
  double ans = 10000000;
  for (auto i=0; i<N; i++) {
    ans = min(ans, suisen(P[i], P[(i+1)%N], p));
  }
  cout << fixed << setprecision(14) << ans << endl;
}
