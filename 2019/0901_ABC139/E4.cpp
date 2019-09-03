#define DEBUG 1
/**
 * File    : E4.cpp
 * Author  : Kazune Takahashi
 * Created : 2019/9/3 19:23:12
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

int make_id(int x, int y, int N)
{
  if (x > y)
  {
    swap(x, y);
  }
  return x * N + y;
}

vector<vector<int>> make_V(int N, vector<vector<int>> const &A)
{
  vector<vector<int>> V(N * N);
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N - 2; j++)
    {
      V[make_id(i, A[i][j], N)].push_back(make_id(i, A[i][j + 1], N));
    }
  }
  return V;
}

using state = tuple<int, int>;

bool dfs(int N, vector<vector<int>> const &V, vector<int> &ans, int v)
{
  if (ans[v] >= 0)
  {
    return ans[v];
  }
  stack<state> S;
  S.push(state(v, 0));
  while (!S.empty())
  {
    int v, e;
    tie(v, e) = S.top();
    S.pop();
    if (ans[v] == -1 && e == 0)
    {
      ans[v] = -2;
      S.push(state(v, 1));
      for (auto x : V[v])
      {
        dfs(N, V, ans, x);
      }
      return true;
    }
    else if (ans[v] == -2 && e == 1)
    {
      if (V[v].empty())
      {
        ans[v] = 1;
        return true;
      }
      int maxi{0};
      for (auto x : V[v])
      {
        if (ans[x] < 0)
        {
          ans[v] = -1;
          return false;
        }
        maxi = max(maxi, ans[x]);
      }
      ans[v] = maxi + 1;
      return true;
    }
    else // if (ans[v] == -2 && e == 0)
    {
      ans[v] = -1;
      return false;
    }
  }
}

int calc_ans(int N, vector<vector<int>> const &V)
{
  vector<int> ans(N * N, -1);
  int maxi{0};
  for (auto i = 0; i < N * N; i++)
  {
    if (!dfs(N, V, ans, i))
    {
      return -1;
    }
  }
  return *max_element(ans.begin(), ans.end());
}

int main()
{
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N - 1));
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N - 1; j++)
    {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  vector<vector<int>> V{make_V(N, A)};
  int ans{calc_ans(N, V)};
  cout << ans << endl;
}