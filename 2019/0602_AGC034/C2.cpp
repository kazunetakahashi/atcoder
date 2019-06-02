#define DEBUG 1

/**
 * File    : C2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-3 00:42:00
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

/*
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}

void No()
{
  cout << "No" << endl;
  exit(0);
}
*/

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

ll N, X;
ll b[100010], l[100010], u[100010];
ll base = 0;
typedef tuple<ll, ll, ll, ll> test;
vector<test> V;
ll sum[100010];

bool solve(ll T)
{
  ll cnt = T / X;
  ll x = T % X;
  ll ans = -1000000000000000;
  for (auto i = 0; i < N; i++)
  {
    ll t, b, l, u;
    tie(t, b, l, u) = V[i];
    ll tmp = 0;
    if (x >= b)
    {
      tmp = l * b + u * (x - b);
    }
    else
    {
      tmp = l * x;
    }
    if (i < cnt)
    {
      ans = max(ans, sum[cnt + 1] - t + tmp);
    }
    else
    {
      ans = max(ans, sum[cnt] + tmp);
    }
  }
  return (ans >= 0);
}

int main()
{
  cin >> N >> X;
  for (auto i = 0; i < N; i++)
  {
    cin >> b[i] >> l[i] >> u[i];
  }
  for (auto i = 0; i < N; i++)
  {
    base -= l[i] * b[i];
  }
  for (auto i = 0; i < N; i++)
  {
    ll t = l[i] * b[i] + u[i] * (X - b[i]);
    V.emplace_back(t, b[i], l[i], u[i]);
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  sum[0] = base;
  for (auto i = 0; i < N; i++)
  {
    sum[i + 1] = sum[i] + get<0>(V[i]);
  }
  sum[N + 1] = sum[N];
  ll ok = N * X + 1;
  ll ng = -1;
  while (abs(ok - ng) > 1)
  {
    ll t = (ok + ng) / 2;
    if (solve(t))
    {
      ok = t;
    }
    else
    {
      ng = t;
    }
  }
  cout << ok << endl;
}