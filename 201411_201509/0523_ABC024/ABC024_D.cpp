#include <iostream>
using namespace std;

const int W = 1000000007;
const int M = 1000000007;

typedef long long ll;

ll inv(ll i) {
  if (i == 1) return 1;
  return ((M - inv(M%i)) * (M/i))%M;
}

int main() {
  ll x, y, z;
  cin >> x >> y >> z;
  ll r, c;
  if (x%M != 0) { // xはMの倍数にならない。
    ll A = (((y + M - x)%M) * inv(x))%M;
    ll B = (((z + M - x)%M) * inv(x))%M;
    ll ab = (A*B)%M;
    if ((ab-1+M)%M != 0) {
      r = (((ab + A)%M) * inv((1+M-ab)%M))%M;
      c = (B * (r+1)%M)%M;
    } else {
      r = 1;
      c = 0;
    }
  }
  cout << r << " " << c << endl;
}
