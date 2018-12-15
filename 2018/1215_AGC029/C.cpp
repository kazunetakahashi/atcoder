/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-12-15 21:49:53
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

const int C = 100;
// const ll M = 1000000007;

int N;
int A[200010];
int K[C];

bool solve(int X)
{
  fill(K, K + A[0], 0);
  for (auto i = 0; i < N - 1; i++)
  {
    if (A[i] > A[i + 1])
    {
      continue;
    }
    else if (A[i + 1] == C + 1)
    {
      continue;
    }
    else
    {
      bool ok = false;
      for (auto j = A[i] - 1; j >= 0; j--)
      {
        K[j]++;
        if (K[j] == X)
        {
          K[j] = 0;
        }
        else
        {
          ok = true;
          break;
        }
      }
      if (!ok)
      {
        return false;
      }
      for (auto j = A[i]; j < A[i + 1]; j++)
      {
        K[j] = 0;
      }
    }
  }
  return true;
}

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
    A[i] = min(C + 1, A[i]);
  }
  reverse(A, A + N);
  int ub = N;
  int lb = 0;
  while (ub - lb > 1)
  {
    int t = (ub + lb) / 2;
    if (solve(t))
    {
      ub = t;
    }
    else
    {
      lb = t;
    }
  }
  cout << ub << endl;
}