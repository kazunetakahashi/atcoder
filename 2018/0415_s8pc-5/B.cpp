/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-15 21:01:44
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

typedef tuple<double, double> P;

int N, M;
vector<P> V, W;
vector<double> D;

bool ok(double t)
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      P p = V[i];
      P q = W[j];
      double d = D[i] + t;
      double dx = get<0>(p) - get<0>(q);
      double dy = get<1>(p) - get<1>(q);
      if (dx * dx + dy * dy < d * d)
      {
        return false;
      }
    }
  }
  for (auto i = 0; i < M; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      if (i == j)
      {
        continue;
      }
      P p = W[i];
      P q = W[j];
      double d = t + t;
      double dx = get<0>(p) - get<0>(q);
      double dy = get<1>(p) - get<1>(q);
      if (dx * dx + dy * dy < d * d)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    double x, y, r;
    cin >> x >> y >> r;
    V.push_back(P(x, y));
    D.push_back(r);
  }
  for (auto i = 0; i < M; i++)
  {
    double x, y;
    cin >> x >> y;
    W.push_back(P(x, y));
  }
  double ub = 100000;
  double lb = 0;
  for (auto k = 0; k < 100; k++)
  {
    double t = (ub+lb)/2;
    if (ok(t))
    {
      lb = t;
    }
    else
    {
      ub = t;
    }
  }
  cout << fixed << setprecision(13) << lb << endl;
}