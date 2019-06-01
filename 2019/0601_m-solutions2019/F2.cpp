#define DEBUG 1

/**
 * File    : F2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-6-2 00:47:04
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

bool dp_L[2010][2010];
bool dp_R[2010][2010];
bool W[2010][2010];

int main()
{
  int N;
  cin >> N;
  for (auto i = 1; i < N; i++)
  {
    string S;
    cin >> S;
    for (auto j = 0; j < i; j++)
    {
      if (S[j] == '1')
      {
        W[i][j] = true;
        W[j][i] = false;
      }
      else
      {
        W[i][j] = false;
        W[j][i] = true;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    dp_L[i][i] = true;
    dp_R[i][i] = true;
  }
  for (auto n = 1; n < N; n++)
  {
    for (auto a = 0; a + n < N; a++)
    {
      int b = a + n;
      dp_L[a][b] = false;
      for (auto c = a + 1; c < b; c++)
      {
        if (dp_L[a][c] && dp_L[c][b])
        {
          dp_L[a][b] = true;
          break;
        }
      }
      if (!dp_L[a][b] && W[a][b])
      {
        for (auto c = a; c < b; c++)
        {
          if (dp_L[a][c] && dp_R[c + 1][b])
          {
            dp_L[a][b] = true;
            break;
          }
        }
      }
      dp_R[a][b] = false;
      for (auto c = a + 1; c < b; c++)
      {
        if (dp_R[a][c] && dp_R[c][b])
        {
          dp_R[a][b] = true;
          break;
        }
      }
      if (!dp_R[a][b] && W[b][a])
      {
        for (auto c = a; c < b; c++)
        {
          if (dp_L[a][c] && dp_R[c + 1][b])
          {
            dp_L[a][b] = true;
            break;
          }
        }
      }
#if DEBUG == 1
      cerr << "dp_L[" << a << "][" << b << "] = " << dp_L[a][b] << endl;
      cerr << "dp_R[" << a << "][" << b << "] = " << dp_R[a][b] << endl;
#endif
    }
  }
  int ans = 0;
  for (auto i = 0; i < N; i++)
  {
    if (dp_L[0][i] && dp_R[i][N - 1])
    {
      ans++;
    }
  }
  cout << ans << endl;
}