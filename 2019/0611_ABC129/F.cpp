#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/11/2019, 7:30:08 PM
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
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
typedef long long ll;
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}
void No()
{
  cout << "No" << endl;
  exit(0);
}
const int MAX_SIZE = 1000010;
class mint
{
public:
  static ll MOD;
  ll x;
  mint() : x(0) {}
  mint(ll x) : x(x % MOD) {}
  mint operator-() const { return mint(0) - *this; }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  mint &operator-=(const mint &a) { return *this += -a; }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint &operator/=(const mint &a) { return (*this *= power(MOD - 2)); }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  mint operator/(const mint &a) const { return mint(*this) /= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
  const mint power(ll N)
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
      mint half = power(N / 2);
      return half * half;
    }
  }
};
ll mint::MOD = 1e9 + 7;
istream &operator>>(istream &stream, mint &a) { return stream >> a.x; }
ostream &operator<<(ostream &stream, const mint &a) { return stream << a.x; }
mint inv[MAX_SIZE];
mint fact[MAX_SIZE];
mint factinv[MAX_SIZE];
void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
  }
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = mint(i) * fact[i - 1];
    factinv[i] = inv[i] * factinv[i - 1];
  }
}
mint choose(int n, int k)
{
  if (n >= 0 && k >= 0 && n - k >= 0)
  {
    return fact[n] * factinv[k] * factinv[n - k];
  }
  return 0;
}
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

template <class T>
class Matrix
{
private:
  int H, W;
  T **a;

public:
  Matrix() {}

  Matrix(int h, int w) : H(h), W(w)
  {
    a = new T *[H];
    for (auto i = 0; i < H; i++)
    {
      a[i] = new T[W];
    }
  }

  Matrix(const Matrix &A)
  {
    H = A.H;
    W = A.W;
    a = new T *[H];
    for (auto i = 0; i < H; i++)
    {
      a[i] = new T[W];
    }
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        a[i][j] = A.a[i][j];
      }
    }
  }

  Matrix &operator=(const Matrix A)
  {
    H = A.H;
    W = A.W;
    a = new T *[H];
    for (auto i = 0; i < H; i++)
    {
      a[i] = new T[W];
    }
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        a[i][j] = A.a[i][j];
      }
    }
    return *this;
  }

  Matrix &operator=(const vector<T> v)
  {
    assert((int)v.size() == H * W);
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        a[i][j] = v[i * W + j];
      }
    }
    return *this;
  }

  const Matrix operator-() const
  {
    Matrix X(H, W);
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        X.a[i][j] = -a[i][j];
      }
    }
    return X;
  }

  const Matrix operator+(const Matrix &A) const
  {
    assert(A.H == H);
    assert(A.W == W);
    Matrix X(H, W);
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        X.a[i][j] = a[i][j] + A.a[i][j];
      }
    }
    return X;
  }

  const Matrix operator-(const Matrix &A) const
  {
    return this + (-A);
  }

  const Matrix operator*(const Matrix &A) const
  {
    assert(W == A.H);
    Matrix X(H, A.W);
    for (auto i = 0; i < X.H; i++)
    {
      for (auto j = 0; j < X.W; j++)
      {
        X.a[i][j] = 0;
        for (auto k = 0; k < W; k++)
        {
          T t = a[i][k] * A.a[k][j];
          X.a[i][j] += t;
        }
      }
    }
    return X;
  }

  Matrix &operator+=(const Matrix &A)
  {
    Matrix X = this + A;
    this = X;
    return this;
  }

  Matrix &operator-=(const Matrix &A)
  {
    return this += (-A);
  }

  Matrix &operator*=(const Matrix &A)
  {
    Matrix X = this * A;
    this = X;
    return this;
  }

  bool operator==(const Matrix &A) const
  {
    assert(H == A.H);
    assert(W == A.W);
    for (auto i = 0; i < H; i++)
    {
      for (auto j = 0; j < W; j++)
      {
        if (a[i][j] != A.a[i][j])
        {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(const Matrix &A) const
  {
    return !(this == A);
  }

  const T *&operator[](const size_t i) const
  {
    return a[i];
  }

  T *&operator[](const size_t i)
  {
    return a[i];
  }

  const Matrix power(ll N) const
  {
    assert(H == W);
    // N > 0
    if (N == 1)
    {
      return *this;
    }
    if (N % 2 == 1)
    {
      return power(N - 1) * (*this);
    }
    Matrix X = power(N / 2);
    return X * X;
  }
};

ll L, M, A, B;

Matrix<mint> affine(ll k)
{
  mint x = 1;
  for (auto i = 0; i < k; i++)
  {
    x *= 10;
  }
  Matrix<mint> X(3, 3);
  X = {x, 1, 0, 0, 1, B, 0, 0, 1};
  return X;
}

int f(int i)
{
  return (to_string(A + B * i)).size();
}

ll ub[100];

int main()
{
  // init();
  cin >> L >> A >> B >> M;
  mint::MOD = M;
  for (auto i = 1; i <= 18; i++)
  {
    ll x = ub[i - 1];
    if (f(x) != i)
    {
      ub[i] = ub[i - 1];
      continue;
    }
    ll ok = x;
    ll ng = L;
    while (abs(ok - ng) > 1)
    {
      ll t = (ok + ng) / 2;
      if (f(t) == i)
      {
        ok = t;
      }
      else
      {
        ng = t;
      }
    }
    ub[i] = ng;
  }
  Matrix<mint> v(3, 1);
  v = {0, A, 1};
  for (auto i = 1; i <= 18; i++)
  {
    int x = ub[i] - ub[i - 1];
    if (x == 0)
    {
      continue;
    }
    v = affine(i).power(x) * v;
  }
  cout << v[0][0] << endl;
}