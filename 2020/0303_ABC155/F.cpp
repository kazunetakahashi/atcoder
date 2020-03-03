#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 3/3/2020, 9:55:07 PM
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
// constexpr ll infty{1000000000000000LL}; // or
constexpr int infty{1'000'000'010};
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
  cout << "-1" << endl;
  exit(0);
}
// ----- main() -----

using bomb = tuple<int, int>;
using sw = tuple<int, int>;

class Solve
{
  int N, M;
  vector<bomb> V;
  vector<sw> W;
  using edge = tuple<int, int>;
  vector<vector<edge>> E;
  vector<int> F;
  vector<bool> visited;
  vector<int> ans;

public:
  Solve(int N, int M, vector<bomb> V, vector<sw> W) : N{N}, M{M}, V(V), W(W), E(N + 1), F(N + 1), visited(N + 1, false)
  {
    init();
    execute_dfs();
    flush();
  }

private:
  void init()
  {
    vector<int> X(N);
    for (auto i = 0; i < N; ++i)
    {
      X[i] = get<0>(V[i]);
    }
    for (auto i = 0; i < M; ++i)
    {
      auto start{lower_bound(X.begin(), X.end(), get<0>(W[i])) - X.begin()};
      auto finish{lower_bound(X.begin(), X.end(), get<1>(W[i])) - X.begin()};
      if (start != finish)
      {
        E[start].push_back(edge(finish, i));
        E[finish].push_back(edge(start, i));
      }
    }
    F[0] = get<1>(V[0]);
    for (auto i = 0; i < N; ++i)
    {
      F[i + 1] = get<1>(V[i]) ^ get<1>(V[i + 1]);
    }
  }

  void execute_dfs()
  {
    for (auto i = 0; i <= N; ++i)
    {
      if (!visited[i])
      {
        dfs(i);
      }
    }
  }

  void flush()
  {
    for (auto i = 0; i <= N; ++i)
    {
      if (F[i] == 1)
      {
        No();
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
      cout << *it;
      if (it + 1 != ans.end())
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }

  void dfs(int v)
  {
    visited[v] = true;
    for (auto const &e : E[v])
    {
      int w, n;
      tie(w, n) = e;
      if (!visited[w])
      {
        dfs(w);
        if (F[w] == 1)
        {
          F[w] = 0;
          F[v] = 1 - F[v];
          ans.push_back(n);
        }
      }
    }
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<bomb> V(N + 1);
  for (auto i = 0; i < N; ++i)
  {
    cin >> get<0>(V[i]) >> get<1>(V[i]);
  }
  vector<sw> W;
  for (auto i = 0; i < M; ++i)
  {
    cin >> get<0>(W[i]) >> get<1>(W[i]);
    get<1>(W[i])++;
  }
  sort(V.begin(), V.end());
  Solve solve(N, M, V, W);
}
