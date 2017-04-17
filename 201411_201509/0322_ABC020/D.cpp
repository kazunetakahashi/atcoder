// 100点解法
#include <iostream>
using namespace std;

typedef long long ll;

const ll M = 1000000007;

ll gcd(ll x, ll y) {
  if (x < y) return gcd(y, x);
  if (y == 0) return x;
  return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
  return (x * y / gcd(x, y))%M;
}

int main() {
  ll N, K;
  cin >> N >> K;
  ll X = 0;
  for (auto i=1; i<=K; i++) {
    X += ((K * K) / gcd(i, K))%M;
    X %= M;
  }
  ll S = 0;
  for (auto i=1; i<=K; i++) {
    S += lcm(i, K);
    S %= M;
  }
  ll A = 0;
  ll NK = N / K;
  A += (S * NK)%M;
  A %= M;
  A += (((NK * (NK-1) / 2)%M )* X)%M;
  A %= M;
  for (auto i=NK * K + 1; i <= N; i++) {
    A += lcm(i, K);
    A %= M;
  }
  cout << A << endl;
}
