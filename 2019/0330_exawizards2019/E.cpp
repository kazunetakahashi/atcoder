#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-3-30 21:24:12
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 1000010;
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = ((MOD - inv[MOD % i]) * (MOD / i)) % MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = (i * fact[i - 1]) % MOD;
    factinv[i] = (inv[i] * factinv[i - 1]) % MOD;
  }
}

long long C(int n, int k)
{
  if (n >= 0 && k >= 0 && n - k >= 0)
  {
    return ((fact[n] * factinv[k]) % MOD * factinv[n - k]) % MOD;
  }
  return 0;
}

long long power(long long x, long long n)
{
  if (n == 0)
  {
    return 1;
  }
  else if (n % 2 == 1)
  {
    return (x * power(x, n - 1)) % MOD;
  }
  else
  {
    long long half = power(x, n / 2);
    return (half * half) % MOD;
  }
}

long long gcd(long long x, long long y)
{
  return y ? gcd(y, x % y) : x;
}

ll Inv(ll x)
{
  return power(x, MOD - 2);
}

ll B, W;
ll N;

typedef tuple<ll, ll> Q;

Q operator+(Q p, Q q)
{
  ll a = get<0>(p);
  ll b = get<1>(p);
  ll c = get<0>(q);
  ll d = get<1>(q);
  ll y = ((a * d) % MOD) + ((b * c) % MOD);
  y %= MOD;
  ll z = (b * d) % MOD;
  return Q(y, z);
}

Q operator-(Q p)
{
  ll a = get<0>(p);
  ll b = get<1>(p);
  ll y = (MOD - a) % MOD;
  return Q(y, b);
}

Q operator-(Q p, Q q)
{
  return p + (-q);
}

Q operator*(Q p, Q q)
{
  ll a = get<0>(p);
  ll b = get<1>(p);
  ll c = get<0>(q);
  ll d = get<1>(q);
  ll y = (a * c) % MOD;
  ll z = (b * d) % MOD;
  return Q(y, z);
}

ostream &operator<<(ostream &o_str, const Q &p)
{
  o_str << "{ " << get<0>(p) << " / " << get<1>(p);
  return o_str << " }";
}

vector<Q> ans;

void flush()
{
  assert((ll)ans.size() == B + W);
  for (auto x : ans)
  {
    ll y = get<0>(x);
    ll z = get<1>(x);
    cout << (y * Inv(z)) % MOD << endl;
  }
}

Q b[200010];
Q w[200010];

int main()
{
  init();
  cin >> B >> W;
  N = B + W;
  b[0] = Q(0, 1);
  w[0] = Q(0, 1);
  for (auto i = 0LL; i < N; i++)
  {
    Q x = Q(1, 2);
    ll z = power(2, i) * fact[W];
    z %= MOD;
    z *= fact[B];
    z %= MOD;
    z *= factinv[N - i];
    z %= MOD;
    if (i - W >= 0)
    {
      ll y = fact[W] * fact[i - W];
      y %= MOD;
      y *= C(i - 1, W - 1);
      y %= MOD;
      b[i + 1] = b[i] + Q(y, z);
      x = x + b[i + 1] * Q(1, 2);
    }
    else
    {
      b[i + 1] = Q(0, 1);
    }
    if (i - B >= 0)
    {
      ll y = fact[W] * fact[i - B];
      y %= MOD;
      y *= C(i - 1, B - 1);
      y %= MOD;
      w[i + 1] = w[i] + Q(y, z);
      x = x - w[i + 1] * Q(1, 2);
    }
    else
    {
      w[i + 1] = Q(0, 1);
    }
#if DEBUG == 1
    cerr << "b[" << i + 1 << "] = " << b[i + 1] << endl;
    cerr << "w[" << i + 1 << "] = " << w[i + 1] << endl;
#endif
    ans.push_back(x);
  }
  flush();
}