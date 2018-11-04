/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-11-4 21:27:34
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
const ll M = 1000000007;

ll H, W, K;

ll cnt[10];
ll S[10];
ll T[10];

ll DP[110][10];

int main()
{
  cin >> H >> W >> K;
  K--;
  cnt[0] = 1;
  cnt[1] = 2;
  for (auto i = 2; i < 10; i++)
  {
    cnt[i] = cnt[i - 1] + cnt[i - 2];
  }
  for (ll i = 0; i < 10; i++)
  {
    S[i] = cnt[max(i - 2, 0ll)] * cnt[max(W - i - 3, 0ll)];
    T[i] = cnt[max(i - 2, 0ll)] * cnt[max(W - i - 2, 0ll)];
  }
  DP[0][0] = 1;
  for (auto i = 1; i < W; i++)
  {
    DP[0][i] = 0;
  }
  for (auto i = 1; i <= H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      DP[i][j] = DP[i - 1][j] * T[j];
      DP[i][j] %= M;
      if (j - 1 >= 0)
      {
        DP[i][j] += DP[i - 1][j - 1] * S[j - 1];
        DP[i][j] %= M;
      }
      if (j + 1 < W)
      {
        DP[i][j] += DP[i - 1][j + 1] * S[j];
        DP[i][j] %= M;
      }
    }
  }
  cout << DP[H][K] << endl;
}