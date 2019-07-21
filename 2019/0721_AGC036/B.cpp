#define DEBUG 1
/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 7/21/2019, 9:18:18 PM
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
int combination::MAX_SIZE = 1e6 + 10;
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

int N;
ll K;
int A[200010];
int B[200010];
int T[200010];

void test()
{
  if (N * K > 100)
  {
    assert(false);
  }
  vector<int> V(N * K);
  for (auto k = 0; k < K; k++)
  {
    for (auto i = 0; i < N; i++)
    {
      V[k * N + i] = A[i];
    }
  }
  deque<int> X;
  vector<bool> used(200010, false);
  for (auto i = 0; i < N * K; i++)
  {
#if DEBUG == 1
    cerr << "V[" << i << "] = " << V[i] << endl;
#endif
    if (!used[V[i]])
    {
      used[V[i]] = true;
      X.push_back(V[i]);
    }
    else
    {
      while (*X.rbegin() != V[i])
      {
        assert(used[*X.rbegin()]);
        used[*X.rbegin()] = false;
        X.pop_back();
      }
      assert(*X.rbegin());
      used[*X.rbegin()] = false;
      X.pop_back();
    }
#if DEBUG == 1
    cerr << "{ ";
    for (auto x : X)
    {
      cerr << x << ", ";
    }
    cerr << "}" << endl;
#endif
  }
}

void make_B()
{
  fill(B, B + N, -1);
  vector<int> T(200010, -1);
  for (auto k = 0; k < 2; k++)
  {
    for (auto i = 0; i < N; i++)
    {
      if (T[A[i]] != -1)
      {
        B[i] = T[A[i]];
      }
      T[A[i]] = i;
    }
  }
#if DEBUG == 1
  for (auto i = 0; i < N; i++)
  {
    cerr << "B[" << i << "] = " << B[i] << endl;
  }
#endif
}

int circ()
{
  int cnt = 1;
  int now = N - 1;
  while (true)
  {
    if (B[now] >= now)
    {
      ++cnt;
    }
    now = B[now];
    T[now] = -cnt;
    if (now > 0)
    {
      --now;
    }
    else
    {
      break;
    }
  }
  return cnt;
}

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  make_B();
  int C = circ();
#if DEBUG == 1
  cerr << "circ() = " << C << endl;
#endif
  K %= C;
  for (auto i = 0; i < N; i++)
  {
    T[i] += C + 1;
  }
  int start = -1;
  for (auto i = N - 1; i >= 0; i--)
  {
    if (T[i] == K)
    {
      start = i;
      break;
    }
  }
  if (start == -1)
  {
    cout << endl;
    return 0;
  }
  deque<int> X;
  vector<bool> used(200010, false);
  for (auto i = start; i < N; i++)
  {
#if DEBUG == 1
    cerr << "A[" << i << "] = " << A[i] << endl;
#endif
    if (!used[A[i]])
    {
      used[A[i]] = true;
      X.push_back(A[i]);
    }
    else
    {
      while (*X.rbegin() != A[i])
      {
        assert(used[*X.rbegin()]);
        used[*X.rbegin()] = false;
        X.pop_back();
      }
      assert(*X.rbegin());
      used[*X.rbegin()] = false;
      X.pop_back();
    }
#if DEBUG == 1
    cerr << "{ ";
    for (auto x : X)
    {
      cerr << x << ", ";
    }
    cerr << "}" << endl;
#endif
  }
  if (X.empty())
  {
    return 0;
  }
  for (auto i = 0u; i < X.size(); i++)
  {
    cout << X[i];
    if (i < X.size() - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}