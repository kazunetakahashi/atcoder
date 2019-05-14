#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-14 14:51:45
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
const ll M = 1000000007;

int N;
int A[500010];
int X[500010];
typedef tuple<int, int> info;
vector<info> V[1 << 20];
int zero[1 << 20];
int cnt = 0;
typedef tuple<int, int> res;

void make_vector()
{
  fill(zero, zero + (1 << 20), 0);
  for (auto i = 1; i < N; i++)
  {
    if (X[i] == 0)
    {
      cnt++;
    }
    else
    {
      int K = X[i];
      int t = cnt - zero[K];
      if (t > 0)
      {
        V[K].push_back(info(0, t));
      }
      V[K].push_back(info(K, 1));
      zero[X[i]] = cnt;
    }
  }
  for (auto K = 1; K < (1 << 20); K++)
  {
    int t = cnt - zero[K];
    if (t > 0)
    {
      V[K].push_back(info(0, t));
    }
  }
}

res DP(int K)
{
  int S = V[K].size();
  vector<ll> DP0(S + 1, 0);
  vector<ll> DP1(S + 1, 0);
  DP0[0] = 1;
#if DEBUG == 1
  if (K < 4)
  {
    cerr << "DP(" << K << ")" << endl;
  }
#endif
  for (auto i = 0; i < S; i++)
  {
    int n = get<0>(V[K][i]);
    ll s = get<1>(V[K][i]);
    if (n == 0)
    {
      DP0[i + 1] = (DP0[i] + s * DP1[i]) % M;
      DP1[i + 1] = DP1[i];
    }
    else
    {
      DP0[i + 1] = DP0[i];
      DP1[i + 1] = (DP0[i] + DP1[i]) % M;
    }
#if DEBUG == 1
    if (K < 4)
    {
      cerr << "DP0[" << i + 1 << "] = " << DP0[i + 1]
           << ", DP1[" << i + 1 << "] = " << DP1[i + 1] << endl;
    }
#endif
  }
  return res(DP0[S], DP1[S]);
}

void solve0()
{
  ll ans = 1;
  for (auto i = 1; i < N; i++)
  {
    if (X[i] == 0)
    {
      ans *= 2;
      ans %= M;
    }
  }
  make_vector();
  for (auto K = 1; K < (1 << 20); K++)
  {
    ll temp = get<1>(DP(K));
    ans += temp;
    ans %= M;
  }
  cout << ans << endl;
}

void solve1()
{
  make_vector();
  cout << get<0>(DP(X[N])) << endl;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  X[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    X[i + 1] = A[i] ^ X[i];
  }
  if (X[N] == 0)
  {
    solve0();
  }
  else
  {
    solve1();
  }
}