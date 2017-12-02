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
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, K;
ll a[100010];
ll b[100010];

typedef tuple<ll, ll> machine;

int main () {
  cin >> N >> K;
  for (auto i = 0; i < N; ++i) {
    cin >> a[i] >> b[i];
  }
  priority_queue<machine, vector<machine>, greater<machine> > Q;
  for (auto i = 0; i < N; ++i) {
    Q.push(machine(a[i], b[i]));
  }
  ll ans = 0;
  for (auto i = 0; i < K; ++i) {
    ll x = get<0>(Q.top());
    ll y = get<1>(Q.top());
    Q.pop();
    ans += x;
    Q.push(machine(x+y, y));
  }
  cout << ans << endl;
}
