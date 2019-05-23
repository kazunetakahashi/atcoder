#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-3-30 21:04:45
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

int N, Q;
string S;
char T[200010];
char D[200010];

int f(int n)
{
  for (auto i = 0; i < Q; i++)
  {
    if (S[n] == T[i])
    {
      if (D[i] == 'L')
      {
        n--;
      }
      else
      {
        n++;
      }
    }
    if (!(0 <= n && n < N))
    {
      return n;
    }
  }
  return n;
}

int main()
{
  cin >> N >> Q >> S;
  for (auto i = 0; i < Q; i++)
  {
    char t, d;
    cin >> t >> d;
    T[i] = t;
    D[i] = d;
  }
  int ok = N;
  int ng = -1;
  while (abs(ok - ng) > 1)
  {
    int t = (ok + ng) / 2;
    if (f(t) == -1)
    {
      ng = t;
    }
    else
    {
      ok = t;
    }
  }
  int left = ok;
  ok = -1;
  ng = N;
  while (abs(ok - ng) > 1)
  {
    int t = (ok + ng) / 2;
    if (f(t) == N)
    {
      ng = t;
    }
    else
    {
      ok = t;
    }
  }
  int right = ok;
#if DEBUG == 1
  cerr << "left = " << left << ", right = " << right << endl;
  cerr << "f(" << left << ") = " << f(left) << endl;
  cerr << "f(" << right << ") = " << f(right) << endl;
#endif
  cout << right - left + 1 << endl;
}