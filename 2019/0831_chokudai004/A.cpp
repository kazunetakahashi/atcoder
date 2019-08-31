#define DEBUG 1
/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 8/31/2019, 8:52:40 PM
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
constexpr int infty = 1e9 + 7;
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
vector<int> B;
vector<vector<int>> L, R, ans;

void input()
{
  cin >> N;
  B.resize(3);
  for (auto i = 0; i < 3; i++)
  {
    cin >> B[i];
  }
  L = vector<vector<int>>(N, vector<int>(N));
  R = vector<vector<int>>(N, vector<int>(N));
  ans = vector<vector<int>>(N, vector<int>(N, 0));
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cin >> L[i][j];
    }
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cin >> R[i][j];
    }
  }
}

void WA()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cout << 0;
      if (j < N - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
  exit(0);
}

void must_do()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (L[i][j] == R[i][j])
      {
        ans[i][j] = L[i][j];
      }
    }
  }
}

using P = tuple<int, int, int>;
vector<P> V;

void make_V()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (L[i][j] == R[i][j])
      {
        continue;
      }
      V.emplace_back(abs(L[i][j] - R[i][j]), i, j);
    }
  }
  sort(V.begin(), V.end());
}

int calc(int x, int y, int v)
{
  ans[x][y] = v;
  int res{0};
  for (auto t = 0; t < 3; t++)
  {
    int sum{0};
    int right{0};
    for (auto i = 0; i < N; i++)
    {
      while (right <= y || (right < N && sum < B[t]))
      {
        sum += ans[x][right++];
      }
      if (sum == B[t])
      {
        res += B[t];
      }
      sum -= ans[x][i];
    }
  }
  for (auto t = 0; t < 3; t++)
  {
    int sum{0};
    int right{0};
    for (auto i = 0; i < N; i++)
    {
      while (right <= x || (right < N && sum < B[t]))
      {
        sum += ans[right++][y];
      }
      if (sum == B[t])
      {
        res += B[t];
      }
      sum -= ans[i][y];
    }
  }
  ans[x][y] = 0;
  return res;
}

int calc_point()
{
  int res{0};
  for (auto x = 0; x < N; x++)
  {
    for (auto i = 0; i < N; i++)
    {
      for (auto j = i + 1; j < N; j++)
      {
        int sum{0};
        for (auto k = i; k < j; k++)
        {
          sum += ans[x][k];
        }
        for (auto t = 0; t < 3; t++)
        {
          if (sum == B[t])
          {
            res += sum;
          }
        }
      }
    }
  }
  for (auto y = 0; y < N; y++)
  {
    for (auto i = 0; i < N; i++)
    {
      for (auto j = i + 1; j < N; j++)
      {
        int sum{0};
        for (auto k = i; k < j; k++)
        {
          sum += ans[k][y];
        }
        for (auto t = 0; t < 3; t++)
        {
          if (sum == B[t])
          {
            res += sum;
          }
        }
      }
    }
  }
  return res;
}

random_device seed_gen;
mt19937 engine(seed_gen());

int min_calc(int x, int y)
{
  int mini{infty};
  int val{L[x][y]};
  for (auto v = L[x][y]; v <= R[x][y]; v++)
  {
    int tmp{calc(x, y, v)};
    if (mini > tmp)
    {
      mini = tmp;
      val = v;
    }
  }
  ans[x][y] = val;
  return mini;
}

void make_min_ans()
{
  for (auto e : V)
  {
    int t, x, y;
    tie(t, x, y) = e;
    if (t == 0)
    {
      continue;
    }
    min_calc(x, y);
  }
}

void flush()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cout << ans[i][j];
      if (j < N - 1)
      {
        cout << " ";
      }
      else
      {
        cout << endl;
      }
    }
  }
  // cerr << calc_point() << endl;
}

int main()
{
  auto start{chrono::system_clock::now()};
  auto goal{chrono::system_clock::now()};
  double dif{0};
  input();
  /*
  if (B[0] != 11 || B[1] != 21 || B[2] != 36)
  {
    WA();
  }
  */
  must_do();
  make_V();
  make_min_ans();
  while (true)
  {
    goal = chrono::system_clock::now();
    dif = chrono::duration_cast<chrono::milliseconds>(goal - start).count();
    // cerr << dif << endl;
    if (dif >= 2994)
    {
      break;
    }
    shuffle(V.begin(), V.end(), engine);
    make_min_ans();
  }
  flush();
}