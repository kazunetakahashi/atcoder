/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-15 23:25:04
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

int N, M, Q;
int a[50];
int l[50];
int r[50];
bool used[50];

ll solve()
{
  ll ans = 0;
  for (auto i = 0; i < Q; i++)
  {
    int maxi = 0;
    for (auto j = l[i]; j <= r[i]; j++)
    {
      if (!used[j] && a[j] > maxi)
      {
        maxi = a[j];
      }
    }
    // cerr << maxi << " ";
    ans += maxi;
  }
  // cerr << ", ans = " << ans << endl;
  return ans;
}

void solveA()
{
  ll ans = 10000000000000;
  for (auto i = 0; i < (1 << N); i++)
  {
    int cnt = 0;
    for (auto j = 0; j < N; j++)
    {
      if ((i >> j) & 1)
      {
        cnt++;
      }
    }
    if (cnt == M)
    {
      for (auto j = 0; j < N; j++)
      {
        used[j] = (i >> j) & 1;
      }
      ans = min(ans, solve());
    }
  }
  cout << ans << endl;
}

void solveB()
{
  ll ans = 10000000000000;
  ll master = (1 << M) - 1;
  for (auto k = 0; k < N; k++)
  {
    ll i = master << k;
    for (auto j = 0; j < N; j++)
    {
      used[j] = (i >> j) & 1;
    }
    ans = min(ans, solve());
  }
  cout << ans << endl;
}

int main()
{
  cin >> N >> M >> Q;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  for (auto i = 0; i < Q; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  if (N <= 15)
  {
    solveA();
  }
  else
  {
    solveB();
  }
}