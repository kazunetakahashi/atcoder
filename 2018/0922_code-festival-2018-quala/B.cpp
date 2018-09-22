/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 9/22/2018, 9:07:42 PM
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

int N, M, A, B;
int L[100010];
int R[100010];
int X[100010];

int main()
{
  cin >> N >> M >> A >> B;
  for (auto i = 0; i < M; i++)
  {
    cin >> L[i] >> R[i];
    L[i]--;
    R[i]--;
  }
  if (A >= B)
  {
    cout << A * N << endl;
  }
  else
  {
    fill(X, X + N, B);
    for (auto i = 0; i < M; i++)
    {
      for (auto j = L[i]; j < R[i] + 1; j++)
      {
        X[j] = A;
      }
    }
    int sum = 0;
    for (auto i = 0; i < N; i++)
    {
      sum += X[i];
    }
    cout << sum << endl;
  }
}