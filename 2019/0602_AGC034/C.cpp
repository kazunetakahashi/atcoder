#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-2 21:52:44
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

int N;
ll X;
ll b[100010];
ll l[100010];
ll u[100010];
ll maxi = 0;
ll now = 0;
ll ans = 0;

typedef tuple<ll, ll, ll, ll> card; // maxi, b, l, u;
typedef tuple<ll, ll, ll> card2;    // b, l, u;

vector<card> V;

int main()
{
  cin >> N >> X;
  for (auto i = 0; i < N; i++)
  {
    cin >> b[i] >> l[i] >> u[i];
  }
  for (auto i = 0; i < N; i++)
  {
    maxi += b[i] * l[i];
  }
  for (auto i = 0; i < N; i++)
  {
    ll t = (l[i] * b[i] + u[i] * (X - b[i]));
    V.emplace_back(t, b[i], l[i], u[i]);
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  int ind = 0;
  while (true)
  {
    ll t, b, l, u;
    tie(t, b, l, u) = V[ind++];
    if (now + t >= maxi)
    {
      break;
    }
    now += t;
  }
  ans = X;
  ll dx = maxi - now;
  for (auto i = ind; i < N; i++)
  {
    ll t, b, l, u;
    tie(t, b, l, u) = V[i];
    ll tmp = 0;
    if (dx >= l * b)
    {
      tmp = b + (dx - l * b + u - 1) / u;
    }
    else
    {
      tmp = (dx + b - 1) / b;
    }
    ans = min(tmp, ans);
  }
  cout << ans + X * ind << endl;
}