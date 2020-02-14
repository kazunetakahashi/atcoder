#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2/14/2020, 3:31:58 PM
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

using Edge = tuple<int, int>;

class Solve
{
  int N, M;
  vector<vector<int>> V; // T
  vector<Edge> W;
  vector<vector<int>> parent; // parent[root][vertex] = parent in T
  vector<vector<int>> G;

public:
  Solve(int N, int M, vector<vector<int>> V, vector<Edge> W) : N{N}, M{M}, V{V}, W{W}, parent(N, vector<int>(N, -1)), G(N, vector<int>(N, -1))
  {
    init();
    generate_G();
    cout << answer() << endl;
  }

private:
  bool is_edge(int v, int w) { return G[v][w] == w; }

  int answer()
  {
    int ans{0};
    for (auto i = 0; i < N; ++i)
    {
      ans += dfs_count(i, i);
#if DEBUG == 1
      cerr << "dfs_count(" << i << ", " << i << ") = " << dfs_count(i, i) << endl;
#endif
    }
    return ans / 2;
  }

  int dfs_count(int root, int v, int p = -1)
  {
    int ans{0};
    if (is_edge(root, v))
    {
      ++ans;
      root = v;
    }
    for (auto x : V[v])
    {
      if (x != p)
      {
        ans += dfs_count(root, x, v);
      }
    }
    return ans;
  }

  void generate_G()
  {
    for (auto &e : W)
    {
      add_edge(get<0>(e), get<1>(e));
    }
  }

  void add_edge(int v, int w)
  {
    assert(0 <= v && v < N && 0 <= w && w < N && v != w);
    if (G[v][w] == w)
    {
      assert(G[w][v] == v);
      return;
    }
#if DEBUG == 1
    cerr << "add_edge(" << v << ", " << w << ")" << endl;
#endif
    G[v][w] = w;
    G[w][v] = v;
    auto BFS = [&](int x, int y) {
      queue<int> Q;
      Q.push(x);
      while (!Q.empty())
      {
        int src{Q.front()};
        Q.pop();
        for (auto dst : V[src])
        {
          if (dst != parent[y][src])
          {
            if (G[y][dst] == dst)
            {
              assert(G[dst][y] == y);
              add_edge(x, dst);
            }
            else
            {
              G[y][dst] = G[dst][y] = x;
              Q.push(dst);
            }
          }
        }
      }
    };
    BFS(v, w);
    BFS(w, v);
  }

  void init()
  {
    for (auto i = 0; i < N; ++i)
    {
      dfs_init(i, i);
    }
  }

  void dfs_init(int r, int v, int p = -1)
  {
    parent[r][v] = p;
    for (auto x : V[v])
    {
      if (x != p)
      {
        dfs_init(r, x, v);
      }
    }
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> V(N);
  for (auto i = 0; i < N - 1; ++i)
  {
    int A, B;
    cin >> A >> B;
    --A;
    --B;
    V[A].push_back(B);
    V[B].push_back(A);
  }
  vector<Edge> W(M);
  for (auto i = 0; i < M; ++i)
  {
    cin >> get<0>(W[i]) >> get<1>(W[i]);
    get<0>(W[i])--;
    get<1>(W[i])--;
  }
  Solve solve(N, M, V, W);
}
