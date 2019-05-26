#define DEBUG 1

/**
 * File    : F3.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 14:03:38
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

template <class T>
class SegTree
{ // 0-indexed, [0, N).
private:
  int N;
  T *dat;
  T UNIT; // モノイドの単位元

  static T func(T x, T y)
  { // ここで演算を定義する。圏、特にモノイドであればなんでも良い。
    // 実装はモノイドであるとする。
    // return min(x, y);
    return x + y;
  }

public:
  SegTree()
  {
    dat = new T[0];
  }

  ~SegTree()
  {
    delete[] dat;
  }

  SegTree(int n, T unit)
  { // ここで unit を定義するのも変な実装だけどめんどいからこれでいい。
    // min の場合は INFTY = (1LL << 60)
    // + の場合は 0 とする。
    UNIT = unit;
    N = 1;
    while (N < n)
    {
      N *= 2;
    }
    dat = new T[2 * N - 1];
    for (auto i = 0; i < 2 * N - 1; ++i)
    {
      dat[i] = UNIT;
    }
  }

  void update(int k, T a)
  {
    k += N - 1;
    dat[k] = a;
    while (k > 0)
    {
      k = (k - 1) / 2;
      dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

private:
  T find(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
      return UNIT;
    if (a <= l && r <= b)
      return dat[k];
    T vl = find(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = find(a, b, k * 2 + 2, (l + r) / 2, r);
    return func(vl, vr);
  }

public:
  T find(int a, int b)
  { // [a, b) の find をする。
    return find(a, b, 0, 0, N);
  }
};

typedef tuple<bool, ll, ll> query;

int Q;
query X[200010];
set<ll> S;
map<ll, int> M;
SegTree<ll> tree;

priority_queue<ll> L;
priority_queue<ll, vector<ll>, greater<ll>> R;
ll B = 0;

void merge(ll a, ll b)
{
  B += b;
  L.push(a);
  R.push(a);
  if (L.top() <= R.top())
  {
    // nothing
  }
  else
  {
    ll l = L.top();
    ll r = R.top();
    L.pop();
    R.pop();
    L.push(r);
    R.push(l);
  }
  tree.update(M[a], a);
}

void flush()
{
  ll p = L.top();
  int ind = M[p];
  ll v = -tree.find(0, ind) + tree.find(ind + 1, S.size());
  cout << p << " " << v << endl;
}

int main()
{
  cin >> Q;
  for (auto i = 0; i < Q; i++)
  {
    char x;
    cin >> x;
    if (x == '1')
    {
      ll a, b;
      cin >> a >> b;
      X[i] = query(true, a, b);
    }
    else
    {
      X[i] = query(false, 0, 0);
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    if (get<0>(X[i]))
    {
      S.insert(get<1>(X[i]));
    }
  }
  int ind = 0;
  for (auto x : S)
  {
    M[x] = ind++;
  }
  tree = SegTree<ll>(S.size(), 0);
}