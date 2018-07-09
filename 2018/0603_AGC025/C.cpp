/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-9 22:57:40
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
ll L[100010];
ll imos_L[100010];
ll R[100010];
ll imos_R[100010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> L[i] >> R[i];
    R[i] = -R[i];
  }
  sort(L, L + N);
  reverse(L, L + N);
  sort(R, R + N);
  reverse(R, R + N);
  imos_L[0] = 0;
  imos_R[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    imos_L[i + 1] = imos_L[i] + L[i];
    imos_R[i + 1] = imos_R[i] + R[i];
  }
  ll ans = 0;
  for (auto i = 0; i <= N; i++)
  {
    for (auto j = i - 1; j <= i + 1; j++)
    {
      if (0 <= j && j <= N)
      {
        ans = max(ans, imos_L[i] + imos_R[j]);
      }
    }
  }
  cout << 2 * ans << endl;
}