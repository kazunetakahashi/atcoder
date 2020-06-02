#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 6/2/2020, 12:34:10 PM
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

struct Edge
{
  bool valid;
  int src, dst;
  ll cost;

  Edge() {}
  Edge(int src, int dst, ll cost) : valid{true}, src{src}, dst{dst}, cost{cost} {}

  void added_edge(vector<vector<int>> &V)
  {
    V[src].push_back(dst);
  }

  void added_rev(vector<vector<int>> &V)
  {
    V[dst].push_back(src);
  }
};

class Solve
{
  int N, M;
  ll P;
  vector<Edge> E;

public:
  Solve(int N, int M) : N{N}, M{M}, E(M)
  {
    cin >> P;
    for (auto i = 0; i < M; ++i)
    {
      int A, B;
      ll C;
      cin >> A >> B >> C;
      --A;
      --B;
      E[i] = Edge(A, B, P - C);
    }
  }

  void flush()
  {
#if DEBUG == 1
    cerr << "Here" << endl;
#endif
    determine_validness();
#if DEBUG == 1
    cerr << "Here" << endl;
#endif
    cout << bf() << endl;
  }

private:
  ll bf()
  {
    vector<ll> D(N, infty);
    D[0] = 0;
    bool updated{false};
    for (auto t = 0; t < N + 2; ++t)
    {
      for (auto const &e : E)
      {
        auto tmp{D[e.src] + e.cost};
        if (D[e.dst] > tmp)
        {
          D[e.dst] = tmp;
          updated = true;
        }
      }
      if (!updated)
      {
        return -D[N - 1];
      }
      if (t == N + 1)
      {
        return -1;
      }
    }
    assert(false);
    return -2;
  }

  void determine_validness()
  {
    auto table{valid_vertexes()};
    for (auto &e : E)
    {
      if (!(table[e.src] && table[e.dst]))
      {
        e.valid = false;
      }
    }
  }

  vector<bool> valid_vertexes()
  {
    vector<vector<int>> V(N);
    for (auto i = 0; i < M; ++i)
    {
      E[i].added_edge(V);
    }
    vector<bool> X(N, false);
    dfs(V, X, 0);
    vector<vector<int>> W(N);
    for (auto i = 0; i < M; ++i)
    {
      E[i].added_rev(W);
    }
    vector<bool> Y(N, false);
    dfs(V, Y, N - 1);
    vector<bool> res(N, false);
    for (auto i = 0; i < N; ++i)
    {
      res[i] = X[i] && Y[i];
    }
    return res;
  }

  void dfs(vector<vector<int>> const &V, vector<bool> &visited, int src, int parent = -1)
  {
    visited[src] = true;
    for (auto dst : V[src])
    {
      if (dst != parent && !visited[dst])
      {
        dfs(V, visited, dst, src);
      }
    }
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  Solve solve(N, M);
  solve.flush();
}
