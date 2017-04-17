#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

const int L = 1000000;
int R = 100000;
const int RR = R * 2;
const int T = 49;

typedef complex<double> point;

bool say(double x, double y) {
  printf("%.9f %.9f\n", x, y); fflush(stdout);
  string result;
  cin >> result;
  if (result == "found" || result == "kill") {
    exit(0);
  }
  return (result == "close");
}

int main () {
  int indi, indj;
  for (auto i = 0; i < 10; i++) {
    for (auto j = 0; j < 10; j++) {
      if (say(i * R + R/2, j * R + R/2)) {
        indi = i * R + R/2;
        indj = j * R + R/2;
        goto EXIT;
      }
    }
  }
 EXIT:
  double ub = indi;
  double lb = indi - 2 * R - 1;
  double other = indj;
  for (auto t = 0; t < T; t++) {
    double temp = (ub + lb)/2;
    if (say(temp, other)) {
      ub = temp;
    } else {
      lb = temp;
    }
  }
  double ansx1 = ub;
  double ansy1 = other;
  ub = indj;
  lb = indj - 2 * R - 1;
  other = indi;
  for (auto t = 0; t < T; t++) {
    double temp = (ub + lb)/2;
    if (say(other, temp)) {
      ub = temp;
    } else {
      lb = temp;
    }
  }
  double ansx2 = other;
  double ansy2 = ub;
  point a = point(ansx1, ansy1);
  point p = point((ansx1+ansx2)/2, (ansy1+ansy2)/2);
  point l = p - a;
  point n = point(-l.imag(), l.real());
  // cerr << n << " " << abs(n) << endl;
  point m = n * (1.0/abs(n)) * sqrt((double)R * (double)R - abs(l) * abs(l));
  // cerr << n * (1.0/abs(n)) << endl;
  // cerr << m << " " << abs(m) << endl;
  point ans = p + m;
  say(round(ans.real()), round(ans.imag()));
}
