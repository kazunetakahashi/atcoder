/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-2 20:45:55
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
#include <random> // random_device rd; mt19937 mt(rd());
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
const ll MOD = 1000000007;
const ll M = 250010;
random_device rd;
mt19937 mt(rd());
typedef tuple<ll, ll> D;

int N;
string S;
map<ll, int> ans;
ll X;
ll X_inv;
ll C;
ll a[500100];
D g[250010];
map<ll, ll> G;

ll power2(int i)
{
  if (i == 0)
  {
    return 1;
  }
  else if (i % 2 == 0)
  {
    ll half = power2(i / 2);
    return (half * half) % MOD;
  }
  else
  {
    return (power2(i - 1) * X) % MOD;
  }
}

ll power(int i)
{
  if (i == 0)
  {
    return 1;
  }
  else if (i < 0)
  {
    return power2(MOD + i - 1);
  }
  return power2(i);
}

ll calc_hash()
{
  fill(a, a + 500100, 0);
  int P = M;
  for (auto e : S)
  {
    if (e == '+')
    {
      a[P]++;
    }
    else if (e == '-')
    {
      a[P]--;
    }
    else if (e == '>')
    {
      P++;
    }
    else
    {
      P--;
    }
  }
  ll res = 0;
  for (auto i = 0; i < 500100; i++)
  {
    res += (((MOD + a[i]) % MOD) * power(i - M)) % MOD;
    res %= MOD;
  }
  return res;
}

void calc_g()
{
  g[N] = D(1, 0);
  for (auto i = N - 1; i >= 0; i--)
  {
    ll A_prime = get<0>(g[i + 1]);
    ll B_prime = get<1>(g[i + 1]);
    ll A, B;
    if (S[i] == '+')
    {
      A = 1, B = -1;
    }
    else if (S[i] == '-')
    {
      A = 1, B = -1;
    }
    else if (S[i] == '>')
    {
      A = X_inv, B = 0;
    }
    else
    {
      A = X, B = 0;
    }
    g[i] = D((A_prime * A) % MOD,
             ((A_prime * B) % MOD + B_prime) % MOD);
  }
}

ll count_ans()
{
  ll res = 0;
  G.clear();
  for (int i = N; i >= 1; i--)
  {
    ll J = get<1>(g[i]);
    if (G.find(J) == G.end())
    {
      G[J] = 1;
    }
    else
    {
      G[J]++;
    }
    ll I = ((get<0>(g[i - 1]) * C) % MOD + get<1>(g[i - 1])) % MOD;
    if (G.find(I) != G.end())
    {
      cerr << "i = " << i - 1 << ", cnt of j = " << G[I] << endl;
      res += G[I];
    }
  }
  return res;
}

void solve()
{
  X = abs((ll)mt());
  X_inv = power(-1);
  C = calc_hash();
  calc_g();
  ll res = count_ans();
  if (ans.find(res) == ans.end())
  {
    ans[res] = 1;
  }
  else
  {
    ans[res]++;
  }
}

int main()
{
  cin >> N >> S;
  for (auto i = 0; i < 6; i++)
  {
    solve();
  }
  ll res = 0;
  int maxi = 0;
  for (auto e : ans)
  {
    ll a = e.first;
    int cnt = e.second;
    if (cnt > maxi)
    {
      cnt = maxi;
      res = a;
    }
  }
  cout << res << endl;
}