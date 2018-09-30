/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-30 15:28:44
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
const ll M = 1000000007;

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

class BIT
{ // index starts at 1.
public:
  int N;
  ll *data;

  BIT(int n) : N(n)
  {
    data = new ll[N + 1];
    for (auto i = 1; i <= N; ++i)
    {
      data[i] = 0;
    }
  }

  ~BIT()
  {
    delete[] data;
  }

  ll sum(int i)
  { // [1, i]
    ll s = 0;
    while (i > 0)
    {
      s += data[i];
      i -= i & -i;
    }
    return s;
  }

  ll sum(int a, int b)
  { // [a, b)
    return sum(b - 1) - sum(a - 1);
  }

  void add(int i, ll x)
  {
    while (i <= N)
    {
      data[i] += x;
      i += i & -i;
    }
  }

  void add(int i)
  {
    add(i, 1);
  }
};

int N;
int a[200010];
ll b[200010];
ll c[200010];
ll d[200010];

int main()
{
  init();
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  BIT bit(N + 1);
  cerr << "b: ";
  for (auto i = 0; i < N; i++)
  {
    b[i] = a[i] - bit.sum(1, a[i] + 1);
    bit.add(a[i] + 1);
    cerr << b[i] << " ";
  }
  cerr << endl;
  c[N - 1] = 1;
  for (int i = N - 2; i >= 0; i--)
  {
    c[i] = (b[i] * fact[N - 1 - i]) % MOD;
    c[i] += c[i + 1];
    c[i] %= MOD;
  }
  cerr << "c: ";
  for (auto i = 0; i < N; i++)
  {
    cerr << c[i] << " ";
  }
  cerr << endl;
  ll ans = 0;
  for (auto i = 0; i < N; i++)
  {
    d[i] = 0;
    d[i] += (fact[N - 1 - i] * (((b[i] * (b[i] - 1)) / 2) % MOD)) % MOD;
    d[i] %= MOD;
    d[i] += (((b[i] * fact[N - 1 - i]) % MOD) * ((C(N - 1 - i, 2) * inv[2]) % MOD)) % MOD;
    d[i] %= MOD;
    d[i] += (b[i] * c[i]) % MOD;
    d[i] %= MOD;
    ans += d[i];
    ans %= MOD;
  }
  cerr << "d: ";
  for (auto i = 0; i < N; i++)
  {
    cerr << d[i] << " ";
  }
  cerr << endl;
  cout << ans << endl;
}