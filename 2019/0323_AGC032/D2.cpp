#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-28 18:47:58
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

const ll infty = 100000000000007;
int N;
ll A, B;
int p[5010];
ll DP[5010][5010];

int main()
{
  cin >> N >> A >> B;
  for (auto i = 1; i <= N; i++)
  {
    cin >> p[i];
  }
  fill(&DP[0][0], &DP[0][0] + 5010 * 5010, infty);
  DP[0][0] = 0;
  for (auto i = 0; i <= N; i++)
  {
    for (auto j = 0; j <= N; j++)
    {
      if (j < N)
      {
        DP[i][j + 1] = min(DP[i][j + 1], DP[i][j]);
      }
      if (i < N)
      {
        if (p[i + 1] <= j)
        {
          DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + B);
        }
        else
        {
          DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + A);
        }
      }
      if (i < N && j < N && p[i + 1] == j + 1)
      {
        DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j]);
      }
    }
  }
  cout << DP[N][N] << endl;
}