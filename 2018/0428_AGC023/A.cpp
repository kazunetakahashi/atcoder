/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-28 20:51:18
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

int N;
ll A[200010];
ll sum[200010];
map<ll, ll> M;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sum[0] = A[0];
  for (auto i = 1; i < N; i++)
  {
    sum[i] = sum[i - 1] + A[i];
  }
  for (auto i = 0; i < N; i++)
  {
    if (M.find(sum[i]) == M.end())
    {
      M[sum[i]] = 1;
    }
    else
    {
      M[sum[i]]++;
    }
  }
  ll ans = 0;
  for (auto x : M)
  {
    ll c = x.second;
    ans += c * (c - 1) / 2;
  }
  cout << ans << endl;
}