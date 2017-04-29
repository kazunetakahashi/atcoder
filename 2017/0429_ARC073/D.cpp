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

int N;
vector<ll> V[4];
vector<ll> S[4];
ll W;
ll w[110];
ll v[110];
ll K;

int main () {
  cin >> N >> W;
  for (auto i = 0; i < N; ++i) {
    cin >> w[i] >> v[i];
  }
  K = w[0];
  for (auto i = 0; i < N; ++i) {
    V[w[i] - K].push_back(v[i]);
  }
  for (auto i = 0; i < 4; ++i) {
    int sum = 0;
    sort(V[i].begin(), V[i].end());
    reverse(V[i].begin(), V[i].end());
    S[i].push_back(0);
    for (auto x : V[i]) {
      sum += x;
      S[i].push_back(sum);
    }
  }
  ll ans = 0;
  for (ll i = 0; i < (ll)S[0].size(); ++i) {
    for (ll j = 0; j < (ll)S[1].size(); ++j) {
      for (ll k = 0; k < (ll)S[2].size(); ++k) {
        ll weight = (i+j+k) * K + j + 2 * k;
        if (W < weight) continue;
        int l = (W - weight)/(K+3);
        ans = max(ans, S[0][i] + S[1][j] + S[2][k] + S[3][l]);
      }
    }
  }
  cout << ans << endl;
}
