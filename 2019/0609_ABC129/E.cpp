#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 6/9/2019, 9:16:59 PM
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

const ll MOD = 1000000007;

string L;
ll dp[100010][2];

int main()
{
  cin >> L;
  reverse(L.begin(), L.end());
  int N = L.size();
  dp[0][0] = 1;
  for (auto i = 0; i < N; i++)
  {
    dp[i + 1][1] += (3 * dp[i][1]) % MOD;
    dp[i + 1][1] %= MOD;
    if (L[i] == '0')
    {
      dp[i + 1][0] += dp[i][0];
      dp[i + 1][0] %= MOD;
    }
    else
    {
      dp[i + 1][1] += dp[i][0];
      dp[i + 1][1] %= MOD;
      dp[i + 1][0] += (2 * dp[i][0]) % MOD;
      dp[i + 1][0] %= MOD;
    }
#if DEBUG == 1
    cerr << "dp[" << i + 1 << "][" << 0 << "] = " << dp[i + 1][0] << endl;
    cerr << "dp[" << i + 1 << "][" << 1 << "] = " << dp[i + 1][1] << endl;
#endif
  }
  cout << (dp[N][0] + dp[N][1]) % MOD << endl;
}