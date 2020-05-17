#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 6/9/2019, 9:04:45 PM
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

int N, M;
bool ok[100010];
ll dp[100010];

int main()
{
  cin >> N >> M;
  fill(ok, ok + 100010, true);
  for (auto i = 0; i < M; i++)
  {
    int a;
    cin >> a;
    ok[a] = false;
  }
  dp[0] = 1;
  for (auto i = 0; i < N; i++)
  {
    if (ok[i + 1])
    {
      dp[i + 1] += dp[i];
      dp[i + 1] %= MOD;
    }
    if (ok[i + 2])
    {
      dp[i + 2] += dp[i];
      dp[i + 2] %= MOD;
    }
  }
  cout << dp[N] << endl;
}