#define DEBUG 1

/**
 * File    : B2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-29 15:58:23
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

int N;
int C[200010];
ll DP[200010];
ll sum[200010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> C[i];
    C[i]--;
  }
  C[N] = -1;
  DP[0] = 1;
  for (auto i = 1; i <= N; i++)
  {
    if (C[i - 1] == C[i])
    {
      DP[i] = DP[i - 1];
    }
    else
    {
      DP[i] = DP[i - 1] + sum[C[i - 1]];
      DP[i] %= MOD;
      sum[C[i - 1]] += DP[i - 1];
      sum[i] %= MOD;
    }
#if DEBUG == 1
    cerr << "DP[" << i << "] = " << DP[i] << endl;
#endif
  }
  cout << DP[N] << endl;
}