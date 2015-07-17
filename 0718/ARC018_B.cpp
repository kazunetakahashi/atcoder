#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

typedef long long ll;
typedef complex<ll> point;
point P[110];

ll ext_prod(point P, point Q, point R) {
  return (conj(Q-P) * (R-P)).imag();
}

int main() {
  int n;
  cin >> n;
  ll x, y;
  for (auto i=0; i<n; i++) {
    cin >> x >> y;
    P[i] = point(x, y);
  }
  int ans = 0;
  for (auto i=0; i<n; i++) {
    for (auto j=i+1; j<n; j++) {
      for (auto k=j+1; k<n; k++) {
        ll SS = abs(ext_prod(P[i], P[j], P[k]));
        // cerr << SS << endl;
        if (SS > 0 && (SS % 2) == 0) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
