/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-15 16:51:34
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
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
const ll infty = 1000000007;
const ll MOD = 1000000007;

typedef tuple<ll, ll> P;

int N;
ll H[110];

long long power(long long x, long long n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n % 2 == 1)
  {
    return (x * power(x, n - 1)) % MOD;
  }
  else
  {
    long long half = power(x, n / 2);
    return (half * half) % MOD;
  }
}

int h_ind(int l, int r)
{
  int ind = -1;
  ll mini = infty;
  for (auto i = l; i < r; i++)
  {
    if (H[i] < mini)
    {
      ind = i;
      mini = H[i];
    }
  }
  return ind;
}

P func(int l, int r, ll h)
{
  if (l == r)
  {
    return P(1, 1);
  }
  int ind = h_ind(l, r);
  ll height = H[ind] - h;
  if (l + 1 == r && height == 1)
  {
    return P(2, 1);
  }
  if (height == 1)
  {
    auto it1 = func(l, ind, h);
    auto it2 = func(ind + 1, r, h);
    ll f1 = get<0>(it1);
    ll g1 = get<1>(it1);
    ll f2 = get<0>(it2);
    ll g2 = get<1>(it2);
    ll f = (((2 * f1) % MOD) * f2) % MOD;
    ll g = (g1 * g2) % MOD;
    return P(f, g);
  }
  auto it1 = func(l, ind, h + height - 1);
  ll f1 = get<0>(it1);
  ll g1 = get<1>(it1);
  ll f = f1;
  f += 2 * (MOD - g1);
  f %= MOD;
  f += (power(2, height) * g1) % MOD;
  f %= MOD;
  ll g = (power(2, height - 1) * g1) % MOD;
  return P(f, g);
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> H[i];
  }
  cout << get<0>(func(0, N, 0)) << endl;
}