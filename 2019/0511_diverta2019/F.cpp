#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-11 22:04:36
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

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int> edge;
typedef tuple<int, int, int> info;

int N, M;
int a[210];
int b[210];
vector<edge> V[20];
vector<int> W[1 << 20];
vector<int> memo[1 << 20];
set<int> sets[1 << 20];

void add_mask(int mask, int num)
{
  if (sets[mask].find(num) == sets[mask].end())
  {
    return;
  }
  sets[mask].insert(num);
  for (auto i = 0; i < N; i++)
  {
    if (((mask >> i) & 1) == 0)
    {
      add_mask(mask + (1 << i), num);
    }
  }
}

int main()
{
  init();
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  for (auto i = 0; i < N - 1; i++)
  {
    V[a[i]].push_back(edge(b[i], i));
    V[b[i]].push_back(edge(a[i], i));
  }
  for (auto i = N - 1; i < M; i++)
  {
    edge from[20];
    fill(from, from + 20, edge(-1, -1));
    stack<info> S;
    S.push(info(a[i], -1, -1));
    while (!S.empty())
    {
      info e = S.top();
      int dst = get<0>(e);
      int src = get<1>(e);
      int num = get<2>(e);
      S.pop();
      if (from[dst] == edge(-1, -1))
      {
        from[dst] = edge(src, num);
        if (dst == b[i])
        {
          break;
        }
        for (auto x : V[dst])
        {
          int next = get<0>(x);
          int next_num = get<1>(x);
          if (from[next] == edge(-1, -1))
          {
            S.push(info(next, dst, next_num));
          }
        }
      }
    }
    int mask = 0;
    int temp = b[i];
    while (temp != a[i])
    {
      int num = get<1>(from[temp]);
      mask += (1 << num);
      temp = get<0>(from[temp]);
    }
    int x = (1 << N) - mask;
    ll score = 0;
    for (auto i = 0; i < N; i++)
    {
      if ((x >> i) & 1)
      {
        score++;
      }
    }
    memo[mask].push_back(i);
  }
#if DEBUG == 1
  for (auto i = 0; i < (1 << N); i++)
  {
    cerr << "sets[" << i << "] = {";
    for (auto x : sets[i])
    {
      cerr << x << ", ";
    }
    cerr << "}" << endl;
  }
#endif
  ll ans = (fact[N] * fact[M]) % MOD;
}