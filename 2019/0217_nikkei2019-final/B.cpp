#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2/17/2019, 12:52:37 PM
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

int N, M, K;
ll A[100010];
ll B[100010];

int solve()
{
  if (K == 1)
  {
    ll sum_A = 0;
    ll sum_B = 0;
    for (auto i = 0; i < N; i++)
    {
      sum_A += A[i];
      sum_B += B[i];
    }
    if (sum_A < sum_B)
    {
      return 1;
    }
    else if (sum_A > sum_B)
    {
      return 0;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    for (auto i = 0; i < N; i++)
    {
      if (A[i] < B[i])
      {
        return 1;
      }
      else if (A[i] > B[i])
      {
        return 0;
      }
    }
    return 2;
  }
}

int main()
{
  cin >> N >> M >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> B[i];
  }
  int s = solve();
  if (s == 0)
  {
    cout << "X" << endl;
  }
  else if (s == 1)
  {
    cout << "Y" << endl;
  }
  else
  {
    cout << "Same" << endl;
  }
}