#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2/6/2020, 1:50:46 PM
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
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
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
  Mint &operator++() { return *this += 1; }
  Mint &operator++(int)
  {
    Mint tmp{*this};
    ++*this;
    return tmp;
  }
  Mint &operator--() { return *this -= 1; }
  Mint &operator--(int)
  {
    Mint tmp{*this};
    --*this;
    return tmp;
  }
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
  vector<double> alpha, beta, S, T;
  double total;

public:
  Solve(int N, vector<vector<int>> const &V) : N{N}, V(V), alpha(N, 0.0), beta(N, 0.0), S(N, 0.0), T(N, 0.0)
  {
    calc_alpha();
    calc_beta();
    calc_S();
    calc_T();
    total = S[N - 1];
#if DEBUG == 1
    cerr << fixed << setprecision(4);
    for (auto i = 0; i < N; ++i)
    {
      cerr << "alpha[" << i << "] = " << alpha[i] << endl;
    }
    for (auto i = 0; i < N; ++i)
    {
      cerr << "beta[" << i << "] = " << beta[i] << endl;
    }
    for (auto i = 0; i < N; ++i)
    {
      cerr << "S[" << i << "] = " << S[i] << endl;
    }
    for (auto i = 0; i < N; ++i)
    {
      cerr << "T[" << i << "] = " << T[i] << endl;
    }
#endif
  }

  void flush()
  {
    double ans{0.0};
    for (auto i = 0; i < N; ++i)
    {
      if (V[i].size() <= 1)
      {
        continue;
      }
      double Delta{0.0};
      double d{delta(i)};
      for (auto j : V[i])
      {
        Delta += delta(i, j, d);
      }
      d = delta_zero(i);
      for (auto j : V[i])
      {
        ch_min(ans, Delta + delta(i, j, d));
      }
    }
    cout << fixed << setprecision(10) << ans + total << endl;
  }

private:
  double prob(int i)
  {
    assert(!V[i].empty());
    return 1.0 / V[i].size();
  }

  double delta(int i)
  {
    assert(V[i].size() > 1);
    return 1.0 / (V[i].size() - 1) - 1.0 / V[i].size();
  }

  double delta_zero(int i)
  {
    assert(V[i].size() > 1);
    return -1.0 / (V[i].size() - 1);
  }

  double delta(int u, int v, double d)
  {
    return d * (beta[v] * S[u] + alpha[u] * T[v] + alpha[u] * beta[v]);
  }

  void calc_alpha()
  {
    alpha[0] = 1.0;
    for (auto i = 0; i < N - 2; ++i)
    {
      for (auto j : V[i])
      {
        alpha[j] += prob(i) * alpha[i];
#if DEBUG == 1
        cerr << "i = " << i << ", j = " << j << ", alpha[" << i << "] = " << alpha[i] << ", prob(" << i << ") = " << prob(i) << endl;
#endif
      }
    }
  }

  void calc_beta()
  {
    beta[N - 1] = 1.0;
    for (auto i = N - 2; i >= 0; --i)
    {
      double sum{0.0};
      for (auto j : V[i])
      {
        sum += beta[j];
      }
      beta[i] = prob(i) * sum;
    }
  }

  void calc_S()
  {
    for (auto i = 0; i < N - 2; ++i)
    {
      for (auto j : V[i])
      {
        S[j] += prob(i) * (S[i] + 1.0);
      }
    }
  }

  void calc_T()
  {
    for (auto i = N - 2; i >= 0; --i)
    {
      double sum{0.0};
      for (auto j : V[i])
      {
        sum += T[j];
      }
      T[i] = 1.0 + prob(i) * sum;
    }
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> V(N);
  for (auto i = 0; i < M; ++i)
  {
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    V[s].push_back(t);
  }
  Solve solve(N, V);
  solve.flush();
}
