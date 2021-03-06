/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 1/18/2019, 11:27:05 PM
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
const ll infty = 100000000007;

int N;
int h[100010];
ll DP[100010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> h[i];
  }
  fill(DP, DP + N, infty);
  DP[0] = 0;
  for (auto i = 0; i < N; i++)
  {
    int j = i + 1;
    if (j < N)
    {
      DP[j] = min(DP[j], DP[i] + abs(h[i] - h[j]));
    }
    j = i + 2;
    if (j < N)
    {
      DP[j] = min(DP[j], DP[i] + abs(h[i] - h[j]));
    }
  }
  cout << DP[N - 1] << endl;
}