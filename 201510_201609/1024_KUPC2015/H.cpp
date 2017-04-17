#include <iostream>
using namespace std;

typedef long long ll;

int MAX_SIZE;
ll N;

int countone(ll x) {
  int ans = 0;
  while (x > 0) {
    ans += (x & 1);
    x = (x >> 1);
  }
  return ans;
}

ll junban(int USE_SIZE) { // USE_SIZE > 0
  ll one = 1;
  ll comb = (one << USE_SIZE) - 1;
  // cerr << comb << endl;
  while (comb < (one << MAX_SIZE)) {
    // ここで作業する
    for (auto i=0; i<MAX_SIZE; i++) {
      if (countone(N+comb) == USE_SIZE) return comb;
    }
    // 以下処理。
    ll tmpx = comb & (-comb);
    ll tmpy = comb + tmpx;
    ll tmpz = comb & (~(tmpy));
    comb = (((tmpz/tmpx) >> 1) | tmpy);
  }
  return -1;
}

ll solve() {
  ll M = N;
  MAX_SIZE = 0;
  while (M > 0) {
    M = (M >> 1);
    MAX_SIZE++;
  }
  int renzoku = 0;
  bool isone = false;
  for (auto i=0; i<MAX_SIZE; i++) {
    if (isone) {
      if (((N >> i) & 1) == 0) {
        isone = false;
      }
    } else {
      if (((N >> i) & 1) == 1) {
        isone = true;
        renzoku++;
      }
    }
  }
  cerr << MAX_SIZE << " " << renzoku << endl;
  return junban(renzoku);
}

int main() {
  int T;
  cin >> T;
  for (auto i=0; i<T; i++) {
    cin >> N;
    cout << solve() << endl;
  }
}
