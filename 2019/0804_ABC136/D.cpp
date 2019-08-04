#define DEBUG 1
/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/8/4 21:12:45
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
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using ll = long long;
class mint
{
public:
  static ll MOD;
  ll x;
  mint() : x(0) {}
  mint(ll x) : x(x % MOD) {}
  mint operator-() const { return x ? MOD - x : 0; }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  mint &operator-=(const mint &a) { return *this += -a; }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint &operator/=(const mint &a)
  {
    mint b{a};
    return *this *= b.power(MOD - 2);
  }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  mint operator/(const mint &a) const { return mint(*this) /= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
  const mint power(ll N)
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
      mint half = power(N / 2);
      return half * half;
    }
  }
};
ll mint::MOD = 1e9 + 7;
istream &operator>>(istream &stream, mint &a) { return stream >> a.x; }
ostream &operator<<(ostream &stream, const mint &a) { return stream << a.x; }
class combination
{
public:
  vector<mint> inv, fact, factinv;
  static int MAX_SIZE;
  combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i = 2; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i = 1; i < MAX_SIZE; i++)
    {
      fact[i] = mint(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }
  mint operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }
};
int combination::MAX_SIZE = 3000010;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// constexpr double epsilon = 1e-10;
// constexpr ll infty = 1000000000000000LL;
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
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

string S;
int N;
using info = tuple<int, int>; // int, ind

vector<info> make_info()
{
  bool R = true;
  int cnt = 0;
  int cng = 0;
  int sum = 0;
  vector<info> res;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'R' && !R)
    {
      res.emplace_back(cnt, cng);
      sum += cnt;
      cnt = 1;
      cng = 0;
      R = true;
    }
    else if (S[i] == 'R' && R)
    {
      ++cnt;
    }
    else if (S[i] == 'L' && !R)
    {
      ++cnt;
    }
    else
    {
      R = false;
      ++cnt;
      cng = i - sum - 1;
    }
  }
  res.emplace_back(cnt, cng);
  return res;
}

vector<int> make_ans(const vector<info> &I)
{
  vector<int> ans;
  for (auto x : I)
  {
    int l, i;
    tie(l, i) = x;
    vector<int> res(l, 0);
    int a = l / 2;
    int b = l - a;
    if (i % 2 == 0)
    {
      swap(a, b);
    }
    res[i] = a;
    res[i + 1] = b;
    ans.insert(ans.end(), res.begin(), res.end());
  }
  return ans;
}

int main()
{
  cin >> S;
  N = S.size();
  vector<info> I = make_info();
#if DEBUG == 1
  for (auto x : I)
  {
    cerr << get<0>(x) << " " << get<1>(x) << endl;
  }
#endif
  vector<int> V = make_ans(I);
  for (auto i = 0; i < N; i++)
  {
    cout << V[i];
    if (i < N - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}