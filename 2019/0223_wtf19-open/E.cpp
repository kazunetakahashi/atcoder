#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2/24/2019, 9:39:27 AM
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
const ll MOD = 1000000007;

const int MAX_SIZE = 1000010;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];
ll factinvsum[MAX_SIZE];

void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = ((MOD - inv[MOD % i]) * (MOD / i)) % MOD;
  }
  fact[0] = factinv[0] = factinvsum[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = (i * fact[i - 1]) % MOD;
    factinv[i] = (inv[i] * factinv[i - 1]) % MOD;
    factinvsum[i] = (factinv[i] + factinvsum[i - 1]) % MOD;
  }
}

typedef vector<ll> Poly;

ostream &operator<<(ostream &o_str, const Poly &p)
{
  o_str << "{ ";
  for (auto i = 0; i < (int)p.size(); i++)
  {
    o_str << p[i];
    if (i < (int)p.size() - 1)
    {
      o_str << ", ";
    }
  }
  return o_str << " }";
}

void reduce(Poly &v)
{
  while (!v.empty() && v.back() % MOD == 0)
  {
    v.pop_back();
  }
}

bool is_zero(Poly p)
{
  reduce(p);
  return p.empty();
}

Poly operator+(Poly p, Poly q)
{
  reduce(p);
  reduce(q);
  if (p.size() < q.size())
  {
    return q + p;
  }
  else
  {
    for (auto i = 0; i < (int)q.size(); i++)
    {
      p[i] += q[i];
      p[i] %= MOD;
    }
  }
  reduce(p);
  return p;
}

Poly operator-(Poly p)
{
  reduce(p);
  for (auto i = 0; i < (int)p.size(); i++)
  {
    p[i] %= MOD;
    p[i] = MOD - p[i];
    p[i] %= MOD;
  }
  reduce(p);
  return p;
}

Poly operator-(Poly p, Poly q)
{
  return p + (-q);
}

typedef tuple<Poly, Poly, ll> Func;

ostream &operator<<(ostream &o_str, const Func &f)
{
  o_str << "a = " << get<0>(f) << endl;
  o_str << "b = " << get<1>(f) << endl;
  o_str << "c = " << get<2>(f);
  return o_str;
}

void reduce(Func &f)
{
  reduce(get<0>(f));
  reduce(get<1>(f));
}

Func operator+(Func f, Func g)
{
  reduce(f);
  reduce(g);
  Func ans = Func(get<0>(f) + get<0>(g), get<1>(f) + get<1>(g), get<2>(f) + get<2>(g));
  reduce(ans);
  get<2>(ans) %= MOD;
  return ans;
}

Func operator-(Func f)
{
  reduce(f);
  Func ans = Func(-get<0>(f), -get<1>(f), (MOD - get<2>(f)) % MOD);
  reduce(f);
  return f;
}

Func operator-(Func p, Func q)
{
  return p + (-q);
}

Func int_0(Func f)
{
  Poly a = get<0>(f);
  Poly b = get<1>(f);
  ll c = get<2>(f);
  Poly a_prime, b_prime;
  ll c_prime;
  int K = a.size();
  a_prime.push_back(c);
  for (auto i = 1; i <= K; i++)
  {
    a_prime.push_back((a[i - 1] * inv[i]) % MOD);
  }
  reduce(a_prime);
  int L = b.size();
  b_prime.push_back(0);
  for (auto i = 1; i <= L; i++)
  {
    b_prime.push_back((b[i - 1] * inv[i]) % MOD);
  }
  reduce(b_prime);
  c_prime = (MOD - c) % MOD;
  return Func(a_prime, b_prime, c_prime);
}

Func int_1(Func f)
{
  Poly a = get<0>(f);
  Poly b = get<1>(f);
  ll c = get<2>(f);
  Poly a_prime, b_prime;
  ll c_prime;
  int K = a.size();
  ll t = 0;
  for (auto i = 0; i < K; i++)
  {
    t += (a[i] * inv[i + 1]) % MOD;
    t %= MOD;
  }
  a_prime.push_back(t);
  for (auto i = 1; i <= K; i++)
  {
    a_prime.push_back((MOD - ((a[i - 1] * inv[i]) % MOD)) % MOD);
  }
  reduce(a_prime);
  int L = b.size();
  t = (MOD - c) % MOD;
  for (auto i = 0; i < L; i++)
  {
    t += (b[i] * inv[i + 1]) % MOD;
    t %= MOD;
  }
  b_prime.push_back(t);
  for (auto i = 1; i <= L; i++)
  {
    b_prime.push_back((MOD - ((b[i - 1] * inv[i]) % MOD)) % MOD);
  }
  reduce(b_prime);
  c_prime = c;
  return Func(a_prime, b_prime, c_prime);
}

typedef tuple<ll, ll, ll> Flush;

ostream &operator<<(ostream &o_str, const Flush &x)
{
  return o_str << get<0>(x) << " " << get<1>(x) << " " << get<2>(x);
}

Flush operator+(Flush x, Flush y)
{
  get<0>(x) += get<0>(y);
  get<0>(x) %= MOD;
  get<1>(x) += get<1>(y);
  get<1>(x) %= MOD;
  get<2>(x) += get<2>(y);
  get<2>(x) %= MOD;
  return x;
}

Flush operator-(Flush x)
{
  get<0>(x) = (MOD - get<0>(x)) % MOD;
  get<1>(x) = (MOD - get<1>(x)) % MOD;
  get<2>(x) = (MOD - get<2>(x)) % MOD;
  return x;
}

Flush operator-(Flush x, Flush y)
{
  return x + (-y);
}

Flush operator*(ll k, Flush x)
{
  get<0>(x) *= k;
  get<0>(x) %= MOD;
  get<1>(x) *= k;
  get<1>(x) %= MOD;
  get<2>(x) *= k;
  get<2>(x) %= MOD;
  return x;
}

Flush operator*(Flush x, ll k)
{
  return k * x;
}

Flush int_01(ll i)
{
  ll x = fact[i];
  ll y = (MOD - (fact[i] * factinvsum[i]) % MOD) % MOD;
  return Flush(x, y, 0);
}

Flush int_01_e(ll i)
{
  ll x = fact[i];
  ll y = (MOD - (fact[i] * factinvsum[i]) % MOD) % MOD;
  return Flush(0, x, y);
}

Flush int_e_2()
{
  return Flush(inv[2], 0, (MOD - inv[2]) % MOD);
}

Flush integral(Func f)
{
  Poly a = get<0>(f);
  Poly b = get<1>(f);
  ll c = get<2>(f);
  ll x = c;
  int K = a.size();
  for (auto i = 0; i < K; i++)
  {
    x += (a[i] * inv[i + 1]) % MOD;
    x %= MOD;
  }
  ll y = (MOD - c) % MOD;
  int L = b.size();
  for (auto i = 0; i < L; i++)
  {
    y += (b[i] * inv[i + 1]) % MOD;
    y %= MOD;
  }
  return Flush(x, y, 0);
}

Flush integral_e(Func f)
{
  Flush ans = Flush(0, 0, 0);
  Poly a = get<0>(f);
  Poly b = get<1>(f);
  ll c = get<2>(f);
  int K = a.size();
  for (auto i = 0; i < K; i++)
  {
    ans = ans + int_01(i) * a[i];
  }
  int L = b.size();
  for (auto i = 0; i < L; i++)
  {
    ans = ans + int_01_e(i) * b[i];
  }
  ans = ans + int_e_2() * c;
  return ans;
}

int N;
string S;
Func DP[1010][2][2][2];

int main()
{
  init();
  vector<ll> temp_v;
  Func zero = Func(temp_v, temp_v, 0);
  fill(&DP[0][0][0][0], &DP[0][0][0][0] + 1010 * 2 * 2 * 2, zero);
  cin >> N >> S;
  if (S[0] == 'X')
  {
    DP[0][0][1][0] = Func(temp_v, temp_v, 1);
  }
  else
  {
    DP[0][0][0][1] = Func(temp_v, temp_v, 1);
    vector<ll> temp_w;
    temp_w.push_back(1);
    DP[0][1][1][1] = Func(temp_w, temp_v, MOD - 1);
  }
  for (auto i = 1; i < N; i++)
  {
    if (S[i] == 'X')
    {
      for (auto k = 0; k < 2; k++)
      {
        DP[i][0][1][0] = DP[i][0][1][0] + int_0(DP[i - 1][1][1][k]);
      }
      for (auto k = 0; k < 2; k++)
      {
        for (auto l = 0; l < 2; l++)
        {
          DP[i][0][1][0] = DP[i][0][1][0] + int_1(DP[i - 1][k][l][1]);
        }
      }
    }
    else
    {
      for (auto k = 0; k < 2; k++)
      {
        DP[i][0][0][1] = DP[i][0][0][1] + int_0(DP[i - 1][1][1][k]);
      }
      for (auto k = 0; k < 2; k++)
      {
        DP[i][1][1][1] = DP[i][1][1][1] + int_0(DP[i - 1][0][1][k]);
      }
      for (auto k = 0; k < 2; k++)
      {
        for (auto l = 0; l < 2; l++)
        {
          DP[i][0][0][1] = DP[i][0][0][1] + int_1(DP[i - 1][k][1][l]);
        }
      }
    }
    /*
#if DEBUG == 1
    if (N < 10)
    {
      for (auto k = 0; k < 2; k++)
      {
        for (auto l = 0; l < 2; l++)
        {
          for (auto m = 0; m < 2; m++)
          {
            cerr << "DP[" << i << "][" << k << "][" << l << "][" << m << "]:" << endl;
            cerr << DP[i][k][l][m] << endl;
          }
        }
      }
    }
#endif
    */
  }
  Flush ans = Flush(0, 0, 0);
#if DEBUG == 1
  for (auto k = 0; k < 2; k++)
  {
    for (auto l = 0; l < 2; l++)
    {
      for (auto m = 0; m < 2; m++)
      {
        cerr << "DP[" << N - 1 << "][" << k << "][" << l << "][" << m << "]:" << endl;
        cerr << DP[N - 1][k][l][m] << endl;
      }
    }
  }
#endif
  for (auto k = 0; k < 2; k++)
  {
    ans = ans + integral(DP[N - 1][k][0][1]);
    ans = ans + integral(DP[N - 1][k][1][1]);
  }
  for (auto k = 0; k < 2; k++)
  {
    ans = ans + integral_e(DP[N - 1][k][1][0]);
    ans = ans - integral_e(DP[N - 1][k][0][1]);
  }
  cout << ans << endl;
}