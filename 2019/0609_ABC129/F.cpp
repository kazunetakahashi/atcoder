#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/9/2019, 9:32:28 PM
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
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

template <class T>
class Matrix
{
public:
  static T MOD;

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

  Matrix &operator=(const Matrix A)
  {
    H = A.H;
    W = A.W;
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
        X.a[i][j] = MOD - a[i][j];
        if (MOD > 0)
        {
          X.a[i][j] %= MOD;
        }
      }
    }
    return this;
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
        if (MOD > 0)
        {
          X.a[i][j] %= MOD;
        }
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
          if (MOD > 0)
          {
            t %= MOD;
          }
          X.a[i][j] += t;
          if (MOD > 0)
          {
            X.a[i][j] %= MOD;
          }
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

  Matrix power(T N)
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

template <class T>
T Matrix<T>::MOD = 0;

ll L, A, B, M;
ll upper[100];

Matrix<ll> choose(ll k, ll n)
{
  Matrix<ll> K(3, 3);
  ll p = 1;
  for (auto i = 0; i < k; i++)
  {
    p *= 10LL;
  }
  K = {p % Matrix<ll>::MOD, 1, 0, 0, 1, B, 0, 0, 1};
  return K.power(n);
}

ll f(ll i)
{
  return A + B * i;
}

int main()
{
  cin >> L >> A >> B >> M;
  Matrix<ll>::MOD = M;
  for (auto i = 1; i <= 18; i++)
  {
    ll ok = upper[i - 1];
    ll ng = L;
    if ((int)to_string(f(ok)).size() != i)
    {
      upper[i] = ok;
      continue;
    }
    while (abs(ok - ng) > 1)
    {
      ll t = (ok + ng) / 2;
      if ((int)to_string(f(t)).size() == i)
      {
        ok = t;
      }
      else
      {
        ng = t;
      }
    }
    upper[i] = ng;
  }
  Matrix<ll> v(3, 1);
  v = {0, A, 1};
  for (auto i = 1; i <= 18; i++)
  {
    ll x = upper[i] - upper[i - 1];
    if (x == 0)
    {
      continue;
    }
#if DEBUG == 1
    cerr << "i = " << i << ", upper[" << i << "] = " << upper[i] << endl;
    cerr << "f(" << upper[i] - 1 << ") = " << f(upper[i] - 1) << endl;
    cerr << "f(" << upper[i] << ") = " << f(upper[i]) << endl;
#endif
    v = choose(i, x) * v;
#if DEBUG == 1
    cerr << v[0][0] << " " << v[1][0] << " " << v[2][0] << endl;
#endif
  }
  cout << v[0][0] << endl;
}