#define DEBUG 1
/**
 * File    : L.cpp
 * Author  : Kazune Takahashi
 * Created : 2020/1/31 16:50:07
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
template <typename T>
T gcd(T x, T y) { return y ? gcd(y, x % y) : x; }
template <typename T>
T lcm(T x, T y) { return x / gcd(x, y) * y; }
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

char to_char(int x)
{
  return x + 'A';
}

bool query(int const &x, int const &y)
{
  cout << "? " << to_char(x) << " " << to_char(y) << endl;
  char a;
  cin >> a;
  return a == '<';
}

template <typename Iter, typename Comp>
void merge_sort(Iter begin, Iter end, Comp cmp);

template <typename Iter, typename Comp>
void merge_sort_impl(Iter begin, Iter end, Comp cmp, random_access_iterator_tag)
{
  int N{static_cast<int>(end - begin)};
  if (N <= 1)
  {
    return;
  }
  auto mid{begin + N / 2};
  merge_sort(begin, mid, cmp);
  merge_sort(mid, end, cmp);
  vector<typename Iter::value_type> temp(N);
  merge(begin, mid, mid, end, temp.begin(), cmp);
  copy(temp.begin(), temp.end(), begin);
}

template <typename Iter, typename Comp>
void merge_sort(Iter begin, Iter end, Comp cmp)
{
  merge_sort_impl(begin, end, cmp, typename std::iterator_traits<Iter>::iterator_category());
}

bool check_vector(vector<int> const &V, int x, int y)
{
  for (auto e : V)
  {
    if (e == x)
    {
      return true;
    }
    else if (e == y)
    {
      return false;
    }
  }
  assert(false);
  return true;
}

int main()
{
  int N, Q;
  cin >> N >> Q;
  vector<int> V(N);
  for (auto i = 0; i < N; ++i)
  {
    V[i] = i;
  }
  if (Q == 1000)
  {
    sort(V.begin(), V.end(), query);
    cout << "! ";
    for (auto i = 0; i < N; ++i)
    {
      cout << to_char(V[i]);
    }
    cout << endl;
  }
  else if (Q == 100)
  {
    merge_sort(V.begin(), V.end(), query);
    cout << "! ";
    for (auto i = 0; i < N; ++i)
    {
      cout << to_char(V[i]);
    }
    cout << endl;
  }
  else
  {
    vector<vector<int>> W;
    do
    {
      W.push_back(V);
    } while (next_permutation(V.begin(), V.end()));
    while (static_cast<int>(W.size()) > 1)
    {
      auto cnt{static_cast<int>(W.size())};
      int ind_x = -1, ind_y = -1;
      for (auto x = 0; x < N; ++x)
      {
        for (auto y = x + 1; y < N; ++y)
        {
          int tmp{0};
          for (auto const &v : W)
          {
            if (check_vector(v, x, y))
            {
              ++tmp;
            }
          }
          auto c_tmp{static_cast<int>(W.size()) - tmp};
          auto t{max(tmp, c_tmp)};
          if (cnt > t)
          {
            cnt = t;
            ind_x = x;
            ind_y = y;
          }
        }
      }
      assert(ind_x != -1 && ind_y != -1);
      if (!query(ind_x, ind_y))
      {
        swap(ind_x, ind_y);
      }
      vector<vector<int>> U;
      for (auto const &v : W)
      {
        if (check_vector(v, ind_x, ind_y))
        {
          U.push_back(v);
        }
      }
      swap(U, W);
    }
    auto const &v{W[0]};
    cout << "! ";
    for (auto i = 0; i < N; ++i)
    {
      cout << to_char(v[i]);
    }
    cout << endl;
  }
}
