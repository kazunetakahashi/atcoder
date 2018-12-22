/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 12/22/2018, 9:09:29 PM
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
// const ll M = 1000000007;

int N;
ll A[200010];
ll X[200010];
ll Y[200010];
ll imos_X[200010];
ll imos_Y[200010];
ll imos_imos_X[200010];
ll imos_imos_Y[200010];

ll calc(ll x, ll y)
{
  ll res = 0;
  ll mult = 1;
  while (x > y * mult)
  {
    res += 2;
    mult *= 4;
  }
  return res;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  X[0] = 0;
  for (auto i = 1; i < N; i++)
  {
    X[i] = calc(A[i - 1], A[i]);
  }
  imos_X[0] = 0;
  for (auto i = 1; i < N; i++)
  {
    imos_X[i] = X[i] + imos_X[i - 1];
    cerr << "imos_X[" << i << "] = " << imos_X[i] << endl;
  }
  imos_imos_X[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    imos_imos_X[i] = imos_X[i] + imos_imos_X[i - 1];
  }
  Y[N - 1] = 0;
  for (auto i = N - 2; i >= 0; i--)
  {
    Y[i] = calc(A[i + 1], A[i]);
  }
  imos_Y[N - 1] = 0;
  for (auto i = N - 2; i >= 0; i--)
  {
    imos_Y[i] = Y[i] + imos_Y[i + 1];
    cerr << "imos_Y[" << i << "] = " << imos_Y[i] << endl;
  }
  imos_imos_Y[N - 1] = 0;
  for (auto i = N - 2; i >= 0; i--)
  {
    imos_imos_Y[i] = imos_Y[i] + imos_imos_Y[i + 1];
  }
  ll ans = 1000000000000000;
  for (auto i = 0; i < N; i++)
  {
    ll t = i + imos_imos_X[N - 1] - imos_imos_X[i] + imos_imos_Y[0];
    if (i >= 1)
    {
      t -= imos_imos_Y[i - 1];
    }
    ans = min(t, ans);
  }
  cout << ans << endl;
}