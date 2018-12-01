/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-12-1 22:26:27
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
int F[110][10];
ll P[110][11];
int cnt[110];
ll ans = -10000000000000;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < 10; j++)
    {
      cin >> F[i][j];
    }
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < 11; j++)
    {
      cin >> P[i][j];
    }
  }
  for (auto i = 1; i < (1 << 10); i++)
  {
    fill(cnt, cnt + N, 0);
    for (auto j = 0; j < 10; j++)
    {
      if ((i >> j) & 1)
      {
        for (auto k = 0; k < N; k++)
        {
          if (F[k][j])
          {
            cnt[k]++;
          }
        }
      }
    }
    ll tans = 0;
    for (auto k = 0; k < N; k++)
    {
      tans += P[k][cnt[k]];
    }
    ans = max(tans, ans);
  }
  cout << ans << endl;
}