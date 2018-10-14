/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-10-14 21:35:05
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

int N, M;
ll q;
ll x[2010];
ll p[2010];
ll r[2010];
int ok[2010];

int main()
{
  cin >> N >> M >> q;
  for (auto i = 0; i < M; i++)
  {
    cin >> x[i] >> p[i];
  }
  for (auto i = 0; i < M; i++)
  {
    r[i] = p[i] * N / q;
    cerr << "r[" << i << "] = " << r[i] << endl;
  }
  ll rem = N;
  for (auto i = 0; i < M; i++)
  {
    rem -= r[i];
  }
  cerr << "rem = " << rem << endl;
  for (auto i = 0; i < M; i++)
  {
    if (abs(p[i] * N - r[i] * q) > abs(p[i] * N - (r[i] + 1) * q))
    {
      ok[i] = 2;
    }
    else if (abs(p[i] * N - r[i] * q) == abs(p[i] * N - (r[i] + 1) * q))
    {
      ok[i] = 1;
    }
    else
    {
      ok[i] = 0;
    }
    cerr << "ok[" << i << "] = " << ok[i] << endl;
  }
  for (int i = M - 1; i >= 0; i--)
  {
    if (ok[i] == 2 && rem > 0)
    {
      r[i]++;
      rem--;
    }
  }
  for (int i = M - 1; i >= 0; i--)
  {
    if (ok[i] == 1 && rem > 0)
    {
      r[i]++;
      rem--;
    }
  }
  r[0] += rem;
  for (auto i = 0; i < M; i++)
  {
    cerr << "r[" << i << "] = " << r[i] << endl;
  }
  double E_init = 0;
  for (auto i = 0; i < M; i++)
  {
    E_init += r[i] * x[i];
  }
  E_init /= N;
  double E = 0;
  for (auto i = 0; i < M; i++)
  {
    E += p[i] * x[i];
  }
  E /= q;
  cout << fixed << setprecision(12) << abs(E - E_init) * N << endl;
}