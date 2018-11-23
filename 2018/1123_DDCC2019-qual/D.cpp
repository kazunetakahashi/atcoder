/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 11/23/2018, 9:25:43 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
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
// const ll M = 1000000007;

ll a[40];

void no()
{
  cout << "invalid" << endl;
  exit(0);
}

ll sum(ll N, ll k)
{
  ll ans = 0;
  while (N > 0)
  {
    ans += N % k;
    ans /= k;
  }
  return ans;
}

bool check(ll N)
{
  if (!(1 <= N && N <= 1000000000000))
  {
    return false;
  }
  for (auto i = 2; i <= 30; i++)
  {
    if (sum(N, i) != a[i])
    {
      return false;
    }
  }
  return true;
}

vector<vector<ll>> X[9];
ll pwr[24];

void init()
{
  for (auto i = 0; i <= 2; i++)
  {
    for (auto j = 0; j <= 2; j++)
    {
      for (auto k = 0; k <= 2; k++)
      {
        for (auto l = 0; l <= 2; l++)
        {
          X[i + j + k + l].push_back({i, j, k, l});
        }
      }
    }
  }
  pwr[0] = 1;
  for (auto i = 1; i < 24; i++)
  {
    pwr[i] = 3 * pwr[i - 1];
  }
}

bool discover(vector<ll> V)
{
  assert((int)V.size() == 6);
  for (auto x : V)
  {
    if (!(0 <= x && x <= 8))
    {
      return false;
    }
  }
  vector<ll> Y[6];
  for (auto i = 0; i < 6; i++)
  {
    for (auto v : X[V[i]])
    {
      ll Q = 0;
      for (auto j = 0; j < 4; j++)
      {
        Q += pwr[6 * j + i] * v[j];
      }
      Y[i].push_back(Q);
    }
  }
  for (auto a : Y[0])
  {
    for (auto b : Y[1])
    {
      for (auto c : Y[2])
      {
        for (auto d : Y[3])
        {
          for (auto e : Y[4])
          {
            for (auto f : Y[5])
            {
              ll N = a + b + c + d + e + f;
              cerr << "N = " << N << endl;
              if (check(N))
              {
                cout << N << endl;
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

int main()
{
  init();
  for (auto i = 2; i <= 30; i++)
  {
    cin >> a[i];
  }
  for (auto i = 0; i <= 8; i++)
  {
    for (auto j = 0; j <= 8; j++)
    {
      for (auto k = 0; k <= 8; k++)
      {
        vector<ll> V;
        V.push_back(i);
        V.push_back(j);
        V.push_back(k);
        ll A = a[3] - (i + j + k);
        ll B = a[9] - (i + 3 * j + k);
        ll C = a[27] - (i + 3 * j + 9 * k);
        ll T = -4 * A + B + C;
        if (T % 8 != 0)
        {
          continue;
        }
        ll X5 = T / 8;
        ll U = B - A;
        if (U % 2 != 0)
        {
          continue;
        }
        ll X3 = U / 2 - X5;
        ll X4 = A - X3 - X5;
        V.push_back(X3);
        V.push_back(X4);
        V.push_back(X5);
        if (discover(V))
        {
          return 0;
        }
      }
    }
  }
  no();
}