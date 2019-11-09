#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 11/10/2019, 3:15:39 AM
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
constexpr ll MOD{1000000007LL};
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
  cout << "-1" << endl;
  exit(0);
}

vector<vector<ll>> best_solution_odd(ll N);
vector<vector<ll>> best_solution_even(ll N);

vector<vector<ll>> best_solution(ll N)
{
  vector<vector<ll>> V;
  if (N % 2 == 0)
  {
    V = best_solution_even(N);
  }
  else
  {
    V = best_solution_odd(N);
  }
  for (auto i = 0; i < N; i++)
  {
    assert(static_cast<int>(V[i].size()) == 2);
  }
#if DEBUG == 1
  for (auto i = 0; i < N; i++)
  {
    cerr << V[i][0] << " + " << V[i][1] << " = " << V[i][0] + V[i][1] << endl;
  }
#endif
  return V;
}

vector<vector<ll>> best_solution_odd(ll N)
{
  vector<vector<ll>> V(N);
  ll M{(N - 1) / 2};
  for (auto i = 0LL; i < M; i++)
  {
    V[(i * 2) % N].push_back(i);
    V[(i * 2) % N].push_back(3 * M + 1 + i);
    V[(i * 2) % N + 1].push_back(M + 1 + i);
    V[(i * 2) % N + 1].push_back(2 * M + 1 + i);
  }
  V[N - 1].push_back(M);
  V[N - 1].push_back(2 * M + N);
  return V;
}

vector<vector<ll>> best_solution_even(ll N)
{
  vector<vector<ll>> V(N);
  ll M{N / 2};
  for (auto i = 0LL; i < M; i++)
  {
    V[(i * 2) % N].push_back(i);
    V[(i * 2) % N].push_back(3 * M + i);
    V[(i * 2) % N + 1].push_back(M + i);
    V[(i * 2) % N + 1].push_back(2 * M + i);
  }
  return V;
}

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<vector<ll>> V{best_solution(N)};
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < 2; j++)
    {
      V[i][j] += K;
    }
  }
  vector<ll> C(N);
  for (auto i = 0; i < N; i++)
  {
    C[i] = K + 2 * N + i;
  }
  for (auto i = 0; i < N; i++)
  {
    if (V[i][0] + V[i][1] > C[i])
    {
      No();
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cout << V[i][0] << " " << V[i][1] << " " << C[i] << endl;
  }
}