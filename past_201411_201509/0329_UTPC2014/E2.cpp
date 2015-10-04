#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;
const ll MAX_N = (ll)1 << 30;
int n, dat[2 * MAX_N - 1];

void init(int n_) {
  n = 1;
  while (n < n_) n *= 2;
  for (int i = 0; i<2*n-1; i++) dat[i] = 0;
}

void update(int k, int a) {
  k += n-1;
  dat[k] = a;
  while (k > 0) {
    k = (k-1)/2;
    dat[k] = max(dat[k*2+1], dat[k*2+2]);
  }
}

int make_max(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return 0;
  if (a <= l && r <= b) return dat[k];
  else {
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
}

int main() {
  int n;
  cin >> n;
  bit_init(1000000000);
  for (auto i=0; i<n; i++) {
    string a;
    int b;
    cin >> a >> b;
    int s = a.size();
    for (auto j=0; j<9-s; j++) {
      a = "0" + a;
    }
    reverse(a.begin(), a.end());
    cerr << "a = " << a << endl;
    int x = 1000000000 - stoi(a);
    cerr << "x = " << x << endl;
    ll next = bit_max(x);
    bit_setmax(x, next+b);
    cout << next+b << endl;
  }
}
