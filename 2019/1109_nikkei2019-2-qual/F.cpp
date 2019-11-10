#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 11/10/2019, 5:08:05 PM
 * Powered by Visual Studio Code
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
template <typename T>
void ch_max(T &left, T right)
{
  if (left < right)
  {
    left = right;
  }
}
template <typename T>
void ch_min(T &left, T right)
{
  if (left > right)
  {
    left = right;
  }
}
using ll = long long;
constexpr ll MOD{998244353LL};
constexpr ll MAX_SIZE{3000010LL};
template <ll MOD = MOD>
class Mint
{
public:
  ll x;
  Mint() : x{0LL} {}
  Mint(ll x) : x{x % MOD} {}
  Mint operator-() const { return x ? MOD - x : 0; }
  Mint &operator+=(const Mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  Mint &operator-=(const Mint &a) { return *this += -a; }
  Mint &operator*=(const Mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  Mint &operator/=(const Mint &a)
  {
    Mint b{a};
    return *this *= b.power(MOD - 2);
  }
  Mint operator+(const Mint &a) const { return Mint(*this) += a; }
  Mint operator-(const Mint &a) const { return Mint(*this) -= a; }
  Mint operator*(const Mint &a) const { return Mint(*this) *= a; }
  Mint operator/(const Mint &a) const { return Mint(*this) /= a; }
  bool operator<(const Mint &a) const { return x < a.x; }
  bool operator==(const Mint &a) const { return x == a.x; }
  const Mint power(ll N)
  {
    if (N == 0)
    {
      return 1;
    }
    else if (N % 2 == 1)
    {
      return *this * power(N - 1);
    }
    else
    {
      Mint half = power(N / 2);
      return half * half;
    }
  }
};
template <ll MOD>
Mint<MOD> operator+(ll lhs, const Mint<MOD> &rhs)
{
  return rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator-(ll lhs, const Mint<MOD> &rhs)
{
  return -rhs + lhs;
}
template <ll MOD>
Mint<MOD> operator*(ll lhs, const Mint<MOD> &rhs)
{
  return rhs * lhs;
}
template <ll MOD>
Mint<MOD> operator/(ll lhs, const Mint<MOD> &rhs)
{
  return Mint<MOD>{lhs} / rhs;
}
template <ll MOD>
istream &operator>>(istream &stream, Mint<MOD> &a)
{
  return stream >> a.x;
}
template <ll MOD>
ostream &operator<<(ostream &stream, const Mint<MOD> &a)
{
  return stream << a.x;
}
template <ll MOD = MOD, ll MAX_SIZE = MAX_SIZE>
class Combination
{
public:
  vector<Mint<MOD>> inv, fact, factinv;
  Combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i = 2LL; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[MOD % i]) * (MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i = 1LL; i < MAX_SIZE; i++)
    {
      fact[i] = Mint<MOD>(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }
  Mint<MOD> operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }
  Mint<MOD> catalan(int x, int y)
  {
    return (*this)(x + y, y) - (*this)(x + y, y - 1);
  }
};

class UnionFind
{
  int N;
  vector<int> par;

public:
  UnionFind() : N{0} {}
  UnionFind(int N) : N{N}, par(N, -1) {}

  bool is_same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
    {
      return false;
    }
    if (par[x] > par[y])
    {
      swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x)
  {
    return -par[root(x)];
  }

  int count_parts()
  {
    int ans{0};
    for (auto i = 0; i < N; i++)
    {
      if (root(i) < 0)
      {
        ++ans;
      }
    }
    return ans;
  }

private:
  int root(int x)
  {
    if (par[x] < 0)
    {
      return x;
    }
    return par[x] = root(par[x]);
  }
};

// for C++14
using mint = Mint<MOD>;
using combination = Combination<MOD, MAX_SIZE>;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// constexpr double epsilon{1e-10};
// constexpr ll infty{1000000000000000LL};
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}
void No()
{
  cout << "0" << endl;
  exit(0);
}

enum class State
{
  empty,
  on,
  off,
  que,
  used,
  invalid
};

vector<vector<State>> make_states(int N, vector<string> const &A)
{
  vector<vector<State>> V(N + 1, vector<State>(N + 1, State::empty));
  for (auto i = 1; i < N; i++)
  {
    for (auto j = 1; j < N; j++)
    {
      char c{A[i - 1][j - 1]};
      int a{abs(i - j)};
      int b{min(2 * N - i - j, i + j)};
#if DEBUG == 1
      cerr << "(" << i << ", " << j << ") = " << a << ", " << b << endl;
#endif
      assert(a != b);
      State s;
      if (c == 'o')
      {
        s = State::on;
      }
      else if (c == 'x')
      {
        s = State::off;
      }
      else
      {
        assert(c == '?');
        s = State::que;
      }
      if (V[a][b] == State::empty)
      {
        V[a][b] = V[b][a] = s;
      }
      else if (V[a][b] != s)
      {
        if ((s == State::on && V[a][b] == State::off) || (s == State::off && V[a][b] == State::on))
        {
          No();
        }
        if (V[a][b] == State::que)
        {
          V[a][b] = V[b][a] = s;
        }
      }
    }
  }
  return V;
}

mint calc_even(int N, vector<vector<State>> &V, int K);
mint calc_odd(int N, vector<vector<State>> &V, int K);

mint calc(int N, vector<vector<State>> &V, int K)
{
  int Y{N / 2};
  int X{N - Y};
  int U;
  if (K == 0)
  {
    U = X;
  }
  else
  {
    assert(K == 1);
    U = Y;
  }
  if (U % 2 == 0)
  {
    return calc_even(N, V, K);
  }
  else
  {
    return calc_odd(N, V, K);
  }
}

mint calc_even(int N, vector<vector<State>> &V, int K)
{
  int cnt{0};
  for (auto i = K; i < N; i += 2)
  {
    for (auto j = K; j < N; j += 2)
    {
      if (V[i][j] == State::que)
      {
        ++cnt;
      }
    }
  }
  cnt /= 2;
  return mint{2}.power(cnt);
}

mint calc_odd(int N, vector<vector<State>> &V, int K)
{
  int cnt{0};
  UnionFind uf(N);
  for (auto i = K; i < N; i += 2)
  {
    for (auto j = i + 2; j < N; j += 2)
    {
      if (V[i][j] == State::que && !uf.merge(i, j))
      {
        ++cnt;
      }
    }
  }
  // working on each connected components
  vector<bool> visited(N, false);
  for (auto i = K; i < N; i += 2)
  {
    if (visited[i])
    {
      continue;
    }
    for (auto j = K; j < N; j += 2)
    {
      if (uf.is_same(i, j))
      {
        visited[j] = true;
      }
    }
    int c{0};
    for (auto j = K; j < N; j += 2)
    {
      for (auto k = K; k < N; k += 2)
      {
        if (uf.is_same(i, j) && !uf.is_same(i, k) && V[j][k] == State::on)
        {
          ++c;
        }
      }
    }
    if (c % 2 == 1)
    {
      No();
    }
  }
  return mint{2}.power(cnt);
}

int main()
{
  int N;
  cin >> N;
  vector<string> A(N);
  for (auto i = 0; i < N - 1; i++)
  {
    cin >> A[i];
  }
  vector<vector<State>> V{make_states(N, A)};
  ++N;
  mint ans{1};
  ans *= calc(N, V, 0);
  ans *= calc(N, V, 1);
  cout << ans << endl;
}
