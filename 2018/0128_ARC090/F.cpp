/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-27 18:27:15
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
// const ll M = 1000000007;

const long long MOD = 1000000007;

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

int f[20000010];

int main()
{
  int S;
  cin >> S;
  vector<int> Y;
  int SQ = sqrt(S) + 10;
  for (int i = 1; i < SQ; i++)
  {
    if (S%i == 0)
    {
      int j = S / i;
      if (i < j)
      {
        Y.push_back(i);
        Y.push_back(j);
      }
      else if (i == j)
      {
        Y.push_back(i);
      }
    }
  }
  ll ans = 0;
  for (auto i = 0; i < 8; i++)
  {
    int lb = power(10, i);
    int ub = min((int)power(10, i + 1), 20000010);
    for (auto j = lb; j < ub; j++)
    {
      f[j] = i+1;
    }
  }
  int lb = 1;
  int ub = 1;
  int sum = 0;
  while (lb < 10000000)
  {
    if (sum == S)
      ans++;
    if (sum <= S)
    {
      sum += f[ub++];
    }
    else
    {
      sum -= f[lb++];
    }
  }
  ans += S / 8;
  for (auto k : Y)
  {
    if (k <= S/8)
    {
      int d = S / k;
      ans += (power(10, d) + MOD - power(10, d - 1) + MOD - S / d) % MOD;
      ans %= MOD;
    }
  }
  cout << ans << endl;
}