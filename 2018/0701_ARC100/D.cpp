/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-1 20:39:17
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
const ll infty = 1000000000000007;

int N;
ll A[200010];
ll sum = 0;
ll imos[200010];

int index(ll sum)
{
  int lb = 0;
  int ub = N - 1;
  if (sum < imos[lb])
  {
    return lb;
  }
  while (ub - lb > 1)
  {
    int t = (ub + lb) / 2;
    if (sum < imos[t])
    {
      ub = t;
    }
    else
    {
      lb = t;
    }
  }
  return lb;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
    sum += A[i];
  }
  fill(imos, imos + 200010, 0);
  imos[0] = A[0];
  for (auto i = 1; i < N; i++)
  {
    imos[i] = imos[i - 1] + A[i];
  }
  ll ans = infty;
  for (auto s = 1; s < N - 2; s++)
  {
    ll PQ = imos[s];
    ll RS = sum - imos[s];
    int ind = index(PQ / 2);
    for (auto k = ind - 2; k <= ind + 2; k++)
    {
      if (0 <= k && k < s)
      {
        ll P = imos[k];
        ll Q = PQ - P;
        ll ind2 = index(PQ + RS / 2);
        for (auto t = ind2 - 2; t < ind2 + 2; t++)
        {
          if (s < t && t < N - 1)
          {
            // cerr << "k = " << k << ", s = " << s << ", t = " << t << endl;
            ll R = imos[t] - PQ;
            ll S = RS - R;
            ll maxi = max(max(P, Q), max(R, S));
            ll mini = min(min(P, Q), min(R, S));
            ans = min(ans, maxi - mini);
          }
        }
      }
    }
  }
  cout << ans << endl;
}