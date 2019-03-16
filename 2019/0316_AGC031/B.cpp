#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 3/16/2019, 9:13:03 PM
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
const ll M = 1000000007;

ll N;
int C[200010];
ll dp[200010];
ll table[200010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> C[i];
    C[i]--;
  }
  fill(dp, dp + 200010, 0);
  fill(table, table + 200010, 0);
  dp[0] = 1;
  dp[1] = 1;
  table[C[0]] = 1;
  for (auto i = 2; i <= N; i++)
  {
    if (C[i] == C[i - 1])
    {
      dp[i] = dp[i - 1];
    }
    else
    {
      dp[i] = dp[i - 1] + table[C[i - 1]];
      dp[i] %= M;
      table[C[i - 1]] += dp[i - 1];
      table[C[i - 1]] %= M;
    }
  }
  cout << dp[N] << endl;
}