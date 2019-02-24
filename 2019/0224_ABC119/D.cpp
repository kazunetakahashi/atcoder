#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2/24/2019, 9:21:23 PM
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
const ll infty = 10000000000000007;

int A, B, Q;
ll s[100010];
ll t[100010];
ll x[100010];

void flush(ll y)
{
  int lb = 0;
  int ub = A;
  while (ub - lb > 1)
  {
    int temp = (lb + ub) / 2;
    if (y < s[temp])
    {
      lb = temp;
    }
    else
    {
      ub = temp;
    }
  }
  int ind_a = lb;
  lb = 0;
  ub = B;
  while (ub - lb > 1)
  {
    int temp = (lb + ub) / 2;
    if (y < t[temp])
    {
      lb = temp;
    }
    else
    {
      ub = temp;
    }
  }
  int ind_b = lb;
  ll p0 = s[ind_a - 1];
  ll p1 = s[ind_a];
  ll q0 = t[ind_b - 1];
  ll q1 = t[ind_b];
#if DEBUG == 1
  cerr << y << " " << p0 << " " << p1 << " " << q0 << " " << q1 << endl;
#endif
  ll ans = min(y - min(p0, q0), max(p1, q1) - y);
  ans = min(ans, 2 * (p1 - y) + (y - q0));
  ans = min(ans, (p1 - y) + 2 * (y - q0));
  ans = min(ans, 2 * (q1 - y) + (y - p0));
  ans = min(ans, (q1 - y) + 2 * (y - p0));
  cout << ans << endl;
}

int main()
{
  cin >> A >> B >> Q;
  s[0] = -infty;
  for (auto i = 1; i <= A; i++)
  {
    cin >> s[i];
  }
  s[A + 1] = infty;
  A += 2;
  t[0] = -infty;
  for (auto i = 1; i <= B; i++)
  {
    cin >> t[i];
  }
  t[B + 1] = infty;
  B += 2;
  for (auto i = 0; i < Q; i++)
  {
    cin >> x[i];
  }
  for (auto i = 0; i < Q; i++)
  {
    flush(x[i]);
  }
}