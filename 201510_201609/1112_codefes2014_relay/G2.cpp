#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

set<int> S[60];

int main() {
  int n, m;
  cin >> n >> m;
  int a[60];
  for (auto i=0; i<n; i++) {
    cin >> a[i];
  }
  S[0].insert(0);
  for (auto i=0; i<n; i++) {
    for (auto e : S[i]) {
      S[i+1].insert(e);
      if (e+a[i] < 20010) {
        S[i+1].insert(e+a[i]);
      }
    }
  }
  auto x = S[n].lower_bound(m);
  if (x != S[n].end()) {
    cout << *x << endl;
  } else {
    cout << -1 << endl;
  }
}
