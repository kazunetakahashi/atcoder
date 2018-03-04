/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-4 21:11:47
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

vector<ll> V[100010];
vector<ll> sum[100010];
ll H, W, D;
int A[310][310];
int Q;
ll L[100010];
ll R[100010];

typedef tuple<ll, ll> point;
point P[100010];

ll dist(point p, point q)
{
  return abs(get<0>(p) - get<0>(q)) + abs(get<1>(p) - get<1>(q));
}

int main()
{
  cin >> H >> W >> D;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  cin >> Q;
  for (auto i = 0; i < Q; i++)
  {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      P[A[i][j]] = point(i, j);
    }
  }
  for (auto k = 0; k < D; k++)
  {
    int now = k;
    while (now + D < H * W)
    {
      V[k].push_back(dist(P[now], P[now + D]));
      now += D;
    }
  }
  for (auto k = 0; k < D; k++)
  {
    sum[k] = vector<ll>(V[k].size() + 1, 0);
    for (auto i = 0; i < (int)V[k].size(); i++)
    {
      sum[k][i + 1] = sum[k][i] + V[k][i];
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    int k = L[i] % D;
    int l = L[i] / D;
    int r = R[i] / D;
#if DEBUG == 1
    cerr << "k = " << k << ", l = " << l << ", r = " << r << endl;
#endif
    cout << sum[k][r] - sum[k][l] << endl;
  }
}