#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 1/15/2020, 8:11:07 PM
 * Powered by Visual Studio Code
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// ----- boost -----
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>
// ----- using directives and manipulations -----
using namespace std;
using boost::rational;
using boost::multiprecision::cpp_int;
using ll = long long;
// ----- constexpr for Mint and Combination -----
constexpr ll MOD{1000000007LL};
// constexpr ll MOD{998244353LL}; // be careful
constexpr ll MAX_SIZE{3000010LL};
// constexpr ll MAX_SIZE{30000010LL}; // if 10^7 is needed
// ----- ch_max and ch_min -----
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
// ----- Mint -----
template <ll MOD = MOD>
class Mint
{
public:
  ll x;
  Mint() : x{0LL} {}
  Mint(ll x) : x{(x % MOD + MOD) % MOD} {}
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
  bool operator<=(const Mint &a) const { return x <= a.x; }
  bool operator>(const Mint &a) const { return x > a.x; }
  bool operator>=(const Mint &a) const { return x >= a.x; }
  bool operator==(const Mint &a) const { return x == a.x; }
  bool operator!=(const Mint &a) const { return !(*this == a); }
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
// ----- Combination -----
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
// ----- for C++14 -----
using mint = Mint<MOD>;
using combination = Combination<MOD, MAX_SIZE>;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
// ----- frequently used constexpr -----
// constexpr double epsilon{1e-10};
// constexpr ll infty{1000000000000000LL};
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
// ----- Yes() and No() -----
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
// ----- main() -----

using I = int16_t;

enum class Color : I
{
  None = 0,
  Black = 1,
  White = 2,
  Mixed = 3,
  Invalid
};
ostream &operator<<(ostream &os, Color C)
{
  return os << static_cast<I>(C);
}
Color operator|(Color L, Color R)
{
  return static_cast<Color>(static_cast<I>(L) | static_cast<I>(R));
}

constexpr I C{186};
constexpr I X{17};

// The memory limit is strict.
I dp1[X][C][C][C];
I dp2[X][C][C][C];

I H, W;
Color A[C][C];

vector<Color> press_X(int X0, int X1)
{
  assert(X0 < X1);
  vector<Color> V(W, Color::None);
  for (auto j = 0; j < W; j++)
  {
    for (auto i = X0; i < X1; i++)
    {
      V[j] = V[j] | A[i][j];
    }
  }
  return V;
}

vector<Color> press_Y(int Y0, int Y1)
{
  assert(Y0 < Y1);
  vector<Color> V(H, Color::None);
  for (auto i = 0; i < H; i++)
  {
    for (auto j = Y0; j < Y1; j++)
    {
      V[i] = V[i] | A[i][j];
    }
  }
  return V;
}

void zero_setup()
{
  // dp1
  for (auto X0 = 0; X0 <= H; X0++)
  {
    for (auto X1 = X0; X1 <= H; X1++)
    {
      if (X0 == X1)
      {
        for (auto Y0 = 0; Y0 <= W; Y0++)
        {
          dp1[0][X0][X1][Y0] = W;
        }
      }
      else
      {
        auto V{press_X(X0, X1)};
        auto Y1{W};
        auto now{Color::None};
        dp1[0][X0][X1][W] = W;
        for (auto Y0 = W - 1; Y0 >= 0; --Y0)
        {
          auto next{now | V[Y0]};
          if (next != Color::Mixed)
          {
            now = next;
          }
          else if (V[Y0] == Color::Black || V[Y0] == Color::White)
          {
            Y1 = Y0 + 1;
            now = V[Y0];
          }
          else
          {
            Y1 = Y0;
            now = Color::None;
          }
          dp1[0][X0][X1][Y0] = Y1;
        }
      }
    }
  }
  // dp2
  for (auto Y0 = 0; Y0 <= W; Y0++)
  {
    for (auto Y1 = Y0; Y1 <= W; Y1++)
    {
      if (Y0 == Y1)
      {
        for (auto X0 = 0; X0 <= H; X0++)
        {
          dp2[0][Y0][Y1][X0] = H;
        }
      }
      else
      {
        auto V{press_Y(Y0, Y1)};
        auto X1{H};
        auto now{Color::None};
        dp2[0][Y0][Y1][H] = H;
        for (auto X0 = H - 1; X0 >= 0; --X0)
        {
          auto next{now | V[X0]};
          if (next != Color::Mixed)
          {
            now = next;
          }
          else if (V[X0] == Color::Black || V[X0] == Color::White)
          {
            X1 = X0 + 1;
            now = V[X0];
          }
          else
          {
            X1 = X0;
            now = Color::None;
          }
          dp2[0][Y0][Y1][X0] = X1;
        }
      }
    }
  }
}

void fill_dp1(int k)
{
  for (auto X0 = 0; X0 <= H; ++X0)
  {
    for (auto X1 = X0; X1 <= H; ++X1)
    {
      I Y0{W}, Y1{W};
      while (Y0 >= 0)
      {
        assert(Y0 <= Y1);
        if (dp1[k - 1][X0][X1][dp1[k - 1][X0][X1][Y0]] >= Y1 || dp2[k - 1][Y0][Y1][dp2[k - 1][Y0][Y1][X0]] >= X1)
        {
          dp1[k][X0][X1][Y0] = Y1;
#if DEBUG == 1
          cerr << "dp1[" << k << "][" << X0 << "][" << X1 << "][" << Y0 << "] = " << Y1 << endl;
#endif
          Y0--;
        }
        else
        {
          Y1--;
        }
      }
    }
  }
}

void fill_dp2(int k)
{
  for (auto Y0 = 0; Y0 <= W; ++Y0)
  {
    for (auto Y1 = Y0; Y1 <= W; ++Y1)
    {
      I X0{H}, X1{H};
      while (X0 >= 0)
      {
        assert(X0 <= X1);
        if (dp2[k - 1][Y0][Y1][dp2[k - 1][Y0][Y1][X0]] >= X1 || dp1[k - 1][X0][X1][dp1[k - 1][X0][X1][Y0]] >= Y1)
        {
          dp2[k][Y0][Y1][X0] = X1;
          X0--;
        }
        else
        {
          X1--;
        }
      }
    }
  }
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    string S;
    cin >> S;
    for (auto j = 0; j < W; j++)
    {
      if (S[j] == '.')
      {
        A[i][j] = Color::White;
      }
      else
      {
        A[i][j] = Color::Black;
      }
    }
  }
  zero_setup();
  for (auto k = 1; k <= 16; ++k)
  {
    fill_dp1(k);
    fill_dp2(k);
  }
  I ans_X{-1}, ans_Y{-1};
  for (I k = 0; k <= 16; ++k)
  {
    if (dp1[k][0][H][0] >= W)
    {
      ch_max(ans_X, k);
    }
    if (dp2[k][0][W][0] >= H)
    {
      ch_max(ans_Y, k);
    }
  }
  assert(ans_X >= 0);
  assert(ans_Y >= 0);
  assert(ans_X == ans_Y);
  cout << ans_X << endl;
}
