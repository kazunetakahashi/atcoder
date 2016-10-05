#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265359;

int main() {
  double l[3];
  for (auto i = 0; i < 3; i++) {
    cin >> l[i];
  }
  sort(l, l+3);
  double R = l[0] + l[1] + l[2];
  double r = max(l[2] - l[0] - l[1], 0.0);
  cout << fixed << setprecision(13) << PI * (R * R - r * r) << endl;
}
