#define DEBUG 1
/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 12/11/2019, 4:20:39 PM
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
#include <boost/optional.hpp> // for C++14
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

struct Element
{
  int ind;
  ll left, right;
  boost::optional<int> value; // for C++14
  bool operator<(Element const &rhs) const
  {
    return ind < rhs.ind;
  }
  bool operator==(Element const &rhs) const
  {
    return ind == rhs.ind;
  }
};

Element make_element(int ind)
{
  return Element{ind, 0, 0, boost::none};
}

class Solve
{
  int N, L;
  set<Element> A;
  map<int, vector<int>> indexes; // value -> inds

public:
  Solve(int N, int L, vector<int> input) : N{N}, L{L}
  {
    for (auto i = 0; i < N; i++)
    {
      A.insert({i, 1, 1, input[i]});
      indexes[input[i]];
      indexes[input[i]].push_back(i);
    }
  }

  ll count()
  {
    ll ans{N};
    while (!indexes.empty())
    {
      vector<Element> tmp;
      auto &vec{indexes.begin()->second};
      sort(vec.begin(), vec.end());
      int min_value{indexes.begin()->first};
#if DEBUG == 1
      cerr << "min_value = " << min_value << endl;
#endif
      for (auto ind : indexes[min_value])
      {
        auto it{A.find(make_element(ind))};
#if DEBUG == 1
        cerr << "A[" << it->ind << "] = (" << (it->value ? to_string(*it->value) : "n") << ", " << it->right << ", " << it->left << ")" << endl;
#endif
        assert(it != A.end());
        tmp.push_back(*it);
        it = A.erase(it);
        if (it == A.end() || it->value != min_value)
        {
          update(ans, tmp);
        }
      }
      if (!tmp.empty())
      {
        update(ans, tmp);
      }
      indexes.erase(indexes.begin());
    }
    return ans;
  }

private:
  void
  update(ll &ans, vector<Element> &tmp)
  {
    ans += calc(tmp);
    tmp = press(tmp);
    ans -= calc(tmp);
    for (auto e : tmp)
    {
      A.insert(e);
    }
    tmp.clear();
#if DEBUG == 1
    cerr << "updated." << endl;
#endif
  }

  ll calc(vector<Element> const &X)
  {
    ll ans{0};
    ll sum_right{0};
    int S{static_cast<int>(X.size())};
    for (auto i = L - 1; i < S; i++)
    {
      sum_right += X[i].right;
    }
    for (auto i = 0; i < S - L + 1; i++)
    {
      ans += X[i].left * sum_right;
      sum_right -= X[i + L - 1].right;
    }
    assert(sum_right == 0);
    return ans;
  }

  vector<Element> press(vector<Element> const &V)
  {
    assert(!V.empty());
    int S{static_cast<int>(V.size())};
    if (S < L)
    {
      return {{V[0].ind, 0, 0, boost::none}};
    }
    int index{V[0].ind};
    int K{*V[0].value + 1};
    vector<Element> ans(S / L);
    for (auto &e : ans)
    {
      e.ind = index;
      e.value = K;
      indexes[K];
      indexes[K].push_back(index);
      ++index;
    }
    for (auto i = L - 1; i < S; i++)
    {
      ans[(i - L + 1) / L].right += V[i].right;
    }
    int mod{S % L};
    for (auto i = 0; i < S - L + 1; i++)
    {
      ans[(i + L - mod - 1) / L].left += V[i].left;
    }
    return ans;
  }
};

int main()
{
  int N, L;
  cin >> N >> L;
  vector<int> A(N);
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  Solve solve(N, L, A);
  cout << solve.count() << endl;
}
