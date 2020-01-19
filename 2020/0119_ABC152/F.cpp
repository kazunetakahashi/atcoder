#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/1/19 21:18:43
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

struct C
{
  int u, w;
};

struct Edge
{
  int to, num;
};

int N;
vector<vector<Edge>> V;

ll power(ll x)
{
  if (x == 0)
  {
    return 1;
  }
  if (x % 2 == 0)
  {
    ll h{power(x / 2)};
    return h * h;
  }
  return 2 * power(x - 1);
}

vector<int> count(C c)
{
  int u{c.u};
  int w{c.w};
  vector<int> parent(N, -1);
  stack<int> S;
  S.push(u);
  while (!S.empty())
  {
    int now{S.top()};
    S.pop();
    for (auto x : V[now])
    {
      if (x.to != parent[now])
      {
        parent[x.to] = now;
        S.push(x.to);
      }
    }
  }
  vector<int> res;
  int temp{w};
  while (temp != -1)
  {
    for (auto x : V[temp])
    {
      if (x.to == parent[temp])
      {
        res.push_back(x.num);
        break;
      }
    }
    temp = parent[temp];
  }
  return res;
}

int main()
{
  cin >> N;
  V.resize(N);
  for (auto i = 0; i < N - 1; ++i)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    V[a].push_back((Edge){b, i});
    V[b].push_back((Edge){a, i});
  }
  int M;
  cin >> M;
  vector<C> W(M);
  for (auto i = 0; i < M; ++i)
  {
    cin >> W[i].u >> W[i].w;
    W[i].u--;
    W[i].w--;
  }
  vector<vector<int>> visited(M);
  for (auto i = 0; i < M; ++i)
  {
    visited[i] = count(W[i]);
#if DEBUG == 1
    cerr << "visited[" << i << "] = ";
    for (auto x : visited[i])
    {
      cerr << x << ", ";
    }
    cerr << endl;
#endif
  }
  ll ans{0};
  for (auto k = 0; k < (1 << M); ++k)
  {
    int cnt{0};
    for (auto i = 0; i < M; ++i)
    {
      cnt += (k >> i) & 1;
    }
    ll K{cnt % 2 ? -1 : 1};
    vector<bool> white(N - 1, false);
    for (auto i = 0; i < M; ++i)
    {
      if ((k >> i) & 1)
      {
        for (auto x : visited[i])
        {
          white[x] = true;
        }
      }
    }
    int free{0};
    for (auto i = 0; i < N - 1; ++i)
    {
      if (!white[i])
      {
        ++free;
      }
    }
#if DEBUG == 1
    cerr << "k = " << k << ", free = " << free << endl;
#endif
    ans += K * power(free);
  }
  cout << ans << endl;
}
