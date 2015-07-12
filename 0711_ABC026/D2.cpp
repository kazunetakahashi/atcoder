#include <iostream>
#include <random>
#include <cmath>
using namespace std;

double A, B, C;

double P = 3.14159265359;

double cal(double t) {
  return A * t + B * sin(C * P * t);
}

bool ok(double t) {
  return abs(cal(t) - 100) < 0.0000001;
}

int main() {
  cin >> A >> B >> C;
  double tmax = 250;
  double tmin = 0;
  double t = 0;
  while (true) {
    t = (tmax + tmin)/2;
    if (ok(t)) {
      // printf("%.30f\n", cal(t));
      printf("%.30f\n", t);
      return 0;
    } else if (cal(t) > 100) {
      tmax = t;
    } else {
      tmin = t;
    }
  }
}
