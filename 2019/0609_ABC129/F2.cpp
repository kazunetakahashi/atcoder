#define DEBUG 1

/**
 * File    : F2.cpp
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

#define mattype long long

#include <valarray>
#include <random>
using namespace std;

// 行列
struct matrix
{
  int row, col;
  valarray<mattype> a;
  matrix(int N, int M)
  { // matrix A(N, M); で初期化できる。
    a = valarray<mattype>(N * M);
    row = N;
    col = M;
  }
  bool operator<(const matrix &right) const
  { // 使わないけどtupleに必要
    if (row != right.row)
    {
      return row < right.row;
    }
    if (col != right.col)
    {
      return col < right.col;
    }
    for (auto i = 0; i < row * col; i++)
    {
      if (a[i] != right.a[i])
      {
        return a[i] < right.a[i];
      }
    }
    return false;
  }
  bool operator>(const matrix &right) const
  { // 使わないけどtupleに必要
    if (row != right.row)
    {
      return row > right.row;
    }
    if (col != right.col)
    {
      return col > right.col;
    }
    for (auto i = 0; i < row * col; i++)
    {
      if (a[i] != right.a[i])
      {
        return a[i] > right.a[i];
      }
    }
    return false;
  }
  bool operator==(const matrix &right) const
  {
    if (row != right.row)
      return false;
    if (col != right.col)
      return false;
    for (auto i = 0; i < row * col; i++)
    {
      if (a[i] != right.a[i])
      {
        return false;
      }
    }
    return true;
  }
  string to_s() const
  {
    string res = "";
    for (auto i = 0; i < row; i++)
    {
      for (auto j = 0; j < col; j++)
      {
        res += to_string(a[i * col + j]);
        if (j != col - 1)
          res += " ";
      }
      if (i != row - 1)
        res += "\n";
    }
    return res;
  }
  void input()
  { // 大抵行列表示で入力されるからこれで事足りるでしょう。
    for (auto i = 0; i < row * col; i++)
    {
      cin >> a[i];
    }
  }
};

ostream &operator<<(ostream &s, const matrix A)
{ // cout << A << endl; で苦もなく表示。
  return s << A.to_s();
}

matrix multiply(matrix A, matrix B)
{ // AB を出力
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i = 0; i < C.row; i++)
  {
    for (auto j = 0; j < C.col; j++)
    {
      C.a[i * C.col + j] = ((valarray<mattype>)A.a[slice(i * A.col, N, 1)] *
                            (valarray<mattype>)B.a[slice(j, N, B.col)])
                               .sum();
    }
  }
  return C;
}

matrix inverse(matrix A, matrix B)
{ // A^{-1} B を出力
  assert(A.row == A.col);
  assert(A.col == B.row);
  int N = A.row;
  int M = B.col;
  for (auto i = 0; i < N; i++)
  {
    mattype taikaku = A.a[i * N + i];
    for (auto k = 0; k < N; k++)
    {
      if (i == k)
        continue;
      mattype keisu = A.a[k * N + i] / taikaku;
      // A.a[k*N+i] = 0;
      for (auto j = i + 1; j < N; j++)
      {
        A.a[k * N + j] = A.a[k * N + j] - keisu * A.a[i * N + j];
      }
      for (auto j = 0; j < M; j++)
      {
        B.a[k * M + j] = B.a[k * M + j] - keisu * B.a[i * M + j];
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    mattype taikaku = A.a[i * N + i];
    for (auto j = 0; j < M; j++)
    {
      B.a[i * M + j] = B.a[i * M + j] / taikaku;
    }
  }
  return B;
}

matrix transposed(matrix A)
{ // 転置
  matrix B = matrix(A.col, A.row);
  for (auto i = 0; i < B.row; i++)
  {
    for (auto j = 0; j < B.col; j++)
    {
      B.a[i * B.col + j] = A.a[j * A.col + i];
    }
  }
  return B;
}

bool AB_is_equal_to_C(matrix A, matrix B, matrix C, int times)
{ // AB = C かどうかを判定。timesには回数を指定。
  // N * M が 10^6 くらいなら、times = 10 で 1秒単位がかかるようになるから要注意。
  // でも 10 はほしいところである。
  assert(A.col == B.row);
  assert(A.row == C.row);
  assert(B.col == C.col);
  random_device rd;
  mt19937 mt(rd());
  matrix p = matrix(B.col, 1);
  for (auto i = 0; i < times; i++)
  {
    for (auto j = 0; j < B.col; j++)
    {
      p.a[j] = mt() % 10000;
    }
    if (multiply(A, multiply(B, p)) == multiply(C, p))
    {
      /*
      cerr << "ABp is following:" << endl;
      cerr << multiply(A, multiply(B, p)) << endl;
      cerr << "Cp is following:" << endl;
      cerr << multiply(C, p) << endl;
      */
      continue;
    }
    else
    {
      return false;
    }
  }
  return true;
}

// 此処から先は、modを取るパターン。

mattype MOD = 1000;

matrix mod_multiply(matrix A, matrix B)
{
  assert(A.col == B.row);
  int N = A.col;
  matrix C(A.row, B.col);
  for (auto i = 0; i < C.row; i++)
  {
    for (auto j = 0; j < C.col; j++)
    {
      C.a[i * C.col + j] = ((valarray<mattype>)A.a[slice(i * A.col, N, 1)] *
                            (valarray<mattype>)B.a[slice(j, N, B.col)])
                               .sum() %
                           MOD;
    }
  }
  return C;
}

matrix mod_pow(matrix A, mattype n)
{ // n \geq 1
  if (n % 2 == 0)
  {
    matrix B = mod_pow(A, n / 2);
    return mod_multiply(B, B);
  }
  else if (n == 1)
  {
    return A;
  }
  else
  {
    return mod_multiply(A, mod_pow(A, n - 1));
  }
}

// 此処から先 main

ll L, A, B;
ll upper[100];

matrix choose(ll k, ll n)
{
  matrix K(3, 3);
  ll p = 1;
  for (auto i = 0; i < k; i++)
  {
    p *= 10LL;
  }
  K.a = {p % MOD, 1, 0, 0, 1, B, 0, 0, 1};
  return mod_pow(K, n);
}

ll f(ll i)
{
  return A + B * i;
}

int main()
{
  cin >> L >> A >> B >> MOD;
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
  matrix v(3, 1);
  v.a = {0, A, 1};
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
    v = mod_multiply(choose(i, x), v);
#if DEBUG == 1
    cerr << v.a[0] << " " << v.a[1] << " " << v.a[2] << endl;
#endif
  }
  cout << v.a[0] << endl;
}
