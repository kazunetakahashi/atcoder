#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;

ll BIT[1000000010];
ll bit_size;

void bit_init(int n) {
  fill(BIT, BIT+n, 0);
  bit_size = n;
}

ll bit_max(int n) { // [1,n]の最大値
  long long ans = 0;
  while (n > 0) {
    ans = max(ans, BIT[n]);
    n &= n-1;
  }
  return ans;
}
void bit_setmax(int n, long long v) { // [1,n]の最大値をvに更新する
  while (n< bit_size) {
    BIT[n] = max(BIT[n], v);
    n += n & (-n);
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
