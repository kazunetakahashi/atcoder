/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-21 21:12:38
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N;
ll C;
ll x[100010];
ll v[100010];
ll w[100010];
ll w_rev[100010];

ll solve()
{
  ll ans = 0;
  fill(w, w + N, 0);
  w[0] = v[0];
  for (auto i = 1; i < N; i++)
  {
    w[i] = w[i - 1] + v[i];
  }
  for (auto i = 0; i < N; i++)
  {
    ans = max(ans, w[i] - x[i]);
  }
  w_rev[N - 1] = v[N - 1];
  for (auto i = N - 2; i >= 0; i--)
  {
    w_rev[i] = w_rev[i + 1] + v[i];
  }
  ll maxi = 0;
  for (auto i = N - 1; i >= 1; i--)
  {
    maxi = max(maxi, w_rev[i] - (C - x[i]));
    ans = max(ans, w[i - 1] - 2 * x[i - 1] + maxi);
  }
  maxi = max(maxi, w_rev[0] - (C - x[0]));
  ans = max(ans, maxi);
  return ans;
}

int main()
{
  cin >> N >> C;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i] >> v[i];
  }
  ll ans = solve();
  for (auto i = 0; i < N; i++)
  {
    x[i] = C - x[i];
  }
  reverse(v, v + N);
  reverse(x, x + N);
  ans = max(ans, solve());
  cout << ans << endl;
}