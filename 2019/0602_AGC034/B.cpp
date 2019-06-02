#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-2 21:27:51
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

// const ll MOD = 1000000007;

string S;

// A: 0, B: 1, C: 2

ll DP[200010][4][4];

int main()
{
  cin >> S;
  int N = S.size();
  for (auto n = 0; n < N; n++)
  {
    for (auto i = 0; i < 4; i++)
    {
      for (auto j = 0; j < 4; j++)
      {
        int k = S[n] - 'A';
        DP[n + 1][j][k] = max(DP[n + 1][j][k], DP[n][i][j]);
        if (i == 0 && j == 1 && k == 2)
        {
          DP[n + 1][2][0] = max(DP[n + 1][2][0], DP[n][i][j] + 1);
        }
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i < 3; i++)
  {
    for (auto j = 0; j < 3; j++)
    {
      ans = max(ans, DP[N][i][j]);
    }
  }
  cout << ans << endl;
}