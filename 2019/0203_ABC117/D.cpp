/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2/3/2019, 9:10:55 PM
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
const ll infty = (1LL << 60);

ll N;
ll K;
ll A[100010];
ll S[45][2];
ll DP[46][2];

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  fill(&S[0][0], &S[0][0] + 45 * 2, 0);
  for (auto i = 0; i < 45; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if ((A[j] >> i) & 1)
      {
        S[i][0] += (1LL << i);
      }
      else
      {
        S[i][1] += (1LL << i);
      }
    }
    // cerr << "S[" << i << "][" << 0 << "] = " << S[i][0] << endl;
    // cerr << "S[" << i << "][" << 1 << "] = " << S[i][1] << endl;
  }
  DP[45][0] = 0;
  DP[45][1] = -infty;
  for (auto i = 45 - 1; i >= 0; i--)
  {
    DP[i][0] = 0;
    DP[i][1] = 0;
    if ((K >> i) & 1)
    {
      DP[i][0] = max(DP[i][0], DP[i + 1][0] + S[i][1]);
      DP[i][1] = max(DP[i][1], DP[i + 1][0] + S[i][0]);
      DP[i][1] = max(DP[i][1], DP[i + 1][1] + S[i][1]);
      DP[i][1] = max(DP[i][1], DP[i + 1][1] + S[i][0]);
    }
    else
    {
      DP[i][0] = max(DP[i][1], DP[i + 1][0] + S[i][0]);
      DP[i][1] = max(DP[i][1], DP[i + 1][1] + S[i][1]);
      DP[i][1] = max(DP[i][1], DP[i + 1][1] + S[i][0]);
    }
  }
  cout << max(DP[0][0], DP[0][1]) << endl;
}