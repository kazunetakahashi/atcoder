#define DEBUG 1
/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 7/14/2019, 10:10:17 PM
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
  mint &operator/=(const mint &a) { return (*this *= power(MOD - 2)); }
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
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

int N, M;
using edge = tuple<int, int>;
using info = tuple<int, int>;
set<int> V[100010];
vector<edge> ans;
bool visited[100010];
int cnt[100010];
priority_queue<info, vector<info>, greater<info>> Q;

void Yes()
{
  assert((int)ans.size() == M);
  for (auto x : ans)
  {
    cout << get<0>(x) << " " << get<1>(x) << endl;
  }
  exit(0);
}
void No()
{
  cout << "-1" << endl;
  exit(0);
}

void solve()
{
  for (auto i = 0; i < N; i++)
  {
    Q.push(info(V[i].size(), i));
  }
  while (!Q.empty())
  {
    // int sz = get<0>(Q.top());
    int v = get<1>(Q.top());
    Q.pop();
    if (!visited[v])
    {
      visited[v] = true;
      for (auto x : V[v])
      {
        ans.push_back(edge(x, v));
        cnt[x]++;
        V[x].erase(v);
        Q.push(info(V[x].size(), x));
      }
      V[v].clear();
      if (cnt[v] % 2 == 1)
      {
        auto it = ans.end();
        --it;
        cnt[get<0>(*it)]--;
        swap(get<0>(*it), get<1>(*it));
      }
    }
  }
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    V[a].insert(b);
    V[b].insert(a);
  }
  if (M % 2 == 1)
  {
    No();
  }
  solve();
  Yes();
}