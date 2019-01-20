/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 1/20/2019, 9:01:34 PM
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

ll s;
ll a[1000010];
set<ll> S;

ll f(ll n)
{
  if (n % 2 == 0)
  {
    return n / 2;
  }
  else
  {
    return 3 * n + 1;
  }
}

int main()
{
  cin >> s;
  a[0] = s;
  for (auto i = 0; i < 1000010 - 1; i++)
  {
    if (S.find(a[i]) == S.end())
    {
      a[i + 1] = f(a[i]);
    }
    else
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
}