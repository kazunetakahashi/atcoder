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

ll solve()
{
  ll ans = 0;
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
        ans = max(ans, t);
        t = 0;
      }
    }
    ans = max(ans, t);
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
  ll ans = 0;
  ans += solve();
  for (auto i = 0; i < 2010; i++)
  {
    for (auto j = 0; j < i; j++)
    {
      swap(X[i][j], X[j][i]);
    }
  }
  swap(H, W);
  ans += solve();
  cout << ans + 1 << endl;
}