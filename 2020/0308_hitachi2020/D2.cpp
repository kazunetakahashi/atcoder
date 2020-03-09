#define DEBUG 1
/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/3/9 17:08:58
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
constexpr ll infty{1000000000000000LL}; // or
// constexpr int infty{1'000'000'010};
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

using shop = tuple<ll, ll>;

ostream &operator<<(ostream &os, shop const &s)
{
  return os << "(" << get<0>(s) << ", " << get<1>(s) << ")";
}

class Solve
{
  static constexpr int C{32};
  int N, M, L;
  ll T;
  vector<shop> V;
  vector<shop> normal, zero;
  vector<ll> sum;
  vector<vector<ll>> dp;

public:
  Solve(int N, ll T, vector<shop> V) : N{N}, T{T}, V(V)
  {
    make_normal_zero();
    execute_dp();
    cout << calc_ans() << endl;
  }

private:
  static bool compare_normal(shop const &left, shop const &right)
  {
    return (get<0>(right) - 1) * get<1>(left) - (get<0>(left) - 1) * get<1>(right) <= 0;
  }

  static bool compare_zero(shop const &left, shop const &right)
  {
    return get<1>(left) <= get<1>(right);
  }

  ll f(int i, ll x)
  {
    return get<0>(V[i]) * x + get<1>(V[i]);
  }

  void make_normal_zero()
  {
    for (auto i = 0; i < N; ++i)
    {
      if (get<0>(V[i]) >= 2)
      {
        normal.push_back(V[i]);
      }
      else
      {
        zero.push_back(V[i]);
      }
    }
    M = normal.size();
    L = zero.size();
    sort(normal.begin(), normal.end(), compare_normal);
    sort(zero.begin(), zero.end(), compare_zero);
#if DEBUG == 1
    cerr << "normal" << endl;
    for (auto &s : normal)
    {
      cerr << s << ": " << static_cast<double>((get<0>(s) - 1)) / get<1>(s) << endl;
    }
    cerr << "zero" << endl;
    for (auto &s : zero)
    {
      cerr << s << endl;
    }
#endif
    sum = vector<ll>(L + 1, 0);
    for (auto i = 0; i < L; ++i)
    {
      sum[i + 1] = sum[i] + get<1>(zero[i]);
    }
  }

  void execute_dp()
  {
    dp = vector<vector<ll>>(M + 1, vector<ll>(C, infty));
    dp[0][0] = 0;
    for (auto i = 0; i < M; ++i)
    {
      dp[i + 1][0] = dp[i][0];
      for (auto j = 1; j < C; ++j)
      {
        dp[i + 1][j] = min(dp[i][j], f(i, dp[i][j - 1]));
      }
#if DEBUG == 1
      for (auto j = 0; j < C; ++j)
      {
        cerr << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
      }
#endif
    }
  }

  int calc_ans()
  {
    int ans{0};
    for (auto i = 0; i < C; ++i)
    {
      ll remain{T - dp[M][i]};
      if (remain < 0)
      {
        continue;
      }
      int z{static_cast<int>(upper_bound(sum.begin(), sum.end(), remain) - sum.begin()) - 1};
      ch_max(ans, z + i);
    }
    return ans;
  }
};

int main()
{
  int N;
  ll T;
  cin >> N >> T;
  vector<shop> V(N);
  for (auto i = 0; i < N; ++i)
  {
    ll a, b;
    cin >> a >> b;
    V[i] = shop(a + 1, a + b + 1);
  }
  Solve solve(N, T, V);
}
