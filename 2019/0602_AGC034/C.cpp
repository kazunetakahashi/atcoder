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

typedef tuple<ll, ll, ll, ll> card;  // maxi, b, l, u;
typedef tuple<ll, ll, ll, ll> card2; // u, l, b, cost;
vector<card> V;
vector<card2> W;

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
  while (maxi >= now)
  {
    ll t, b, l, u;
    tie(t, b, l, u) = V[ind++];
    now += t;
    ans += X;
    W.emplace_back(u, l, b, X);
#if DEBUG == 1
    cerr << "(" << t << ", " << b << ", " << l << ", " << u << ")" << endl;
#endif
  }
  sort(W.begin(), W.end());
  ind = 0;
#if DEBUG == 1
  ll u, l, b, x;
  tie(u, l, b, x) = W[0];
  cerr << "W[0]: ";
  cerr << "(" << u << ", " << l << ", " << b << ", " << x << ")" << endl;
#endif
  while (now >= maxi)
  {
    if (get<3>(W[0]) > get<2>(W[0]))
    {
      now -= get<0>(W[0]);
    }
    else
    {
      now -= get<1>(W[0]);
    }
    get<3>(W[0])--;
    ans--;
  }
  cout << ans + 1 << endl;
}