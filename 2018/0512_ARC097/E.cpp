/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-20 16:21:24
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
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
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
const int infty = 1000000007;

class BIT
{ // index starts at 1.
public:
  int N;
  ll *data;

  BIT(int n) : N(n)
  {
    data = new ll[N + 1];
    for (auto i = 1; i <= N; ++i)
    {
      data[i] = 0;
    }
  }

  BIT()
  {
    BIT(0);
  }

  ~BIT()
  {
    delete[] data;
  }

  ll sum(int i)
  { // [1, i]
    ll s = 0;
    while (i > 0)
    {
      s += data[i];
      i -= i & -i;
    }
    return s;
  }

  ll sum(int a, int b)
  { // [a, b)
    return sum(b - 1) - sum(a - 1);
  }

  void add(int i, ll x)
  {
    while (i <= N)
    {
      data[i] += x;
      i += i & -i;
    }
  }

  void add(int i)
  {
    add(i, 1);
  }
};

char c[4020];
int a[4020];
int cost[2][2010][2010];
int DP[2010][2010];

int main()
{
  int N;
  cin >> N;
  for (auto i = 0; i < 2 * N; i++)
  {
    cin >> c[i] >> a[i];
  }
  BIT bit[2];
  bit[0] = BIT(N);
  bit[1] = BIT(N);
  reverse(c, c + 2 * N);
  reverse(a, a + 2 * N);
  fill(&cost[0][0][0], &cost[0][0][0] + 2 * 2010 * 2010, -1);
  for (auto l = 0; l < 2 * N; l++)
  {
    int k = (c[l] == 'B');
    int i = a[l];
    bit[k].add(i);
    // cerr << "bit[" << k << "].add(" << i << ")" << endl;
    if (k == 0)
    {
      for (auto j = 0; j <= N; j++)
      {
        cost[k][i - 1][j] = bit[0].sum(i - 1) + bit[1].sum(j);
      }
    }
    else
    {
      for (auto j = 0; j <= N; j++)
      {
        cost[k][j][i - 1] = bit[1].sum(i - 1) + bit[0].sum(j);
      }
    }
  }
  DP[0][0] = 0;
  for (auto i = 0; i <= N; i++)
  {
    for (auto j = 0; j <= N; j++)
    {
      if (i == 0 && j == 0)
      {
        DP[i][j] = 0;
        continue;
      }
      DP[i][j] = infty;
      if (i > 0)
      {
        assert(cost[0][i - 1][j] >= 0);
        DP[i][j] = min(DP[i][j], DP[i - 1][j] + cost[0][i - 1][j]);
      }
      if (j > 0)
      {
        assert(cost[1][i][j - 1] >= 0);
        DP[i][j] = min(DP[i][j], DP[i][j - 1] + cost[1][i][j - 1]);
      }
    }
  }
  cout << DP[N][N] << endl;
  return 0;
}
