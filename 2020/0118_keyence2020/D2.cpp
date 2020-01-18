#define DEBUG 1
/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/1/19 1:54:23
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
constexpr int infty{100000000};
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

struct Card
{
  int A, B;
};

class Solve
{
  int N;
  vector<Card> V;
  vector<vector<int>> DP;
  vector<vector<bool>> visited;
  using Info = tuple<int, int>;
  queue<Info> Q;

public:
  Solve(int N, vector<Card> const &V) : N{N}, V{V}, DP((1 << N), vector<int>(N + 1, infty)), visited((1 << N), vector<bool>(N + 1, false))
  {
    DP[0][N] = 0;
    Q.push(Info(0, N));
  }

  int answer()
  {
    if (N == 1)
    {
      return 0;
    }
    make_DP();
    int ans{infty};
    for (auto i = 0; i < N; ++i)
    {
      ch_min(ans, DP[(1 << N)][i]);
    }
    return ans;
  }

private:
  void make_DP()
  {
    while (!Q.empty())
    {
      int mask, index;
      tie(mask, index) = Q.front();
      Q.pop();
      if (!visited[mask][index])
      {
        visited[mask][index] = true;
        int cnt{count_one(mask)};
        for (auto i = 0; i < N; ++i)
        {
          if (((mask >> i) & 1) == 0)
          {
            int n_mask{mask | 1 << i};
            // DP[n_mask][i] <- DP[mask][index]
            if (index == N)
            {
              ch_min(DP[n_mask][i], DP[mask][index]);
            }
            else
            {
              int now_number{cnt % 2 == 0 ? V[index].A : V[index].B};
              int next_number{(cnt + 1) % 2 == 0 ? V[i].A : V[i].B};
              if (now_number <= next_number)
              {
                int dist{0};
                for (auto j = i; j < N; ++j)
                {
                  dist += (mask >> j & 1);
                }
                ch_min(DP[n_mask][i], DP[mask][index] + dist);
                Q.push(Info(n_mask, i));
              }
            }
          }
        }
      }
    }
  }

  static int count_one(int mask)
  {
    int res{0};
    while (mask > 0)
    {
      res += mask & 1;
      mask >>= 1;
    }
    return res;
  }
};

int main()
{
  int N;
  cin >> N;
  vector<Card> V(N);
  for (auto i = 0; i < N; ++i)
  {
    cin >> V[i].A >> V[i].B;
  }
  for (auto i = 1; i < N; i += 2)
  {
    swap(V[i].A, V[i].B);
  }
  Solve solve(N, V);
  int ans{solve.answer()};
  if (ans == infty)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << ans << endl;
  }
}
