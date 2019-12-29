#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 12/29/2019, 9:21:44 PM
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
// ----- boost -----
#include <boost/rational.hpp>
// ----- using directives and manipulations -----
using boost::rational;
using namespace std;
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

class Solve
{
  int N;
  vector<vector<int>> V;
  vector<int> parent;
  vector<vector<int>> children;
  vector<int> cnt;
  vector<mint> tmp;
  mint ans;
  mint two;

public:
  Solve(int N, vector<vector<int>> V) : N{N}, V(V), parent(N), children(N), cnt(N), tmp(N), ans{0LL}, two{2LL}
  {
    dfs(0);
    calc(0);
    for (auto i = 0; i < N; i++)
    {
      ans += tmp[i];
    }
    ans /= two.power(N);
  }

  mint answer()
  {
    return ans;
  }

private:
  void dfs(int x, int p = -1)
  {
    parent[x] = p;
    for (auto c : V[x])
    {
      if (c != p)
      {
        children[x].push_back(c);
        dfs(c, x);
      }
    }
  }

  void calc(int x)
  {
    for (auto c : children[x])
    {
      calc(c);
    }
    vector<int> L;
    int sum{0};
    for (auto c : children[x])
    {
      L.push_back(cnt[c]);
      sum += cnt[c];
    }
    cnt[x] = sum + 1;
    L.push_back(N - cnt[x]);
    mint res{two.power(N - 1) - 1};
    for (auto e : L)
    {
      res -= (two.power(e) - 1);
    }
    tmp[x] = res;
  }
};

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> V(N);
  for (auto i = 0; i < N - 1; i++)
  {
    int A, B;
    cin >> A >> B;
    --A;
    --B;
    V[A].push_back(B);
    V[B].push_back(A);
  }
  Solve solve(N, V);
  cout << solve.answer() << endl;
}
