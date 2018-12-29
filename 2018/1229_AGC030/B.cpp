/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 12/29/2018, 9:05:34 PM
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

ll L;
int N;
ll X[200010];
ll sum[200010];
ll sum_rev[200010];
ll ans = 0;

void solve()
{
  sort(X + 1, X + N + 1);
  sum[0] = 0;
  for (auto i = 1; i <= N; i++)
  {
    sum[i] = sum[i - 1] + X[i];
    cerr << "sum[" << i << "] = " << sum[i] << endl;
  }
  sum_rev[N + 1] = 0;
  for (auto i = N; i >= 1; i--)
  {
    sum_rev[i] = sum_rev[i + 1] + L - X[i];
    cerr << "sum_rev[" << i << "] = " << sum_rev[i] << endl;
  }
  for (auto right = 0; right <= N; right++)
  {
    int left = N - right;
    int num = min(right + 1, left);
    cerr << "left = " << left << ", right = " << right << endl;
    ll tans = sum[right] - sum[right - (num - 1)] + sum_rev[right + 1] - sum_rev[right + 1 + num];
    tans *= 2;
    tans -= L - X[right + 1 + num];
    cerr << "tans = " << tans << endl;
    ans = max(tans, ans);
    num = min(right, left + 1);
    tans = sum[right] - sum[right - num] + sum_rev[right + 1] - sum_rev[right + 1 + (num - 1)];
    tans *= 2;
    tans -= X[right - num];
    cerr << "tans = " << tans << endl;
    ans = max(tans, ans);
  }
}

int main()
{
  cin >> L >> N;
  X[0] = 0;
  for (auto i = 1; i <= N; i++)
  {
    cin >> X[i];
  }
  X[N + 1] = L;
  solve();
  for (auto i = 1; i <= N; i++)
  {
    X[i] = L - X[i];
  }
  solve();
  cout << ans << endl;
}