#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  double t, h, v, g;
  double y[3];
  t = 0;
  printf("? %.12f\n", t); fflush(stdout);
  scanf("%lf", y);
  t = sqrt(2);
  printf("? %.12f\n", t); fflush(stdout);
  scanf("%lf", y+1);
  t = sqrt(2) * 2;
  printf("? %.12f\n", t); fflush(stdout);
  scanf("%lf", y+2);
  double A = y[1] - y[0];
  double B = y[2] - y[0];
  h = y[0];
  g = (2*A - B)/2;
  v = A + g;
  printf("! %.12f %.12f %.12f\n", h, v, g); fflush(stdout);
}
