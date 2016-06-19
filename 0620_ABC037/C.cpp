#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  int N, K;
  cin >> N >> K;
  ll a[100010];
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  ll X = 0;
  for (auto i = 0; i < K; i++) {
    X += a[i];
  }
  ans += X;
  for (auto i = 0; i + K < N; i++) {
    X -= a[i];
    X += a[i+K];
    ans += X;
  }
  cout << ans << endl;
}
