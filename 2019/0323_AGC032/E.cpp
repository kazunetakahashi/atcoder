#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-28 20:34:04
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
ll M;
ll a[200010];
ll ans = 100 * M;

bool solve(int t)
{
  ll res = 0;
  for (auto i = 0; i < t; i++)
  {
    res = max(res, a[i] + a[2 * t - 1 - i]);
  }
  for (auto i = 0; i < N - t; i++)
  {
    ll temp = a[2 * t + i] + a[2 * N - 1 - i];
    if (temp < M)
    {
      return false;
    }
    else
    {
      res = max(res, temp - M);
    }
  }
  ans = min(ans, res);
  return true;
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < 2 * N; i++)
  {
    cin >> a[i];
  }
  sort(a, a + 2 * N);
  int ng = -1;
  int ok = N + 1;
  while (abs(ok - ng) > 1)
  {
    int t = (ng + ok) / 2;
    if (solve(t))
    {
      ok = t;
    }
    else
    {
      ng = t;
    }
  }
  cout << ans << endl;
}