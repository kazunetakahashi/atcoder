#define DEBUG 1

/**
 * File    : D3.cpp
 * Author  : Kazune Takahashi
 * Created : 2/16/2019, 11:46:09 PM
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

const int H[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int N, M;
int A[10];
int DP[100010];

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i];
  }
  sort(A, A + M);
  reverse(A, A + M);
  fill(DP + 1, DP + 100010, -1);
  DP[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    if (DP[i] == -1)
    {
      continue;
    }
    else
    {
      for (auto j = 0; j < M; j++)
      {
        DP[i + H[A[j]]] = max(DP[i + H[A[j]]], DP[i] + 1);
      }
    }
  }
  assert(DP[N] > 0);
  int ind = 0;
  while (N > 0)
  {
    assert(ind < M);
    if (DP[N] - 1 == DP[N - H[A[ind]]])
    {
      cout << A[ind];
      N -= H[A[ind]];
    }
    else
    {
      ind++;
    }
  }
}