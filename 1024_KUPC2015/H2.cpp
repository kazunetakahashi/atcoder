#include <iostream>
using namespace std;

typedef long long ll;

ll N;

ll solve() {
  int a[64];
  int b[64];
  int c[64];
  int renzoku = 0;
  for (auto i=0; i<64; i++) {
    a[i] = ((N >> i) & 1);
    b[i] = a[i];
    if (renzoku > 0) {
      if (b[i] == 1) {
        b[i] = 0;
        renzoku++;
      } else {
        renzoku = 0;
      }
    } else {
      if (b[i] == 1) {
        renzoku++;
      }
    }
    c[i] = b[i];
  }
  for (auto i=63; i>=0; i--) {
    if (b[i] == 1) {
      int ones = 0;
      for (auto j=0; i+j<64; j++) {
        if (a[i+j] == 1) {
          ones++;
        } else {
          break;
        }
      }
      for (auto j=1; j<i; j++) {
        if (b[j] == 0 && c[j] == 0 && c[j-1] == 1) {
          int zeros = 0;
          for (auto k=0; k+j<i; k++) {
            if (a[k+j] == 0) {
              zeros++;
            } else {
              break;
            }
          }
          if (ones+1 <= zeros) {
            c[i] = 0;
            for (auto k=0; k<ones; k++) {
              c[j+k] = 1;
            }
            break;
          }
        }
      }
    }
  }
  ll one = 1;
  ll ans = 0;
  for (auto i=0; i<64; i++) {
    if (c[i] == 1) {
      ans += (one << i);
    }
  }
  return ans;
}

int countone(ll x) {
  int ans = 0;
  while (x > 0) {
    ans += (x & 1);
    x = (x >> 1);
  }
  return ans;
}

int main() {
  for (auto i=0; i<100; i++) {
    N = i;
    int s = solve();
    if (countone(s) != countone(s + N)) {
      cout << N << endl;
      cout << "solve wrong = " << s << endl;
    } else {
      int t = -1;
      for (auto j=0; j<=i; j++) {
        if (countone(j) == countone(j+N)) {
          t = j;
          break;
        }
      }
      if (t != s) {
        cout << N << endl;
        cout << "s = " << s << ", t = " << t << endl;
      }
    }
  }
}

/*
int main() {
  int T;
  cin >> T;
  for (auto i=0; i<T; i++) {
    cin >> N;
    cout << solve() << endl;
  }
}
*/
