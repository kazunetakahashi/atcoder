#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ll N, X;
  cin >> N >> X;
  ll g = gcd(N, X);
  ll M = N/g;
  cout << g * (M-1) * 3 << endl;
}
