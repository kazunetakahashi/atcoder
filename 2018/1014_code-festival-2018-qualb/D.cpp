/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-14 21:35:05
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

int N, M;
double q;
ll x[2010];
ll p[2010];

int main()
{
  cin >> N >> M >> q;
  for (auto i = 0; i < M; i++)
  {
    cin >> x[i] >> p[i];
  }
  p[M] = 0;
  x[M] = 1000010;
  M++;
  ll maxi = 0;
  for (auto k = 0; k < M; k++)
  {
    ll A = 0;
    ll B = 0;
    for (auto i = 0; i < k; i++)
    {
      A += p[i];
      B -= p[i] * x[i];
    }
    for (auto i = k; i < M; i++)
    {
      A -= p[i];
      B += p[i] * x[i];
    }
    ll y = 0;
    if (A > 0 || k == 0)
    {
      y = x[k];
    }
    else
    {
      y = x[k - 1];
    }
    maxi = max(maxi, y * A + B);
  }
  cerr << fixed << setprecision(12) << maxi / q << endl;
}