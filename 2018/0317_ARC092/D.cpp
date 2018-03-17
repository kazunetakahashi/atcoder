/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-17 21:09:24
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

int N;
ll a[2][200010];
ll zero[2][100];
ll one[2][100];
ll res[100];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[0][i] >> a[1][i];
  }
  if (N == 1)
  {
    cout << a[0][0] + a[1][0] << endl;
    return 0;
  }
  fill(&zero[0][0], &zero[0][0] + 200, 0);
  fill(&one[0][0], &one[0][0] + 200, 0);
  for (auto i = 0; i < 50; i++)
  {
    for (auto k = 0; k < 2; k++)
    {
      for (auto j = 0; j < N; j++)
      {
        if ((a[k][j] >> i) & 1)
        {
          one[k][i]++;
        }
        else
        {
          zero[k][i]++;
        }
      }
    }
  }
  for (auto i = 0; i < 50; i++)
  {
    res[i] = zero[0][i] * one[1][i] + zero[1][i] * one[0][i];
    for (auto j = 0; j < i; j++)
    {
      res[i] += one[0][j] * one[1][j];
    }
  }
  ll ans = 0;
  for (auto i = 0; i < 50; i++)
  {
    if (res[i] % 2 == 1)
    {
      ans += (1ll << i);
    }
  }
  cout << ans << endl;
  return 0;
}