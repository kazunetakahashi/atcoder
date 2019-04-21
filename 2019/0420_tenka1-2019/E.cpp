#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-4-21 10:41:20
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
bool isprime[MAX_SIZE];
vector<int> prime_num;

void init()
{
  fill(isprime, isprime + MAX_SIZE, true);
  isprime[0] = isprime[1] = false;
  for (auto i = 2; i < MAX_SIZE; i++)
  {
    if (isprime[i])
    {
      prime_num.push_back(i);
      for (auto j = 2; i * j < MAX_SIZE; j++)
      {
        isprime[i * j] = false;
      }
    }
  }
}

vector<long long> make_factors(long long x)
{ // 2 \leq x \leq MAX_SIZE^2
  vector<long long> ans;
  auto it = prime_num.begin();
  while (it != prime_num.end())
  {
    if (x == 1)
    {
      break;
    }
    while (x % *it == 0)
    {
      ans.push_back(*it);
      x /= *it;
    }
    it++;
  }
  if (x != 1)
  {
    ans.push_back(x);
  }
  return ans;
}

ll N;
ll a[100010];
set<ll> S;
vector<ll> ans;

void make_primes()
{
  for (auto it = prime_num.begin(); it != prime_num.end(); it++)
  {
    if (*it <= N)
    {
      S.insert(*it);
#if DEBUG == 1
      cerr << "S.insert(" << *it << ")" << endl;
#endif
    }
    else
    {
      break;
    }
  }
  auto W = make_factors(abs(a[N]));
  for (auto x : W)
  {
#if DEBUG == 1
    cerr << "W inclues " << x << endl;
#endif
    S.insert(x);
  }
}

void flush()
{
  sort(ans.begin(), ans.end());
  for (auto x : ans)
  {
    cout << x << endl;
  }
}

void check_prime(ll p)
{
  vector<ll> A(max(p, N + 1), 0);
  A[0] = a[0];
  for (auto i = 1; i <= N; i++)
  {
    ll t = i % (p - 1);
    if (t == 0)
    {
      t = p - 1;
    }
    A[t] += a[i];
  }
  bool ok = true;
  for (auto x : A)
  {
    if (x % p != 0)
    {
      ok = false;
      break;
    }
  }
  if (ok)
  {
    ans.push_back(p);
  }
}

int main()
{
  init();
  cin >> N;
  for (auto i = 0; i <= N; i++)
  {
    cin >> a[i];
  }
  reverse(a, a + N + 1);
  make_primes();
  for (auto x : S)
  {
    check_prime(x);
  }
  flush();
}