#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 6/9/2019, 9:09:02 PM
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

int H, W;
string S[2010];
bool X[2010][2010];
ll A[2010][2010];
ll B[2010][2010];

ll solve()
{
  for (auto i = 0; i < H; i++)
  {
    ll t = 0;
    for (auto j = 0; j < W; j++)
    {
      if (X[i][j])
      {
        t++;
      }
      else
      {
        for (auto k = j; k > j - t; k--)
        {
          A[i][k] = t;
        }
        t = 0;
      }
    }
    for (auto k = W - 1; k > W - 1 - t; k--)
    {
      A[i][k] = t;
    }
  }
  for (auto j = 0; j < W; j++)
  {
    ll t = 0;
    for (auto i = 0; i < H; i++)
    {
      if (X[i][j])
      {
        t++;
      }
      else
      {
        for (auto k = j; k > i - t; k--)
        {
          B[k][j] = t;
        }
        t = 0;
      }
    }
    for (auto k = H - 1; k > H - 1 - t; k--)
    {
      B[k][j] = t;
    }
  }
  ll ans = 0;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      ans = max(ans, A[i][j] + B[i][j]);
    }
  }
  return ans;
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      X[i][j] = (S[i][j] == '.');
    }
  }
  cout << solve() << endl;
}