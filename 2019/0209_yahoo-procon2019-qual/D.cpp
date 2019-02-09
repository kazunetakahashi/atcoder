/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2/9/2019, 9:16:48 PM
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

int L;
ll A[200010];
ll B[200010]; // even
ll C[200010]; // odd
ll sum[3][200010];

ll calc(int a, int b, int c, int d)
{
  ll ans = 0;
  ans += sum[0][a] - sum[0][0];
  ans += sum[1][b] - sum[1][a];
  ans += sum[2][c] - sum[2][b];
  ans += sum[1][d] - sum[1][c];
  ans += sum[0][L] - sum[0][d];
  return ans;
}

int main()
{
  cin >> L;
  ll mini = 0;
  for (auto i = 0; i < L; i++)
  {
    cin >> A[i];
    mini += A[i];
  }
  bool zero = true;
  for (auto i = 0; i < L; i++)
  {
    if (A[i] > 0)
    {
      zero = false;
      break;
    }
  }
  if (zero)
  {
    cout << 0 << endl;
    return 0;
  }
  for (auto i = 0; i < L; i++)
  {
    if (A[i] == 0)
    {
      B[i] = 2;
    }
    else if (A[i] % 2 == 0)
    {
      B[i] = 0;
    }
    else
    {
      B[i] = 1;
    }
  }
  for (auto i = 0; i < L; i++)
  {
    if (A[i] % 2 == 1)
    {
      C[i] = 0;
    }
    else
    {
      C[i] = 1;
    }
  }
  sum[0][0] = sum[0][1] = sum[0][2] = 0;
  for (auto i = 0; i < L; i++)
  {
    sum[0][i + 1] = sum[0][i] + A[i];
    sum[1][i + 1] = sum[1][i] + B[i];
    sum[2][i + 1] = sum[2][i] + C[i];
  }
  for (auto a = 0; a <= L; a++)
  {
    for (auto b = a; b <= L; b++)
    {
      for (auto c = b; c <= L; c++)
      {
        for (auto d = c; d <= L; d++)
        {
          ll t = calc(a, b, c, d);
          if (t <= mini)
          {
            mini = min(mini, t);
            cerr << "calc(" << a << ", " << b << ", " << c << ", " << d << ") = " << t << endl;
          }
        }
      }
    }
  }
  cerr << mini << endl;
}