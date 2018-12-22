/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 12/22/2018, 9:09:29 PM
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

ll calc(ll x, ll y)
{
  if (x > y)
  {
    ll res = 0;
    ll mult = 1;
    while (x > y * mult)
    {
      res += 2;
      mult *= 4;
    }
    return res;
  }
  else
  {
    ll res = 0;
    ll mult = 1;
    while (x * (mult * 4) > y)
    {
      res -= 2;
      mult *= 4;
    }
    return res;
  }
}

int N;
ll A[200010];
ll X[200010];
ll imos_X[200010];
ll ans_X[200010];

ll B[200010];
ll Y[200010];
ll imos_Y[200010];
ll ans_Y[200010];

typedef tuple<ll, int> T;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  X[0] = 0;
  for (auto i = 1; i < N; i++)
  {
    X[i] = calc(A[i - 1], A[i]);
  }
  imos_X[0] = 0;
  for (auto i = 1; i < N; i++)
  {
    imos_X[i] = X[i] + imos_X[i - 1];
    cerr << "imos_X[" << i << "] = " << imos_X[i] << endl;
  }
  vector<T> V;
  BIT bit_X = BIT(N);
  BIT bit_cnt_X = BIT(N);
  for (auto i = 0; i < N; i++)
  {
    V.push_back(T(imos_X[i], i));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (auto i = 0; i < N; i++)
  {
    ll M = get<0>(V[i]);
    int ind = get<1>(V[i]) + 1;
    bit_X.add(ind, M);
    bit_cnt_X.add(ind);
    ans_X[ind - 1] = bit_X.sum(ind, N + 1) - M * bit_cnt_X.sum(ind, N + 1);
  }
  for (auto i = 0; i < N; i++)
  {
    B[i] = A[i];
  }
  reverse(B, B + N);
  Y[0] = 0;
  for (auto i = 1; i < N; i++)
  {
    Y[i] = calc(B[i - 1], B[i]);
  }
  imos_Y[0] = 0;
  for (auto i = 1; i < N; i++)
  {
    imos_Y[i] = Y[i] + imos_Y[i - 1];
  }
  V.clear();
  BIT bit_Y = BIT(N);
  BIT bit_cnt_Y = BIT(N);
  for (auto i = 0; i < N; i++)
  {
    V.push_back(T(imos_Y[i], i));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (auto i = 0; i < N; i++)
  {
    ll M = get<0>(V[i]);
    int ind = get<1>(V[i]) + 1;
    bit_Y.add(ind, M);
    bit_cnt_Y.add(ind);
    ans_Y[ind - 1] = bit_Y.sum(ind, N + 1) - M * bit_cnt_Y.sum(ind, N + 1);
  }
  reverse(ans_Y, ans_Y + N);
  ll ans = 10000000000000000;
  for (auto i = 0; i <= N; i++)
  {
    ll t_ans = i;
    cerr << "i = " << i << endl;
    if (i < N)
    {
      t_ans += ans_X[i];
      cerr << "ans_X[" << i << "] = " << ans_X[i] << endl;
    }
    if (i > 0)
    {
      t_ans += ans_Y[i - 1];
      cerr << "ans_Y[" << i - 1 << "] = " << ans_Y[i - 1] << endl;
    }
    ans = min(t_ans, ans);
  }
  cout << ans << endl;
}