#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

int N;
ll X[100010];
ll Y[100010];
point p[100010];

bool ok(ll PX, ll PY) {
  if ((PX+PY)%2 != 0 || (PY-PX)%2 != 0) return false;
  ll x = (PX+PY)/2;
  ll y = (PX-PY)/2;
  //cerr << "x = " << x << ", y = " << y << endl;
  ll R = abs(p[0].first - x) + abs(p[0].second - y);
  for (auto i = 1; i < N; i++) {
    if (R != abs(p[i].first - x) + abs(p[i].second - y)) return false;
  }
  return true;
}

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    X[i] = x + y;
    Y[i] = x - y;
    p[i] = point(x, y);
  }
  bool isx = true;
  sort(X, X+N);
  ll maxi = X[N-1] - X[0];
  sort(Y, Y+N);
  if (maxi < Y[N-1] - Y[0]) {
    maxi = Y[N-1] - Y[0];
    isx = false;
  }
  if (maxi%2 == 0) maxi++;
  ll ansX = 0, ansY = 0;
  if (isx) {
    ll PX = X[0] + maxi/2;
    for (auto i = Y[0]-maxi; i <= Y[N-1]+maxi; i++) {
      if (ok(PX, i)) {
        ansX = PX;
        ansY = i;
        break;
      }
    }
  } else {
    ll PY = Y[0] + maxi/2;
    for (auto i = X[0]-maxi; i <= X[N-1]+maxi; i++) {
      if (ok(i, PY)) {
        ansX = i;
        ansY = PY;
        break;
      }
    }
  }
  cout << (ansX + ansY)/2 << " " << (ansX - ansY)/2 << endl;
}
