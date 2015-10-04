#include <iostream>
#include <random>
#include <cmath>
using namespace std;

double A, B, C;

double cal(double t) {
  return A * t + B * sin(C * M_PI * t);
}

bool ok(double t) {
  return abs(cal(t) - 100) < 0.000001;
}

int main() {
  cin >> A >> B >> C;
  int n = 100 * (int)C / (2 * (int)A);
  random_device rd;
  mt19937 mt(rd());
  uniform_real_distribution<double> ex(2*n/C, 2*(n+1)/C);
  double t;
  while (true) {
    t = ex(mt);
    if (ok(t)) {
      printf("%.9f\n", t);
      return 0;
    }
  }
}
