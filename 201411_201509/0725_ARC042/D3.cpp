#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll X, P, A, B, m;
ll gyaku;
unordered_map<ll, ll> M;
const ll K = (1 << 24);

ll power(int j) {
  if (j==0) return 1;
  if (j%2 == 1) return (power(j-1) * X)%P;
  ll b = power(j/2);
  return (b*b)%P;
}

ll bsgs(ll beta) {
  ll gamma = beta;
  for (auto i=0; i<=m; i++) {
    if (M.find(gamma) != M.end()) {
      ll j = M[gamma];
      return i*m + j;
    }
    gamma = (gamma * gyaku) % P;
  }
  return -1;
}

void answer() {
  cin >> X >> P >> A >> B;
  if ((A%(P-1) == 0) || ((A - A%(P-1)) + (P-1) <= B)) {
    cout << 1 << endl;
    return;
  }
  if (B-A+1 > K) {
    B %= (P-1);
    A %= (P-1);
    m = sqrt(P)+1;
    ll temp = 1;
    M.clear();
    for (auto j=0; j<m; j++) {
      M[temp] = j;
      temp *= X;
      temp %= P;
    }
    gyaku = ((P == 2) ? 1 : power(P-1-m));
    assert((gyaku * power(m)) % P == 1);
    ll ans = 0;
    ll i = 0;
    do {
      ans = bsgs(++i);
      // assert(ans != -1);
      // cerr << "i = " << i << " : " << ans << endl;
    } while (A > ans || ans > B);
    cout << i << endl;
  } else {
    ll ans = P;
    ll now = power(A);
    for (auto i=0; i<=B-A; i++) {
      ans = min(ans, now);
      if (ans == 1) break;
      now *= X;
      now %= P;
    }
    cout << ans << endl;
  }
}

int main() {
  //for (auto i=0; i<10000; i++) {
  //cout << "line = " << i << ", ans = ";
    answer();
    //}
}
