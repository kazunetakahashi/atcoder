#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int gcd(int k, int l) {
  if (k < 0) return gcd(-k, l);
  if (l < 0) return gcd(k, -l);
  if (k < l) return gcd(l, k);
  if (l == 0) return k;
  return gcd(l, k%l);
}

int M = 10000;

bool v(int x) {
  return (-10000 <= x && x <= 10000);
}

int cx[4], cy[4];

bool heikou() {
  return ((cy[0] - cy[1]) * (cx[2] - cx[3])
          - (cy[2] - cy[3]) * (cx[0] - cx[1]) == 0);
}

double eps = 0.000001;

int main() {
  double x, y;
  cin >> x >> y;
  int lx = (x+eps) * 1000;
  int ly = (y+eps) * 1000;
  int count = 0;
  for (auto i=-M; i<M; i++) {
    int li = 1000 * i;
    for (auto j=-M; j<M; j++) {
      int lj = 1000 * j;
      int dx = lx - li;
      int dy = ly - lj;
      int g = gcd(dx, dy);
      dx /= g;
      dy /= g;
      dx *= 1000;
      dy *= 1000;
      int ax1, ay1;
      ax1 = (li + dx)/1000;
      ay1 = (lj + dy)/1000;
      if (v(ax1) && v(ay1)) {
        cx[count * 2] = i;
        cx[count * 2 + 1] = ax1;
        cy[count * 2] = j;
        cy[count * 2 + 1] = ay1;
        if (count == 1 && heikou()) continue;
        count++;
        if (count == 2) {
          cout << cx[0] << " " << cy[0] << " " << cx[1] << " " << cy[1]
               << endl;
          cout << cx[2] << " " << cy[2] << " " << cx[3] << " " << cy[3]
               << endl;
          return 0;
        }
      }
    }
  }
  assert(false);
}
