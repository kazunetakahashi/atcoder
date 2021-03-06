#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 6/15/2020, 4:47:24 PM
 * Powered by Visual Studio Code
 */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
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
using ld = long double;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
// ----- constexpr for Mint and Combination -----
constexpr ll MOD{1'000'000'007LL};
// constexpr ll MOD{998'244'353LL}; // be careful
constexpr ll MAX_SIZE{3'000'010LL};
// constexpr ll MAX_SIZE{30'000'010LL}; // if 10^7 is needed
// ----- ch_max and ch_min -----
template <typename T>
bool ch_max(T &left, T right)
{
  if (left < right)
  {
    left = right;
    return true;
  }
  return false;
}
template <typename T>
bool ch_min(T &left, T right)
{
  if (left > right)
  {
    left = right;
    return true;
  }
  return false;
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
  Mint &operator+=(Mint const &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  Mint &operator-=(Mint const &a) { return *this += -a; }
  Mint &operator++() { return *this += 1; }
  Mint operator++(int)
  {
    Mint tmp{*this};
    ++*this;
    return tmp;
  }
  Mint &operator--() { return *this -= 1; }
  Mint operator--(int)
  {
    Mint tmp{*this};
    --*this;
    return tmp;
  }
  Mint &operator*=(Mint const &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  Mint &operator/=(Mint const &a)
  {
    Mint b{a};
    return *this *= b.power(MOD - 2);
  }
  Mint operator+(Mint const &a) const { return Mint(*this) += a; }
  Mint operator-(Mint const &a) const { return Mint(*this) -= a; }
  Mint operator*(Mint const &a) const { return Mint(*this) *= a; }
  Mint operator/(Mint const &a) const { return Mint(*this) /= a; }
  bool operator<(Mint const &a) const { return x < a.x; }
  bool operator<=(Mint const &a) const { return x <= a.x; }
  bool operator>(Mint const &a) const { return x > a.x; }
  bool operator>=(Mint const &a) const { return x >= a.x; }
  bool operator==(Mint const &a) const { return x == a.x; }
  bool operator!=(Mint const &a) const { return !(*this == a); }
  Mint power(ll N) const
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
Mint<MOD> operator+(ll lhs, Mint<MOD> const &rhs) { return rhs + lhs; }
template <ll MOD>
Mint<MOD> operator-(ll lhs, Mint<MOD> const &rhs) { return -rhs + lhs; }
template <ll MOD>
Mint<MOD> operator*(ll lhs, Mint<MOD> const &rhs) { return rhs * lhs; }
template <ll MOD>
Mint<MOD> operator/(ll lhs, Mint<MOD> const &rhs) { return Mint<MOD>{lhs} / rhs; }
template <ll MOD>
istream &operator>>(istream &stream, Mint<MOD> &a) { return stream >> a.x; }
template <ll MOD>
ostream &operator<<(ostream &stream, Mint<MOD> const &a) { return stream << a.x; }
// ----- Combination -----
template <ll MOD = MOD, ll MAX_SIZE = MAX_SIZE>
class Combination
{
public:
  vector<Mint<MOD>> inv, fact, factinv;
  Combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i{2LL}; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[MOD % i]) * (MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i{1LL}; i < MAX_SIZE; i++)
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
template <typename T>
T gcd(T x, T y) { return y ? gcd(y, x % y) : x; }
template <typename T>
T lcm(T x, T y) { return x / gcd(x, y) * y; }
// ----- for C++17 -----
template <typename T>
int popcount(T x) // C++20
{
  int ans{0};
  while (x != 0)
  {
    ans += x & 1;
    x >>= 1;
  }
  return ans;
}
// ----- Infty -----
template <typename T>
constexpr T Infty() { return numeric_limits<T>::max(); }
template <typename T>
constexpr T mInfty() { return numeric_limits<T>::min(); }
// ----- frequently used constexpr -----
// constexpr double epsilon{1e-10};
// constexpr ll infty{1'000'000'000'000'010LL}; // or
// constexpr int infty{1'000'000'010};
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
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

// ----- 2D, 3D, 4D vectors -----
// Referring to ymatsux-san's source code: https://atcoder.jp/contests/abc138/submissions/7018300

template <typename T>
vector<vector<T>> Make2DVector(size_t d0, size_t d1, T v = T{})
{
  return vector<vector<T>>(d0, vector<T>(d1, v));
}

template <typename T>
vector<vector<vector<T>>> Make3DVector(size_t d0, size_t d1, size_t d2, T v = T{})
{
  return vector<vector<vector<T>>>(d0, Make2DVector(d1, d2, v));
}

template <typename T>
vector<vector<vector<vector<T>>>> Make4DVector(size_t d0, size_t d1, size_t d2, size_t d3, T v = T{})
{
  return vector<vector<vector<vector<T>>>>(d0, Make3DVector(d1, d2, d3, v));
}

// ----- Solve -----

using Info = tuple<int, int, int, int, int>; // score, mini_score, x, y, k
using Score = tuple<int, int>;

constexpr Score Invalid{-1, 0};
constexpr Score Empty{Infty<int>(), 0};

class Solve
{
  int H, W, K;
  vector<vector<vector<Score>>> V;
  int sx, sy, gx, gy;

public:
  Solve(int H, int W) : H{H}, W{W}, V{Make3DVector(H, W, 4, Invalid)}
  {
    cin >> K;
    cin >> sx >> sy >> gx >> gy;
    --sx;
    --sy;
    --gx;
    --gy;
    for (auto i{0}; i < H; ++i)
    {
      for (auto j{0}; j < W; ++j)
      {
        char c;
        cin >> c;
        for (auto k{0}; k < 4; ++k)
        {
          if (c == '.')
          {
            V[i][j][k] = Empty;
          }
          else
          {
            V[i][j][k] = Invalid;
          }
        }
      }
    }
  }

  void flush()
  {
    min_heap<Info> H;
    for (auto k{0}; k < 4; ++k)
    {
      H.push(Info{0, 0, sx, sy, k});
    }
    while (!H.empty())
    {
      auto [score, mini_score, src_x, src_y, src_k] = H.top();
      H.pop();
      if (V[src_x][src_y][src_k] != Empty)
      {
        continue;
      }
      V[src_x][src_y][src_k] = Score{score, mini_score};
      for (auto dst_k{0}; dst_k < 4; ++dst_k)
      {
        if (src_k == dst_k)
        {
          continue;
        }
        auto dst_x{src_x};
        auto dst_y{src_y};
        if (valid(dst_x, dst_y) && V[dst_x][dst_y][dst_k] == Empty)
        {
          if (mini_score == 0)
          {
            H.push(Info{score, 0, dst_x, dst_y, dst_k});
          }
          else
          {
            H.push(Info{score + 1, 0, dst_x, dst_y, dst_k});
          }
        }
      }
      auto dst_x{src_x + dx[src_k]};
      auto dst_y{src_y + dy[src_k]};
      auto dst_k{src_k};
      if (valid(dst_x, dst_y) && V[dst_x][dst_y][dst_k] == Empty)
      {
        if (mini_score < K - 1)
        {
          H.push(Info{score, mini_score + 1, dst_x, dst_y, dst_k});
        }
        else
        {
          H.push(Info{score + 1, 0, dst_x, dst_y, dst_k});
        }
      }
    }
    int ans{Infty<int>()};
    for (auto k{0}; k < 4; ++k)
    {
      auto [score, mini_score] = V[gx][gy][k];
      if (score == Infty<int>())
      {
        continue;
      }
      else if (mini_score > 0)
      {
        ch_min(ans, score + 1);
      }
      else
      {
        ch_min(ans, score);
      }
    }
    if (ans == Infty<int>())
    {
      cout << -1 << endl;
    }
    else
    {
      cout << ans << endl;
    }
  }

private:
  bool valid(int x, int y)
  {
    return 0 <= x && x < H && 0 <= y && y < W && V[x][y][0] != Invalid;
  }
};

// ----- main() -----

int main()
{
  int H, W;
  cin >> H >> W;
  Solve solve(H, W);
  solve.flush();
}
