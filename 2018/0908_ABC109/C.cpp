/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-8 21:05:03
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
// const ll M = 1000000007;

int N;
ll X;
ll x[100010];

ll gcd(ll a, ll b)
{
  if (b > a)
  {
    return gcd(b, a);
  }
  else if (b == 1)
  {
    return 1;
  }
  else
  {
    return gcd(b, a % b);
  }
}

int main()
{
  cin >> N >> X;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i];
    x[i] -= X;
    x[i] = abs(x[i]);
  }
  if (N == 1)
  {
    cout << x[0] << endl;
  }
  else
  {
    ll ans = gcd(x[0], x[1]);
    for (auto i = 1; i < N; i++)
    {
      ans = gcd(ans, x[i]);
    }
    cout << ans << endl;
  }
}