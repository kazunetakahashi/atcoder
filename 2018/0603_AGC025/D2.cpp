/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-13 17:49:09
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
typedef tuple<ll, ll> P;

P operator+(const P &p, const P &q)
{
  return P(get<0>(p) + get<0>(q),
           get<1>(p) + get<1>(q));
}

ll N, D[2];
ll M;
ll K;
int color[2][610][610];
vector<P> V[2][610][610];
vector<P> W[2];

ll dist2(int x, int y)
{
  return x * x + y * y;
}

bool valid(P p)
{
  int x = get<0>(p);
  int y = get<1>(p);
  return (0 <= x && x < M && 0 <= y && y < M);
}

int main()
{
  cin >> N >> D[0] >> D[1];
  K = N * N;
  M = 2 * N;
  fill(&color[0][0][0], &color[0][0][0] + 2 * 610 * 610, -1);
  for (auto k = 0; k < 2; k++)
  {
    for (auto x = -M + 1; x < M; x++)
    {
      for (auto y = -M + 1; y < M; y++)
      {
        if (dist2(x, y) == D[k])
        {
          W[k].push_back(P(x, y));
        }
      }
    }
    for (auto i = 0; i < M; i++)
    {
      for (auto j = 0; j < M; j++)
      {
        P p = P(i, j);
        for (auto e : W[k])
        {
          P q = p + e;
          if (valid(q))
          {
            V[k][i][j].push_back(q);
            //cerr << "V[" << k << "][" << i << "][" << j << "].push_back"
            //     << "(" << get<0>(q) << ", " << get<1>(q) << ")" << endl;
          }
        }
      }
    }
    for (auto i = 0; i < M; i++)
    {
      for (auto j = 0; j < M; j++)
      {
        if (color[k][i][j] == -1)
        {
          stack<P> S;
          S.push(P(i, j));
          color[k][i][j] = 0;
          while (!S.empty())
          {
            int x = get<0>(S.top());
            int y = get<1>(S.top());
            S.pop();
            for (auto e : V[k][x][y])
            {
              int xxx = get<0>(e);
              int yyy = get<1>(e);
              if (color[k][xxx][yyy] == -1)
              {
                color[k][xxx][yyy] = 1 - color[k][x][y];
                S.push(e);
              }
            }
          }
        }
      }
    }
  }
  for (auto k = 0; k < 2; k++)
  {
    for (auto l = 0; l < 2; l++)
    {
      int cnt = 0;
      for (auto i = 0; i < M; i++)
      {
        for (auto j = 0; j < M; j++)
        {
          if (color[0][i][j] == k && color[1][i][j] == l)
          {
            cnt++;
          }
        }
      }
      if (cnt >= K)
      {
        cnt = K;
        // cerr << "k = " << k << ", l = " << l << ", cnt = " << cnt << endl;
        for (auto i = 0; i < M; i++)
        {
          for (auto j = 0; j < M; j++)
          {
            if (color[0][i][j] == k && color[1][i][j] == l)
            {
              cout << i << " " << j << endl;
              cnt--;
              if (cnt == 0)
              {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 1;
}