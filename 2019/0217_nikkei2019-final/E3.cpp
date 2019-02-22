#define DEBUG 1

/**
 * File    : E3.cpp
 * Author  : Kazune Takahashi
 * Created : 2/22/2019, 10:18:23 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll MOD = 1000000007;

ll p[100010];

ll power(ll x)
{
  if (x < 0)
  {
    return 0;
  }
  else
  {
    return p[x];
  }
}

ll N, K;
ll DP[5010][5010];

int main()
{
  p[0] = 1;
  for (auto i = 1; i < 100010; i++)
  {
    p[i] = (p[i - 1] * 2) % MOD;
  }
  cin >> N >> K;
  fill(&DP[0][0], &DP[0][0] + 5010 * 5010, 0);
  DP[0][0] = 1;
  for (ll j = 0; j < N; j++)
  {
    for (ll i = 0; i <= j; i++)
    {
      DP[i][j + 1] += (DP[i][j] * power(j - i - K)) % MOD;
      DP[i][j + 1] %= MOD;
      DP[j + 1][j + 1] += (DP[i][j] * (power(j + 1 - K) + MOD - power(j - i - K)) % MOD) % MOD;
    }
  }
  cout << DP[N][N] << endl;
}