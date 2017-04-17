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

ll N;
ll x;
ll a[2010];
ll b[2010];
ll t[2010];

int main () {
  cin >> N;
  cin >> x;
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++) {
    ans += a[i];
  }
  for (auto i = 1; i < N; i++) {
    //cerr << "i = " << i << endl;
    for (auto j = 0; j < N; j++) {
      t[j] = min(b[j], a[(j-i+N)%N]);
    }
    for (auto j = 0; j < N; j++) {
      b[j] = t[j];
    }
    ll tans = x * i;
    for (auto j = 0; j < N; j++) {
      tans += b[j];
    }
    ans = min(ans, tans);
  }
  cout << ans << endl;
}

