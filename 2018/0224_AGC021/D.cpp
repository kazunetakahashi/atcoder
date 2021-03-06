/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-24 22:16:49
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
#include <random> // random_device rd; mt19937 mt(rd());
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

int dp[400][400];
bool used[400];

int lcs(string s, string t)
{
  fill(&dp[0][0], &dp[0][0] + 400 * 400, 0);
  fill(used, used + 400, false);
  int N = s.size();
  int M = t.size();
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      if (s[i] == t[j])
      {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else
      {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  int x = M, y = N;
  while (x >= 1 && y >= 1)
  {
    if (dp[x][y] == dp[x-1][y-1] + 1)
    {
      used[x - 1] = true;
      x--;
      y--;
    }
    else if (dp[x][y] == dp[x-1][y])
    {
      x--;
    }
    else
    {
      y--;
    }
  }
  return dp[N][M];
}

string S;
int K;

int main()
{
  cin >> S >> K;
  string T = S;
  reverse(T.begin(), T.end());
  if (K == 0)
  {
    cout << lcs(S, T) << endl;
  }
  else
  {
    int N = S.size();
    lcs(S, T);
    for (auto i = 0; i < N; i++)
    {
      if (K > 0 && !used[i])
      {
        used[i] = true;
        for (auto j = N-1; j > i; j--)
        {
          if (!used[j])
          {
            used[j] = true;
            break;
          }
        }
        K--;
      }
    }
    for (auto i = 0; i < N; i++)
    {
      if (K > 0 && !used[i])
      {
        used[i] = true;
        K--;
      }
    }
    int cnt = 0;
    for (auto i = 0; i < N; i++)
    {
      if (used[i])
        cnt++;
    }
    cout << cnt << endl;
  }
}