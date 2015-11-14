#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>
#include <cassert>

using namespace std;
typedef long long ll;

const ll M = 1000000007;

int main() {
  int N;
  cin >> N;
  int C[260];
  for (auto i=0; i<N; i++) {
    cin >> C[i];
  }
  reverse(C, C+N);
  ll a[260];
  fill(a, a+260, 0);
  a[C[0]] = 1;
  for (auto i=1; i<N; i++) {
    ll x = 1;
    for (auto j=i-1; j>=0; j--) {
      if (C[j] >= C[i-1]) {
        a[C[i]] += a[C[j]] * x;
        a[C[i]] %= M;
        x++;
      }
    }
  }
  for (auto i=1; i<=N; i++) {
    cout << "a[" << i << "] = " << a[i] << endl;
  }
  if (C[N-1] != 1) {
    cout << 0 << endl;
  } else {
    cout << a[1] << endl;
  }
}
