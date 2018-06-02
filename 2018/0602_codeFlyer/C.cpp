/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-2 21:08:42
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
// const ll M = 1000000007;

ll N, D;
ll X[100010];
ll L[100010];
ll R[100010];
ll A[100010];
ll sum[100010];
ll cnt[100010];

int main()
{
  cin >> N >> D;
  for (auto i = 0; i < N; i++)
  {
    cin >> X[i];
  }
  for (auto i = 0; i < N; i++)
  {
    R[i] = i;
    L[i] = i;
  }
  ll l = 0, r = 0;
  while (r < N)
  {
    if (X[r] - X[l] <= D)
    {
      R[l] = r;
      r++;
    }
    else
    {
      l++;
    }
  }
  r = N - 1;
  while (l < N)
  {
    if (X[r] - X[l] <= D)
    {
      R[l] = r;
      l++;
    }
    else
    {
      l++;
    }
  }
  l = N - 1;
  while (l >= 0)
  {
    if (X[r] - X[l] <= D)
    {
      L[r] = l;
      l--;
    }
    else
    {
      r--;
    }
  }
  l = 0;
  while (r >= 0)
  {
    if (X[r] - X[l] <= D)
    {
      L[r] = l;
      r--;
    }
    else
    {
      r--;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    A[i] = R[i] - i;
  }
  sum[0] = 0;
  for (auto i = 1; i <= N; i++)
  {
    sum[i] = sum[i - 1] + A[i - 1];
    cerr << "sum[" << i << "] = " << sum[i] << endl;
  }
  for (auto j = 0; j < N; j++)
  {
    ll n = R[j] - (L[j] - 1) - 1;
    cerr << "j = " << j << ", n = " << n << endl;
    cnt[j] = n * (n - 1) / 2;
    ll ext = sum[R[j] + 1] - sum[L[j]] - n;
    cerr << "ext = " << ext << endl;
    cnt[j] -= ext;
  }
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    ans += cnt[i];
  }
  cout << ans << endl;
}