/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-17 14:09:03
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
#include <chrono>
using namespace std;

#define DEBUG 1 // change 0 -> 1 if we need debug.

typedef long long ll;

const int dx[5] = {1, 0, -1, 0, 0};
const int dy[5] = {0, 1, 0, -1, 0};

// const int C = 1e6+10;
// const ll M = 1000000007;

random_device rd;
mt19937 mt(rd());

const int N = 100;
typedef tuple<int, int, ll> press;

ll A[100][100];

bool valid(int x, int y)
{
  return (0 <= x && x < N && 0 <= y && y < N);
}

ll calc_score(const vector<vector<ll>> &C)
{
  ll ans = 200000000;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      ans -= abs(A[i][j] - C[i][j]);
    }
  }
  return ans;
}

ll plus_score(vector<vector<ll>> &C, int X, int Y, ll H)
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      C[i][j] += max(0ll, H - abs(i - X) - abs(j - Y));
    }
  }
  return calc_score(C);
}

ll minus_score(vector<vector<ll>> &C, int X, int Y, ll H)
{
  return plus_score(C, X, Y, H);
}

class state
{
public:
  vector<vector<ll>> B;
  vector<press> V;
  ll score;

  bool operator<(const state &rhs) const
  {
    return score < rhs.score;
  }

  state()
  {
    B = vector<vector<ll>>(N, vector<ll>(N, 0));
    score = calc_score(B);
  }

  void add_press(press p)
  {
    int X = get<0>(p);
    int Y = get<1>(p);
    ll H = get<2>(p);
    score = plus_score(B, X, Y, H);
    V.push_back(p);
  }

  void del_press(int k)
  {
    assert(0 <= k && k < (int)V.size());
    auto it = V.begin() + k;
    int X = get<0>(*it);
    int Y = get<1>(*it);
    ll H = get<2>(*it);
    score = minus_score(B, X, Y, H);
    V.erase(it);
  }

  void show_V()
  {
#if DEBUG == 1
    for (auto i = 0; i < N; i++)
    {
      for (auto j = 0; j < N; j++)
      {
        cerr << B[i][j] - A[i][j] << " ";
      }
      cerr << endl;
    }
#endif
    cout << V.size() << endl;
    for (auto e : V)
    {
      cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
    }
  }

  ll able_number(int x, int y)
  {
    ll ans = N;
    for (auto i = 0; i < N; i++)
    {
      for (auto j = 0; j < N; j++)
      {
        ans = min(ans, abs(x - i) + abs(y - j) + (A[i][j] - B[i][j]));
      }
    }
    return ans;
  }

  // ここから直す
  void improve()
  {
    int k = rd() % ((int)V.size());
    int x = get<0>(V[k]);
    int y = get<1>(V[k]);
    ll h = get<2>(V[k]);
    vector<tuple<ll, int, int>> X;
    vector<vector<ll>> C = B;
    minus_score(C, x, y, h);
    for (auto i = 0; i < 5; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!valid(nx, ny))
        continue;
      for (auto j = -10; j <= 10; j++)
      {
        ll nh = h + j;
        if (!(1 <= nh && nh <= N))
          continue;
        ll ns = plus_score(C, nx, ny, nh);
        X.push_back(make_tuple(ns, i, j));
        minus_score(C, nx, ny, nh);
      }
    }
    auto it = max_element(X.begin(), X.end());
    int i = get<1>(*it);
    int j = get<2>(*it);
    press p = make_tuple(x + dx[i], y + dy[i], h + j);
    del_press(k);
    add_press(p);
  }
};

vector<state> W;

void seed()
{
  for (auto k = 0; k < 100; k++)
  {
    state S = state();
    for (auto l = 0; l < 1000; l++)
    {
      int x = rd() % N;
      int y = rd() % N;
      int h = max(1ll, S.able_number(x, y));
      S.add_press(make_tuple(x, y, h));
    }
    W.push_back(S);
  }
}

int main()
{
  auto start_time = std::chrono::system_clock::now();
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }
  seed();
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  auto end_time = std::chrono::system_clock::now();
  double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
  while (true)
  {
    end_time = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    if (elapsed > 5950)
    {
      auto it = max_element(W.begin(), W.end());
      (*it).show_V();
      return 0;
    }
    if (W.size() > 100)
    {
      sort(W.begin(), W.end());
      reverse(W.begin(), W.end());
      vector<state> WW;
      for (auto i = 0; i < 10; i++)
      {
        WW.push_back(W[i]);
      }
      W = WW;
    }
    int num = rd() % ((int)W.size());
    state S = W[num];
    for (auto i = 0; i < 10; i++)
    {
      S.improve();
    }
    W.push_back(S);
  }
}