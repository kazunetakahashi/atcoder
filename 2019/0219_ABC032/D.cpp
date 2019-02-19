#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2/19/2019, 9:14:45 PM
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N;
ll W;
ll v[210];
ll w[210];

typedef tuple<ll, ll> P;

vector<P> half(int x, int y)
{
  map<ll, ll> M;
  M[0] = 0;
  int l = y - x;
  for (auto i = 0; i < (1 << l); i++)
  {
    ll value = 0;
    ll weight = 0;
    for (auto k = 0; k < l; k++)
    {
      if ((i >> k) & 1)
      {
        value += v[k + x];
        weight += w[k + x];
        if (M.find(weight) == M.end())
        {
          M[weight] = value;
        }
        else
        {
          M[weight] = max(M[weight], value);
        }
      }
    }
  }
  vector<P> V;
  ll maxi = 0;
  for (auto x : M)
  {
    maxi = max(x.second, maxi);
    V.push_back(P(x.first, maxi));
  }
  return V;
}

void solve1()
{
  vector<P> X[2] = {half(0, N / 2), half(N / 2, N)};
  reverse(X[1].begin(), X[1].end());
  int ind[2] = {0, 0};
  ll ans = 0;
  while (ind[0] < (int)X[0].size() && ind[1] < (int)X[1].size())
  {
    ll w_0 = get<0>(X[0][ind[0]]);
    ll v_0 = get<1>(X[0][ind[0]]);
    ll w_1 = get<0>(X[1][ind[1]]);
    ll v_1 = get<1>(X[1][ind[1]]);
    if (w_0 + w_1 <= W)
    {
      ans = max(ans, v_0 + v_1);
      ind[0]++;
    }
    else
    {
      ind[1]++;
    }
  }
  cout << ans << endl;
}

ll DP[210][200010];

void solve2()
{
  fill(&DP[0][0], &DP[0][0] + 210 * 200010, -1);
  DP[0][0] = 0;
  int H = min(W, 200001LL);
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j <= H; j++)
    {
      if (DP[i][j] == -1)
      {
        continue;
      }
      DP[i + 1][j] = max(DP[i + 1][j], DP[i][j]);
      if (j + w[i] <= H)
      {
        DP[i + 1][j + w[i]] = max(DP[i + 1][j + w[i]], DP[i][j] + v[i]);
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i <= H; i++)
  {
    ans = max(ans, DP[N][i]);
  }
  cout << ans << endl;
}

ll const infty = 1000000000000000000;

void solve3()
{
  fill(&DP[0][0], &DP[0][0] + 210 * 200010, infty);
  DP[0][0] = 0;
  int H = 200001;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j <= H; j++)
    {
      if (DP[i][j] == infty)
      {
        continue;
      }
      DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);
      if (j + v[i] <= H)
      {
        DP[i + 1][j + v[i]] = min(DP[i + 1][j + v[i]], DP[i][j] + w[i]);
      }
    }
  }
  for (auto i = H - 1; i >= 0; i--)
  {
    if (DP[N][i] <= W)
    {
      cout << i << endl;
      return;
    }
  }
}

int main()
{
  cin >> N >> W;
  for (auto i = 0; i < N; i++)
  {
    cin >> v[i] >> w[i];
  }
  bool ok_w = true;
  for (auto i = 0; i < N; i++)
  {
    if (w[i] > 1000LL)
    {
      ok_w = false;
      break;
    }
  }
  bool ok_v = true;
  for (auto i = 0; i < N; i++)
  {
    if (v[i] > 1000LL)
    {
      ok_v = false;
      break;
    }
  }
  if (!ok_v && !ok_w)
  {
    solve1();
  }
  else if (ok_w)
  {
    solve2();
  }
  else
  {
    solve3();
  }
}