/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 11/24/2018, 9:16:13 PM
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

int N;
ll D;
typedef tuple<ll, ll> P;
vector<P> V;
typedef tuple<ll, ll, ll> X;
vector<X> W;
set<ll> A[2];
int cnt[1010][1010];

ll calc(ll x)
{
  ll lb = 0;
  ll ub = 100010;
  while (ub - lb > 1)
  {
    ll t = (ub + lb) / 2;
    if (t * t < x)
    {
      lb = t;
    }
    else
    {
      ub = t;
    }
  }
  return ub - 1;
}

ll calc_(int k)
{
  if ((int)A[k].size() <= 1)
  {
    return 0;
  }
  auto it = A[k].begin();
  auto it2 = A[k].begin();
  it2++;
  auto last = A[k].end();
  last--;
  ll mini = *last - *it;
  while (it2 != A[k].end())
  {
    mini = min(mini, D - (*it2 - *it));
    it++;
    it2++;
  }
  return mini;
}

int main()
{
  cin >> N >> D;
  for (auto i = 0; i < N; i++)
  {
    ll x, y;
    cin >> x >> y;
    V.push_back(P(x, y));
  }
  fill(&cnt[0][0], &cnt[0][0] + 1010 * 1010, 0);
  for (auto i = 0; i < N; i++)
  {
    ll x = get<0>(V[i]);
    ll y = get<1>(V[i]);
    cnt[x % D][y % D]++;
  }
  for (auto i = 0; i < D; i++)
  {
    for (auto j = 0; j < D; j++)
    {
      if (cnt[i][j] > 0)
      {
        W.push_back(X(cnt[i][j], i, j));
      }
    }
  }
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  ll maxi = get<0>(W[0]);
  ll r = calc(maxi);
  ll s = (maxi + r) / (r + 1) - 1;
  for (auto e : W)
  {
    if (get<0>(e) < (r + 1) * (s + 1))
    {
      break;
    }
    A[0].insert(get<1>(e));
    A[1].insert(get<2>(e));
  }
  ll alpha = calc_(0);
  ll beta = calc_(1);
  /*
  for (auto i = 0; i < D; i++)
  {
    for (auto j = 0; j < D; j++)
    {
      cerr << cnt[i][j] << " ";
    }
    cerr << endl;
  }
  cerr << "maxi = " << maxi << endl;
  cerr << "r = " << r << ", s = " << s << endl;
  */
  // cerr << "alpha = " << alpha << ", beta = " << beta << endl;
  ll ans = max(min(alpha, beta) + r * D, max(alpha, beta) + s * D);
  cout << ans << endl;
}