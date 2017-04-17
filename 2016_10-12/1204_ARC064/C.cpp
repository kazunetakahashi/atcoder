#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

int N;
ll a[100010];
ll x;

int main () {
  cin >> N >> x;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (auto i = 1; i < N; i++) {
    if (x > a[i] + a[i-1]) {
      continue;
    }
    if (a[i] >= a[i] + a[i-1] - x) {
      ans += a[i] + a[i-1] - x;
      a[i] -= a[i] + a[i-1] - x;
    } else {
      ans += a[i] + a[i-1] - x;
      a[i] = 0;
      a[i-1] = x;
    }
  }
  for (auto i = 0; i < N; i++) {
    // cerr << a[i] << " ";
  }
  // cerr << endl;
  cout << ans << endl;
}
