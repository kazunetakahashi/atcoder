#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  double m;
  cin >> n >> m;
  n %= 12;
  n *= 30;
  double nn = n;
  nn += 30 * m/60;
  m *= 6;
  double sa = abs(nn-m);
  sa = min(360-sa, sa);
  cout << sa << endl;
}
