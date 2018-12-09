/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 12/9/2018, 10:32:26 PM
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

const int C = 5000;
// const ll M = 1000000007;

int N, A;
int x[50];

ll DP[60][10000];

int main()
{
  cin >> N >> A;
  for (auto i = 0; i < N; i++)
  {
    cin >> x[i];
    x[i] -= A;
  }
  fill(&DP[0][0], &DP[0][0] + 60 * 10000, 0);
  DP[0][C] = 1;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < 10000; j++)
    {
      if (DP[i][j] == 0)
      {
        continue;
      }
      DP[i + 1][j] += DP[i][j];
      DP[i + 1][j + x[i]] += DP[i][j];
    }
  }
  cout << DP[N][C] << endl;
}